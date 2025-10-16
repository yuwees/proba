#include <iostream>


int main()
{
    // Пункт 1

    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите количество чисел последовательности: " << std::endl;
    std::cin >> n;

    double sum = 0; // Сумма чисел, не превышающих 10.12
    double min_num = 0; // Наименьшее число, не превышающее 10.12
    int numb_min = -1; // Номер наименьшего числа 
    bool found = false; // Флаг для проверки наличия подходящих чисел

    for (int i = 1; i <= n; i++) {
        double num;
        std::cout << "Введите число " << i << ": " << std::endl;
        std::cin >> num;

        if (num <= 10.12) {
            sum += num;
            found = true; // Устанавливаем флаг, что нашлось хотя бы одно число

            // Проверка является ли текущее число наименьшим
            if (numb_min == -1 || num < min_num) {
                min_num = num;
                numb_min = i; // Сохраняем номер
            }
        }
    }

    // Вывод результатов по пункту 1
    if (found) {
        std::cout << "Сумма всех чисел, не превышающих 10.12: " << sum << std::endl;
        std::cout << "Наименьшее число, не превышающее 10.12: " << min_num << std::endl;
        std::cout << "Номер наименьшего числа в последовательности: " << numb_min << std::endl;
    }
    else {
        std::cout << "Нет чисел, удовлетворяющих условию." << std::endl;
    }

    // Пункт 2
    int x;
    bool flag = false;
    int last_3 = 0;
    int position = 0;

    std::cout << "Введите целое число X менее 1000: " << std::endl;
    std::cin >> x;
    x = abs(x);
    if (x < 1000) {
        while (x > 0) {
            int ost = x % 10;
            if (ost == 3) {
                flag = true;
                last_3 = position;
                break;
            }
            x /= 10;
            position++;
            

        }
        if (flag == true) {
            std::cout << "Индекс последней цифры '3': " << last_3  << std::endl;
            
        }
        else {
            std::cout << "Цифра '3' отсутствует в числе." << std::endl;
        }

    }

    return 0;


    


}

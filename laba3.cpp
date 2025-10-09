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
    std::cout << "Введите целое число X менее 1000: " << std::endl;
    std::cin >> x;

    int position = -1;  // Позиция последней цифры '3'
    int copy = x;      // Копия исходного числа для обработки
    int tekyshaa_position = 1; // Текущая позиция цифры 

    while (copy > 0) {
        int ost = copy % 10; // Остаток от деления это текущая цифра
        if (ost == 3) {
            position = tekyshaa_position; // Сохраняем последнюю 3
        }
        copy /= 10; // Отбрасываем последнюю цифру
        tekyshaa_position++; // Увеличиваем счётчик позиций
    }

    // Выводим результат
    if (position != -1) {
        std::cout << "Индекс последней цифры '3': " << position << std::endl;
    }
    else {
        std::cout << "Цифра '3' отсутствует" << std::endl;
    }

    return 0;
 
}
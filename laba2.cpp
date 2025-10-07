

#include <iostream>
#include <bitset>

int main()
{
	setlocale(LC_ALL, "Russian");
	// 1 часть
	short A;
	short i;
	int bitset;
	std::cout << "Введите число А: " << std::endl;
	std::cin >> A;
	std::cout << "Число " << A << " в двоичном виде: " << std::bitset<8>(A) << std::endl;
	std::cout << "Введите номер бита i: " << std::endl;
	std::cin >> i;

	// Проверка правильности ввода номера бита
	if (i <= 0 || i > 7) {
		std::cout << "Введите значение от 0 до 7!" << std::endl;
		return 0;
	}

	int bit_i = (A >> i) & 1; // Получаем знaчение i-го бита
	int bit_zero = A & 1; // Сохранием значение 0 бита

	if (bit_i == 0) {
		A &= ~1; // Устанавливаем 0 бит в bit_i
	}
	else {
		A |= 1; // Устанавливаем 0 бит в 1
	}
	if (bit_zero == 0) { // Устаниваливаем i-й бит в bit_zero
		A &= ~(1 << i); // Устанавливаем i-й бит в 0
	} else{
        A |= (1 << i); // Устанавливаем i-й бит в 1
    }

	int num1;
	int num2;
	int num3;
	std::cout << "Введите три целых числа: " << std::endl;
	std::cin >> num1 >> num2 >> num3;

	int abs1 = abs(num1); // Вычисляем модули
	int abs2 = abs(num2);
	int abs3 = abs(num3);
    
    if (abs1 == abs2 || abs1 == abs3 || abs2 == abs3) { // Проверяем, есть ли равные модули
        std::cout << "Код 0. Вычисление невозможно" << std::endl;
    }
    else {
        int middle;
        if ((abs1 > abs2 && abs1 < abs3) || (abs1 > abs3 && abs1 < abs2)) { // Находим среднее по модулю
            middle = num1;
        }
        else if ((abs2 > abs1 && abs2 < abs3) || (abs2 > abs3 && abs2 < abs1)) {
            middle = num2;
        }
        else {
            middle = num3;
        }
        std::cout << "Среднее по модулю: " << middle << std::endl;
    }

    // Пункт 2

    int N;
    std::cout << "Введите номер региона: ";
    std::cin >> N;

    switch (N) {
    case 102:
        std::cout << "Регион " << N << ": Республика Адыгея" << std::endl;
        break;
    case 11:
        std::cout << "Регион " << N << ": Республика Коми" << std::endl;
        break;
    case 13:
        std::cout << "Регион " << N << ": Республика Мордовия" << std::endl;
        break;
    case 15:
        std::cout << "Регион " << N << ": Республика Северная Осетия-Алания" << std::endl;
        break;
    case 116:
        std::cout << "Регион " << N << ": Республика Татарстан" << std::endl;
        break;
    case 716:
        std::cout << "Регион " << N << ": Республика Тыва" << std::endl;
        break;
    default:
        std::cout << "Информация временно недоступна" << std::endl;
        break;
    }

    return 0;
}
    
	



		
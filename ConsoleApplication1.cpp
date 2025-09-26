#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double a;
	float b;
	
	
	cout << "Введите левую границу интервала: " << endl;
	cin >> a;
	

	cout << "Введите правую границу интервала: ";
	cin >> b;
	
	double mid;
	mid = (a + b) / 2.0;
	cout << "Середина интервала: " << mid << endl;
	cout << "Тип данных: double " << endl;

	cout << "Тип данных: double " << endl;
	cout << "Размер в битах: " << sizeof(double) * 8 << endl;
	cout << "Максимальное значение: " << numeric_limits<double>::max() << endl;
	cout << "Минимальное значение: " << numeric_limits<double>::lowest() << endl;
	cout << "Тип данных: float " << endl;
	cout << "Размер в битах: " << sizeof(double) * 8 << endl;
	cout << "Максимальное значение: " << numeric_limits<float>::max() << endl;
	cout << "Минимальное значение: " << numeric_limits<float>::lowest() << endl;


	return 0;

}
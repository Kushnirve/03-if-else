#include<iostream>
using namespace std;

int main() {
	setlocale(0, "rus");

	//1.1
	float number1;
	cout << "Находится ли значение числа в пределах от 25 до 50?\nВведите число и нажмите <Enter>" << endl;
	cin >> number1;
	if (number1 > 25 and number1 < 50)
		cout << "Значение числа в пределах от 25 до 50.";
	else
		cout << "Число не находится в заданном диапазоне.";

	//1.2
	int number2;
	cout << "Делится ли число на 3 нацело?\nВведите целое число и нажмите <Enter>" << endl;
	cin >> number2;
	if (number2 % 3 == 0)
		cout << "Число " << number2 << " делится нацело на три.";
	else
		cout << "Число " << number2 << " нацело на три не делится.";

	//1.3
	int const seconds_in_minute = 60, transfer_in_seconds = 100;
	float m_and_s, sec;
	int min, seconds;
	cout << "Перевод минут и секунд в секунды.\nВведите время (минут.секунд) -> ";
	cin >> m_and_s;
	min = m_and_s;
	sec = m_and_s - min;
	if (sec * transfer_in_seconds > seconds_in_minute)
		cout << "Ошибка! Количество секунд не может быть больше 60";
	else
		seconds = min * seconds_in_minute + sec * transfer_in_seconds;
	cout << "Секунды: " << seconds << endl;

	//1.4
	int day, month, year, lastday, newday, newmonth, newyear;
	cout << "Введите цифрами сегодняшнюю дату (число, месяц, год) -> ";
	cin >> day >> month >> year;
	if (month == 2) {
		// Проверка на вискосный год
		if (year % 4 == 0 and year % 100 != 0) {
			if (day > 29) {
				cout << "Вы ввели несуществующую дату!" << endl;
				exit(0);
			}
			lastday = 29;
		}
		else if (year % 400 == 0) {
			if (day > 29) {
				cout << "Вы ввели несуществующую дату!" << endl;
				exit(0);
			}
			lastday = 29;
		}
		else {
			if (day > 28) {
				cout << "Вы ввели несуществующую дату!" << endl;
				exit(0);
			}
			lastday = 28;
		}
	}
	else if (month == 4 or month == 6 or month == 9 or month == 11) {
		if (day > 30) {
			cout << "Вы ввели несуществующую дату!" << endl;
			exit(0);
		}
		lastday = 30;
	}
	else {
		if (day > 31) {
			cout << "Вы ввели несуществующую дату!" << endl;
			exit(0);
		}
		lastday = 31;
	}
	// Проверка последний ли день месяца
	if (day == lastday) {
		cout << "Последний день месяца!" << endl;
		newday = 1; // Выставлям день на первый день месяца
		// Если месяц последний
		if (month == 12) {
			newmonth = 1; // Выставляем месяц на первый
			newyear = year + 1; // Прибавляем год
		}
		else {
			newmonth = month + 1; // Прибавляем месяц
			newyear = year; // Тот же год
		}
	}
	else {
		newday = day + 1; // Прибавляем день
		newmonth = month; // Тот же месяц
		newyear = year; // Тот же год
	}
	// Особые даты
	if (day == 31 and month == 12) cout << "С наступающим новым годом!" << endl;
	if (day == 31 and month == 8) cout << "Завтра в школу :(" << endl;
	if (day == 7 and month == 3) cout << "Завтра 8 марта" << endl;
	cout << "Завтра " << newday << "." << newmonth << "." << newyear;
}
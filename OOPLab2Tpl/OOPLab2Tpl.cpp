// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"

int multiplyTwoNumbers(int a, int b) {
	int result = 0;
	while (b > 0) {
		if (b & 1) {
			result += a;
		}
		a = a << 1;
		b = b >> 1;
	}
	return result;
}
int divideTwoNumbers(int a, int b) {
	while (b > 1) {
		a = a >> 1;
		b = b >> 1;
	}
	return a;
}
void Task1()
{
	int a, b, c, d; // вхідні дані з умови
	cout << "Enter a, b, c, d numbers:" << endl;
	cin >> a >> b >> c >> d;
	cout << "Result: " << divideTwoNumbers(multiplyTwoNumbers(17, a) +
		multiplyTwoNumbers(312, c), 32) -
		multiplyTwoNumbers(b, 120) +
		multiplyTwoNumbers(d, 127) << endl;
	//вираз, записаний із заміною операцій множення та ділення
	system("pause");
}
/// @brief 
/// @return 
int main()
{
	setlocale(LC_CTYPE, "ukr");
	cout << "OOP. Template for laboratory work #2.\n";

	char ch = '5';
	do {
		system("cls");
		MenuTask();
		ch = cin.get();

		cin.get();

		switch (ch) {
		case '1': Task1();   break;
		case '2': task1();   break;
		case '3': task1();   break;
		case '4': task1();   break;
		case '5':  Examples(); break;
		case '6': return 0;
		}
		cout << " Press any key and enter\n";
		ch = cin.get();
	} while (ch != '6');

}


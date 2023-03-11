﻿// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Tasks.h"
using namespace std;
#include <bitset>
#pragma warning(disable : 4996) 

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
	cout << "Result: " << (
		divideTwoNumbers(multiplyTwoNumbers(17, a) +
			multiplyTwoNumbers(312, c), 32) -
		multiplyTwoNumbers(b, 120) +
		multiplyTwoNumbers(d, 127)) << endl;
	//вираз, записаний із заміною операцій множення та ділення
	system("pause");
}
void Task2()
{
	const int size = 8 + 1;
	char** S = new char* [size]; // масив з 8 рядків
	unsigned short** Rez = new unsigned short* [size]; // масив для зашифрованих символів рядків
	unsigned char c;// змінна для символа, що буде шифруватися
	unsigned short r, t, b; //змінні для вже зашифрованого символу та пошуку парності полів
	cout << "Enter " << size - 1 << " strings" << endl; // вхідні дані - 8 рядків до 8 символів
	for (unsigned short i = 0; i < size - 1; i++)
		//введення рядків з розподіленням пам'яті під двовимірні масиви 
	{
		S[i] = new char[size];
		Rez[i] = new unsigned short[16];
		cin.getline(S[i], size);
		while (strnlen(S[i], size) < size)//доповнення замалих рядків
		{
			strcat(S[i], " ");
		}

	}
	for (unsigned short i = 0; i < size - 1; i++)
	{
		for (unsigned short j = 0; j < size - 1; j++)
		{
			c = S[i][j];//поточний символ
			r = 0;//поточний шифрований символ
			r |= i;//додавання номера рядка
			r <<= 3;//зсув на 3 біти, виділені під номер символа
			r |= j;//додавання номера символа
			t = 1;
			b = false;
			for (unsigned short z = 0; z < 6; z++) // обчислення біта парності перших 2 полів
			{
				if (r & t) {
					b = !b;
				}
				t <<= 1;
			}
			r <<= 1;//зсув на 1 біт, виділений під парність попередніх двох полів
			r |= b;//додавання парності попередніх двої полів
			r <<= 8;//зсув на 8 позицій для коду символа
			r |= c;//додавання коду символа
			t = 1;
			b = false;
			for (unsigned short z = 0; z < 8; z++) // обчислення біта парності поереднього поля
			{
				if (r & t) {
					b = !b;
				}
				t <<= 1;
			}
			r <<= 1;//зсув на 1 позицію для парності попереднього поля
			r |= b; // додавання парності попереднього поля
			Rez[i][j] = r; //зашифрований символ додається у масив
			cout << std::bitset<16>(Rez[i][j]) << " ";
		}cout << endl;
	}
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
		case '2': Task2();   break;
		case '3': Task1();   break;
		case '4': Task1();   break;
		case '5': return 0;
		case '6': return 0;
		}
		cout << " Press any key and enter\n";
		ch = cin.get();
	} while (ch != '6');

}


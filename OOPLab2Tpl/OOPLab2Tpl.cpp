// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Tasks.h"
using namespace std;
#include <bitset>
#pragma warning(disable : 4996) 
struct CharCode
{
	unsigned short Row : 3; // номер рядка
	unsigned short Pos : 3; // номер позиції в рядку
	bool EvenNumber; // парність номера та позиції
	unsigned short Code : 8; // код символа
	bool EvenCode; // парність коду символа
	unsigned short FullCode : 16; // повний шифр символа
};
struct Task4Struct
{
	unsigned short a : 4;
	unsigned short b : 4;
	unsigned short c : 12;
	unsigned short d : 5;
	bool e;
};
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
	//вираз, записаний із заміною операцій множення та ділення (з використанням додатково написаних функцій) 
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
			r = 0;
			r |= i;//додавання номера рядка
			r <<= 3;//зсув на 3 біти, виділені під номер символа
			r |= j;//додавання номера символа
			t = 1;
			b = false;
			for (unsigned short z = 0; z < 6; z++) // обчислення біта парності перших 2 полів
			{
				if (r & t) {
					b = ~b;
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
					b = ~b;
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
void Task3()
{
	const unsigned short size = 8 + 1;
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
	CharCode cc;
	cc.Row = 0;
	do
	{
		cc.Pos = 0;
		do {
			cc.Code = S[cc.Row][cc.Pos];//поточний символ
			cc.FullCode = 0;//поточний шифрований символ
			cc.FullCode |= cc.Row;//додавання номера рядка
			cc.FullCode <<= 3;//зсув на 3 біти, виділені під номер символа
			cc.FullCode |= cc.Pos;//додавання номера символа
			t = 1;
			cc.EvenNumber = false;
			for (unsigned short z = 0; z < 6; z++) // обчислення біта парності перших 2 полів
			{
				if (cc.FullCode & t) {
					cc.EvenNumber = !cc.EvenNumber;
				}
				t <<= 1;
			}
			cc.FullCode <<= 1;//зсув на 1 біт, виділений під парність попередніх двох полів
			cc.FullCode |= cc.EvenNumber;//додавання парності попередніх двої полів
			cc.FullCode <<= 8;//зсув на 8 позицій для коду символа
			cc.FullCode |= cc.Code;//додавання коду символа
			t = 1;
			cc.EvenCode = false;
			for (unsigned short z = 0; z < 8; z++) // обчислення біта парності поереднього поля
			{
				if (cc.FullCode & t) {
					cc.EvenCode = !cc.EvenCode;
				}
				t <<= 1;
			}
			cc.FullCode <<= 1;//зсув на 1 позицію для парності попереднього поля
			cc.FullCode |= cc.EvenCode; // додавання парності попереднього поля
			Rez[cc.Row][cc.Pos] = cc.FullCode; //зашифрований символ додається у масив
			cout << std::bitset<16>(Rez[cc.Row][cc.Pos]) << " ";
			cc.Pos++;
		} while (cc.Pos != size - 2);
		cout << endl;
		cc.Row++;
	} while (cc.Row != size - 2);
}
void Task4()
{
	Task4Struct t4s;
	cout << "Enter 0 <= a <= 12,	0 <= b <= 9,	1940 <= c <= 2065,	0 <= d <= 31,	0 <= e <= 1" << endl;
	unsigned short a, b, c, d;
	bool e;
	cin >> a >> b >> c >> d >> e;
	if (a > 12 || b > 9 || c < 1940 || c>2065 || d > 31)
		cout << "Wrong input" << endl;
	else {
		t4s.a = a;
		t4s.b = b;
		t4s.c = c;
		t4s.d = d;
		t4s.e = e;
		cout << t4s.a << " " << t4s.b << " " << t4s.c << " " << t4s.d << " " << t4s.e;
	}
	cin.get();
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
		case '3': Task3();   break;
		case '4': Task4();   break;
		case '5': return 0;
		case '6': return 0;
		}
		cout << " Press any key and enter\n";
		ch = cin.get();
	} while (ch != '6');

}


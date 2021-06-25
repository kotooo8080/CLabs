// LRPROG2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	int b[100],           //исходный массив
		arr[100],         //результирующий массив
		size,             //размер исходного массива
		k = 0,            //число для вычисления кратных
		num = 0,          //переменная для подсчета кратных
		z = 0,            //переменная для switch
		i,                //переменная для цикла
		n = 0,            //переменная для цикла результирующего массива
		w0 = 0,           //переменная для цикла
		e = 0, v = 0;     //переменные-флаги

	do {
		cout <<
			"1 - enter the array \n" <<
			"2 - print the array \n" <<
			"3 - remove elements of multiple k \n" <<
			"4 - change elements in places \n\n";

		cout << "Please, enter the menu item number \n";
		cin >> z;
		
		switch (z)
		{
		case 1: //ввод исходных данных
			do {
				cout << "enter the size of the array \n";
				cin >> size;
				if ((size < 1) || (size > 100))
					cout << "please, try to enter size of the array again \n";
			} while ((size < 1) || (size > 100));

			cout << "enter the elements of the array \n";

			for (i = 0; i < size; i++)
				cin >> b[i];
			cout << endl;
			e = 1;
			v = 0;
			break;

		case 2: //контрольный вывод исходного массива
			if (e == 1)
			{
				for (i = 0; i < size; i++)
					cout << b[i] << ' ';
				cout << endl;
			}
			else
				cout << "You didn't enter the original array \n";
			break;

		case 3: //удаление кратных элементов из исходного массива 
			if (e == 1)
			{
				do {
					cout << "enter k " << endl;
					cin >> k;
					if (k < 1)
						cout << "please, enter k again \n";
				} while (k < 1);

				n = 0;
				num = 0;
				for (i = 0; i < size; i++) //подсчет количества элементов не кратных заданному числу
				{
					if (b[i] % k != 0) 
					{
						arr[n] = b[i];
						num++;
						n++;
					}
				}

				for (n = 0; n < num; n++)
					cout << arr[n] << ' ';
				cout << endl;
				v = 1;
			}
			else
				cout << "You didn't enter the original array \n";

			break;

		case 4: //перестановка местами парных элементов массива
			if (v == 1) 
			{
				for (n = 0; n < (num - 1); n += 2) {
					w0 = arr[n + 1];
					arr[n + 1] = arr[n];
					arr[n] = w0;
				}
				for (n = 0; n < num; n++)
					cout << arr[n] << ' ';
				cout << endl;
			}
			else
				cout << "You didn't delete items from the array \n";

			break;

		case 0: // выход из switch
			break;

		default:
			cout << "Something went wrong. Please, try to enter the menu item number again " << endl;
		}
	} while (z != 0);

	system ("pause");
	
	return 0;
}

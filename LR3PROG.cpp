// LR3PROG.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a[50][50],                        //исходный двумерный массив
		res[50][50],                      //результирующая матрица
		a0, a1,                           //переменные для ввода размеров матрицы
		z,                                //переменная для организации меню
		i, j,                             //переменные для организации циклов исходной матрицы
		k = 0, p = 0,                     //переменные для организации циклов новой матрицы
		f,                                //переменная для формирования новой матрицы
		e = 0, l = 0, m = 0, v = 0;       //переменные-флаги
	do
	{
		cout << 
			"1 - enter the number of rows \n" <<
			"2 - enter the number of columns \n" <<
			"3 - enter array's elements \n" <<
			"4 - print the original array \n" <<
			"5 - create a new array from the rows of the array \n" <<
			"6 - print a new array \n" <<
			"0 - exit \n";

		cout << endl;

		cout << "Please, enter the menu item number \n";
		cin >> z;

		switch (z)
		{
		case 1: //ввод количества строк исходного массива
			do {
				cout << "enter the number of rows, a0<51 \n";
				cin >> a0;

				if ((a0 < 1) || (a0 > 50))
					cout << "please, try to enter number of the rows again \n";

			} while ((a0 < 1) || (a0 > 50));
			
			e = 1;
			v = 0;

			break;
		case 2: //ввод количества столбцов исходного массива
			
			do {
					cout << "enter the number of the columns of the array, a1<51 \n";
					cin >> a1;

					if ((a1 < 1) || (a1 > 50))
						cout << "please, try to enter number of the columns again \n";

			} while ((a1 < 1) || (a1 > 50));
				
			v = 0;
			l = 1;
			
			break;

		case 3: //ввод элементов исходного двумерного массива

			if (( e != 0 )&&( l != 0 ))
			{
				cout << "enter the elements of the array \n";
				for (i = 0; i < a0; i++)
				{
					for (j = 0; j < a1; j++)
						cin >> a[i][j];
				}

				m = 1;
				v = 0;
			}
			else
			{
				if (e == 0)
					cout << "You didn't enter the number of the rows \n\n";
				if (l == 0)
					cout << "You didn't enter the number of the columns \n\n";
			}
			e = 0;
			l = 0;

			break;
		
		case 4: //вывод элементов исходного двумерного массива
			if (m != 0)
			{
				for (i = 0; i < a0; i++)
				{
					for (j = 0; j < a1; j++)
						cout << a[i][j] << "     ";
					cout << "\n";

				}
				cout << endl;
			}
			else
				cout << "You didn't enter the original array \n\n";
			break;

		case 5: //формирование новой матрицы из строк исходной
			if (m != 0)
			{
				k = 0;
				for (i = 0; i < a0; i++)
				{
					f = 1;
					for (j = 0; j < (a1 - 1) && f == 1; j++)
						if (a[i][j] >= a[i][j + 1])
							f = 0;
					if (f == 1)
					{
						for (j = 0; j < a1; j++)
							res[k][j] = a[i][j];
						k++;
					}
				}
				p = k;
				v = 1;
			}
			
			break;

		case 6:  //вывод матрицы, сформированной из строк исходной
			if (v == 1)
			{
				if (k == 0)
					cout << "strings that match the conditions aren't found \n\n" << endl;
				else
					for (k = 0; k < p; k++)
					{
						for (j = 0; j < a1; j++)
							cout << res[k][j] << "     ";
						cout << "\n";
					}
			}
			else
				cout << "You didn't create a new array from the rows of the original array \n\n";
			break;

		case 0:  // выход из switch
			break;
		}
	} while (z != 0);

	system("pause");

    return 0;
}


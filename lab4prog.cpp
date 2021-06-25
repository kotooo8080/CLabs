// lab4prog.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()

{
	int **array = NULL,                      //исходный динамический массив
		**array_new = NULL,                  //результирующий массив
		i, j,                                //переменные для организации циклов
		rows = 0,                            //количество строк
		columns = 0,                         //количество столбцов
		s,                                   //переменная для организации case
		f,                                   //переменная для формирования новой матрицы
		k, p,                                //переменные для организации циклов новой матрицы
		wr = 0,                              //переменная для формирования нового массива
		e1 = 0, e2 = 0, e3 = 0, e5 = 0;      //переменные-флаги
		


	do {
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
		cin >> s;

		switch (s)
		{
		case 1:  //ввод количества строк исходного двумерного массива

			if (e5 == 1)
			{
				for (i = 0; i < rows; i++)   //освобождение памяти из под массивов 		
					free(*(array + i));
				free(array);

				if (k != 0);
				{
					for (i = 0; i < rows; i++)
						free(*(array_new + i));
					free(array_new);
				}
			}
			do
			{
				cout << "enter the number of the rows in the array (1 <= rows) \n";
				cin >> rows;

				if (rows <= 0)
					cout << "please, try to enter number of the rows again \n";

			} while (rows <= 0);

			e1 = 1;
			e3 = e5 = 0;

			break;

		case 2:  //ввод количества столбцов исходного двумерного массива

			if (e5 == 1)
			{
				for (i = 0; i < rows; i++)   //освобождение памяти из под массивов		
					free(*(array + i));
				free(array);

				if (k != 0);
				{
					for (i = 0; i < rows; i++)
						free(*(array_new + i));
					free(array_new);
				}
			}

			do
			{
				cout << "enter the number of the columns of the array, >1 \n";
				cin >> columns;

				if (columns <= 1)
					cout << "please, try to enter number of the columns again \n";

			} while (columns <= 1);

			e2 = 1;
			e3 = e5 = 0;

			break;

		case 3:  //ввод элементов исходного двумерного массива

			if ((e1 == 1) && (e2 == 1))
			{
				if (e5 == 1)
				{
					for (i = 0; i < rows; i++)   //освобождение памяти из под массивов		
						free(*(array + i));
					free(array);

					if (k != 0);
					{
						for (i = 0; i < rows; i++)
							free(*(array_new + i));
						free(array_new);
					}
				}
				cout << "enter the elements of the matrix: " << endl;
				array = (int **)malloc(rows * sizeof(int *));
				for (i = 0; i < rows; i++)
				{
					array[i] = (int *)malloc(columns * sizeof(int));
				}
				for (i = 0; i < rows; i++)
					for (j = 0; j < columns; j++)
						cin >> (*(*(array + i) + j));

				e3 = 1;
				e5 = k = 0;
			}
			else
			{
				if (e1 != 1)
					cout << "You didn't enter the number of rows of the array \n\n";
				if (e2 != 1)
					cout << "You didn't enter the number of the columns of the array \n\n";

				break;


		case 4:  //вывод исходного двумерного массива

			if (e3 == 1)
			{
				cout << "Your matrix: " << endl;
				for (i = 0; i < rows; i++)
				{
					for (j = 0; j < columns; j++)
					{
						cout << (*(*(array + i) + j)) << " ";
					}
					cout << endl;
				}
			}
			else
				cout << "You didn't enter the original array \n\n";
			break;


		case 5:  //формирование новой матрицы из строк исходной

			if (e3 == 1)
			{
				array_new = (int**)malloc(rows * sizeof(int*));
				for (i = 0; i < rows; i++)
					*(array_new + i) = NULL;

				k = 0;
				for (i = 0; i < rows; i++)
				{
					f = 1;
					for (j = 0; j < (columns - 1) && f == 1; j++)
						if (array[i][j] >= array[i][j + 1])
							f = 0;
					if (f == 1)
					{
						k++;
					}
				}
				p = k;
				
				wr = rows - k;   //количество строк, которые не переносятся в новый массив

				for (i = 0; i < rows; i++)
				{
					f = 1;
					for (j = 0; (j < (columns - 1) && (f == 1)); j++)
						if (array[i][j] >= array[i][j + 1])
							f = 0;
					if (f == 1)
					{
						for (j = 0; j < columns; j++)
							*(array_new + i - wr) = (int*)malloc(columns * sizeof(int));

						for (j = 0; j < columns; j++)

							*(*(array_new + i - wr) + j) = *(*(array + i) + j);
					}
				}

				e5 = 1;

				if (k != 0)
					cout << "New array is formed \n";
				
				if (k == 0)
					cout << "strings that match the conditions aren't found \n\n";
			}
			else
				cout << "You didn't enter the original array \n\n";

			break;

		case 6:  //вывод результата
			if (e5 != 0)
			{
				if (k == 0)
					cout << "strings that match the conditions aren't found \n\n";

				cout << "Your matrix: " << endl;
				for (int i = 0; i < p; i++)
				{
					for (j = 0; j < columns; j++)
						printf(" %4d ", *(*(array_new + i) + j));
					printf("\n");
				}
			}
			else
			{
			    cout << "You didn't create a new array from the rows of the original array \n\n";
				
			}
			break;

		case 0:
			puts("Thank you for using this program! \n");
			if (e5 != 0)
			{
				for (i = 0; i < rows; i++)   //освобождение памяти из под массивов		
					free(*(array + i));
				free(array);

				if (k != 0);
				{
					for (i = 0; i < rows; i++)
						free(*(array_new + i));
					free(array_new);
				}
			}
			break;

		default:
			cout << "Something went wrong. Please, try to enter the menu item number of 0 to 6 again" << endl;

			}
		}
	} while (s != 0);
	
	system("pause");

    return 0;
}


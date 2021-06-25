// lab5prog.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;


//----------Считывает количество строк исходного двумерного массива----------//
int  n_rows(void)
{
	int rows = 0;
	do
	{
		puts ("enter the number of the rows in the array \n");
		scanf_s("%d", &rows);

		if (rows <= 0)
			cout << "please, try to enter number of the rows again \n";

	} while (rows <= 0);

	return rows;
}

//----------Считывает количество столбцов исходного двумерного массива----------//
int n_columns(void)
{
	int columns = 0;
	do
	{
		puts("enter the number of the columns of the array \n");
		scanf_s("%d", &columns);

		if (columns <= 0)
			cout << "please, try to enter number of the columns again \n";

	} while (columns <= 0);

	return columns;
}

//----------Ввод элементов исходного двумерного массива----------//
void elements(int** array, int rows, int columns)
{
	puts("enter the elements of the matrix: \n\n");

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			scanf_s("%d", *(array + i) + j);
}

//----------Выделение памяти для исходной матрицы-----------//
int** array_1(int rows, int columns)
{
	int** array;
	array = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++)
		*(array + i) = (int*)malloc(columns * sizeof(int));
	return array;
}


//----------Вывод исходного двумерного массива----------//
void original_array(int** array, int rows, int columns)
{
	cout << "Your matrix: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << (*(*(array + i) + j)) << " ";
		}
		cout << endl;
	}
}

//----------Создание нового двумерного массива из строк исходного----------//
int c_res(int** array, int rows, int columns)
{
	int f = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < (columns - 1) && f == 1; j++)
			if (*(*(array + i) + j) >= *(*(array + i) + (j + 1)))
				f = 0;
	}
	return (f);
}

//----------Вывод результата----------//
void out_res(int **array_new, int columns, int p)
{
	cout << "Your matrix: " << endl;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < columns; j++)
			printf(" %4d ", *(*(array_new + i) + j));
		printf("\n");
	}
}

//----------Освобождение памяти из под исходного двумерного массива----------//
int** free_massiv(int **array, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
		free(*(array + i));
	free(array);

	return array = NULL;
}

//------------Освобождение памяти из под новой матрицы----------//
int** free_m_2(int **array_new, int p)
{
	for (int i = 0; i < p; i++)
		free(*(array_new + i));
	free(array_new);

	return array_new = NULL;
}

//----------Функция main----------//
int main()
{
	int **array = NULL,                  //исходный динамический массив
		**array_new = NULL,              //результирующий массив
		i = 0, j = 0,                    //переменные для организации циклов
		rows = 0,                        //количество строк
		columns = 0,                     //количество столбцов
		s,                               //переменная для организации case
		f = 0,                           //переменная для формирования новой матрицы
		k, p = 0,                        //переменные для организации циклов новой матрицы
		wr = 0,                          //переменная для формирования нового массива
		e = 0, e2 = 0, e3 = 0, e5 = 0;   //переменные-флаги

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
		case 1:        //Ввод количества строк исходного двумерного массива
			if (e5 == 1)
			{
				array = free_massiv(array, rows);
				if (p != 0)
				{
					array_new = free_massiv(array_new, rows);
					p = 0;
					k = 0;
				}
			}

			rows = n_rows();
			e = 1;
			e3 = e5 = 0;

			break;

		case 2:        //Ввод количества столбцов исходного двумерного массива
			if (e5 == 1)
			{
				array = free_massiv(array, rows);
				if (p != 0)
				{
					array_new = free_massiv(array_new, rows);
					p = 0;
					k = 0;
				}
			}

			columns = n_columns();
			e2 = 1;
			e3 = e5 = 0;

			break;

		case 3:
			if ((e == 1) && (e2 == 1))
			{
				if (e3 == 1)
				{
					array = free_massiv(array, rows);
					if (p != 0)
					{
						array_new = free_massiv(array_new, rows);
						p = 0;
						k = 0;
					}
				}

				array = array_1(rows, columns);
				elements(array, rows, columns);

				e3 = 1;
				e5 = p = 0;
			}
			else
			{
				if (e != 1)
					cout << "You didn't enter the number of the rows \n";
				if (e2 != 1)
					cout << "You didn't enter the number of the columns \n";
			}
			break;

		case 4:

			if (e3 == 1)
				original_array(array, rows, columns);
			else
				cout << "You didn't enter the original array \n\n";
			break;

		case 5:

			if (e3 == 1)
			{
				array_new = (int**)malloc(rows * sizeof(int*));
				for (i = 0; i < rows; i++)
					*(array_new + i) = NULL;

				k = 0;
				
				f = c_res(array, rows, columns);
				if (f == 1)
					k++;
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


		case 6:

			if (e5 != 0)
			{
				if (k == 0)
					cout << "strings that match the conditions aren't found \n\n";
				else
				out_res(array_new, columns, p);
	
			}
			else
				cout << "You didn't create a new array from the rows of the original array \n\n";
			
			break;

		case 0:
			break;

		default:
			cout << "Something went wrong. Please, try to enter the menu item number again" << endl;
		
		}

	} while (s != 0);
	
	system("pause");
    return 0;
}


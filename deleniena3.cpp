// deleniena3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int p = 0, //переменная для записи частного
		r = 0, //переменная для записи остатка
		n = 0; //переменная для записи исходного числа

	puts("Please enter a number, that you would like to divide by 3");
	scanf_s("%d", &n);

	r = n;
	if (r >= 3)
		while (r >= 3)
		{
			r = r - 3;
			p++;
		}
	else
		while (r < 0)
		{
			r = r + 3;
			p--;
		}

	printf("Your initial number: %d, quotient: %d, remainder: %d \n", n, p, r);
	system("pause");
    return 0;
}


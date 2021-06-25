// pribavim11.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h" 
#include <iostream> 
using namespace std;

int main()
{
	int* a;
	int colvo;
	int c = 0;
	a = (int*)malloc(sizeof(int));
	/*for (size_t i = 0; (c = getchar()) != '\n'; i++)
	{
		a = (int*)realloc(a, (i + 1) * sizeof(int));
		a[i] = c - '0';
		colvo = i + 1;
	}*/

	//int l = 0;

	//cin >> l;

	/*for (int i = 0; (l/10)>0 ; i++)
	{
		a = (int*)realloc(a, (i + 1) * sizeof(int));
		a[i] = l % 10;
		l = l / 10;
		colvo = i + 1;
	}*/
	for (size_t i = 0; c != '\n'; i++)
	{
		c = getchar();
		a = (int*)realloc(a, (i + 1) * sizeof(int));
		a[i] = c - '0';
		colvo = i;
	}


	int* t = (int*)malloc(colvo * sizeof(int));

	for (int i = colvo - 1; i >= 0; i--)
	{
		t[colvo - i - 1] = a[i];
	}
	a = t;
	int p = 0;

	a[0] = ((a[0] + 1) % 2);
	p = (a[0] + 1) / 2;
	if (a[1] == 1) 
	a[1] = ((a[1] + p + 1) % 2);
	else 
	a[1] = ((a[1] + p) % 2); 
	p = (a[1] + p + 1) / 2;
	//int cl = colvo;
	//for (int i = 2; i < colvo; i++)
	//{
		if (p >= 0)
		{
			int i = 2;
			while ((a[i] == 1) && (i < colvo))
			{
				a[i] = 0;
				i++;
			}
			if (i == colvo)
			{
				a = (int*)realloc(a, (i + 1) * sizeof(int));
				a[i] = 1;
				colvo++;
			}
			else
			{
				a[i] = 1;
			}
		}
	//}
	//colvo = cl;
	printf("Result:");
	for (size_t i = 0; i < colvo; i++)
	{
		printf("%d", a[colvo - i - 1]);
	}
	putchar('\n');
	system("pause");
	return 0;
}


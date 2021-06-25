// NOD.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
//#include "golova.h"

using namespace std;
struct Nat
{
	unsigned short int razmer;
	unsigned short int *chislo;
};

Nat input_nat()
{

	Nat input;
	input.razmer = 0;
	input.chislo = NULL;
	bool flag = true;
	for (size_t schet = 0; flag; schet++)
	{
		input.chislo = (unsigned short int*)realloc(input.chislo, (schet + 1) * sizeof(unsigned short int));
		*(input.chislo + schet) = (getchar() - 48);
		input.razmer++;
		if (*(input.chislo + schet) > 9 || *(input.chislo + schet) < 0)
		{
			if (*(input.chislo + schet) != ('\n' - 48))
			{
				puts("Please, input correct data");
				free(input.chislo);
				input.razmer = 0;
			}
			flag = false;
		}
	}

	if (input.razmer == 1 && *input.chislo == 0)
	{
		puts("Please, input correct data");
		free(input.chislo);
		input.razmer = 0;
	}

	if (input.razmer == 0)
		puts("Your degit is empty");

	return input;
}

int GCF_NN_N(int a, int b)
{
	int a1 = a;
	int b1 = b;

	while (1)
	{
		if ((a == b) || (a*b == 0))
		{
			break;
		}
		if (a > b)
		{
			a1 = a1 - b1;
		}
		if (a < b)
		{
			b1 = b1 - a1;
		}
	}

	if (a1 == 0)
	{
		return b1;
	}
	else
	{
		return a1;
	}

}


int main()
{
	int k = 0, l = 0;
	int nod, nok;

	printf("Please, enter two integers \n");
	scanf_s("%d, %d", k, l);

	nod = GCF_NN_N(k, l);

	nok = (k*l) / nod;

    return 0;
}



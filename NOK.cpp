// NOK.cpp: определяет точку входа для консольного приложения.
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

Nat GCF_NN_N(Nat *a, Nat *b)
{
	if (COM_NN_D(a, b) == 0)
	{
		return *a;
	}
	if (COM_NN_D(a, b) == 1)
	{
		Nat *tmp = a;
		a = b;
		b = tmp;
	}

	return ;
}

/*Nat GCF_NN_N(Nat a, Nat b)
{
	if ((COM_NN_D(a, b) == 1)||(COM_NN_D(a, b) == 2))
		if (COM_NN_D(a, b) == 1)
		{
		Nat tmp = a;
		a = b;
		b = tmp;
		}
	b = b - a;
	return a;
}
*/
Nat LCM_NN_N(Nat a, Nat b)
{
	int k,
		i1;
	Nat c,
		d,
		nod;
	bool flag = true;
	for (int i = 2; flag; i++)
	{
		i1 = i;
		for (k = 1; i > 10; k++)
			i1 /= 10;

		c.razmer = k;
		c.chislo = (unsigned short int*)malloc(c.razmer * sizeof(unsigned short int));
		for (int j = 0; j < c.razmer; j++)
		{
			c.chislo[c.razmer - (j + 1)] = i % 10;
			i /= 10;
		}
		d = MUL_NN_N(a, c);
		nod = GCF_NN_N(d, b);
		if (b.chislo == nod.chislo)
			flag = false;
	}
	return (d);
}

Nat GCF_NN_N(Nat a, Nat b) {
	Nat c;
	while (b.chislo[0]) {
		c = MOD_NN_N(a,b);
		a = b;
		b = c;
	}
	return (a);
}

int main()
{
    return 0;
}


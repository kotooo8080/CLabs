// org1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void binary_char(char c)
{
	for (int n = 0; n < 8; n++)
	{
		if ((1 << (7 - n)) & c)
			printf("1");
		else
			printf("0");
	}
	puts("");
}

void binary_double(long long num, int p)
{
	for (int k = p - 1; k >= 0; k--)
	{
		if (num & (long long)1 << k)
			printf("1");
		else
			printf("0");
	}
}

union udouble{
	double dd;
	long long u;
};

int main()
{
	int z = 0;
	char ch;
	double d;
	udouble ud;
	
	printf("1 - enter char and double\n2 - output char and double\n3 - invert bits\n");
	do
	{
		puts("Please, enter the menu item number");
		scanf_s("%d", &z);

		switch (z)
		{
		case 1:
		{
			getchar();
			puts("Please, enter the symbol");
			scanf_s("%c", &ch);
			puts("Please, enter double");
			scanf_s("%lf", &d);
			break;
		}
		case 2:
		{
			printf("char:    %c\n", ch);
			printf("double: %lf\n", d);
			ud.dd = d;
			binary_char(ch);
			binary_double(ud.u, 64);
			puts("");
			break;
		}
		case 3:
		{
			ud.dd = d;
			int quantity = 0, num_of_bit = 0;
			puts("for char:");
			puts("Enter the bit number from which you want to invert the values");
			do {
				scanf_s("%d", &num_of_bit);
				if ((num_of_bit > 7) || (num_of_bit < 0))
					printf("Enter the correct number of bit(0 - 7)");
			} while ((num_of_bit > 7) || (num_of_bit < 0));

			puts("Enter quantity of bits");
			do {
				scanf_s("%d", &quantity);
				if ((quantity > 8) || (quantity < 1))
					printf("Enter the correct quantity(1 - 8)");
			} while ((quantity > 8) || (quantity < 1));

			for (int i = num_of_bit; i < (num_of_bit + quantity); i++)
			{
				ch ^= 1 << i;
			}

			puts("for double:");
			puts("Enter the bit number from which you want to invert the values");
			do {
				scanf_s("%d", &num_of_bit);
				if ((num_of_bit > 63) || (num_of_bit < 0))
					printf("Enter the correct number of bit(0 - 63)");
			} while ((num_of_bit > 63) || (num_of_bit < 0));

			puts("Enter quantity of bits");
			do {
				scanf_s("%d", &quantity);
				if ((quantity > 64) || (quantity < 1))
					printf("Enter the correct quantity(1 - 64)");
			} while ((quantity > 64) || (quantity < 1));

			for (int i = num_of_bit; i < (num_of_bit + quantity); i++)
			{
				ud.u ^= (long long)1 << i;
			}
			
			printf("invert char bits:   ");
			binary_char(ch);
			puts("");
			printf("invert double bits: ");
			binary_double(ud.u, 64);
			puts("");

			printf("result char:   %c\n", ch);
			printf("result double: %.30lf\n", ud.dd);
			break;
		}
		default:
			puts("Enter the correct menu item number");
			break;
		}
	} while (z != 0);
	system("pause");
    return 0;
}


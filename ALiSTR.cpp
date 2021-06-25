// ALiSTR.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;
const int Nmax = 26;
struct list {
	char el;
	list *next;
};
list *add(list* head, char ch) //ввод элементов односвязного списка
{
	list *ptr = (struct list*)malloc(1 * sizeof(struct list));
	ptr->el = ch;
	ptr->next = head;
	head = ptr;
	return (head);
}
bool mas(char arr[], char alf[], bool brr[]) //набор элементов в массив bool
{
	int len_arr = strlen(arr),
		flag = false;
	char tmp;
	for (int i = 0; i < len_arr - 1; i++)
	{
		for (int j = 1; j < len_arr; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int k = 0; k < len_arr; k++)
	{
		for (int q = 0; (q < Nmax) && (!flag); q++)
		{
			if (arr[k] == alf[q])
			{
				brr[q] = true;
				flag = true;
			}
		}
		flag = false;
	}
	return (brr);
}
int dec(bool brr[], int digit) //перевод в машинное слово
{
	for (int i = 0; i < Nmax; i++)
	{
		digit |= brr[i] << (Nmax - 1 - i);
	}
	return digit;
}
void vvod(char mas[])
{
	char c = '1';
	bool f = 0;
	int k = 0;
	for (int k = 0; ((k < Nmax) && (c != '\n')); k++)
	{
		c = getchar();
		for (int j = 0; j < k; j++)
		{
			if (c == mas[j])
			{
				k--;
				f = true;
			}
		}
		if (!f)
			mas[k] = c;
		f = 0;
		if (c == '\n')
			mas[k] = '\0';
	}
}
void vvod_is_fayla(char Buff[], char arr[])
{
	
	char c = '1';
	bool f = 0;
	int k = 0, b = 0;
	while (b < strlen(Buff))
	{
		for (int k = 0; ((k < Nmax) && (c != '\0')); k++)
		{
			c = Buff[b];
			b++;
			for (int j = 0; j < k; j++)
			{
				if (c == arr[j])
				{
					k--;
					f = true;
				}
			}
			if (!f)
				arr[k] = c;
			f = 0;
			if (c == '\n')
				arr[k] = '\0';
		}
	}
}
void generation(char arr[])
{
	char vr[Nmax + 1];
	bool f1 = false;
	int r = 0;
	int x1 = rand() % 27;
	for (int i = 0; i < x1; i++)
	{
		vr[i] = rand() % 26 + 97;
	}
	vr[x1] = '\0';
	for (int j = 0; j < x1; j++)
	{
		f1 = false;
		for (int t = 0; t < r; t++)
		{
			if (vr[j] == arr[t])
			{
				f1 = true;
				break;
			}
		}
		if (!f1)
		{
			arr[r] = vr[j];
			r++;
		}
	}
	arr[r] = '\0';
}
list* free_list(list* info )
{
	list *tmp = NULL;
	while (info != NULL)
	{
		tmp = info;
		info = info->next;
		free(tmp);
	}
	return(info);
}

int main()
{
	srand(time(0));

	list* lA = NULL;
	list* lB = NULL;
	list* lC = NULL;
	list* lD = NULL;
	list* lE = NULL;

	bool flag = false;
	int  num = 0, wA = 0, wB = 0, wC = 0, wD = 0, wE = 0;

	char A[Nmax + 1], B[Nmax + 1], C[Nmax + 1], D[Nmax + 1], E[Nmax + 1],
		uni[Nmax] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	bool bA[Nmax] = { 0, }, bB[Nmax] = { 0, }, bC[Nmax] = { 0, }, bD[Nmax] = { 0, }, bE[Nmax] = { 0, };

	int menu = 0;
	bool check = false;
	do
	{
		cout << "data from the file - 1, keyboard input - 2, generate data - 3: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			fstream file;
			file.open("data.txt", ios_base::in);
			if (!file)
				cout << "File can't be open!\n";
			else
			{
				cout << "File is open!\n";
				char Buff[Nmax];
				file.getline(Buff, Nmax, '\n');
				vvod_is_fayla(Buff, A);
				Buff[Nmax] = { '0', };
				file.getline(Buff, Nmax, '\n');
				vvod_is_fayla(Buff, B);
				Buff[Nmax] = { '0', };
				file.getline(Buff, Nmax, '\n');
				vvod_is_fayla(Buff, C);
				Buff[Nmax] = { '0', };
				file.getline(Buff, Nmax, '\n');
				vvod_is_fayla(Buff, D);
			}
			file.close();
			check = false;
			break;
		}
		case 2:
		{
			cout << "Please, enter array A: ";
			getchar();
			vvod(A);
			cout << "Please, enter array B: ";
			vvod(B);
			cout << "Please, enter array C: ";
			vvod(C);
			cout << "Please, enter array D: ";
			vvod(D);
			check = false;
			break;
		}
		case 3:
		{
			generation(A);
			generation(B);
			generation(C);
			generation(D);
			check = false;
			break;
		}
		default:
		{
			check = true;
			break;
		}
		}
	} while (check == true);

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "C = " << C << endl;
	cout << "D = " << D << endl;
	
	int time = clock();
	for (int p = 0; p < 1000000; p++)
	{
		for (int k = 0; D[k - 1] != '\0'; k++)
			E[k] = D[k];
		num = strlen(E);
		for (int k = 0; A[k - 1] != '\0'; k++)
		{
			flag = false;
			for (int q = 0; (D[q] != '\0') && (flag != true); q++)
			{
				if (A[k] == D[q])
					flag = true;
			}
			if (flag != true)
			{
				for (int i = 0; (B[i] != '\0') && (flag != true); i++)
				{
					if (A[k] == B[i])
						flag = true;
				}
			}
			if (flag != true)
			{
				for (int j = 0; (C[j] != '\0') && (flag != true); j++)
				{
					if (A[k] == C[j])
						flag = true;
				}
			}
			if (!flag)
			{
				E[num] = A[k];
				num++;
			}
		}
	}
	time = clock() - time;
	cout << "time(E): "<< time << endl;

	fstream result;
	result.open("data2.txt", ios_base::out);
	if (!result)
		cout << "File can't be open!\n\n";
	else
	{
		result << "E:  ";
		result << E;
		result << "\n";
	}
	result.close();
	cout << "E:  " << E << endl;

	int nA = strlen(A), nB = strlen(B), nC = strlen(C), nD = strlen(D);

	for (int k = 0; k < nA; k++)
		lA = add(lA, A[k]);
	for (int k = 0; k < nB; k++)
		lB = add(lB, B[k]);
	for (int k = 0; k < nC; k++)
		lC = add(lC, C[k]);
	for (int k = 0; k < nD; k++)
		lD = add(lD, D[k]);
	flag = false;

	list *tmp = NULL, *tmp2 = NULL, *tmp3 = NULL, *tmp4 = NULL;
	
	int time1 = clock();
	for (int p = 0; p < 1000000; p++)
	{
		tmp = lD;
		if (tmp != NULL)
		{
			do {
				list *ptr = (struct list*)malloc(1 * sizeof(struct list));
				ptr->el = tmp->el;
				ptr->next = lE;
				lE = ptr;
				tmp = tmp->next;
			} while (tmp != NULL);
		}
		tmp = lA;

		if (tmp != NULL)
		{
			do
			{
				tmp2 = lD;
				tmp3 = lB;
				tmp4 = lC;
				flag = false;
				if (tmp2 != NULL)
				{
					do {
						if (tmp->el == tmp2->el)
							flag = true;
						tmp2 = tmp2->next;
					} while ((tmp2 != NULL) && (flag != true));
				}
				if (flag != true)
				{
					if (tmp3 != NULL)
					{
						do
						{
							if (tmp->el == tmp3->el)
								flag = true;
							tmp3 = tmp3->next;
						} while ((tmp3 != NULL) && (flag != true));
					}
				}
				if (flag != true)
				{
					if (tmp4 != NULL)
					{
						do
						{
							if (tmp->el == tmp4->el)
								flag = true;
							tmp4 = tmp4->next;
						} while ((tmp4 != NULL) && (flag != true));
					}
				}
				if (!flag)
				{
					list *ptr = (struct list*)malloc(1 * sizeof(struct list));
					ptr->el = tmp->el;
					ptr->next = lE;
					lE = ptr;
				}
				tmp = tmp->next;
			} while (tmp != NULL);
		
		}
		if (p != 999999)
			lE = free_list(lE);
	}
	time1 = clock() - time1;
	cout << "time(lE): " << time1 << endl;

	cout << "lE: ";
	result.open("data2.txt", ios_base::app);
	if (!result)
		cout << "File can't be open!\n\n";
	else
	{
		result << "lE: ";
		tmp = lE;
		while (tmp != NULL)
		{
			result << tmp->el;
			cout << tmp->el;
			tmp = tmp->next;
		};
		result << "\n";
	}
	result.close();
	cout << endl;

	mas(A, uni, bA);
	mas(B, uni, bB);
	mas(C, uni, bC);
	mas(D, uni, bD);

	int time2 = clock();
	for (int p = 0; p < 1000000; p++)
	{
		for (int i = 0; i < Nmax; i++)
			bE[i] = ((bA[i] && !(bB[i] || bC[i])) || bD[i]);
	}
	time2 = clock() - time2;
	cout << "time(bE): " << time2 << endl;

	cout << "bE: ";
	result.open("data2.txt", ios_base::app);
	if (!result)
		cout << "File can't be open!\n\n";
	else
	{
		result << "bE: ";
		for (int l = 0; l < Nmax; l++)
		{
			if (bE[l] == 1)
			{
				cout << uni[l];
				result << uni[l];
			}
		}
		result << "\n";
	}
	result.close();
	cout << endl;

	wA = dec(bA, wA);
	wB = dec(bB, wB);
	wC = dec(bC, wC);
	wD = dec(bD, wD);

	int time3 = clock();
	for (int p = 0; p < 1000000; p++)
	{
		wE = (wA & ~(wB | wC) | wD);
	}
	time3 = clock() - time3;
	cout << "time(wE): " << time3 << endl;

	cout << "wE: ";
	result.open("data2.txt", ios_base::app);
	if (!result)
		cout << "File can't be open!\n\n";
	else
	{
		result << "wE: ";
		for (int i = 0, p = 0; i < Nmax; i++)
		{
			if ((wE >> i) & 1)
			{
				cout << uni[Nmax - 1 - i];
				result << uni[Nmax - 1 - i];
			}
			p++;
		}
		result << "\n";
	}
	result.close();
	cout << endl;

	system("pause");
	return 0;
}


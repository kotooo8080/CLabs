// structures1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

char *enter_str();                                 //----------ввод слова---------//

int enter_num();                                   //----------функция для ввода значений типа integer-----------//

struct movies* en_st(int &k, struct movies* obj);  //----------ввод структуры данных---------//

void out (movies * obj, int k);                    //----------вывод структуры---------//

struct movies* poisk (int &n, struct movies* obj); //----------поиск----------//

int menu();                                        //----------меню-----------//

void help_menu();                                  //----------вспомогательная таблица-----------//

int main()
{
	struct movies *obj = NULL;
	struct movies *obj_1 = NULL;

	int k = 0,
		m = 0,
		g = 0,
		help = 0;

	bool a0 = false,
		 f0 = false,
		 f1 = false;

	do
	{
		m = menu();

		switch (m)
		{
		case 1:
		{
			if (a0 == true)
			{
				free(obj);
				obj = NULL;
			}
			puts("Please, enter information about the movie \n");
			puts("If you need some help with entering information, please, press 1 ");
			scanf_s("%d", &help);

			if (help == 1)
				help_menu();

			k = 0;
			obj = en_st(k, obj);

			f0 = true;
			a0 = false;

			break;
		}
		case 2:
		{
			if (f0 == true)
			{
				printf("You enter such films: \n");
				puts("-------------------------------------------------------------------------------------------------------\n");
				puts("|      name      |    producer    |      genre     |      price     |     rating     |    category    |\n");
				puts("-------------------------------------------------------------------------------------------------------\n");
				out(obj, k);
				puts("-------------------------------------------------------------------------------------------------------\n");
				system("cls");
			}

			else
				puts("Sorry, you didn't enter a structure \n");

			break;
		}
		case 3:
		{
			if (a0 == true)
			{
				free(obj_1);
				obj_1 = NULL;
			}

			if (f0 == true)
			{
				g = k;
				obj_1 = poisk(g, obj);
				f0 = false;
				f1 = true;
				a0 = true;

				if (obj_1 == NULL)
					puts("Sorry, appropriate movies not found");
			}

			else
				puts("Sorry, you didn't enter a structure \n");

			break;
		}
		case 4:
		{
			if ((f0 == true) && (f1 == true))
			{
				printf("You enter such films: \n");
				puts("-------------------------------------------------------------------------------------------------------\n");
				puts("|      name      |    producer    |      genre     |      price     |     rating     |    category    |\n");
				puts("-------------------------------------------------------------------------------------------------------\n");
				out(obj_1, g);
				puts("-------------------------------------------------------------------------------------------------------\n");
				system("cls");
			}
			break;
		}
		}

	} while (m != 0);

	system("pause");
    return 0;
}

//----------ввод слова---------//
char *enter_str()
{
	int k = 0;
	char* new_word = NULL,
		n_w;
	do
	{

		new_word = (char*)realloc(new_word, (k + 1) * sizeof(char));
		n_w = getchar();
		if (n_w != '\n')
		{
			*(new_word + k) = n_w;
			k++;
		}
	} while (n_w != '\n');
	*(new_word + k) = '\0';

	return (new_word);
}

//----------функция для ввода значений типа integer-----------//
int enter_num()
{
	int num = 0;
	//scanf_s("%d", &num);
	do
	{
		puts("Please, enter decimal number \n");
		scanf_s("%d", &num);
	} while (isdigit(num) != true);

	return(num);
}

struct movies
{
	char *name_of_film = NULL,   //название фильма
		*pr_surname = NULL,     //фамилия режиссера
		*movie_genre = NULL;    //жанр фильма

	int
		ticket_price,   //цена билета
		rating,         //рейтинг
		age_category;   //возрастная категория
};

//----------ввод структуры данных---------//
struct movies*en_st(int &k, struct movies* obj)
{
	int k_1;

	bool f_1 = 0,
		f_2 = 0;

	do {
		getchar();
		obj = (struct movies*)realloc(obj, (k + 1) * sizeof(struct movies));
		printf("Please, enter film %d: \n", k + 1);

		puts("enter name of film");
		obj[k].name_of_film = enter_str();
		puts("enter producer surname");
		obj[k].pr_surname = enter_str();
		puts("enter the film genre");
		obj[k].movie_genre = enter_str();

		do
		{
			puts("enter the ticket price");
			obj[k].ticket_price = enter_num();
		} while ((obj[k].ticket_price <= 0) || (obj[k].ticket_price > 1500));

		do
		{
			puts("enter the rating of the film (from 0 to 10)");
			obj[k].rating = enter_num();
		} while ((obj[k].rating < 0) || (obj[k].rating > 10));

		
		do
		{
			puts("enter the age category of the film \n");
			puts("(please, enter age categories according to Russian Age Rating System: 0, 6, 12, 16, 18)");
			obj[k].age_category = enter_num();
		} while ((obj[k].age_category < 0) || (obj[k].age_category > 18));

		k++;

		puts("Do you want to enter new film? yes - 1, no - 0");
		scanf_s("%d", &k_1);
	} while (k_1);
	getchar();

	return (obj);
}

//----------вывод структуры---------//
void out(movies * obj, int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("\t%s \t|\t%s \t|\t%s \t|\t%d \t|\t%d \t|\t%d \t|", (obj + i)->name_of_film, (obj + i)->pr_surname, (obj + i)->movie_genre, (obj + i)->ticket_price, (obj + i)->rating, (obj + i)->age_category);
		printf("\n");
	}
	puts("\n");
}

//----------поиск----------//
struct movies* poisk(int &g0, struct movies* obj)
{
	struct movies* obj_1 = NULL;
	int l_1 = 0,
		l_2 = 0,
		l_3 = 0,
		k = 0;

	do {
		puts("Please, enter maximum ticket price: ");
		scanf_s("%d", &l_1);
	} while (l_1 <= 0);

	do {
		puts("Please, enter desired movie rating (from 1 to 10) : ");
		scanf_s("%d", &l_2);
	} while ((l_2 < 0) || (l_2 > 10));

	do
	{
		puts("Enter the age category of the film, that you search or enter your age (the program will pick the right movies for you)");
		puts("please, enter age categories according to Russian Age Rating System: 0, 6, 12, 16, 18)");
		scanf_s("%d", &l_3);
	} while ((l_3 != 0) && (l_3 != 6) && (l_3 != 12) && (l_3 != 16) && (l_3 != 18));

	for (int j = 0; j < g0; j++)
	{
		if (((*(obj + j)).ticket_price <= l_1) && ((*(obj + j)).rating >= l_2) && ((*(obj + j)).age_category <= l_3))
		{
			k++;
			obj_1 = (struct movies*) realloc (obj_1, k * sizeof(struct movies));
			(*(obj_1 + k - 1)) = (*(obj + j));
		}
	}
	g0 = k;

	return (obj_1);
}

//-----------меню-----------//
int menu()
{
	int s;
	printf(" ---------------------MENU-------------------- \n"
		" 1 - enter data \n"
		" 2 - output data \n"
		" 3 - calculate results \n"
		" 4 - output results \n"
		" 0 - exit \n");

	printf("Please enter the menu item number\n");
	scanf_s("%d", &s);
	system("cls");
	return (s);
}

//-----------вспомогательная таблица-----------//
void help_menu()
{
	printf("You have opened an auxiliary menu, here possible data for input \n"
		"********genres of films are presented here*******\n"
		"        adventure             action\n"
		"        drama                 comedy\n"
		"        thriller/suspense     horror\n"
		"        romantic_comedy       musical\n"
		"        documentary           multfilm\n"
		"        fantasy               epics/historical\n"
		"        science               war\n");

	system("pause");
	system("cls");
}

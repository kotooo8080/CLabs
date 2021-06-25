// KURSOVAYA.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

//----------Вывод меню----------//
int menu()
{
	int s;
	printf(" -----------------------MENU-------------------------------  \n"
		"  / 1 - enter separator characters                         / \n"
		"  / 2 - output separator characters                        / \n"
		"  / 3 - enter original text                                / \n"
		"  / 4 - output original text                               / \n"
		"  / 5 - enter word                                         / \n"
		"  / 6 - generate and output new text from the source lines / \n"
		"  / 7 - call help                                          / \n"
		"  / 0 - end the program                                    / \n"
		"  ---------------------------------------------------------- \n");

	printf(" Please, enter the menu item number \n");
	scanf("%d", &s);

	return (s);
}

//---------Справка----------//
void help_menu()
{
	puts("\n ----------------------------------------------------------------------");
	puts("\n ***Cправка***");
	puts("\n ***Программа заменяет слово минимальной длины на заданное слово***");
	puts("\n ***Программа поддерживает ввод на русском и английском языках***");
	puts("\n ----------------------------------------------------------------------");
	puts("\n ***Ввод символов-разделителей***");
	puts("\n #### Введенные ранее разделители будут удалены ####");
	puts("\n #### Ввод разделителей осуществляется до нажатия клавиши Enter ####");
	puts("\n #### Количество разделителей не должно превышать 100 ####");
	puts("\n ----------------------------------------------------------------------");
	puts("\n ***Ввод исходного текста***");
	puts("\n #### Максимальная длина вводимой строки 100 ####");
	puts("\n #### Ввод текста заканчивается при вводе конечной строки ####");
	puts("\n #### Максимальный пазмер строки, означающей конец ввода 100 ####");
	puts("\n ----------------------------------------------------------------------");
	puts("\n ***Ввод специального слова***");
	puts("\n #### Введенное ранее слово будет удалено ####");
	puts("\n ----------------------------------------------------------------------");

	system("pause");
	system("cls");
}

//----------Освобождение памяти для строк----------//
char* f_str(char* s_g)
{
	free(s_g);
	s_g = NULL;

	return (s_g);
}

//----------Освобождение памяти для исходной динамической структуры-----------//
char** f_text(char** arr_t, int rows)
{
	for (int i = 0; i < rows; i++)
		arr_t[i] = f_str(arr_t[i]);

	free(arr_t);
	arr_t = NULL;

	return NULL;
}

//---------Ввод строки----------//
char* en_str(int str_size, int i = 0)
{
	char* s_d;
	char vsymb = ' ';

	int f = 0;
	s_d = (char*)malloc(sizeof(char));

	do
	{
		f = 0;
		while (vsymb != '\n')
		{
			vsymb = getchar();
			s_d[i] = vsymb;
			i += 1;
			s_d = (char*)realloc(s_d, i + 1);
		}
		s_d[i - 1] = '\0';
	} while (f);

	return (s_d);
}

//----------Ввод количества строк----------//
int n_rows(int rows_num)
{
	do
	{
		puts("Enter the number of the rows: ");
		scanf_s("%d", &rows_num);

		getchar();
		if (rows_num <= 0)
			puts(" You enter wrong number of the rows \n");
	} while (rows_num <= 0);

	return (rows_num);
}

//----------Ввод текста----------//
char** en_text(int rows_num)
{
	char** arr_t = NULL;
	arr_t = (char**)malloc(rows_num * sizeof(char*));

	printf("Enter your text here: \n");
	for (int i = 0; i < rows_num; i++)
		arr_t[i] = en_str(100);

	return (arr_t);
}

//---------Вывод текста---------//
void your_text(char** t_t, int rows)
{
	for (int i = 0; i < rows; i++)
		printf_s("%s\n", t_t[i]);
}

//----------Ввод символов-разделителей----------//
char* razd()
{
	int k = 0;
	char *det_symb = NULL,
		d_s;
	d_s = getchar();

	printf("Please, enter separator characters \n");
	do
	{
		d_s = getchar();
		if (d_s != '\n')
		{
			det_symb = (char*)realloc(det_symb, (k + 1) * sizeof(char));
			*(det_symb + k) = d_s;
			k++;
		}
	} while (d_s != '\n');

	det_symb = (char*)realloc(det_symb, (k + 1) * sizeof(char));
	*(det_symb + k) = '\0';

	return (det_symb);
}

//----------Вывод символов-разделителей----------//
void your_symbols(char* det_symb)
{
	for (int i = 0; det_symb[i] != '\0'; i++)
		putchar(det_symb[i]);

	puts("\n");
}

//-----------Проверка является ли символ разделителем----------//
bool is_sep(char c, char* seps)
{
	for (int i = 0; seps[i]; i++)
		if (seps[i] == c)
			return 1;

	return 0;
}

//----------Количество слов в строке---------//
int words_count(char* str, char* seps)
{
	int words = 0;
	bool word = 0;
	for (int i = 0; str[i]; i++)
	{
		if (!is_sep(str[i], seps))
		{
			if (!word)
			{
				word = 1;
				words++;
			}
		}
		else
		{
			word = 0;
		}
	}

	return words;
}

//-----------Формирование нового текста----------//
char** your_new_text(int rows, int strok, int nech, char** t_t, char* det_symb_2)
{
	char **new_text = NULL;
	int k = 0;
	new_text = (char**)malloc(nech * sizeof(char*));

	for (int i = 0; i < rows; i++)
	{
		strok = words_count(t_t[i], det_symb_2);
		if ((strok % 2) != 0)
		{
			new_text[k] = t_t[i];
			printf("%s \n", new_text[k]);
			k++;
		}
	}

	return (new_text);
}

//-----------Ввод специального слова----------//
char* your_word()
{
	int k = 0;
	char* new_word = NULL,
		n_w;

	printf("\nPlease, enter your word \n");
	n_w = getchar();
	do
	{
		n_w = getchar();
		if (n_w != '\n')
		{
			new_word = (char*)realloc(new_word, (k + 1) * sizeof(char));
			*(new_word + k) = n_w;
			k++;
		}
	} while (n_w != '\n');

	new_word = (char*)realloc(new_word, (k + 1) * sizeof(char));
	*(new_word + k) = '\0';

	return (new_word);
}

//----------Поиск минимального слова----------//
int  short_word(char* text_str, char* det_char, char* shortest_word)
{
	int word_len = 30;
	char *tmp_word = NULL;
	char *tmp_text = NULL;

	tmp_text = (char*)calloc(strlen(text_str), sizeof(char));
	strcpy(tmp_text, text_str);

	tmp_word = strtok(tmp_text, det_char);

	while (tmp_word != NULL)
	{
		if (word_len >= strlen(tmp_word))
		{
			word_len = strlen(tmp_word);
			strcpy(shortest_word, tmp_word);
		}
		tmp_word = strtok(NULL, det_char);
	}

	return (strlen(shortest_word));
}

//----------Замена слова на заданное----------//
void word_replace(char *&str, char *repl, char *det_symb)
{
	char *temp = (char*)malloc(30 * sizeof(char));

	int min_len = short_word(str, det_symb, temp),  //длина минимального слова в строке
		str_len = strlen(str),                      //длина строки текста
		rep_len = strlen(repl),                     //длина слова замены
		delta = rep_len - min_len;                  //разница в длине слова-замены и длине минимального слова

	int buff_size = (str_len + 1);                           //размер буфферa
	char *buff = (char*)malloc(buff_size * sizeof(char));    //буффер

	buff[0] = '\0';

	for (int i = 0, j = 0; i < str_len; ++i)
	{
		if (is_sep(str[i], det_symb))
		{
			buff[j] = str[i];
			buff[j + 1] = '\0';
			++j;
			continue;
		}

		int w_l = 0;                                //вычисленная длина какого-либо слова

		while (str[i + w_l] && !is_sep(str[i + w_l], det_symb))
			w_l++;

		if (w_l == min_len)
		{
			buff_size += delta;
			buff = (char*)realloc(buff, buff_size * sizeof(char));

			buff[j] = '\0';
			strcat(buff, repl);
			j += rep_len;

		}
		else
		{
			strncat(buff, str + i, w_l);
			j += w_l;
		}
		i += w_l - 1;
	}
	free(str);
	str = buff;
}

//----------Главная функция---------//
int main()
{
	char ** arr_t = NULL,      //исходный текст
		 ** t_t = NULL,        //исходный текст
		 **new_text = NULL,    //новый текст
		 **new_text_1 = NULL,
		 *det_symb_2 = NULL,   //строка символов разделителей
		 *new_word_1 = NULL,
		 *str_t = NULL,
		 *word_1 = NULL;

	int  m = 0,                //переменная для организации меню
		 rows = 0,             //количество строк исходного текста
		 i = 0,                //вспомогательная переменная для организации цикла for
		 k = 0,                //вспомогательная переменная для организации цикла for
		 min = 0,              //длина минимального слова в строке
		 min_1 = 0,            //длина минимального слова в строке
		 rows_num = 0,         //количество строк
		 strok = 0,            //переменная для подсчета количества слов в строке
		 nech = 0;             //количество строк нового текста (количество строк с нечетным количеством слов)

	bool e1 = 0,               //вспомогательные переменные для организации меню
		 e3 = 0,
		 e5 = 0;

	do
	{
		m = menu();
		switch (m)
		{
		case 1:
			if (e1 == 0)
				det_symb_2 = f_str(det_symb_2);

			if (e3 == 0)
				t_t = f_text(t_t, rows);

			det_symb_2 = razd();

			e1 = 1;
			e5 = 0;

			break;

		case 2:
			if (e1 == 1)
				your_symbols(det_symb_2);

			else
				puts("You didn't enter separator symbols \n");

			break;

		case 3:
			if (e3 == 0)
				f_text(arr_t, rows);

			rows = n_rows(rows_num);
			t_t = en_text(rows);

			e3 = 1;
			e5 = 0;

			break;

		case 4:
			if (e3 == 1)
				your_text(t_t, rows);

			else
				puts("You didn't enter the original text \n");

			break;

		case 5:
			if ((e1 == 1) && (e3 == 1))
			{
				for (i = 0; i < rows; i++)
				{
					strok = words_count(t_t[i], det_symb_2);

					if (strok & 1)
						nech++;
				}
				new_text_1 = your_new_text(rows, strok, nech, t_t, det_symb_2);
				new_word_1 = (char*)calloc(30, sizeof(char));
				new_word_1 = your_word();

				for (i = 0; i < nech; i++)
				{
					word_replace(new_text_1[i], new_word_1, det_symb_2);
				}

				e5 = 1;
				e1 = e3 = 0;
			}
			else
			{
				if (e1 != 1)
					puts("Sorry, you didn't enter separator symbols \n");

				if (e3 != 1)
					puts("Sorry, you didn't enter original text \n");
			}

			break;

		case 6:
			if (e5 == 1)
				your_text(new_text_1, nech);

			else
				puts("You didn't get result, try to enter original data again! \n");

			break;

		case 7:
			help_menu();

			break;

		case 0:

			printf("Thank you for using this program, bye! \n");

			m = 0;

			break;

		default:
			puts("Something went wrong, try to enter the menu item number again \n");
			puts("\nPlease, enter items from 0 to 7\n");

			break;
		}
	} while (m != 0);

	system("pause");
	return 0;
}

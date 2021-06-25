// NEWFESTELNET.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string r_1, r_2,
		o_text, en_text,       //строки для записи исходного и зашифрованного текста
		de_text, de_text_2,
		k0,
		key_w;                 //исходная запись ключа
	int i, j,
		k_l,                   //раундовый ключ
		p, p0, l, s, n;

	unsigned long int L0, R0,  //левый и правый входные подблоки
		A0;

	//-------------------------ENCRYPTOR-------------------------//

	ifstream original_file("text_file.txt", ios::in);
	if (!original_file.is_open())
		puts("There was a problem, this file could not be opened");
	else
	{
		while (getline(original_file, k0))
			o_text += k0 + '\n';
		original_file.close();

		//если длина текста недостаточна для деления поровну на фрагменты по 64 бита, то дописываем в конце выбранный символ
		while ((o_text.length() % 8) != 0)
			o_text += ' ';
		p0 = o_text.length() / 8;

		//ввод ключевого слова
		puts("Please, enter a keyword to encrypt the text");
		cin >> key_w;

		//ввод количества раундов
		puts("Please, enter the number of the rounds");
		cin >> n;

		cout << o_text << endl;

		s = 0;
		for (i = 0; i < p0; i++)
		{
			R0 = L0 = 0;

			for (j = 7 + 8 * i, p = 0; j >= 4 + 8 * i; j--, p++)
				for (l = 0; l < 8; l++)
					R0 |= ((((unsigned long int)o_text[j] >> l) & 1)
						<< (l + p * 8));

			for (j = 3 + 8 * i, p = 0; j >= 0 + 8 * i; j--, p++)
				for (l = 0; l < 8; l++)
					L0 |= ((((unsigned long int)o_text[j] >> l) & 1)
						<< (l + p * 8));

			for (j = 0; j < n; j++)
			{
				k_l = (key_w[j%key_w.length()] ^ (j + 1)) + 2;
				//присваиваем значение левого подблока правому подблоку
				if (j != n - 1)
				{
					A0 = L0;
					L0 = (((L0*k_l) % 65536) & 58853) ^ R0;   //результат складываем по модулю 2 с правым подблоком
					R0 = A0;
				}
				else
					R0 = (((L0*k_l) % 65536) & 58853) ^ R0;
			}

			r_1 = r_1 + (char) ((L0 & 4278190080) >> 24);  //11111111000000000000000000000000
			r_1 = r_1 + (char) ((L0 & 16711680) >> 16);    //111111110000000000000000
			r_1 = r_1 + (char) ((L0 & 65280) >> 8);        //1111111100000000
			r_1 = r_1 + (char) ((L0 & 255) >> 0);          //11111111

			r_1 = r_1 + (char) ((R0 & 4278190080) >> 24);  //11111111000000000000000000000000
			r_1 = r_1 + (char) ((R0 & 16711680) >> 16);    //111111110000000000000000
			r_1 = r_1 + (char) ((R0 & 65280) >> 8);        //1111111100000000
			r_1 = r_1 + (char) ((R0 & 255) >> 0);          //11111111
			
			de_text += r_1;
			r_1.clear();
		}

		puts("encrypting is ended \n");

		ofstream en_file("en_text.txt", ios::out);
		en_file << de_text;
		en_file.close();
		
		cout << de_text << endl;

		//--------------------DECRYPTOR-------------------//

		ifstream enc_file("en_text.txt", ios::in);

		while (getline(enc_file, k0))
		{
			en_text += k0 + '\n';
		}
		enc_file.close();

		//ввод ключевого слова
		cout << "Please, enter a keyword to decrypt the text \n";
		cin >> key_w;

		//ввод количества раундов
		puts("Please, enter the number of the rounds");
		cin >> n;
		
		while ((en_text.length() % 8) != 0)
			en_text += ' ';

		p0 = en_text.length() / 8;
		s = 0;
		for (i = 0; i < p0; i++)
		{
			R0 = L0 = 0;
			for (j = 7 + 8 * i, p = 0; j >= 4 + 8 * i; j--, p++)
				for (l = 0; l < 8; l++)
					R0 |= ((((unsigned long int)en_text[j] >> l) & 1)
						<< (l + p * 8));

			for (j = 3 + 8 * i, p = 0; j >= 0 + 8 * i; j--, p++)
				for (l = 0; l < 8; l++)
					L0 |= ((((unsigned long int)en_text[j] >> l) & 1)
						<< (l + p * 8));

			for (j = n - 1; j >= 0; j--)
			{
				
				k_l = (key_w [j%key_w.length()] ^ (j + 1)) + 2;

				//присваиваем значение левого подблока правому подблоку
				if (j != 0)
				{
					A0 = L0;
					L0 = (((L0*k_l) % 65536) & 58853) ^ R0; //результат складываем по модулю 2(XOR) с правым подблоком
					R0 = A0;
				}
				else
					R0 = (((L0*k_l) % 65536) & 58853) ^ R0;
			}

			r_2 = r_2 + (char) ((L0 & 4278190080) >> 24);  //11111111000000000000000000000000
			r_2 = r_2 + (char) ((L0 & 16711680) >> 16);    //111111110000000000000000
			r_2 = r_2 + (char) ((L0 & 65280) >> 8);        //1111111100000000
			r_2 = r_2 + (char) ((L0 & 255) >> 0);          //11111111
			
			r_2 = r_2 + (char) ((R0 & 4278190080) >> 24);  //11111111000000000000000000000000
			r_2 = r_2 + (char) ((R0 & 16711680) >> 16);    //111111110000000000000000
			r_2 = r_2 + (char) ((R0 & 65280) >> 8);        //1111111100000000
			r_2 = r_2 + (char) ((R0 & 255) >> 0);          //11111111

			de_text_2 += r_2;
			r_2.clear();
		}

		ofstream de_file("de_text.txt");
		de_text_2.resize(de_text_2.size() - 8);
		de_file << de_text_2;
		de_file.close();

		cout << endl << "Your text: " << de_text_2;
	}
	system("pause");
	return 0;
}

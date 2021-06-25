// VIGENERE.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int l = 0;
	int i = 0;   

	string en;
	string en_1;
	string key_word;
	string de;
	string de_1;

	//--------------------ENCRYPTOR--------------------//

	ifstream original_file ("original_text.txt",ios::in);
	
	if (!original_file.is_open())
		puts("There was a problem, this file could not be opened");
		
	else {
		do {
			puts("Please, enter a keyword to encrypt the text");
			getline(cin, key_word);

			if (key_word.length() < 3)
			{
				puts("The length of the keyword is not sufficient, please try to enter keyword again \n");
				puts("Keyword length >= 3  \n");
			}
			puts("\n");
		} while (key_word.length() < 3);

		l = -1;
		while (original_file)
		{
			getline(original_file, en);

			for (int i = 0; i < (int)en.size(); i++)
			{
				if ((int)en[i] >= 97 && ((int)en[i] <= 122))
					en[i] = (char)en[i] - 32;

				if ((int)key_word[i % key_word.length()] >= 97 && ((int)key_word[i % key_word.length()] <= 122))
					key_word[i % key_word.length()] = (char)key_word[i % key_word.length()] - 32;

				if (((int)en[i] >= 97 && ((int)en[i] <= 122)) || (((int)en[i] >= 65) && (int)(en[i] <= 90)))
				{
					l++;
					en_1 += (char(((en[i] + key_word[(l) % key_word.length()]) % 26) + 65));
				}
				else
					en_1 += (char(en[i]));
			}

			en_1 += '\n';
		}
		original_file.close();
		en_1.resize(en_1.size() - en.size() - 1);

		ofstream encoded_file("encoded.txt", ios::out);

		encoded_file << en_1;

		cout << "Your encoded text: " << en_1 << endl;

		encoded_file.close();

		//--------------------DECRYPTOR-------------------//

		ifstream encoded_f_2("encoded.txt", ios_base::in);
		puts("Please, enter a keyword to decrypt the text");
		getline(cin, key_word);

		l = -1;

		while (encoded_f_2)
		{
			getline(encoded_f_2, de);

			for (int i = 0; i < (int)de.size(); i++)
			{
				if ((int)de[i] >= 97 && ((int)de[i] <= 122))
					de[i] = (char)de[i] - 32;

				if ((int)key_word[i % key_word.length()] >= 97 && ((int)key_word[i % key_word.length()] <= 122))
					key_word[i % key_word.length()] = (char)key_word[i % key_word.length()] - 32;

				if (((int)de[i] >= 97 && ((int)de[i] <= 122)) || (((int)de[i] >= 65) && (int)(de[i] <= 90)))
				{
					l++;
					//ищем с каким символом алфавита совпало значение
					de_1 += (char((((de[i] - key_word[(l) % key_word.length()]) + 26) % 26) + 65));
				}
				else
					//приписываем в строку декодера символ
					de_1 += (char(de[i]));
			}
			de_1 += '\n';

		}

		encoded_f_2.close();
		de_1.resize(de_1.size() - de.size() - 1);
		ofstream decoded_f_1("decoded.txt", ios_base::out);

		cout <<"Your decoded text: " << de_1 << endl;

		decoded_f_1 << de_1;
		decoded_f_1.close();
	}
	system("pause");
	return 0;
}
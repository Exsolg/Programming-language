#define _CRT_SECURE_NO_WARNINGS 
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

char* copy(char* a, const char* c);
void shortest_word(char* a, char* b);

int main()
{
	setlocale(LC_ALL, "rus");
	int var;
start:
	cout << endl << "1. Копирование строки" << endl << "2. Самое короткое слово" << endl << "3. Упорядочивание по длине" << endl << "0. Выход" << endl;
	cout << endl << "Введите номер задания: ";  cin >> var; cout << endl;
	cin.clear(); cin.ignore();
	switch (var)
	{
	case 1: 
	{
		char s[255] = { '\0' };
		cout << "Введите текст: ";
		cin.getline(s, 255);
		char check[255] = { '\0' };
		copy(check, s);
		cout << "Введеная строка - " << s << endl;
		cout << "Скопированная строка - " << check << endl;
		copy(s, "Успешно скопированно!");
		cout << s << endl;
		cout << "Для продолжения нажмите любую клавишу...";
		cin.get();
		system("cls");
		break;
	}
	case 2:
	{
		ifstream text("text.txt");
		if (!text)
		{
			cout << "Ошибка открытия файла" << endl << "Для продолжения нажмите любую клавишу...";
			cin.get();
			system("cls");
			break;
		}
		char s[3][255] = { '\0' };
		char buf[255] = { '\0' };
		for (int i = 0; i < 3; i++)
			text.getline(s[i], 255);
		text.close();
		cout << "1-ая строка - " << s[0] << endl;
		shortest_word(s[0], buf);
		cout << "Самое короткое слово - " << buf << endl; 
		cout << "Для продолжения нажмите любую клавишу...";
		cin.get();
		system("cls");
		break;
	}
	case 3:
	{
		ifstream text("text.txt");
		if (!text)
		{
			cout << "Ошибка открытия файла" << endl << "Для продолжения нажмите любую клавишу...";
			cin.get();
			system("cls");
			break;
		}
		char s[3][255] = { '\0' };
		char buf[3][255] = { '\0' };
		for (int i = 0; i < 3; i++)
			text.getline(s[i], 255);
		cout << "Изначальный текст: " << endl;
		for (int i = 0; i < 3; i++)
			cout << s[i] << endl;
		for (int j = 0; j < 3; j++)
		{
			for (int i = j-1; i >= 0; i--)
			{
				if (strlen(s[i]) < strlen(s[i + 1]))
				{
					copy(buf[i], s[i]);
					copy(s[i], s[i + 1]);
					copy(s[i + 1], buf[i]);
				}
			}
		}
		cout << endl << "Текст в порядке убывания: " << endl;
		for (int i = 0; i < 3; i++)
			cout << s[i] << endl;
		cout << "Для продолжения нажмите любую клавишу...";
		cin.get();
		system("cls");
	}
	}
	goto start;
}

char* copy(char* a, const char* c)
{
	char* temp = a;
	while (*a++ = *c++);
	return temp;
}

void shortest_word(char* a, char* b)
{
	char* check = strtok(a, " ,.!?\0");
	copy(b, check);
	for (int i = 0; i < 3; i++)
	{
		if (strlen(check) < strlen(b))
			copy(b, check);
		check = strtok(NULL, " ,.!?\0");
	}
}
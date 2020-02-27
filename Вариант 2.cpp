#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void input(int* a, int n);
void output(int* a, int n);
int neg(int* a, int n);
void rev(int* a, int* b, int n);
void inclusionsort(int* b, int c);
void rin(int* a, int n, int z, int x);

int main()
{
	setlocale(LC_ALL, "rus");
	int m = 0;
	int n;
	while (m != 1 && m != 2)
	{
		cout << "Введите номер задания: "; cin >> m;
		if (m == 1)
		{
			cout << "n="; cin >> n;
			int* a = new int[n];
			input(a, n);
			output(a, n);
			int c = neg(a, n);
			int* b = new int[c];
			rev(a, b, n);
			cout << "Массив из нечетных чисел: " << endl;
			output(b, c);
			inclusionsort(b, c);
			cout << "Массив из нечетных чисел упорядоченный по убыванию: " << endl;
			output(b, c);
			delete a;
			delete b;
		}
		if (m == 2)
		{
			int e, x, z;
			cout << "n="; cin >> n;
			cout << "Введите левую границу: " << endl; cin >> x;
			cout << "Введите правую границу: " << endl; cin >> z;
			int* a = new int[n];
			rin(a, n, z, x);
			output(a, n);
			e = neg(a, n);
			int* b = new int[e];
			cout << "Массив без четных элементов" << endl;
			rev(a, b, n);
			output(b, e);
			delete a;
			delete b;
		}
		if (m == 3) return 0;
		m = 0;
	}
}

void input(int* a, int n) //Ввод значений элементов массива
{
	ifstream F("dbase.txt");
	for (int i = 0; i < n; i++)
	{
		F >> a[i];
	}
}

void output(int* a, int n) //Вывод значений элементов массива
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

int neg(int* a, int n) //Количество нечетных чисел
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0) count++;
	}
	return count;
}

void rev(int* a, int* b, int n) //Заполненеие нового массива нечетными эдемента предыдущего массива
{
	for (int i = 0, j = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			b[j] = a[i];
			j++;
		}
	}
}

void inclusionsort(int* b, int c) //Метод прямого включения, упорядочивающий элементы по убыванию
{
	for (int i = 1; i < c; i++)
	{
		int value = b[i]; // запоминаем значение элемента
		int index = i; // и его индекс
		while ((index > 0) && (b[index - 1] < value))
		{ // смещаем другие элементы к концу массива пока они меньше index
			b[index] = b[index - 1];
			index--; // смещаем просмотр к началу массива
		}
		b[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	}
}

void rin(int* a, int n, int z, int x) //Заполнение массива случайными числами из диапазона [a,b]
{
	int k;
	for (int i = 0; i < n; i++)
	{
		k = rand() % (z + 1) - x;
		a[i] = k;
		k = 0;
	}
}

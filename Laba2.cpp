#include "iostream"
#include "iomanip"
#include "cstdlib"
#include "ctime"
#include "conio.h"
#include "fstream"

#define N 50

using namespace std; 

void input(int** a, int n, int m);
void life(int** a, int n, int m);
void output(int** a, int n, int m);
void check(int** a, int** b, int i, int j);
void matrix_change(int** a, int** b, int n, int m);
int select_var();
void matrix_input(int** a, int n, int m, int z, int x);
void shooters(int** a, int n, int m);
void scores(int** a, int n, int m);
void smax(int** a, int** b, int n, int m);
int maximum(int** a, int n, int m);
void max_scores(int** a, int** b, int n, int m);
void sum_scores(int** a, int** b, int n, int m);
void max_neg(int** a, int n, int m, int z, int &ind, int &jnd);
void min_pos(int** a, int n, int m, int x, int &ind, int &jnd);
void matrix_output(int** a, int n, int m);
void min(int** a, int n, int m);
void transp(int** a, int** b, int n, int m);
int* mul(int** a, int* b, int n, int m);
void vin(int* a, int n);
void aout(int* a, int n);
void muln(int** a, int n, int m, int x);
int* con(int* a, int* b, int n);
void sysin(int &n, double mas[][N+1]);
void sysout(int n, double mas[][N + 1]);
void roots_order(int n, int order[N]);
void for_app(int n, int order[N], double mas[][N + 1]);
void back_app(int n, double x[N], double mas[][N + 1]);
void mainel(int a, double mas[][N + 1], int n, int otv[]);
void roots_out(int n, int order[N], double x[N]);

int main() 
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		int var = select_var();
		cin.clear(); cin.ignore();
		switch (var)
		{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			int n = 0, m = 0, g = 0;
			cout << "Введите кол-во строк: " << endl; cin >> n; cout << endl;
			cout << "Введите кол-во столбцов: " << endl; cin >> m; cout << endl;
			cout << "Введите кол-во поколений: " << endl; cin >> g; cout << endl;
			int** a = new int* [n];
			for (int i = 0; i < n; i++) a[i] = new int[m];
			input(a, n, m);
			life(a, n, m);
			int** b = new int* [n];
			for (int i = 0; i < n; i++) b[i] = new int[m];
			input(b, n, m);
			for (int f = 1; f <= g; f++)
			{
				cout << "Поколение " << f << endl;
				for (int i = 1; i < n - 1; i++)
					for (int j = 1; j < m - 1; j++)
						check(a, b, i, j);
				matrix_change(a, b, n, m);
				output(a, n, m);
				cout << endl;
			}
			for (int i = 0; i < n; i++) delete[] a[i];
			delete[] a;
			for (int i = 0; i < n; i++) delete[] b[i];
			delete[] b;
			cout << endl << "Для продолжения нажмите любую клавишу..." << endl;
			_getch();
			system("cls");
			break;
		}
		case 2:
		{
			double mas[N][N+1];
			double x[N]; //Корни системы
			int order[N]; //Порядок корней
			int n;
			system("cls");
			sysin(n, mas);
			system("cls");
			sysout(n, mas);
			roots_order(n, order);
			//Прямой ход
			for_app(n, order, mas);
			//Обратный ход
			back_app(n, x, mas);
			//Вывод результата
			cout << endl;
			roots_out(n, order, x);
			_getch();
			system("cls");
			break;
		}
		case 3:
		{
			int n = 0, m = 0, g = 0;
			cout << "Введите кол-во стрелков: " << endl; cin >> n; cout << endl;
			cout << "Введите кол-во выстрелов: " << endl; cin >> m; cout << endl;
			int** a = new int* [n];
			for (int i = 0; i < n; ++i) a[i] = new int[m];
			scores(a, n, m);
			shooters(a, n, m);
			int** b = new int* [n];
			for (int i = 0; i < n; ++i) b[i] = new int[3];
			smax(a, b, n, m);
			for (int i = 0; i < n; i++) delete[] a[i];
			delete[] a;
			for (int i = 0; i < n; i++) delete[] b[i];
			delete[] b;
			cout << endl << "Для продолжения нажмите любую клавишу..." << endl;
			_getch();
			system("cls");
			break;
		}
		case 4:
		{
			int n, z, x, indi, indj, ind1i, ind1j;
			cout << "Введите размеры кв. матрицы: " << endl; cin >> n; cout << endl;
			cout << "Введите интервал [a,b]: " << endl; cin >> z >> x;
			int** a = new int* [n];
			for (int i = 0; i < n; i++) a[i] = new int[n];
			matrix_input(a, n, n, z, x);
			matrix_output(a, n, n);
			max_neg(a, n, n, z, indi, indj);
			min_pos(a, n, n, x, ind1i, ind1j);
			a[indi][indj] = a[indi][indj] + a[ind1i][ind1j];
			a[ind1i][ind1j] = a[indi][indj] - a[ind1i][ind1j];
			a[indi][indj] = a[indi][indj] - a[ind1i][ind1j];
			matrix_output(a, n, n);
			for (int i = 0; i < n; i++) delete[] a[i];
			delete[] a;
			cout << endl << "Для продолжения нажмите любую клавишу..." << endl;
			_getch();
			system("cls");
			break;
		}
		case 5:
		{
			int n, m;
			cout << "Введите количество строк: " << endl; cin >> n; cout << endl;
			cout << "Введите количество столбцов: " << endl; cin >> m; cout << endl;
			int** a = new int* [m];
			for (int i = 0; i < n; i++) a[i] = new int[n];
			min(a, m, n);
			cout << "Матрица А: ";
			matrix_output(a, m, n);
			cout << endl;
			int** b = new int* [m];
			for (int i = 0; i < n; i++) b[i] = new int[n];
			transp(a, b, m, n);
			cout << "Транспонированная матрица A: ";
			matrix_output(b, n, m);
			cout << endl;
			int* c = new int[m];
			vin(c, m);
			cout << endl << "Вектор B: ";
			aout(c, m);
			int* d = mul(b, c, n, m);
			cout << endl << "Транспонированная матрица A на вектор B: ";
			aout(d, n);
			cout << endl;
			int** tc = new int* [n];
			for (int i = 0; i < n; i++) tc[i] = new int[m];
			min(tc, n, m);
			cout << "Матрица C: ";
			matrix_output(tc, n, m);
			cout << endl;
			muln(tc, n, m, 10);
			int* z = new int[m];
			vin(z, m);
			cout << endl << "Вектор D: ";
			aout(z, m);
			int* x = mul(tc, z, n, m);
			cout << endl << "Матрица 10*С на вектор D: ";
			aout(x, n);
			int* j = con(d, x, n);
			cout << endl << "Транспонированная матрица A на вектор B минус матрица 10*С на вектор D: ";
			aout(j, n);
			for (int i = 0; i < n; i++) delete[] a[i];
			delete[] a;
			for (int i = 0; i < n; i++) delete[] b[i];
			delete[] b;
			for (int i = 0; i < n; i++) delete[] tc[i];
			delete[] tc;
			delete[] c;
			delete[] d;
			delete[] z;
			delete[] x;
			delete[] j;
			cout << endl << "Для продолжения нажмите любую клавишу..." << endl;
			_getch();
			system("cls");
			break;
		}
		default:
			cout << "Unknown";
		}
		system("cls");
	}
}

void matrix_change(int** a, int** b, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];
}

void input(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) a[i][j] = 0;
}

void life(int** a, int n, int m)
{
	srand(time(NULL));
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++) a[i][j] = rand() % 2;
}

void output(int** a, int n, int m)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			if (a[i][j] == 1)
			{
				cout << setw(2) << "@";
			}
			else cout << setw(2) << "-";
		}
		cout << endl;
	}
}

void check(int** a, int** b, int i, int j)
{
	int lcount = 0;
	for (int k = i - 1; k < i + 2; k++)
		for (int x = j - 1; x < j + 2; x++)
			lcount += a[k][x];
	lcount -= a[i][j];
	if (lcount == 3 && a[i][j] == 0) b[i][j] = 1;
	if ((lcount < 2 || lcount > 3) && a[i][j] == 1) b[i][j] = 0;
}

int select_var()
{
	int var;
	cout << "1. Игра жизнь" << endl;
	cout << "2. Метод Гаусса" << endl;
	cout << "3. Состязания по стрельбе" << endl;
	cout << "4. Задание 1" << endl;
	cout << "5. Задание 2" << endl;
	cout << "0. Выход" << endl;
	cin >> var;
	return var;
}

void matrix_input(int** a, int n, int m, int z, int x)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) a[i][j] = z + rand() % (x - z + 1);
	}
}

void shooters(int** a, int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Стрелок " << i+1 << ": ";
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void scores(int** a, int n, int m)
{
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = rand() % 11;
}

void smax(int** a, int** b, int n, int m)
{
	int count = 0, index = 0, max_sum = 0;
	
	max_scores(a, b, n, m);
	sum_scores(a, b, n, m);

	for (int i = 0; i < n; i++)
		if (b[i][0] > 0)
		{
			count++;
			index = i;
		}

	if (count == 1) cout << "Номер " << index + 1<< " - победитель!" << endl;
	if (count > 1)
	{
		for (int i = 0; i < n; i++)
			if (b[i][0] > 0)
				if (b[i][1] > max_sum)
					max_sum = b[i][1];

		for (int i = 0; i < n; i++)
			if (b[i][0] > 0 && b[i][1] == max_sum)
				b[i][2] = i + 1;

		for (int i = 0; i < n; i++)
			if (b[i][0] > 0)
				if (b[i][2] > 0)
					cout << "Номер " << i + 1 << " - победитель!" << endl;
	}
}

int maximum(int** a, int n, int m)
{
	int max = a[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] > max) max = a[i][j];
	return max;
}

void max_scores(int** a, int** b, int n, int m)
{
	int max = maximum(a, n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == max)
				b[i][0] = i + 1;
}

void sum_scores(int** a, int** b, int n, int m)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
			sum = sum + a[i][j];
		b[i][1] = sum;
	}
}

void max_neg(int** a, int n, int m, int z, int &ind, int &jnd)
{
	int max = z - 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i > j&& i > n - j - 1)
				if (a[i][j] < 0 && a[i][j] > max)
				{
					max = a[i][j];
					ind = i;
					jnd = j;
				}
	if (max == z - 1) cout << endl << "Нет максимальных отрицательных чисел в треугольнике" << endl;
	else cout << endl << "Максимальный отрицательный эл-нт: " << max << endl;
}

void matrix_output(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++) cout << setw(5) << a[i][j];
	}
	cout << endl;
}

void min_pos(int** a, int n, int m, int x, int &ind, int &jnd)
{
	int min = x + 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (i < j && i < n - j - 1)
				if (a[i][j] > 0 && a[i][j] < min)
				{
					min = a[i][j];
					ind = i;
					jnd = j;
				}
	if (min == x + 1) cout << endl << "Нет минимальных положительных чисел чисел в треугольнике" << endl;
	else cout << endl << "Минимальный положительный эл-нт: " << min << endl;
}

void min(int** a, int n, int m)
{
	ifstream arr("arr.txt");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr >> a[i][j];
	arr.close();
}

void transp(int** a, int** b, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[j][i] = a[i][j];
}

int* mul(int** a, int* b, int n, int m)
{
	int* c = new int[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = 0;
		for (int j = 0; j < m; j++)
		{
			c[i] += a[i][j] * b[j];
		}
	}
	return c;
}

void vin(int* a, int n)
{
	ifstream arr("arr.txt");
	for (int i = 0; i < n; i++)
		arr >> a[i];
	arr.close();
}

void aout(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void muln(int** a, int n, int m, int x)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] *= x;
}

int* con(int* a, int* b, int n)
{
	int* c = new int[n];
	for (int i = 0; i < n; i++)
		c[i] = a[i] - b[i];
	return c;
}

void sysin(int &n, double mas[][N+1])
{
	do
	{
		cout << "Введите число уравнений системы: ";
		cin >> n;
		if (N < n)
			cout << "Слишком большое число уравнений. Повторите ввод\n";
	} while (N < n);
	cout << "Введите систему:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			cin >> mas[i][j];
}

void sysout(int n, double mas[][N+1])
{
	cout << "Система:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
			printf("%7.2f ", mas[i][j]);
		printf("\n");
	}
}

void roots_order(int n, int order[N])
{
	//Все корни по порядку
	for (int i = 0; i < n + 1; i++)
		order[i] = i;
}

void for_app(int n, int order[N], double mas[][N+1])
{
	for (int k = 0; k < n; k++)
	{ //На какой позиции должен стоять главный элемент
		mainel(k, mas, n, order); //Установка главного элемента
		if (fabs(mas[k][k]) < 0.0001)
		{
			cout << "Система не имеет единственного решения";
			break;
		}
		for (int j = n; j >= k; j--)
			mas[k][j] /= mas[k][k];
		for (int i = k + 1; i < n; i++)
			for (int j = n; j >= k; j--)
				mas[i][j] -= mas[k][j] * mas[i][k];
	}
}

void back_app(int n, double x[N], double mas[][N+1])
{
	for (int i = 0; i < n; i++)
		x[i] = mas[i][n];
	for (int i = n - 2; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			x[i] -= x[j] * mas[i][j];
}

void roots_out(int n, int order[N], double x[N])
{
	cout << "Ответ:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == order[j])
			{
				printf("%f\n", x[j]);
				break;
			}
}

void mainel(int a, double mas[][N + 1], int n, int otv[])
{
	int i, j, i_max = a, j_max = a;
	double temp;
	//Ищем максимальный по модулю элемент
	for (i = a; i < n; i++)
		for (j = a; j < n; j++)
			if (fabs(mas[i_max][j_max]) < fabs(mas[i][j]))
			{
				i_max = i;
				j_max = j;
			}
	//Переставляем строки
	for (j = a; j < n + 1; j++)
	{
		temp = mas[a][j];
		mas[a][j] = mas[i_max][j];
		mas[i_max][j] = temp;
	}
	//Переставляем столбцы
	for (i = 0; i < n; i++)
	{
		temp = mas[i][a];
		mas[i][a] = mas[i][j_max];
		mas[i][j_max] = temp;
	}
	//Учитываем изменение порядка корней
	i = otv[a];
	otv[a] = otv[j_max];
	otv[j_max] = i;

}
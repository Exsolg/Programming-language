#include <iostream>
#include <ctime>
#include <iomanip>
#include <conio.h>

using namespace std;

int factorialr(int a);
int factorial(int a);
int calculate(int a);
int degree(int a);
void arrayin(int* a, int n);
void arrayout(int* a, int n);
int sum(int* a, int n);
int multiply(int a, int b);
int F(int a);
int G(int a);

int main()
{
    setlocale(LC_ALL, "rus");
    int a, var;
    while (true)
    {
        cout << "1. Вычисление факториала" << endl << "2. Вычисление значения функции" << endl << "3. Проверка на степень двойки" << endl << "4. Сумма элементов массива" << endl << "5. Умножение через сложение" << endl << "6. Вычисление значения функции" << endl << "0. Выход" << endl;
        cin >> var; cout << endl;
        cin.clear(); cin.ignore();
        switch (var)
        {
        case 1:
        {
            cout << "Enter a number: ";  cin >> a;
            cout << "Recursive factorial of " << a << " is " << factorialr(a) << endl;
            cout << "Factorial of " << a << " is " << factorial(a) << endl;
            _getch();
            system("cls");
            break;
        }
        case 2:
        {
            int a;
            cout << "Enter a number: ";  cin >> a;
            cout << "F(" << a << ") = " << calculate(a) << endl;
            _getch();
            system("cls");
            break;
        }
        case 3:
        {
            cout << "Enter a number: ";  cin >> a;
            if (degree(a) == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
            _getch();
            system("cls");
            break;
        }
        case 4:
        {
            int n;
            cout << "Enter a number of elements in array: ";  cin >> n;
            int* a = new int[n];
            arrayin(a, n);
            arrayout(a, n);
            cout << "Sum of elements array is " << sum(a, n) << endl;
            delete[] a;
            _getch();
            system("cls");
            break;
        }
        case 5:
        {
            int a, b;
            cout << "Enter numbers that u want multiply: "; cin >> a >> b;
            cout << endl << a << " x " << b << " = " << multiply(a, b) << endl;
            _getch();
            system("cls");
            break;
        }
        case 6:
        {
            for (int i = 1; i <= 10; i++)
            {
                cout << F(i) << setw(5) << G(i) << endl;
            }
            _getch();
            system("cls");
            break;
        }
        case 0:
        {
            return 0;
        }
        }
    }
}

int factorialr(int a) 
{
    if (a == 1 || a == 0)
        return 1;
    return a * factorialr(a - 1);
}

int factorial(int a)
{
    int res = 1;
    for (int i = 1; i <= a; i++)
        res *= i;
    return res;
}

int calculate(int a)
{
    if (a == 1) return 3;
    return calculate(a - 1) * (a - 1);
}

int degree(int a)
{
    if (a == 2)
        return 1;
    if (a % 2)
        return 0;
    else
        return degree(a / 2);
}

void arrayin(int* a, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 11;
    }
}

void arrayout(int* a, int n)
{
    cout << "Array:";
    for (int i = 0; i < n; i++)
        cout << " " << a[i];
    cout << endl;
}

int sum(int* a, int n)
{   
    if (n <= 0) return 0;
    return sum(a, n - 1) + a[n - 1];
}

int multiply(int a, int b)
{
    if (b == 1) return a;
    return a + multiply(a, --b);
}

int F(int a)
{
    if (a == 1) return 10;
    return F(a - 1) + G(a - 1);
}

int G(int a)
{
    if (a == 1) return -1;
    return F(a - 1) + G(a - 1);
}
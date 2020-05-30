#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <conio.h>

using namespace std;

struct aviasales
{
    int fnum;
    char fname[40] = { '\0' };
    char pod[25] = { '\0' };
    int dur;
};
tuple <aviasales*, int> input();
void information(aviasales* tick);
void surname(aviasales* tick);
void dursort(aviasales* tick);

int main()
{
    setlocale(LC_ALL, "rus");
    int var;
    while (true)
    {
        cout << "1. Информация о билетах" << endl << "2. Пассажиры с одной фамилией" << endl << "3. Рейсы болле 3-ех часов" << endl << "0. Выход" << endl << endl << "Введите номер задания: ";
        cin >> var;
        cout << endl;
        cin.clear(); cin.ignore();
        aviasales* tickets = get<0>(input());
        switch (var)
        {
        case 1:
        {
            information(tickets);
            _getch();
            system("cls");
            break;
        }
        case 2:
        {
            surname(tickets);
            _getch();
            system("cls");
            break;
        }
        case 3:
        {
            dursort(tickets);
            _getch();
            system("cls");
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Error" << endl;
            _getch();
            system("cls");
            break;
        }
        }
    }
}

tuple <aviasales*, int> input() //кортеж, возвращающий все рейсы и их кол-во
{
    ifstream tickets("tickets.txt"); 
    char tick_inf[255];
    int cnt = 0;
    while (tickets.getline(tick_inf, 255, '\n')) cnt++; //считаем кол-во рейсов
    aviasales* inf = new aviasales[cnt]; //создаем массив объектов
    char* buf;
    int i = 0;
    tickets.close();
    tickets.open("tickets.txt");
    while(tickets.getline(tick_inf, 255, '\n')) //читаем информацию с файла по разделтелям
    {
        buf = strtok(tick_inf, "/");
        inf[i].fnum = stoi(buf);
        buf = strtok(NULL, "/");
        strcpy(inf[i].fname, buf);
        buf = strtok(NULL, "/");
        strcpy(inf[i].pod, buf);
        buf = strtok(NULL, "/");
        inf[i].dur = stoi(buf);
        i++;
    }
    tickets.close();
    return make_tuple(inf, cnt);
}

void information(aviasales* tick)
{
    for (int i = 0; i < get<1>(input()); i++) //пока i меньше кол-ва рейсов, выводим рейсы
    {
        cout << "Номер рейса - " << tick[i].fnum << endl;
        cout << "ФИО - " << tick[i].fname << endl;
        cout << "Место назначения - " << tick[i].pod << endl;
        cout << "Продолжительность полёта - " << tick[i].dur << " мин." << endl;
        cout << endl;
    }
}

void surname(aviasales* tick) //выводит все рейсы с запрашиваемой фамилией
{
    string sur;
    cout << "Введите фамилию: ";
    getline(cin, sur);
    char* buf;
    string sur_;
    for (int i = 0; i < get<1>(input()); i++) //ищем фамилию
    {

        sur_ = tick[i].fname;
        buf = strtok(tick[i].fname, " ");
        if (buf == sur) //сравниваем фамилию с введенной и выводим все рейсы с этой фамилией
        {
            cout << "Номер рейса - " << tick[i].fnum << endl;
            cout << "ФИО - " << sur_ << endl;
            cout << "Место назначения - " << tick[i].pod << endl;
            cout << "Продолжительность полёта - " << tick[i].dur << " мин." << endl;
            cout << endl;
        }
    }
}

void dursort(aviasales* tick) //выводит (по алфавиту) номера рейсов больше 3-ех часов
{
    int cnt = 0;
    for (int i = 0; i < get<1>(input()); i++)
        if (tick[i].dur > 180) cnt++; //выясняем сколько рейсов больше 3-ех часов
    int* a = new int[cnt];
    for (int i = 0, j = 0; i < get<1>(input()); i++) //записываем в массив номера рейсов больше 3-ех часов
    {
        if (tick[i].dur > 180)
        {
            a[j] = i;
            j++;
        }
    }

    aviasales* temp = new aviasales[cnt]; //создаем новый обьект, в котором хранятся нужные нам рейсы
    for (int i = 0; i < cnt; i++)
    {
        temp[i].fnum = tick[a[i]].fnum;
        strcpy(temp[i].fname, tick[a[i]].fname);
        strcpy(temp[i].pod, tick[a[i]].pod);
        temp[i].dur = tick[a[i]].dur;
    }

    aviasales temp2; 
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (strcmp(temp[j].fname, temp[j-1].fname) < 0) //сортируем, сравнивая фамилии 
            {
                temp2 = temp[j];
                temp[j] = temp[j - 1];
                temp[j - 1] = temp2;
            }
        }
    }
    for (int i = 0; i < cnt; i++) //вывод
    {
        cout << "Номер рейса - " << temp[i].fnum << endl;
        cout << "ФИО - " << temp[i].fname << endl;
        cout << "Место назначения - " << temp[i].pod << endl;
        cout << "Продолжительность полёта - " << temp[i].dur << " мин." << endl;
        cout << endl;
    }
}


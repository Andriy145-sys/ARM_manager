#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<windows.h>
#include<fstream>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include "Kursova/Goods.h"
#include"Kursova/Purchase.h"
#include"Kursova/Customer.h"

using namespace std;

int main()
{
    system("chcp 1251 > null");
    string Motof = { "MotoDB.txt" }, Purchasef = { "PurchaseDB.txt" }, Customerf = { "CustomerDB.txt" };
    Goods god;
    Purchase purc;
    Customer cust;
    fstream fs, fsc, fsp;

    int n = -1;
    char* str = new char[1024];
    int a = 0;
    time_t td;
    td = time(NULL);
    while (n != 0) {
        std::cout << "----------------------------[Мотомагазин 'Драйв']----------------------------\n";
        std::cout << "(0)Вийти\n" << "(1)Додати мотоцикл\n" << "(2)Оформити покупця\n" << "(3)Знайти мотоцикл\n";
        std::cout << "(4)Знайти покупця\n" << "(5)Наявні мотоцикли\n" << "(6)Звіт\n" << "(7)Видалити мотоцикл\n";
        std::cout << "(8)Змінити дані мотоцикла\n";
        std::cout << "-----------------------------------------------------------------------------\n";
        std::cout << "Ваш вибір:";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        switch (n) {
        case 0: {
            cout << "\nПрограма успішно завершила роботу\n"; 
            break; }
        case 1: {

            string N, M, T, Tc, Cv;
            int E, Nh, PPP, Id=0;
            char d = 'd';
            bool bo;

            fs.open(Motof, fstream::in);
            system("cls");
            cout << "\t\tДодавання мотоцикла\n\n";
            Id = god.Kil(Motof)+1;
            while (d != 'n') {
                cout << "Введіть назву виробника: ";
                cin >> N;
                cout << "Введіть модель: ";
                cin >> M;
                cout << "Введіть тип: ";
                cin >> T;
                cout << "Введіть тип охолодження: ";
                cin >> Tc;
                cout << "Введіть об'єм двигуна: ";
                cin >> E;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Не правильно введено символ потрібно вводити тільки цифри\n Введіть ще раз:" << std::endl;
                    cin >> E;
                }
                cout << "Введіть кількість кінських сил: ";
                cin >> Nh;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Не правильно введено символ потрібно вводити тільки цифри\n Введіть ще раз:" << std::endl;
                    cin >> Nh;
                }
                cout << "Введіть країну виробника: ";
                cin >> Cv;
                cout << "Введіть ціну за одиницю: ";
                cin >> PPP;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Не правильно введено символ потрібно вводити тільки цифри\n Введіть ще раз:" << std::endl;
                    cin >> PPP;
                }
                god.Parametrs(Id, N, M, T, Tc, Cv, E, Nh, PPP);
                god.AddMoto(Motof);
                cout << "Додати ще один мотоцикл(y) Вийти(n)\n Ваш вибір:";
                cin >> d;
                if (d != 'y' && d != 'n') {// перевірка вводу
                    cout << "Будь ласка ведіть коректне значення\n";
                    cin >> d;
                }
                Id += 1;
            }
            system("cls");

        }break;
        case 2: {
            int Id, Num, Id_god, Id_cust, Pa, i;
            string Date, P, I, B, N_p;
            char d = 'd';
            system("cls");
            //для пошуку доступних ід 
            fs.open(Motof, fstream::in);
            while (!fs.eof())
            {
                fs.getline(str, 1024, '\n');
                a++;
            }
            fs.close();
            i = a / 10;
            a = 0;
            //для автоматичного ід покупок
            fsp.open(Purchasef, fstream::in);
            while (!fsp.eof())
            {
                fsp.getline(str, 1024, '\n');
                a++;
            }fsp.close();
            Id = (a / 7) + 1;
            a = 0;
            //для автоматичних ід покупця
            fsc.open(Customerf, fstream::in);
            while (!fsc.eof())
            {
                fsc.getline(str, 1024, '\n');
                a++;
            }fsc.close();
            Id_cust = (a / 4) + 1;
            a = 0;
            //додавання покупки
            cout << "\t\tДодавання покупки\n\n";
            while (d != 'n') {
                cout << "Введіть ПІБ покупця: ";
                cin >> P >> I >> B;
                cout << "Введіть №паспорта покупця: ";
                cin >> N_p;
                cout << "Введіть ID мотоцикла: ";
                cin >> Id_god;

                if (Id_god > i) {
                    cin.clear();
                    cin.ignore();
                    cout << "Такого id немає в базі\n Введіть коректне id: ";
                    cin >> Id_god;
                };
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Не правильно введено,потрібно вводити тільки цифри\n Введіть ще раз:" << std::endl;
                    cin >> Id_god;
                }
                cout << "Введіть кількість товару: ";
                cin >> Num;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Не правильно введено символ потрібно вводити тільки цифри\n Введіть ще раз:" << std::endl;
                    cin >> Num;
                }
                Date = ctime(&td);
                cout << "Введіть суму покупки: ";
                cin >> Pa;
                purc.PurParametrs(Id, Num, Id_god, Id_cust, Pa, Date);
                cust.CusParametrs(Id_cust, P, I, B, N_p);
                purc.AddPurchase(Purchasef);
                cust.AddCustomer(Customerf);
                cout << "Додати ще одину покупку(y) Вийти(n)\n";
                cin >> d;
                if (d != 'y' && d != 'n') {// перевірка вводу
                    cout << "Будь ласка ведіть коректне значення\n";
                    cin >> d;
                }
                Id += 1;
                Id_cust += 1;
            }
            system("cls");
        }break;
        case 3: {
            system("cls");
            int v = -1;
            string word_fn;

            while (v != 0) {
                cout << "Пошук мотоцикла по іd(1), по моделі мотоцикла(2)\n";
                cout << "Ваш вибір: ";
                cin >> v;
                switch (v) {
                case 1: { cout << "Введіть id: ";
                    cin >> word_fn;
                    break; }
                case 2: { 
                    cout << "Доступні мотоцикли:\n";
                     god.Models(Motof);
                    cout << "Введіть модель мотоцикла: ";
                    cin >> word_fn;
                    break; }
                }
                god.SearchMoto(Motof, word_fn, v);
                cout << "Продовжити (1) Повернутись до головного меню (0)\n Ваш вибір:";
                cin >> v;
            }
            system("cls");
            break;
        }break;
        case 4: {
            system("cls");
            string word_fn;
            cout << "Введіть ID покупця\n";
            cin >> word_fn;
            cust.SearchCustomer(Customerf, word_fn);
            system("pause");
            system("cls");
        }break;
        case 5: {
            system("cls");
            god.Print(Motof); break; }
        case 6: {
            string date,s;
            system("cls");
            cout << "(1)По даті покупки\n(2)Всі покупки\nВаш вибір: ";
            cin >> n;
            switch (n) {
            case 1: {
                system("cls");
                cout << "Введіть дату: ";
                getline(cin, date);
                getline(cin, date);
                cout << endl;
                purc.PrintDate(Purchasef,date); break; }
            case 2: {purc.PrintPurchase(Purchasef);}break;
            }
         system("cls");
        }break;
        case 7: {
            system("cls");
            cout << "\tВидалення мотоцикла\n\n";
            cout << "Доступні мотоцикли:\n";
            god.Models(Motof);
            cout << endl;
            god.DeleteMoto(Motof);
            system("cls");
        }break;
        case 8: {
            system("cls");
            god.ChangeMoto(Motof); }break;
        default: {
            cout << "Введіть коректне значення: " << endl;
            system("cls");
            break; }
        }
    }
}


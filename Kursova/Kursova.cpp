// Kursova.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<windows.h>
using namespace std;
int main()
{
    system("chcp 1251 > null");
    std::cout << "\t\t\tМотомагазин Дорога до раю\n";
    std::cout << "(0)Вийти\n" << "(1)Додати мотоцикл\n" << "(2)Оформити покупця\n" << "(3)Знайти мотоцикл\n"; 
    std::cout<< "(4)Знайти покупця\n" << "(5)Наявні мотоцикли\n" << "(6)Звіт\n" << "(7)Видалити мотоцикл\n";
    int n;
    std::cout << "Ваш вибір:";
    cin >> n;
    while (n == -1) {
        switch (n) {
        case 0: {exit; }break;
        case 1: {}break;
        case 2: {}break;
        case 3: {}break;
        case 4: {}break;
        case 5: {}break;
        case 6: {}break;
        case 7: {}break;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

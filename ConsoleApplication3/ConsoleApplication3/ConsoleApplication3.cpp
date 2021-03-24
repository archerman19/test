#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "Struct.h"
#include "Menu.h"
#include "Add.h"
#include "Prosmotr.h"
#include "Poisk.h"
#include "Exit.h"

using namespace std;

catalog hc;

int main()
{
    setlocale(LC_ALL, "rus");
    fstream file;
    bool f = true;
    const char* doc = "file.txt";
    int choise;
    while (f) {
        menu(); // вызов меню
        cin >> choise;
        switch (choise)
        {
        case 1: // Добавление записи
            getchar();
            cout << "Марка: "; cin.getline(hc.mark, 30);
            cout << "Модель: "; cin.getline(hc.model, 30);
            cout << "Класс: "; cin.getline(hc.helicopter_class, 30);
            cout << "Страна: "; cin.getline(hc.country, 30);
            cout << "Год выпуска: "; cin >> hc.year;
            cout << "Цена: "; cin >> hc.price;

            add(doc, hc); // Add.h
            break;
        case 2: // Просмотр записей
            prosmotr(doc, hc); // Prosmotr.h
            break;
        case 3: // Поиск записей
            poisk(doc, hc); // Poisk.h
            break;
        case 4: // Выход
            f = exit();
            break;
        default:
            cout << "Такой команды не существует, убедитесь в правильном написании" << endl;
            break;
        }
    }
    return 0;
}


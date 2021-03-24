#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>

using namespace std;

typedef struct catalog //структура процессоров
{
    char mark[30];
    char model[30];
    char helicopter_class[30];
    char country[30];
    int year;
    double price;
}*ccatalog;

ccatalog hc;

int main()
{
    setlocale(LC_ALL, "rus");
    fstream* file;
    hc = new catalog;
    file = new fstream;
    bool f = true, // для повторного вызова меню
        find = false; // нашлась запись в бд или нет
    const char* doc = "file.txt";
    char nameX[40]; // переменная для поиска по строке
    int choise,
        numberi; // переменная для поиска по целочисленным значениям
    double numberd; // переменная для поиска по значениям с плавающей точкой
    while (f) { // зацикленное воспроизведение меню
        cout << "1 - Новая запись" << endl;
        cout << "2 - Просмотр записей" << endl;
        cout << "3 - Поиск по записям" << endl;
        cout << "4 - выход" << endl;
        cin >> choise;
        switch (choise)
        {
        case 1: // добавление записи в бд
            getchar();
            cout << "Марка: "; cin.getline(hc->mark, 30);
            cout << "Модель: "; cin.getline(hc->model, 30);
            cout << "Класс: "; cin.getline(hc->helicopter_class, 30);
            cout << "Страна: "; cin.getline(hc->country, 30);
            cout << "Год выпуска: "; cin >> hc->year;
            cout << "Цена: "; cin >> hc->price;

            file->open(doc, ios_base::app | ios_base::binary);
            if (!file->is_open())
                cout << "Файл не может быть открыт!\n";
            else {
                file->write((char*)hc, sizeof(catalog));
            }
            file->close();
            break;
        case 2: // вывод всех записей в консоль
            file->open(doc, ios_base::in | ios_base::binary);
            if (!file->is_open())
                cout << "Файл не может быть открыт!\n";
            else {
                cout << "\tВсе записи:\nМарка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                while (true)
                {
                    file->read((char*)hc, sizeof(catalog));
                    if (!file->eof())
                        cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                    else
                        break;
                }
                file->close();
                break;
            }
            break;
        case 3: // поиск записей по фильтрам
            int filter_option; // выбор фильтра
            cout << "Фильтры:\n"
                << "\t1 - Поиск по марке\n"
                << "\t2 - Поиск по модели\n"
                << "\t3 - Поиск по классу\n"
                << "\t4 - Поиск по цене\n"
                << "\t5 - Поиск по году\n"
                << "\t6 - Поиск по стране\n";
            cout << "Какой фильтр применить? "; cin >> filter_option;

            switch (filter_option) // выбор фильтра поиска
            {
            case 1: // Поиск по названию процессора
                getchar();
                cout << "Введите марку вертолета: "; cin.getline(nameX, 40);
                file->open(doc, ios_base::in | ios_base::binary);
                if (!file->is_open())
                    cout << "Файл не может быть открыт!\n";
                else {
                    cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                    while (true)
                    {
                        file->read((char*)hc, sizeof(catalog));
                        if (!file->eof()) {
                            if (strcmp(hc->mark, nameX) == 0)
                            {
                                cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                find = true;
                            }
                        }
                        else
                            break;
                    }
                    if (!find)
                        cout << "Записей не найдено.\n";
                    file->close();
                    break;
                }
            case 2: // Поиск по модели процессора
                getchar();
                cout << "Введите модель: "; cin.getline(nameX, 40);
                file->open(doc, ios_base::in | ios_base::binary);
                if (!file->is_open())
                    cout << "Файл не может быть открыт!\n";
                else {
                    cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                    while (true)
                    {
                        file->read((char*)hc, sizeof(catalog));
                        if (!file->eof()) {
                            if (strcmp(hc->model, nameX) == 0)
                            {
                                cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                find = true;
                            }
                        }
                        else
                            break;
                    }
                    if (!find)
                        cout << "Записей не найдено.\n";
                    file->close();
                    break;
                }
            case 3: // Поиск по сокету
                getchar();
                cout << "Введите класс: "; cin.getline(nameX, 40);
                file->open(doc, ios_base::in | ios_base::binary);
                if (!file->is_open())
                    cout << "Файл не может быть открыт!\n";
                else {
                    cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                    while (true)
                    {
                        file->read((char*)hc, sizeof(catalog));
                        if (!file->eof()) {
                            if (strcmp(hc->helicopter_class, nameX) == 0)
                            {
                                cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                find = true;
                            }
                        }
                        else
                            break;
                    }
                    if (!find)
                        cout << "Записей не найдено.\n";
                    file->close();
                    break;
                }
            case 4: // Поиск по частоте(ГГц)
                getchar();
                int oper; // выбор подфильтра
                file->open(doc, ios_base::in | ios_base::binary);
                if (!file->is_open())
                    cout << "Файл не может быть открыт!\n";
                else {
                    cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper; // выбор подфильтра
                    switch (oper) // поиск по подфильтру
                    {
                    case 1: // если введенное значние == заданному
                        cout << "Введите цену: "; cin >> numberd;
                        cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                        while (true)
                        {
                            file->read((char*)hc, sizeof(catalog));
                            if (!file->eof()) {
                                if (hc->price == numberd)
                                {
                                    cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                    find = true;
                                }
                            }
                            else
                                break;
                        }
                        if (!find)
                            cout << "Записей не найдено.\n";
                        file->close();
                        break;
                    case 2: // если значние >= заданного
                        cout << "Введите цену: "; cin >> numberd;
                        cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                        while (true)
                        {
                            file->read((char*)hc, sizeof(catalog));
                            if (!file->eof()) {
                                if (hc->price >= numberd)
                                {
                                    cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                    find = true;
                                }
                            }
                            else
                                break;
                        }
                        if (!find)
                            cout << "Записей не найдено.\n";
                        file->close();
                        break;
                    case 3: // если значние <= заданного
                        cout << "Введите цену: "; cin >> numberd;
                        cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                        while (true)
                        {
                            file->read((char*)hc, sizeof(catalog));
                            if (!file->eof()) {
                                if (hc->price <= numberd)
                                {
                                    cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                    find = true;
                                }
                            }
                            else
                                break;
                        }
                        if (!find)
                            cout << "Записей не найдено.\n";
                        file->close();
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 5: // Поиск по техпроцессу(нм)
                getchar();
                file->open(doc, ios_base::in | ios_base::binary);
                if (!file->is_open())
                    cout << "Файл не может быть открыт!\n";
                else {
                    cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper;
                    switch (oper)
                    {
                    case 1:
                        cout << "Введите год: "; cin >> numberi;
                        cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                        while (true)
                        {
                            file->read((char*)hc, sizeof(catalog));
                            if (!file->eof()) {
                                if (hc->year == numberi)
                                {
                                    cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                    find = true;
                                }
                            }
                            else
                                break;
                        }
                        if (!find)
                            cout << "Записей не найдено.\n";
                        file->close();
                        break;
                    case 2:
                        cout << "Введите год: "; cin >> numberi;
                        cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                        while (true)
                        {
                            file->read((char*)hc, sizeof(catalog));
                            if (!file->eof()) {
                                if (hc->year >= numberi)
                                {
                                    cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                    find = true;
                                }
                            }
                            else
                                break;
                        }
                        if (!find)
                            cout << "Записей не найдено.\n";
                        file->close();
                        break;
                    case 3:
                        cout << "Введите год: "; cin >> numberi;
                        cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                        while (true)
                        {
                            file->read((char*)hc, sizeof(catalog));
                            if (!file->eof()) {
                                if (hc->year <= numberi)
                                {
                                    cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                    find = true;
                                }
                            }
                            else
                                break;
                        }
                        if (!find)
                            cout << "Записей не найдено.\n";
                        file->close();
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 6: // Поиск по количеству ядер
                getchar();
                cout << "Введите страну: "; cin.getline(nameX, 40);
                file->open(doc, ios_base::in | ios_base::binary);
                if (!file->is_open())
                    cout << "Файл не может быть открыт!\n";
                else {
                    cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
                    while (true)
                    {
                        file->read((char*)hc, sizeof(catalog));
                        if (!file->eof()) {
                            if (strcmp(hc->country, nameX) == 0)
                            {
                                cout << hc->mark << "\t\t" << hc->model << "\t\t" << hc->helicopter_class << "\t" << hc->country << "\t\t" << hc->year << "\t\t" << hc->price << endl;
                                find = true;
                            }
                        }
                        else
                            break;
                    }
                    if (!find)
                        cout << "Записей не найдено.\n";
                    file->close();
                    break;
                }
                break;
            default:
                break;
            }
            break;
        case 4: // выход из программы
            f = false;
            break;
        default:
            cout << "Такой команды не существует, убедитесь в правильном написании" << endl;
            break;
        }
    }
    delete file;
    delete hc;
    return 0;
}

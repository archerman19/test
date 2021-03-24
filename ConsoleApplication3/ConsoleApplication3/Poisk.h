#pragma once
#ifndef POISK_H
#define POISK_H

#include <iostream>
using namespace std;

void poisk(const char* doc, catalog hc) {
    ifstream file;
    bool find = false;
    char nameX[40];
    int filter_option, numberi;
    double numberd;
	cout << "Фильтры:\n"
		<< "\t1 - Поиск по марке\n"
		<< "\t2 - Поиск по модели\n"
		<< "\t3 - Поиск по классу\n"
		<< "\t4 - Поиск по стране\n"
		<< "\t5 - Поиск по году\n"
		<< "\t6 - Поиск по цене\n";
	cout << "Какой фильтр применить? ";
	cin >> filter_option;
	switch (filter_option) {
	case 1:
	{
		getchar();
		find = false;
		cout << "Введите марку вертолета: "; cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
			while (true)
			{
				file.read((char*)&hc, sizeof(catalog));
				if (!file.eof()) {
					if (strcmp(hc.mark, nameX) == 0)
					{
						cout << hc.mark << "\t\t" << hc.model << "\t\t"
							<< hc.helicopter_class << "\t\t" << hc.country
							<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
						find = true;
					}
				}
				else
					break;
			}
			system("pause");
			if (!find)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	}
	case 2:
		getchar();
		find = false;
		cout << "Введите модель вертолета: ";
		cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
			while (true)
			{
				file.read((char*)&hc, sizeof(catalog));
				if (!file.eof()) {
					if (strcmp(hc.model, nameX) == 0)
					{
						cout << hc.mark << "\t\t" << hc.model << "\t\t"
							<< hc.helicopter_class << "\t\t" << hc.country
							<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
						find = true;
					}
				}
				else
					break;
			}
			system("pause");
			if (!find)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	case 3:
		find = false;
		getchar();
		cout << "Введите класс вертолета: "; cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
			while (true)
			{
				file.read((char*)&hc, sizeof(catalog));
				if (!file.eof()) {
					if (strcmp(hc.helicopter_class, nameX) == 0)
					{
						cout << hc.mark << "\t\t" << hc.model << "\t\t"
							<< hc.helicopter_class << "\t\t" << hc.country
							<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
						find = true;
					}
				}
				else
					break;
			}
			system("pause");
			if (!find)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	case 4:
		find = false;
		getchar();
		cout << "Введите страну: "; cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
			while (true)
			{
				file.read((char*)&hc, sizeof(catalog));
				if (!file.eof()) {
					if (strcmp(hc.country, nameX) == 0)
					{
						cout << hc.mark << "\t\t" << hc.model << "\t\t"
							<< hc.helicopter_class << "\t\t" << hc.country
							<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
						find = true;
					}
				}
				else
					break;
			}
			system("pause");
			if (!find)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	case 5:
		getchar();
		int oper; // выбор подфильтра
		find = false;
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
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
					file.read((char*)&hc, sizeof(catalog));
					if (!file.eof()) {
						if (hc.year == numberi)
						{
							cout << hc.mark << "\t\t" << hc.model << "\t\t"
								<< hc.helicopter_class << "\t\t" << hc.country
								<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
							find = true;
						}
					}
					else
						break;
				}
				system("pause");
				if (!find)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			case 2:
				cout << "Введите год: "; cin >> numberi;
				cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
				while (true)
				{
					file.read((char*)&hc, sizeof(catalog));
					if (!file.eof()) {
						if (hc.year >= numberi)
						{
							cout << hc.mark << "\t\t" << hc.model << "\t\t"
								<< hc.helicopter_class << "\t\t" << hc.country
								<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
							find = true;
						}
					}
					else
						break;
				}
				system("pause");
				if (!find)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			case 3:
				cout << "Введите год: "; cin >> numberi;
				cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
				while (true)
				{
					file.read((char*)&hc, sizeof(catalog));
					if (!file.eof()) {
						if (hc.year <= numberi)
						{
							cout << hc.mark << "\t\t" << hc.model << "\t\t"
								<< hc.helicopter_class << "\t\t" << hc.country
								<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
							find = true;
						}
					}
					else
						break;
				}
				system("pause");
				if (!find)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			default:
				break;
			}
		}
		break;
	case 6:
		getchar();
		find = false;
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
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
					file.read((char*)&hc, sizeof(catalog));
					if (!file.eof()) {
						if (hc.price == numberd)
						{
							cout << hc.mark << "\t\t" << hc.model << "\t\t"
								<< hc.helicopter_class << "\t\t" << hc.country
								<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
							find = true;
						}
					}
					else
						break;
				}
				system("pause");
				if (!find)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			case 2: // если значние >= заданного
				cout << "Введите цену: "; cin >> numberd;
				cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
				while (true)
				{
					file.read((char*)&hc, sizeof(catalog));
					if (!file.eof()) {
						if (hc.price >= numberd)
						{
							cout << hc.mark << "\t\t" << hc.model << "\t\t"
								<< hc.helicopter_class << "\t\t" << hc.country
								<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
							find = true;
						}
					}
					else
						break;
				}
				system("pause");
				if (!find)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			case 3: // если значние <= заданного
				cout << "Введите цену: "; cin >> numberd;
				cout << "Марка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
				while (true)
				{
					file.read((char*)&hc, sizeof(catalog));
					if (!file.eof()) {
						if (hc.price <= numberd)
						{
							cout << hc.mark << "\t\t" << hc.model << "\t\t"
								<< hc.helicopter_class << "\t\t" << hc.country
								<< "\t\t" << hc.year << "\t\t" << hc.price << endl;
							find = true;
						}
					}
					else
						break;
				}
				system("pause");
				if (!find)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			default:
				break;
			}
		}
		break;

	}
}

#endif POISK_H

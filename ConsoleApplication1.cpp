#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>


using namespace std;

struct catalog {
	char mark[30];
	char model[30];
	char helicopter_class[30];
	char country[30];
	int year;
	double price;
};

catalog hc;


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int start, i;
	bool find = false;
	char nameX[40]; 
	int choise, numberi;
	double numberd;


	do
	{
		system("cls");
		cout << "Новая запись - 1" << endl;
		cout << "Просмотр записей - 2" << endl;
		cout << "Поиск - 3" << endl;
		cout << "Выход - 4" << endl;
		cout << "Выберите операцию: "; 
		cin >> start;

		switch (start)
		{
		case 1:
		{
		getchar();
		ofstream file("file.txt", std::ios::app | ios_base::binary);
		if (!file.is_open()) {
			cout << "Файл не открыт!\n";
		}
		else {
			cout << "Марка: "; cin >> hc.mark;
			cout << "Модель: "; cin >> hc.model;
			cout << "Класс: "; cin >> hc.helicopter_class;
			cout << "Страна: "; cin >> hc.country;
			cout << "Год выпуска: "; cin >> hc.year;
			cout << "Цена: "; cin >> hc.price;
			file.write((char*)&hc, sizeof(catalog));
			file.close();
		}
		cout << "Выберите операцию\n";
		cin >> i;
		break;
		}
		case 2: {
			ifstream file("file.txt");
			if (!file.is_open()) {
				cout << "Файл не открыт!\n";
			}
			else
			{
				cout << "\tВсе записи:\nМарка\t\tМодель\t\tКласс\t\tСтрана\t\tГод выпуска\t\tЦена\n";
				while (true)
				{

					file.read((char*)&hc, sizeof(catalog));
					if (!file.eof())
						cout << hc.mark << "\t\t" << hc.model << "\t\t"
						<< hc.helicopter_class << "\t\t" << hc.country
						<< "\t\t" << hc.year << "\t\t" << hc.price << endl;

					else break;
				}
			}
			file.close();
			cout << "Выберите операцию\n";
			cin >> i;
			break;
		}
		case 3:
			fstream file;
			int filter_option;
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
				int oper; 
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
					cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper; 
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
					case 2: 
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
					case 3: 
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
	} while (start != 4);
}

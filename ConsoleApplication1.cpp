#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

struct catalog {
	char mark[30];
	char model[30];
	char helicopter_class[30];
	char country[30];
	int year;
	float price;
	int capacity;
	void Print() {
		cout << mark << "\t\t";
		cout << "        " << model << "\t";
		cout << "        " << helicopter_class << "\t";
		cout << "        " << country << "\t";
		cout << "        " << year << "\t";
		cout << "        " << price << "\t";
		cout << "        " << capacity << "\t";
		cout << endl;
	}
};

catalog hc;
int start, n = 0;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ofstream file;
	cout << "Ввод новой записи - 1" << endl;
	cout << "Вывод всех записей - 2" << endl;
	cout << "Поиск - 3" << endl;
	cout << "Выход - 4" << endl;
	cout << "Выберите операцию: "; cin >> start;
	
	if (start != 4) {
		switch (start)
		{
		case 1:
		{FILE* fa;
		fa = fopen("file.txt", "w+");
		if (!fa) {
			cout << "Файл не открыт!\n";
		}
		else {
			cout << "Марка: "; cin >> hc.mark;
			cout << "Модель: "; cin >> hc.model;
			cout << "Класс: "; cin >> hc.helicopter_class;
			cout << "Страна: "; cin >> hc.country;
			cout << "Год выпуска: "; cin >> hc.year;
			cout << "Цена: "; cin >> hc.price;
			cout << "Вместимость: "; cin >> hc.capacity;
			fread(&n, sizeof(int), 1, fa);
			cout << "n = " << n;
			n++;
			fwrite(&n, sizeof(int), 1, fa);
			fclose(fa);
			FILE* fb;
			fb = fopen("file.txt", "a");
			fwrite((char*)&hc, sizeof(catalog), 1, fb);
			fclose(fb);
			cout << n;
		}
		break;
		}
		case 2: {
			FILE* f;
			f = fopen("file.txt", "r");
			if (!f) {
				cout << "Файл не открыт!\n";
			}
			else
			{
				fread(&n, sizeof(int), 1, f);
				cout << n;
				catalog* p;
				p = (catalog*)calloc(n, sizeof(catalog));
				for (int i = 0; i < n; i++) {
					fread(&p[i], sizeof(catalog), 1, f);
				}
				for (int i = 0; i < n; i++) {
					p[i].Print();
				}
			}
			fclose(f);
			break;
		}
		case 3:
		default:
			cout << "error";
			break;
		}
	}
}
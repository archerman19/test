#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct catalog {
	char mark[30];
	char model[30];
	char helicopter_class[30];
	char country[30];
	int year;
	float price;
	int capacity;
};

catalog hc;
int start, n = 0;

int main() {
	setlocale(LC_ALL, "RUS");
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
		{file.open("file.bin", ios_base::app);
		if (!file) {
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
			vector <catalog> vhc;
			file.write((char*)&vhc, sizeof(catalog));
			file.close();
			ifstream file("file.bin", ios::in);
			file.read((char*)&n, sizeof(int));
			n++;
			file.close();
			ofstream file("file.bin", ios_base::app);
			file.write((char*)&n, sizeof(int));
			file.close();
			//file.write((char*)&hc, sizeof(catalog));
			
		}
		break;
		}
		case 2: {
			ifstream file("file.bin", ios::in);
			if (!file) {
				cout << "Файл не открыт!\n";
			}
			else
			{
				catalog hc;
				vector <catalog> vhc;
				while (!file.eof()) {
					file.read((char*)&hc, sizeof(catalog));
					/*cout << "Марка: " << hc.mark << endl;
					cout << "Модель: " << hc.model << endl;
					cout << "Класс: " << hc.helicopter_class << endl;
					cout << "Страна: " << hc.country << endl;
					cout << "Год выпуска: " << hc.year << endl;
					cout << "Цена: " << hc.price << endl;
					cout << "Вместимость: " << hc.capacity << endl;*/
					vhc.push_back(hc);
					for (int i = 0; i <= vhc.size(); ++i) {
						cout << vhc[0] << endl;
					}
				}
				file.close();
			}
			break;
		}
		case 3:
		default:
			cout << "error";
			break;
		}
	}
}
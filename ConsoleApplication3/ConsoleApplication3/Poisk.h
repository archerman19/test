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
	cout << "�������:\n"
		<< "\t1 - ����� �� �����\n"
		<< "\t2 - ����� �� ������\n"
		<< "\t3 - ����� �� ������\n"
		<< "\t4 - ����� �� ������\n"
		<< "\t5 - ����� �� ����\n"
		<< "\t6 - ����� �� ����\n";
	cout << "����� ������ ���������? ";
	cin >> filter_option;
	switch (filter_option) {
	case 1:
	{
		getchar();
		find = false;
		cout << "������� ����� ���������: "; cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "���� �� ����� ���� ������!\n";
		else {
			cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
				cout << "������� �� �������.\n";
			file.close();
			break;
		}
	}
	case 2:
		getchar();
		find = false;
		cout << "������� ������ ���������: ";
		cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "���� �� ����� ���� ������!\n";
		else {
			cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
				cout << "������� �� �������.\n";
			file.close();
			break;
		}
	case 3:
		find = false;
		getchar();
		cout << "������� ����� ���������: "; cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "���� �� ����� ���� ������!\n";
		else {
			cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
				cout << "������� �� �������.\n";
			file.close();
			break;
		}
	case 4:
		find = false;
		getchar();
		cout << "������� ������: "; cin.getline(nameX, 40);
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "���� �� ����� ���� ������!\n";
		else {
			cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
				cout << "������� �� �������.\n";
			file.close();
			break;
		}
	case 5:
		getchar();
		int oper; // ����� ����������
		find = false;
		file.open("file.txt", ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "���� �� ����� ���� ������!\n";
		else {
			cout << "�������� ��������: \n1) =\n2) >=\n3) <=\n"; cin >> oper;
			switch (oper)
			{
			case 1:
				cout << "������� ���: "; cin >> numberi;
				cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
					cout << "������� �� �������.\n";
				file.close();
				break;
			case 2:
				cout << "������� ���: "; cin >> numberi;
				cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
					cout << "������� �� �������.\n";
				file.close();
				break;
			case 3:
				cout << "������� ���: "; cin >> numberi;
				cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
					cout << "������� �� �������.\n";
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
			cout << "���� �� ����� ���� ������!\n";
		else {
			cout << "�������� ��������: \n1) =\n2) >=\n3) <=\n"; cin >> oper; // ����� ����������
			switch (oper) // ����� �� ����������
			{
			case 1: // ���� ��������� ������� == ���������
				cout << "������� ����: "; cin >> numberd;
				cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
					cout << "������� �� �������.\n";
				file.close();
				break;
			case 2: // ���� ������� >= ���������
				cout << "������� ����: "; cin >> numberd;
				cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
					cout << "������� �� �������.\n";
				file.close();
				break;
			case 3: // ���� ������� <= ���������
				cout << "������� ����: "; cin >> numberd;
				cout << "�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
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
					cout << "������� �� �������.\n";
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

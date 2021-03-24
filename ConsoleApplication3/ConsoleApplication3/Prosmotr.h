#pragma once
#ifndef PROSMOTR_H
#define PROSMOTR_H
#include <iostream>

using namespace std;

void prosmotr(const char* doc, catalog hc)
{
    ifstream file;
    file.open(doc, ios_base::in | ios_base::binary);
    if (!file.is_open())
        cout << "���� �� ����� ���� ������!\n";
    else {
        cout << "\t��� ������:\n�����\t\t������\t\t�����\t\t������\t\t��� �������\t\t����\n";
        while (true)
        {
            file.read((char*)&hc, sizeof(catalog));
            if (!file.eof())
                cout << hc.mark << "\t\t" << hc.model << "\t\t"
                << hc.helicopter_class << "\t\t" << hc.country
                << "\t\t" << hc.year << "\t\t" << hc.price << endl;
            else
                break;
        }
        file.close();
    }
}
#endif PROSMOTR_H

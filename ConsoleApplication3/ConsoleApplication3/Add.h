#pragma once
#ifndef ADD_H
#define ADD_H
#include <iostream>

using namespace std;

void add(const char* doc, catalog hc) {
	ofstream file("file.txt", std::ios::app | ios_base::binary);
	if (!file.is_open()) {
		cout << "Файл не открыт!\n";
	}
	else {
		file.write((char*)&hc, sizeof(catalog));
		file.close();
	}
	file.close();
}
#endif ADD_H
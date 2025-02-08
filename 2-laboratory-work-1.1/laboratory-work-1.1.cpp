﻿#include <iostream>
#include <fstream>
#include <sstream>
#include "firewall.hpp"
#include <string>

using namespace std;


Firewall** read_data(unsigned int n, string file_name)
{
	ifstream file(file_name);
	Firewall** result = new Firewall* [n];
	for (int i = 0; i < n; i++)
	{
		string token;
		string line;
		file >> line;
		stringstream ss(line);
		unsigned char counter = 0;

		string name;
		unsigned char security_status;

		while (getline(ss, token, ';'))
		{
			if (counter == 0) name = token;
			if (counter == 1) security_status = static_cast<unsigned char>(stoi(token));
			counter++;
		}
		result[i] = new Firewall(name, security_status);
	}
	return result;
}

void write_data(unsigned int n, Firewall** data, unsigned char security_status, string file_name)
{
	ofstream file(file_name);
	for (int i = 0; i < n; i++)
	{
		if (data[i]->is_valid(security_status))
		{
			file << data[i]->get_info();
			data[i]->print_info();
		}
	}
}
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 3)
	{
		cerr << "Ошибка! Неверное количество аргументов";
		return -1;
	}
	string read_file_name = argv[1];
	string write_file_name = argv[2];
	unsigned int n;
	int status;
	cout << "Введите количество записей: ";
	cin >> n;
	cout << "Введите уровень защиты: ";
	cin >> status;
	Firewall** data = read_data(n, read_file_name);
	write_data(n, data, static_cast<unsigned char>(status), write_file_name);
	return 0;
}

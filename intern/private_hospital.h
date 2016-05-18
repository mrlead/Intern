#pragma once
#include "company.h"
#include "min_health.h"
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#pragma warning (disable:4244)

using namespace std;

class private_hospital:public min_health
{
protected:
	char *name;
	char *place;
	int vip_room;
	int number;
	int cost;
	char *head_doctor;
	char *number_s;
	int financing;
	char *null_str;
	char *company;
public:
	private_hospital()
	{
		null_str = "";
		name = new char[15];
		company = new char[30];
		place = new char[40];
		head_doctor = new char[30];
		number_s = new char[5];
		number = NULL;
		cost = NULL;
		vip_room = NULL;
		financing = NULL;
		strcpy(name, null_str);
		strcpy(place, null_str);
		strcpy(head_doctor, null_str);
		strcpy(number_s, null_str);
	}
	virtual void get_name();
	virtual void get_number();
	virtual void display_param();
	void get_room();
	void get_place();
	void get_cost();
	void get_company();
	void get_head_private_doctor();
	void clean();
};

void private_hospital::clean()
{
	number = NULL;
	cost = NULL;
	vip_room = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
	strcpy(head_doctor, null_str);
	strcpy(number_s, null_str);
}

void private_hospital::get_name()
{
	const int LENGHT = 15;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "name_hosp.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//Читаем строку из файла источника
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//Случайная строка
		srand(time(NULL));
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void private_hospital::get_number()
{
	do
	{
		cout << "Введите номер больницы: ";
		cin >> number;
		if (number > 0 && number <= 100)
		{
			cout << "Успешно" << endl;
		}
		else
		{
			cout << "Простите, вы ввели некоректные данные" << endl;
		}
	} while (!(number > 0 && number <= 100));
}

void private_hospital::get_cost()
{
	do
	{
		cout << "Введите цену на вип-палату: ";
		cin >> cost;
		if (cost > 0 && cost <= 15000)
		{
			cout << "Успешно" << endl;
		}
		else
		{
			cout << "Простите, вы ввели некоректные данные" << endl;
		}
	} while (!(cost > 0 && cost <= 15000));
}

void private_hospital::get_place()
{
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "place_hosp.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//Читаем строку из файла источника
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//Случайная строка
		srand(time(NULL));
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void private_hospital::get_room()
{
			do
			{
				cout << "Введите количество вип-палат: ";
				cin >> vip_room;
				if (vip_room > 0 && vip_room <= 100)
				{
					cout << "Успешно" << endl;
				}
				else
				{
					cout << "Простите, вы ввели некоректные данные" << endl;
				}
			} while (!(vip_room > 0 && vip_room <= 100));
}

void private_hospital::get_company()
{
	//set_company
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "place_hosp.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//Читаем строку из файла источника
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//Случайная строка
		srand(time(NULL));
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		company = new char[str.length() + 1];
		strcpy(company, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
	//set_financing
	const int LENGHT = 15;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "place_hosp.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//Читаем строку из файла источника
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//Случайная строка
		srand(time(NULL));
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		financing = strtod(str.c_str(), 0);

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void private_hospital::get_head_private_doctor()
{
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "name_hd.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//Читаем строку из файла источника
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//Случайная строка
		srand(time(NULL));
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		head_doctor = new char[str.length() + 1];
		strcpy(head_doctor, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}
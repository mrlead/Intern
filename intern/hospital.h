#pragma once
#include "min_health.h"
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#pragma warning (disable:4244)

using namespace std;

class hospital:public min_health
{
protected:
	char *name;
	char *place;
	int room, vip_room;
	int number;
	int cost;
	char *head_docto;
	char *number_s;
	char *null_str;
public:
	hospital()
	{
		null_str = "";
		name = new char[15];
		place = new char[40];
		head_docto = new char[30];
		number_s = new char[5];
		number = NULL;
		cost = NULL;
		room = NULL;
		vip_room = NULL;
		strcpy(name, null_str);
		strcpy(place, null_str);
		strcpy(head_docto, null_str);
		strcpy(number_s, null_str);
	}
	virtual void get_name();
	virtual void get_number();
	virtual void display_param();
	void get_head_doctor();
	void get_room();
	void get_place();
	void get_cost();
	void clean();
};

void hospital::clean()
{
	number = NULL;
	cost = NULL;
	room = NULL;
	vip_room = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
	strcpy(head_docto, null_str);
	strcpy(number_s, null_str);
}

void hospital::get_name()
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

void hospital::get_number()
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

void hospital::get_cost()
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

void hospital::get_place()
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

void hospital::get_room()
{
	do
	{
		cout << "Введите количество палат: ";
		cin >> room;
		if (room > 0 && room <= 100)
		{
			cout << "Успешно" << endl;
		}
		else
		{
			cout << "Простите, вы ввели некоректные данные" << endl;
		}
	} while (!(room > 0 && room <= 100));
	char yn;
	do
	{
		cout << "Вы хотите прировнять количество вип-палат к обычным палатам(y/n)? ";
		cin >> yn;
		if (yn = 'y')
		{
			vip_room = room;
		}
		else
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
	} while (yn = 'n');
}

void hospital::get_head_doctor()
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
		head_docto = new char[str.length() + 1];
		strcpy(head_docto, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void hospital::display_param()
{
	cout << "Больница: " << name << endl;
	cout << "Номер: " << number << endl;
	cout << "Адрес: " << place << endl;
	cout << "Главный врач: " << head_docto <<  endl;
	cout << "Цена за вип-палату за сутки" << cost << endl;
	cout << "Количество палат: " << room << "	Вип-палат: " << vip_room << endl;
}
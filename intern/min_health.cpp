#pragma once
#include "min_health.h"
#include "person.h"
#include <iostream>
#include "conio.h"
#include <Windows.h>

void min_health::clean()
{
	r = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
}

void min_health::get_name()
{
	const int LENGHT = 60;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/min_data.txt";
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
		int index = rand() % 5;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void min_health::get_place()
{
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/place_min.txt";
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
		int index = rand() % 2;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
	r = 1;
}

void min_health::display_param()
{
	cout << "Название: " << name << endl;
	cout << "Адрес: " << place << endl;
}

void min_health::main_menu_min_health()
{
	min_health* health = new min_health();
	text* tex_m = new text();

	int key1, key2;
	do
	{
		system("cls");
		tex_m->main_health();
		key1 = _getch();
		switch (key1)
		{
		case '1':
		{
			system("cls");
			min_health::min_health();
			health->get_name();
			health->get_place();
			cout << "Созданно" << endl;
			Sleep(1500);
			system("cls");
		}
		break;
		case'2':
		{
			do
			{
				system("cls");
				health->display_param();
				key2 = _getch();
				switch (key2)
				{
				}
			} while (key2 != 27);
		}
		break;
		case'3':
		{
			if (health->r == 0)
			{
				system("cls");
				cout << "Сначала создайте министерство" << endl;
				Sleep(1500);
				system("cls");

			}
			else
			{
				system("cls");
				health->clean();
				cout << "Успешно" << endl;
				Sleep(1500);
				system("cls");
			}
		}
		break;
		case'4':
		{
			system("cls");
			person run;
			run.main_menu_staff();
		}
		}
	} while (key1 != 27);
}
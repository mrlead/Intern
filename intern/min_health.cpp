#pragma once
#include "min_health.h"
#include "hospital.h"
#include "private_hospital.h"
#include <iostream>
#include "conio.h"
#include <Windows.h>
#include <fstream>

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

	ifstream f(filename);
	if (!f.good())
	{
		cout << "Файл не открыт" << endl;
	}
	else
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
		strtok(name, "\n");
		str = "";
		coll.clear();

		fclose(fp);
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

	ifstream f(filename);
	if (!f.good())
	{
		cout << "Файл не открыт" << endl;
	}
	else
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
	r = 1;
}

void min_health::display_param()
{
	cout << GetIniString("1", "answer_health", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_health", "ini_base/menu_list_rus.ini") << place << endl;
	cout << endl;
	cout << GetIniString("11", "objects", "ini_base/menu_list_rus.ini") << count << endl;
}

text* tex_m = new text();
text_eng* text_e = new text_eng();

void min_health::main_menu_min_health()
{
	static min_health* health = new min_health();
	int key1, key2;
	
	do
	{
		system("cls");
		//lang();
		tex_m->main_health();
		key1 = _getch();
		switch (key1)
		{
		case '1':
		{
			setlocale(0, "");
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
			if (health->r == 1)
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
			else
			{
				system("cls");
				cout << "Сначала создайте министерство" << endl;
				Sleep(1500);
				system("cls");
			}
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
			hospital run;
			run.main_menu_hospital();
		}
		break;
		case'5':
		{
			private_hospital run_private_hos;
			run_private_hos.main_menu_private();
		}
		}
	} while (key1 != 27);
}
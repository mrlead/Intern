#include "head_doctor.h"
#include <iostream>
#include "conio.h"
#include <Windows.h>
#include <locale.h>

void head_doctor::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(ag, null_str);
	strcpy(status, null_str);
}

void head_doctor::get_age()
{
	//set_age
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/doct_age.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{

		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{

			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);


		srand(time(NULL));
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void head_doctor::get_name()
{
	//set_name
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/name_hd.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{

		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{

			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);


		srand(time(NULL));
		int index = rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "'\n'");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void head_doctor::GetNumber()
{
	num = 1 + rand() % 99;
}

void head_doctor::get_status()
{
	//set status
	const int LENGHT = 20;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/doct_stat.txt";
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
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		str = "";
		coll.clear();
		strtok(status, "'\n'");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void head_doctor::display_param()
{
	cout << "ФИО: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Статус сотрудника: " << status << endl;
	cout << "Номер бригады скорой помощи: " << num << endl;
}

void head_doctor::main_head_doctor()
{
	static head_doctor* head_d = new head_doctor();
	text* text_head_doct = new text();

	int key1, key2;
	do
	{
		system("cls");
		text_head_doct->main_head_d();
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{
				if (head_d->age != 0)
				{
					system("cls");
					cout << "Для начала произведите очистку данных" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					head_doctor::head_doctor();
					head_d->get_name();
					head_d->get_age();
					head_d->GetNumber();
					head_d->get_status();
					system("cls");
					cout << "Успешно" << endl;
					Sleep(1500);
				}
			}
			break;
		case'2':
			{
				if (head_d->age == 0)
				{
					system("cls");
					cout << "\aСначала создайте врача" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					do
					{
						system("cls");
						head_d->display_param();
						cout << "'ESC' - Назад" << endl;
						key2 = _getch();
						switch (key2)
						{
						}
					} while (key2 != 27);
					break;
				}
			}
			break;
		case'3':
			{
				if (head_d->age == 0)
				{
					system("cls");
					cout << "\aСтирать ещё нечего" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					system("cls");
					head_d->clean();
					cout << "Успешно" << endl;
					Sleep(1500);
				}
			}
			break;
		}
	} while (key1 != 27);
}

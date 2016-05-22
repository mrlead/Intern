#pragma once
#include "person.h"
#include "bro.h"
#include "cleaner.h"
#include "security.h"
#include <iostream>
#include "conio.h"
#include <Windows.h>
#include <locale.h>

#pragma warning(disable:4060)

/*Определение для person
------------------------
-----------------------*/

void person::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void person::rus_loc()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void person::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_female_staff_s.txt";
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
		int index = rand() % 11;
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

void person::get_status()
{
	const int LENGHT = 20;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_s.txt";
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

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void person::get_age()
{
	const int LENGHT = 5;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_s.txt";
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void person::display_param()
{
	cout << endl;
	cout << "ФИО: " << name << endl;
	cout << "Статус сотрудника: " << status << endl;
	cout << "Возраст сотрудника: " << age << endl;
	cout << "Должность: Медсестра" << endl;
	cout << endl;
}

/*Определение для bro
------------------------
-----------------------*/

void bro::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void bro::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_male_staff_m.txt";
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
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void bro::get_status()
{
	const int LENGHT = 15;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_m.txt";
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
		int index = rand() % 6;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void bro::get_age()
{
	const int LENGHT = 5;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_m.txt";
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
		/*num = strtod(str.c_str(), 0);*/
		str = "";
		coll.clear();


		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void bro::display_param()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << endl;
	cout << "ФИО: " << name << endl;
	cout << "Стастус сотрудника: " << status << endl;
	cout << "Возраст сотрудника: " << age << endl;
	cout << "Должность: Медбрат" << endl;
	cout << endl;
}

/*Определение для cleaner
------------------------
-----------------------*/

void cleaner::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void cleaner::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_female_staff_c.txt";
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
		int index = rand() % 11;
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

void cleaner::get_status()
{
	const int LENGHT = 20;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_c.txt";
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

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void cleaner::get_age()
{
	const int LENGHT = 36;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_c.txt";
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void cleaner::display_param()
{
	cout << endl;
	cout << "ФИО: " << name << endl;
	cout << "Статус сотрудника: " << status << endl;
	cout << "Возраст сотрудника: " << age << endl;
	cout << "Должность: Уборщица" << endl;
	cout << endl;
}

/*Определение для cleaner
------------------------
-----------------------*/

void security::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void security::rus_loc()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void security::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_male_staff_se.txt";
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
		int index = rand() % 11;
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

void security::get_status()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_se.txt";
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

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void security::get_age()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_se.txt";
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void security::display_param()
{
	cout << endl;
	cout << "ФИО: " << name << endl;
	cout << "Статус сотрудника: " << status << endl;
	cout << "Возраст сотрудника: " << age << endl;
	cout << "Должность: Охранник" << endl;
	cout << endl;
}

/*Создание меню для всего персонала
------------------------
-----------------------*/

void person::main_menu_staff()
{
	person* sister = new person();
	bro* medbro = new bro();
	cleaner* cleane = new cleaner();
	security* securit = new security();
	text show;
	int key1, key2, key3, key4;
	do
	{
		system("cls");
		show.main_staff();
		key1 = _getch();
		switch (key1)
		{
		case '1':
		{
			do
			{
				system("cls");
				show.menu_create_staff();
				key2 = _getch();
				//system("cls");
				switch (key2)
				{
					system("cls");
				case '1':
				{
					if (sister->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						person::person();
						sister->get_name();
						sister->get_status();
						sister->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '2':
				{
					if (medbro->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						bro::bro();
						medbro->get_name();
						medbro->get_status();
						medbro->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '3':
				{
					if (cleane->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						cleaner::cleaner();
						cleane->get_name();
						cleane->get_status();
						cleane->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '4':
				{
					if (securit->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						security::security();
						securit->get_name();
						securit->get_status();
						securit->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				}
			} while (key2 != 27);
			break;
		}

		case '2':
		{
			do
			{
				system("cls");
				sister->display_param();
				medbro->display_param();
				cleane->display_param();
				securit->display_param();
				key4 = _getch();
				switch (key4)
				{}
			} while (key4 != 27);
			break;
		}
		case '3':
		{
			do
			{
				system("cls");
			show.remove_staff();
			key3 = _getch();
			switch (key3)
			{
					case '1':
					{
						if (sister->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							sister->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
							break;
					}
					case '2':
					{
						if (medbro->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							medbro->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
						break;
					}
					case '3':
					{
						if (cleane->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							cleane->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
						break;
					}
					case '4':
					{
						if (securit->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							securit->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
						break;
					}
				} 
			} while (key3 != 27);
			break;
		}
		}
		}while (key1 != 27);
}

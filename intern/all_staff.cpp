#pragma once
#include "person.h"
#include "bro.h"
#include "cleaner.h"
#include "security.h"
#include <iostream>
#include <fstream>
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

void person::rename()
{
	cout << "Введите путь к фалу для имени" << endl;
	strcpy(file_name, null_str);
	cin >> file_name;
	/*cout << "Введите путь к файлу для возраста" << endl;
	cin >> file_age;
	cout << "Введите путь к файлу для статуса" << endl;
	cin >> file_status;*/
}

void person::get_name(string)
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char input[LENGHT];
	string str;
	FILE *fp;
		
	ifstream f(file_name);
	if (!f.good())
	{
		cout << "Файл не открыт" << endl;
	}
	else
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, file_name, "r");
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
		strtok(name, "\n");
		str = "";
		coll.clear();

		fclose(fp);
	}
}

void person::get_status()
{
	const int LENGHT = 20;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	file_status = "data_base/stat_staff_m.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(file_status);
	if (!f.good())
	{
		cout << "Файл не открыт" << endl;
	}
	else
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, file_status, "r");
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
		strtok(status, "\n");
		str = "";
		coll.clear();

		fclose(fp);
	}
}

void person::get_age()
{
	const int LENGHT = 5;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	file_age = "data_base/age_staff_m.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(file_age);
	if (!f.good())
	{
		cout << "Файл не открыт" << endl;
	}
	else
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, file_age, "r");
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
}

void person::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_per", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_per", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_per", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_per", "ini_base/menu_list_rus.ini") << endl;
	cout << endl;
	cout << GetIniString("1", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	cout << endl;
}

void person::save_origin()
{
	ofstream fout(fileout, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;
		Sleep(900);
	}
	else
	{
		fout << GetIniString("1", "answer_per", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_per", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_per", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_per", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("1", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

void person::save_private()
{
	ofstream fout(file_private, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;
		
	}
	else
	{
		fout << GetIniString("1", "answer_per", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_per", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_per", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_per", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("1", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
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

	ifstream f(filename);
	if (!f.good())
	{
		cout << "Файл не открыт" << endl;
	}
	else
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
		int index = 1 + rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");
		str = "";
		coll.clear();

		fclose(fp);
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

		ifstream f(filename);
		if (!f.good())
		{
			cout << "Файл не открыт" << endl;
		}
		else
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
		strtok(status, "\n");
		str = "";
		coll.clear();

		fclose(fp);
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

	ifstream f(filename);
	if (!f.good())
	{
		cout << "Файл не открыт" << endl;
	}
	else
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
		str = "";
		coll.clear();


		fclose(fp);
	}
}

void bro::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_bro", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_bro", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_bro", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_bro", "ini_base/menu_list_rus.ini") << endl;
	cout << endl;
	cout << GetIniString("2", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	cout << endl;
}

void bro::save_origin()
{
	ofstream fout(file_bro_o, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;

	}
	else
	{
		fout << GetIniString("1", "answer_bro", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_bro", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_bro", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_bro", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("2", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

void bro::save_private()
{
	ofstream fout(file_bro_p, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;

	}
	else
	{
		fout << GetIniString("1", "answer_bro", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_bro", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_bro", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_bro", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("2", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
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
		int index = rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");
		str = "";
		coll.clear();

		fclose(fp);
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
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		strtok(status, "\n");
		str = "";
		coll.clear();

		fclose(fp);
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
}

void cleaner::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_cle", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_cle", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_cle", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_cle", "ini_base/menu_list_rus.ini") << endl;
	cout << endl;
	cout << GetIniString("3", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	cout << endl;
}

void cleaner::save_origin()
{
	ofstream fout(file_cleaner_o, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;

	}
	else
	{
		fout << GetIniString("1", "answer_cle", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_cle", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_cle", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_cle", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("3", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

void cleaner::save_private()
{
	ofstream fout(file_cleaner_p, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;

	}
	else
	{
		fout << GetIniString("1", "answer_cle", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_cle", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_cle", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_cle", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("3", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
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

void security::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_male_staff_se.txt";
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
		int index = rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");
		str = "";
		coll.clear();

		fclose(fp);
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
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		strtok(status, "\n");
		str = "";
		coll.clear();

		fclose(fp);
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
}

void security::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_sec", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_sec", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_sec", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_sec", "ini_base/menu_list_rus.ini") << endl;
	cout << endl;
	cout << GetIniString("4", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	cout << endl;
}

void security::save_origin()
{
	ofstream fout(file_security_o, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;

	}
	else
	{
		fout << GetIniString("1", "answer_cle", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_cle", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_cle", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_cle", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("3", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

void security::save_private()
{
	ofstream fout(file_security_p, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		cout << "Файл поврежден" << endl;

	}
	else
	{
		fout << GetIniString("1", "answer_cle", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_cle", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_cle", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_cle", "ini_base/menu_list_rus.ini") << endl;
		fout << endl;
		fout << GetIniString("3", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

/*Создание меню для всего персонала
------------------------
-----------------------*/

void person::main_menu_staff()
{
	static person* sister = new person();
	static bro* medbro = new bro();
	static cleaner* cleane = new cleaner();
	static security* securit = new security();
	text show;
	int key1, key2, key3, key4;
	do
	{
		setlocale(0, "");
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
						sister->get_name(name);
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
					sister->save_origin();
					medbro->display_param();
					medbro->save_origin();
					cleane->display_param();
					cleane->save_origin();
					securit->display_param();
					securit->save_origin();
					key4 = _getch();
					switch (key4)
					{
					}
				} while (key4 != 27);
		}
			break;
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

void person::main_private_staff()
{
	static person* sis = new person();
	static bro* med = new bro();
	static cleaner* cle = new cleaner();
	static security* sec = new security();
	text show;
	int key1, key2, key3, key4;
	do
	{
		setlocale(0, "");
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
				switch (key2)
				{
					system("cls");
				case '1':
				{
					if (sis->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						person::person();
						sis->get_name(name);
						sis->get_status();
						sis->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '2':
				{
					if (med->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						bro::bro();
						med->get_name();
						med->get_status();
						med->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '3':
				{
					if (cle->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						cleaner::cleaner();
						cle->get_name();
						cle->get_status();
						cle->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '4':
				{
					if (sec->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						security::security();
						sec->get_name();
						sec->get_status();
						sec->get_age();
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
				sis->display_param();
				sis->save_private();
				med->display_param();
				med->save_private();
				cle->display_param();
				cle->save_private();
				sec->display_param();
				sec->save_private();
				key4 = _getch();
				switch (key4)
				{
				}
			} while (key4 != 27);
		}
		break;
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
					if (sis->age == 0)
					{
						system("cls");
						cout << "Увольнять ещё некого!" << endl;
						Sleep(1500);
						system("cls");
					}
					else
					{
						system("cls");
						sis->clean();
						cout << "Успешно" << endl;
						Sleep(1500);
					}
					break;
				}
				case '2':
				{
					if (med->age == 0)
					{
						system("cls");
						cout << "Увольнять ещё некого!" << endl;
						Sleep(1500);
						system("cls");
					}
					else
					{
						system("cls");
						med->clean();
						cout << "Успешно" << endl;
						Sleep(1500);
					}
					break;
				}
				case '3':
				{
					if (cle->age == 0)
					{
						system("cls");
						cout << "Увольнять ещё некого!" << endl;
						Sleep(1500);
						system("cls");
					}
					else
					{
						system("cls");
						cle->clean();
						cout << "Успешно" << endl;
						Sleep(1500);
					}
					break;
				}
				case '4':
				{
					if (sec->age == 0)
					{
						system("cls");
						cout << "Увольнять ещё некого!" << endl;
						Sleep(1500);
						system("cls");
					}
					else
					{
						system("cls");
						sec->clean();
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
	} while (key1 != 27);
}

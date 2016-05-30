#include "head_doctor.h"
#include "lang.h"
#include <iostream>
#include "conio.h"
#include <Windows.h>
#include <locale.h>
#include <fstream>

lang* l_head = new lang();

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

	ifstream f(filename);
	if (!f.good())
	{
		if (l_head->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_head->rus == 0)
			{
				cout << "File not open" << endl;
			}
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

		fclose(fp);
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

	ifstream f(filename);
	if (!f.good())
	{
		if (l_head->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_head->rus == 0)
			{
				cout << "File not open" << endl;
			}
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
		int index = rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "'\n'");

		fclose(fp);
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

	ifstream f(filename);
	if (!f.good())
	{
		if (l_head->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_head->rus == 0)
			{
				cout << "File not open" << endl;
			}
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
		str = "";
		coll.clear();
		strtok(status, "'\n'");

		fclose(fp);
	}
}

void head_doctor::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_head", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_head", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_head", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_head", "ini_base/menu_list_rus.ini") << num << endl;
	cout << endl;
	cout << GetIniString("6", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	cout << endl;
}

void head_doctor::display_eng()
{
	cout << endl;
	cout << GetIniString("1", "answer_head", "ini_base/menu_list_eng.ini") << name << endl;
	cout << GetIniString("2", "answer_head", "ini_base/menu_list_eng.ini") << status << endl;
	cout << GetIniString("3", "answer_head", "ini_base/menu_list_eng.ini") << age << endl;
	cout << GetIniString("4", "answer_head", "ini_base/menu_list_eng.ini") << num << endl;
	cout << endl;
	cout << GetIniString("6", "objects", "ini_base/menu_list_eng.ini") << count << endl;
	cout << endl;
}

void head_doctor::save_origin()
{
	ofstream fout(file_head_o, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		if (l_head->rus == 1)
		{
			cout << "Файл повреждён" << endl;
		}
		else
			if (l_head->rus == 0)
			{
				cout << "Bad file" << endl;
			}
	}
	else
	{
		fout << GetIniString("1", "answer_head", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_head", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_head", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_head", "ini_base/menu_list_rus.ini") << num << endl;
		fout << endl;
		fout << GetIniString("6", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

void head_doctor::main_head_doctor()
{
	static head_doctor* head_d = new head_doctor();
	text* text_head_doct = new text();

	l_head->check();

	int key1, key2;
	do
	{
		system("cls");
		l_head->main_head(l_head);
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{
				setlocale(0, "");
				if (head_d->age != 0)
				{
					if (l_head->rus == 1)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(1500);
					}
					else
						if (l_head->rus == 0)
						{
							cout << "To start make a dismissal" << endl;
							Sleep(1500);
						}
				}
				else
				{
					head_doctor::head_doctor();
					head_d->get_name();
					head_d->get_age();
					head_d->GetNumber();
					head_d->get_status();
					system("cls");
					if (l_head->rus == 1)
					{
						cout << "Успешно" << endl;
						Sleep(1500);
					}
					else
						if (l_head->rus == 0)
						{
							cout << "Successfully" << endl;
							Sleep(1500);
						}
				}
			}
			l_head->check();
			break;
		case'2':
			{
				if (head_d->age == 0)
				{
					if (l_head->rus == 1)
					{
						system("cls");
						cout << "Сначала создайте доктора" << endl;
						Sleep(1500);
					}
					else
						if (l_head->rus == 0)
						{
							system("cls");
							cout << "First, create a doctor" << endl;
							Sleep(1500);
						}
				}
				else
				{
					if (l_head->rus == 1)
					{
						system("cls");
						head_d->display_param();
						head_d->save_origin();
						_getch();
					}
					else
						if (l_head->rus == 0)
						{
							system("cls");
							head_d->display_eng();
							head_d->save_origin();
							_getch();
						}
				}
			}
			l_head->check();
			break;
		case'3':
			{
				if (head_d->age == 0)
				{
					if (l_head->rus == 1)
					{
						cout << "Увольнять ещё некого!" << endl;
						Sleep(1500);
					}
					else
						if (l_head->rus == 0)
						{
							cout << "Dismiss more certain!" << endl;
							Sleep(1500);
						}
				}
				else
				{
					if (l_head->rus == 1)
					{
						cout << "Успешно" << endl;
						Sleep(1500);
					}
					else
						if (l_head->rus == 0)
						{
							cout << "Successfully" << endl;
							Sleep(1500);
						}
				}
			}
			l_head->check();
			break;
		}
	} while (key1 != 27);
}

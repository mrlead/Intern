#pragma once
#include "patient.h"
#include "lang.h"
#include <fstream>

lang* l_pat = new lang();

void patient::clean()
{
	n = NULL;
	age = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
	strcpy(disease, null_str);
	strcpy(ag, null_str);
}

void patient::get_name()
{
	//set_name
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/name_pat.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_pat->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_pat->rus == 0)
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
		int index = 1 + rand() % 23;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");

		fclose(fp);
	}
}

void patient::get_age()
{
	//set_age
	const int LENGHT = 36;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_pat.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_pat->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_pat->rus == 0)
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
		int index = 1 + rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);

		fclose(fp);
	}
}
void patient::get_disease()
{
	//set_disease
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/disease.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_pat->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_pat->rus == 0)
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
		int index = 1 + rand() % 9;
		str = coll[index];
		disease = new char[str.length() + 1];
		strcpy(disease, str.c_str());
		strtok(disease, "\n");

		fclose(fp);
	}
}
void patient::get_place()
{
	//set_place
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/place_pat.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_pat->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_pat->rus == 0)
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
		int index = 1 + rand() % 4;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());
		strtok(place, "\n");

		fclose(fp);
	}
}

void patient::display_param()
{
	cout << GetIniString("1", "answer_patient", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_patient", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("3", "answer_patient", "ini_base/menu_list_rus.ini") << place << endl;
	cout << endl;
	cout << GetIniString("12", "objects", "ini_base/menu_list_rus.ini") << count << endl;
}

void patient::display_eng()
{
	cout << GetIniString("1", "answer_patient", "ini_base/menu_list_eng.ini") << name << endl;
	cout << GetIniString("2", "answer_patient", "ini_base/menu_list_eng.ini") << age << endl;
	cout << GetIniString("3", "answer_patient", "ini_base/menu_list_eng.ini") << place << endl;
	cout << endl;
	cout << GetIniString("12", "objects", "ini_base/menu_list_eng.ini") << count << endl;
}

void patient::save()
{
	ofstream fout(file_pat, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		if (l_pat->rus == 1)
		{
			cout << "Файл повреждён" << endl;
		}
		else
			if (l_pat->rus == 0)
			{
				cout << "Bad file" << endl;
			}
	}
	else
	{
		fout << GetIniString("1", "answer_patient", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_patient", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("3", "answer_patient", "ini_base/menu_list_rus.ini") << place << endl;
		fout << endl;
		fout << GetIniString("12", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

static patient* pat = new patient();

void patient::main_menu_pat()
{
	
	static doctor* health = new doctor();
	text* text_pat = new text();

	l_pat->check();

	int key1;
	do
	{
		system("cls");
		l_pat->main_pat(l_pat);
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{
				setlocale(0, "");
				if (pat->age != 0)
				{
					if (l_pat->rus == 1)
					{
						system("cls");
						cout << "\aТеперь осмотрите пациента" << endl;
						Sleep(900);
						system("cls");
					}
					else
						if (l_pat->rus == 0)
						{
							system("cls");
							cout << "\aNow examine the patient" << endl;
							Sleep(900);
							system("cls");
						}
				}
				else
				{
					patient::patient();
					pat->get_name();
					pat->get_age();
					pat->get_place();
				}
			}
			l_pat->check();
			break;
		case'2':
			{
				if (pat->age == 0)
				{
					if (l_pat->rus == 1)
					{
						system("cls");
						cout << "\aДля начала впустите пациента" << endl;
						Sleep(1500);
						system("cls");
					}
					else
						if (l_pat->rus == 0)
						{
							system("cls");
							cout << "\aTo begin with let the patient" << endl;
							Sleep(1500);
						}
				}
				else
				{
					if (l_pat->rus == 1)
					{
						system("cls");
						pat->display_param();
						pat->save();
						_getch();
					}
					else
						if (l_pat->rus == 0)
						{
							system("cls");
							pat->display_eng();
							pat->save();
							_getch();
						}
				}
			}
			l_pat->check();
			break;
		case'3':
			{	
					system("cls");
					health->Heal();
					_getch();
					n = 1;
			}
			l_pat->check();
			break;
		case'4':
			{
				if (pat->n != 0)
				{
					if (l_pat->rus == 1)
					{
						system("cls");
						cout << "\aТеперь осмотрите пациента" << endl;
						Sleep(900);
						system("cls");
					}
					else
						if (l_pat->rus == 0)
						{
							system("cls");
							cout << "\aNow examine the patient" << endl;
							Sleep(900);
							system("cls");
						}
				}
				else
				{
					patient::patient();
					pat->get_name();
					pat->get_age();
					pat->get_place();
				}
				
			}
			l_pat->check();
			break;
		}
	} while (key1 != 27);
}
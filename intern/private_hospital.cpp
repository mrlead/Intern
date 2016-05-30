#pragma once
#include "private_hospital.h"
#include "head_private_doctor.h"
#include "private_doctor.h"
#include "person.h"
#include "lang.h"
#include <fstream>

lang* l_pr = new lang();

void private_hospital::clean()
{
	number = NULL;
	cost = NULL;
	vip_room = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
	strcpy(number_s, null_str);
}

void private_hospital::get_name()
{
	const int LENGHT = 15;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/name_hosp.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_pr->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_pr->rus == 0)
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
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");

		fclose(fp);
	}
}

void private_hospital::get_number()
{
	do
	{
		while (true)
		{
			cout << endl;
			if (l_pr->rus == 1)
			{
				cout << "Введите номер больницы" << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Enter hospital number" << endl;
				}
			cin >> number;
			if (cin.peek() == '\n')
			{
				cin.get();
				break;
			}
			else
			{
				if (l_pr->rus == 1)
				{
					cout << "Пожалуйста введите число" << endl;
				}
				else
					if (l_pr->rus == 0)
					{
						cout << "Please enter the number" << endl;
					}
				cin.clear();
				while (cin.get() != '\n')
				{
				}
			}
		}
		if (number > 0 && number <= 100)
		{
			if (l_pr->rus == 1)
			{
				cout << "Успешно" << endl;
				Sleep(1500);
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Successfully" << endl;
					Sleep(1500);
				}
		}
		else
		{
			if (l_pr->rus == 1)
			{
				cout << "Простите, вы ввели некорректные данные" << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Sorry , you have entered incorrect data" << endl;
				}
		}
	} while (!(number > 0 && number <= 100));
}

void private_hospital::get_cost()
{
	do
	{
		while (true)
		{
			cout << endl;
			if (l_pr->rus == 1)
			{
				cout << "Введите цену на вип-палату: " << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Enter cost for VIP - chambers: " << endl;
				}
			cin >> cost;
			if (cin.peek() == '\n')
			{
				cin.get();
				break;
			}
			else
			{
				if (l_pr->rus == 1)
				{
					cout << "Пожалуйста введите число" << endl;
				}
				else
					if (l_pr->rus == 0)
					{
						cout << "Please enter the number" << endl;
					}
				cin.clear();
				while (cin.get() != '\n')
				{
				}
			}
		}
		if (cost > 0 && cost <= 15000)
		{
			if (l_pr->rus == 1)
			{
				cout << "Успешно" << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Successfully" << endl;
				}
		}
		else
		{
			if (l_pr->rus == 1)
			{
				cout << "Простите, вы ввели некорректные данные" << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Sorry , you have entered incorrect data" << endl;
				}
		}
	} while (!(cost > 0 && cost <= 15000));
}

void private_hospital::get_place()
{
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/place_hosp.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_pr->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_pr->rus == 0)
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
		int index = 1 + rand() % 2;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());
		strtok(place, "\n");

		fclose(fp);
	}
}

void private_hospital::get_room()
{
	do
	{
		while (true)
		{
			cout << endl;
			if (l_pr->rus == 1)
			{
				cout << "Введите количество палат: " << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Enter the number of chambers: " << endl;
				}
			cin >> vip_room;
			if (cin.peek() == '\n')
			{
				cin.get();
				break;
			}
			else
			{
				if (l_pr->rus == 1)
				{
					cout << "Пожалуйста введите число" << endl;
				}
				else
					if (l_pr->rus == 0)
					{
						cout << "Please enter the number" << endl;
					}
				cin.clear();
				while (cin.get() != '\n')
				{
				}
			}
		}
		if (vip_room > 0 && vip_room <= 100)
		{
			if (l_pr->rus == 1)
			{
				cout << "Успешно" << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Successfully" << endl;
				}
		}
		else
		{
			if (l_pr->rus == 1)
			{
				cout << "Простите, вы ввели некорректные данные" << endl;
			}
			else
				if (l_pr->rus == 0)
				{
					cout << "Sorry , you have entered incorrect data" << endl;
				}
		}
	} while (!(vip_room > 0 && vip_room <= 100));
}

void private_hospital::get_company()
{
	//set_company
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/name_corp.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_pr->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_pr->rus == 0)
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
		int index = 1 + rand() % 5;
		str = coll[index];
		company = new char[str.length() + 1];
		strcpy(company, str.c_str());

		fclose(fp);
	}
}

void private_hospital::display_param()
{
	cout << GetIniString("1", "answer_p_hosp", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_p_hosp", "ini_base/menu_list_rus.ini") << number << endl;
	cout << GetIniString("3", "answer_p_hosp", "ini_base/menu_list_rus.ini") << place << endl;
	cout << GetIniString("4", "answer_p_hosp", "ini_base/menu_list_rus.ini") << company<< endl;
	cout << GetIniString("5", "answer_p_hosp", "ini_base/menu_list_rus.ini") << cost << endl;
	cout << GetIniString("6", "answer_p_hosp", "ini_base/menu_list_rus.ini") << vip_room << endl;
	cout << endl;
	cout << GetIniString("8", "objects", "ini_base/menu_list_rus.ini") << count << endl;
}

void private_hospital::display_eng()
{
	cout << GetIniString("1", "answer_p_hosp", "ini_base/menu_list_eng.ini") << name << endl;
	cout << GetIniString("2", "answer_p_hosp", "ini_base/menu_list_eng.ini") << number << endl;
	cout << GetIniString("3", "answer_p_hosp", "ini_base/menu_list_eng.ini") << place << endl;
	cout << GetIniString("4", "answer_p_hosp", "ini_base/menu_list_eng.ini") << company << endl;
	cout << GetIniString("5", "answer_p_hosp", "ini_base/menu_list_eng.ini") << cost << endl;
	cout << GetIniString("6", "answer_p_hosp", "ini_base/menu_list_eng.ini") << vip_room << endl;
	cout << endl;
	cout << GetIniString("8", "objects", "ini_base/menu_list_eng.ini") << count << endl;
}


void private_hospital::save_private()
{
	ofstream fout(file_hospital_p, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		if (l_pr->rus == 1)
		{
			cout << "Файл повреждён" << endl;
		}
		else
			if (l_pr->rus == 0)
			{
				cout << "Bad file" << endl;
			}
	}
	else
	{
		fout << GetIniString("1", "answer_p_hosp", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_p_hosp", "ini_base/menu_list_rus.ini") << number << endl;
		fout << GetIniString("3", "answer_p_hosp", "ini_base/menu_list_rus.ini") << place << endl;
		fout << GetIniString("4", "answer_p_hosp", "ini_base/menu_list_rus.ini") << company << endl;
		fout << GetIniString("5", "answer_p_hosp", "ini_base/menu_list_rus.ini") << cost << endl;
		fout << GetIniString("6", "answer_p_hosp", "ini_base/menu_list_rus.ini") << vip_room << endl;
		fout << endl;
		fout << GetIniString("8", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

void private_hospital::main_menu_private()
{
	static private_hospital* p_hosp = new private_hospital();
	text* text_p_hosp = new text();

	l_pr->check();

	int key1;
	do
	{
		system("cls");
		l_pr->main_pr_hosp(l_pr);
		key1 = _getch();
		switch (key1)
		{
		case '1':
		{
			setlocale(0, "");
			if (p_hosp->number != 0)
			{
				if (l_pr->rus == 1)
				{
					cout << "Сначала сотрите данные" << endl;
					Sleep(1500);
					system("cls");
				}
				else
					if (l_pr->rus == 0)
					{
						cout << "First, erase data" << endl;
						Sleep(1500);
						system("cls");
					}
			}
			else
			{
				private_hospital::private_hospital();
				p_hosp->get_name();
				p_hosp->get_place();
				p_hosp->get_company();
				p_hosp->get_cost();
				p_hosp->get_room();
				p_hosp->get_number();
			}
			l_pr->check();
			break;
		case'2':
		{
			if (l_pr->rus == 1)
			{
				system("cls");
				p_hosp->display_param();
				p_hosp->save_private();
				_getch();
			}
			else
				if (l_pr->rus == 0)
				{
					system("cls");
					p_hosp->display_eng();
					p_hosp->save_private();
					_getch();
				}
		}
		l_pr->check();
		break;
		case'3':
		{
			if (p_hosp->number == 0)
			{
				if (l_pr->rus == 1)
				{
					system("cls");
					cout << "Стирать ещё нечего" << endl;
					Sleep(1500);
					system("cls");
				}
				else
					if (l_pr->rus == 0)
					{
						system("cls");
						cout << "Wash nothing more" << endl;
						Sleep(1500);
						system("cls");
					}
			}
			else
			{
				system("cls");
				p_hosp->clean();
				if (l_pr->rus == 1)
				{
					cout << "Успешно" << endl;
					Sleep(1500);
				}
				else
					if (l_pr->rus == 0)
					{
						cout << "Successfully" << endl;
						Sleep(1500);
					}
			}
		}
		l_pr->check();
		break;
		case'4':
		{
			system("cls");
			person* run_p = new person();
			run_p->main_private_staff();
		}
		l_pr->check();
		break;
		case'5':
		{
			system("cls");
			head_private_doctor run_head;
			run_head.main_p_head();
		}
		l_pr->check();
		break;
		case'6':
			{
				system("cls");
				private_doctor run_private;
				run_private.main_menu_pr_doctor();
			}
			l_pr->check();
			break;
		}
		l_pr->check();
		break;
		}
	} while (key1 != 27);
}
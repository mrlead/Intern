#pragma once
#include "hospital.h"
#include "person.h"
#include "head_doctor.h"

void hospital::clean()
{
	number = NULL;
	cost = NULL;
	room = NULL;
	vip_room = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
	strcpy(number_s, null_str);
}

void hospital::get_name()
{
	const int LENGHT = 15;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/name_hosp.txt";
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
		int index = rand() % 4;
		str = coll[index];
		name_hosp = new char[str.length() + 1];
		strcpy(name_hosp, str.c_str());
		//strcpy(name_hosp, name);

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
		cout << endl;
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
	char *filename = "data_base/place_hosp.txt";
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
		if (_getch() == 'y')
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
	} while (_getch() == 'n');
	cout << "Успешно" << endl;
}

void hospital::display_param()
{
	cout << "Больница: " << name_hosp << endl;
	cout << "Номер: " << number << endl;
	cout << "Адрес: " << place << endl;
	cout << "Цена за вип-палату за сутки: " << cost << endl;
	cout << "Количество палат: " << room << "	Вип-палат: " << vip_room << endl;
}

void hospital::main_menu_hospital()
{
	static hospital* medical = new hospital();
	text* text_hosp = new text();

	int key1, key2;
	do
	{
		system("cls");
		text_hosp->main_hospital();
		key1 = _getch();
		switch (key1)
		{
		case '1':
			{
				if (medical->number != 0)
				{
					cout << "Для начала произведите очистку данных" << endl;
					Sleep(900);
					system("cls");
				}
				else
				{
					hospital::hospital();
					medical->get_name();
					medical->get_place();
					medical->get_place();
					medical->get_cost();
					medical->get_room();
					medical->get_number();
				}
				break;
			}
		case'2':
			{
				do
				{
					system("cls");
					medical->display_param();
					cout << "'ESC' - Назад" << endl;
					key2 = _getch();
					switch (key2)
					{}
				} while (key2 != 27);
				break;
			}
		case'3':
			{
				if (medical->number == 0)
				{
					system("cls");
					cout << "Стирать ещё нечего" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					system("cls");
					medical->clean();
					cout << "Успешно" << endl;
					Sleep(1500);
				}
				break;
			}
		case'4':
			{
				system("cls");
				person run;
				run.main_menu_staff();
			}
			break;
		case'5':
			{
				system("cls");
				head_doctor run;
				run.main_head_doctor();
			}
			break;
		}
	} while (key1 != 27);
}

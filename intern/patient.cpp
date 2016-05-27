#include "patient.h"

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
		int index = 1 + rand() % 23;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
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
		int index = 1 + rand() % 35;
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
		int index = 1 + rand() % 9;
		str = coll[index];
		disease = new char[str.length() + 1];
		strcpy(disease, str.c_str());
		strtok(disease, "\n");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
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
		int index = 1 + rand() % 4;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());
		strtok(place, "\n");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void patient::display_param()
{
	cout << GetIniString("1", "answer_patient", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_patient", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("3", "answer_patient", "ini_base/menu_list_rus.ini") << place << endl;
}
static patient* pat = new patient();
void patient::main_menu_pat()
{
	
	static doctor* health = new doctor();
	text* text_pat = new text();

	int key1, key2, key3;
	do
	{
		system("cls");
		text_pat->main_patient();
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{
				setlocale(0, "");
				if (pat->age != 0)
				{
					system("cls");
					cout << "\aТеперь осмотрите пациента" << endl;
					Sleep(900);
					system("cls");
				}
				else
				{
					patient::patient();
					pat->get_name();
					pat->get_age();
					pat->get_place();
				}
			}
			break;
		case'2':
			{
				if (pat->age == 0)
				{
					system("cls");
					cout << "\aДля начала впустите пациента" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					do
					{
						system("cls");
						pat->display_param();
						cout << "'ESC' - Назад" << endl;
						key2 = _getch();
						switch (key2)
						{
						}
					} while (key2 != 27);
				}
			}
			break;
		case'3':
			{	
				do
				{
					system("cls");
					health->Heal();
					n = 1;
					cout << "'ESC' - Назад" << endl;
					key3 = _getch();
					switch (key3)
					{
					}
				} while (key3 != 27);
			}
			break;
		case'4':
			{
				if (pat->n != 0)
				{
					system("cls");
					cout << "\aТеперь осмотрите пациента" << endl;
					Sleep(900);
					system("cls");
				}
				else
				{
					patient::patient();
					pat->get_name();
					pat->get_age();
					pat->get_place();
				}
				
			}
		}
	} while (key1 != 27);
}
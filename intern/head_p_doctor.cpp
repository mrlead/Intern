#include "head_private_doctor.h"

void head_private_doctor::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(ag, null_str);
	strcpy(num, null_str);
	strcpy(status, null_str);
}

void head_private_doctor::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/doct_name.txt";
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
		int index = 1 + rand() % 11;
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

void head_private_doctor::get_age()
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

void head_private_doctor::number()
{
			const int LENGHT = 30;
			vector<string> coll;
			vector<string>::iterator it_deep, it_submit, pos;
			char *filename = "data_base/doct_num.txt";
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
				int index = 1 + rand() % 40;
				str = coll[index];
				num = new char[str.length() + 1];
				strcpy(num, str.c_str());

				fclose(fp);
			}
			catch (bad_alloc)
			{
				cout << "Не удалось выделить память под коллекцию" << endl;
			}
}

void head_private_doctor::get_status()
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

void head_private_doctor::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_p_head", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_p_head", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_p_head", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_p_head", "ini_base/menu_list_rus.ini") << num << endl;
	cout << endl;
}

void head_private_doctor::main_p_head()
{
	static head_private_doctor* head_P = new head_private_doctor();
	text* text_p_head_doct = new text();

	int key1, key2;
	do
	{
		setlocale(0, "");
		system("cls");
		text_p_head_doct->main_p_head();
		key1 = _getch();
		switch (key1)
		{
		case'1':
		{
			if (head_P->age != 0)
			{
				system("cls");
				cout << "Для начала произведите очистку данных" << endl;
				Sleep(1500);
				system("cls");
			}
			else
			{
				head_private_doctor::head_private_doctor();
				head_P->get_name();
				head_P->get_age();
				head_P->number();
				head_P->get_status();
				system("cls");
				cout << "Успешно" << endl;
				Sleep(1500);
			}
		}
		break;
		case'2':
		{
			if (head_P->age == 0)
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
					head_P->display_param();
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
			if (head_P->age == 0)
			{
				system("cls");
				cout << "\aСтирать ещё нечего" << endl;
				Sleep(1500);
				system("cls");
			}
			else
			{
				system("cls");
				head_P->clean();
				cout << "Успешно" << endl;
				Sleep(1500);
			}
		}
		break;
		}
	} while (key1 != 27);
}
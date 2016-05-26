#pragma once
#include "private_hospital.h"
#include "head_private_doctor.h"
#include "private_doctor.h"
#include "Errors_c.h"
#include "person.h"

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

	try
	{
		//������ ���������� ����� � ���������
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//������ ������ �� ����� ���������
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//��������� ������
		srand(time(NULL));
		int index = 1 + rand() % 4;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");

		fclose(fp);
	}
	catch (Errors_s)
	{}
}

void private_hospital::get_number()
{
	do
	{
		cout << "������� ����� ��������: ";
		cin >> number;
		if (number > 0 && number <= 100)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << "��������, �� ����� ����������� ������" << endl;
		}
	} while (!(number > 0 && number <= 100));
}

void private_hospital::get_cost()
{
	do
	{
		cout << "������� ���� �� ���-������: ";
		cin >> cost;
		if (cost > 0 && cost <= 15000)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << "��������, �� ����� ����������� ������" << endl;
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

	try
	{
		//������ ���������� ����� � ���������
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//������ ������ �� ����� ���������
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//��������� ������
		srand(time(NULL));
		int index = 1 + rand() % 2;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());
		strtok(place, "\n");

		fclose(fp);
	}
	catch (Errors_s)
	{}
}

void private_hospital::get_room()
{
	do
	{
		cout << "������� ���������� ���-�����: ";
		cin >> vip_room;
		if (vip_room > 0 && vip_room <= 100)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << "��������, �� ����� ����������� ������" << endl;
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

	try
	{
		//������ ���������� ����� � ���������
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//������ ������ �� ����� ���������
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//��������� ������
		srand(time(NULL));
		int index = 1 + rand() % 5;
		str = coll[index];
		company = new char[str.length() + 1];
		strcpy(company, str.c_str());

		fclose(fp);
	}
	catch (Errors_s)
	{}
}

void private_hospital::display_param()
{
	cout << GetIniString("1", "answer_p_hosp", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_p_hosp", "ini_base/menu_list_rus.ini") << number << endl;
	cout << GetIniString("3", "answer_p_hosp", "ini_base/menu_list_rus.ini") << place << endl;
	cout << GetIniString("4", "answer_p_hosp", "ini_base/menu_list_rus.ini") << company<< endl;
	cout << GetIniString("5", "answer_p_hosp", "ini_base/menu_list_rus.ini") << cost << endl;
	cout << GetIniString("6", "answer_p_hosp", "ini_base/menu_list_rus.ini") << vip_room << endl;
}

void private_hospital::main_menu_private()
{
	static private_hospital* p_hosp = new private_hospital();
	text* text_p_hosp = new text();

	int key1, key2;
	do
	{
		system("cls");
		text_p_hosp->main_p_hospital();
		key1 = _getch();
		switch (key1)
		{
		case '1':
		{
			if (p_hosp->number != 0)
			{
				cout << "��� ������ ����������� ������� ������" << endl;
				Sleep(900);
				system("cls");
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
			break;
		case'2':
		{
			do
			{
				system("cls");
				p_hosp->display_param();
				cout << "'ESC' - �����" << endl;
				key2 = _getch();
				switch (key2)
				{
				}
			} while (key2 != 27);
			break;
		}
		case'3':
		{
			if (p_hosp->number == 0)
			{
				system("cls");
				cout << "������� ��� ������" << endl;
				Sleep(1500);
				system("cls");
			}
			else
			{
				system("cls");
				p_hosp->clean();
				cout << "�������" << endl;
				Sleep(1500);
			}
		}
		break;
		case'4':
		{
			system("cls");
			person* run_p = new person();
			run_p->main_private_staff();
		}
		break;
		case'5':
		{
			system("cls");
			head_private_doctor run_head;
			run_head.main_p_head();
		}
		break;
		case'6':
			{
				system("cls");
				private_doctor run_private;
				run_private.main_menu_pr_doctor();
			}
			break;
		}
		}
	} while (key1 != 27);
}
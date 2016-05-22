#pragma once
#include "hospital.h"
#include "person.h"

void hospital::clean()
{
	number = NULL;
	cost = NULL;
	room = NULL;
	vip_room = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
	strcpy(head_docto, null_str);
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
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void hospital::get_number()
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

void hospital::get_cost()
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
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void hospital::get_room()
{
	do
	{
		cout << "������� ���������� �����: ";
		cin >> room;
		if (room > 0 && room <= 100)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << "��������, �� ����� ����������� ������" << endl;
		}
	} while (!(room > 0 && room <= 100));
	char yn;
	do
	{
		cout << "�� ������ ���������� ���������� ���-����� � ������� �������(y/n)? ";
		cin >> yn;
		if (yn == 'y')
		{
			vip_room = room;
		}
		else
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
	} while (yn == 'n');
}

void hospital::get_head_doctor()
{
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/name_hd.txt";
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
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		head_docto = new char[str.length() + 1];
		strcpy(head_docto, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void hospital::display_param()
{
	cout << "��������: " << name << endl;
	cout << "�����: " << number << endl;
	cout << "�����: " << place << endl;
	cout << "������� ����: " << head_docto << endl;
	cout << "���� �� ���-������ �� �����" << cost << endl;
	cout << "���������� �����: " << room << "	���-�����: " << vip_room << endl;
}

void hospital::main_menu_hospital()
{
	hospital* medical = new hospital();
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
					cout << "��� ������ ����������� ������� ������" << endl;
					Sleep(900);
					system("cls");
				}
				else
				{
					hospital::hospital();
					medical->get_name();
					medical->get_place();
					medical->get_place();
					medical->get_head_doctor();
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
					cout << "������� ��� ������" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					system("cls");
					medical->clean();
					cout << "�������" << endl;
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
		}
	} while (key1 != 27);
}
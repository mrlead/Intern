#pragma once
#include "hospital.h"
#include "person.h"
#include "head_doctor.h"
#include "doctor.h"
#include "Errors_c.h"

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
		int index = rand() % 4;
		str = coll[index];
		name_hosp = new char[str.length() + 1];
		strcpy(name_hosp, str.c_str());
		strtok(name_hosp, "\n");

		fclose(fp);
	}
	catch (Errors_s)
	{}
}

void hospital::get_number()
{
	do
	{
	while (true)
	{
		cout << endl;
		cout << "������� ����� ��������: ";
		cin >> number;
		if (cin.peek() == '\n')
		{
			cin.get();
			break;
		}
		else
		{
			cout << "����������, ������� �����" << endl;
			cin.clear();
			while(cin.get() != '\n')
			{}
		}
	}
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
		while (true)
		{
			cout << endl;
			cout << "������� ���� �� ���-������: ";
			cin >> cost;
			if (cin.peek() == '\n')
			{
				cin.get();
				break;
			}
			else
			{
				cout << "����������, ������� �����" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
				}
			}
		}
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

void hospital::get_room()
{
	do
	{
		while (true)
		{
			cout << endl;
			cout << "������� ���������� �����: ";
			cin >> room;
			if (cin.peek() == '\n')
			{
				cin.get();
				break;
			}
			else
			{
				cout << "����������, ������� �����" << endl;
				cin.clear();
				while (cin.get() != '\n')
				{
				}
			}
		}
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
		if (_getch() == 'y')
		{
			vip_room = room;
			
		}
		else
		{
			do
			{
				while (true)
				{
					cout << endl;
					cout << "������� ���������� ���-�����: ";
					cin >> vip_room;
					if (cin.peek() == '\n')
					{
						cin.get();
						break;
					}
					else
					{
						cout << "����������, ������� �����" << endl;
						cin.clear();
						while (cin.get() != '\n')
						{
						}
					}
				}

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
	} while (_getch() == 'n');
	cout << "�������" << endl;
}

void hospital::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_hosp", "ini_base/menu_list_rus.ini") << name_hosp << endl;
	cout << GetIniString("2", "answer_hosp", "ini_base/menu_list_rus.ini") << number << endl;
	cout << GetIniString("3", "answer_hosp", "ini_base/menu_list_rus.ini") << place << endl;
	cout << GetIniString("4", "answer_hosp", "ini_base/menu_list_rus.ini") << cost << endl;
	cout << GetIniString("5", "answer_hosp", "ini_base/menu_list_rus.ini") << room << GetIniString("6", "answer_hosp", "ini_base/menu_list_rus.ini") << vip_room << endl;
	cout << endl;
	cout << GetIniString("7", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	cout << endl;
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
				setlocale(0, "");
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
					cout << "'ESC' - �����" << endl;
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
			}
			break;
		case'4':
			{
				system("cls");
				person* run = new person();;
				run->main_menu_staff();
			}
			break;
		case'5':
			{
				system("cls");
				head_doctor run;
				run.main_head_doctor();
			}
			break;
		case'6':
			{
				system("cls");
				doctor run;
				run.main_menu_doct();
			}
			break;
		}
	} while (key1 != 27);
}

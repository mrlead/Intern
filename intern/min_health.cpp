#pragma once
#include "min_health.h"
#include "hospital.h"
#include <iostream>
#include "conio.h"
#include <Windows.h>

void min_health::clean()
{
	r = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
}

void min_health::get_name()
{
	const int LENGHT = 60;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/min_data.txt";
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
		int index = rand() % 5;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void min_health::get_place()
{
	const int LENGHT = 40;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/place_min.txt";
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
		int index = rand() % 2;
		str = coll[index];
		place = new char[str.length() + 1];
		strcpy(place, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
	r = 1;
}

void min_health::display_param()
{
	cout << "��������: " << name << endl;
	cout << "�����: " << place << endl;
}

void min_health::main_menu_min_health()
{
	min_health* health = new min_health();
	text* tex_m = new text();

	int key1, key2;
	do
	{
		system("cls");
		tex_m->main_health();
		key1 = _getch();
		switch (key1)
		{
		case '1':
		{
			system("cls");
			min_health::min_health();
			health->get_name();
			health->get_place();
			cout << "��������" << endl;
			Sleep(1500);
			system("cls");
		}
		break;
		case'2':
		{
			do
			{
				system("cls");
				health->display_param();
				key2 = _getch();
				switch (key2)
				{
				}
			} while (key2 != 27);
		}
		break;
		case'3':
		{
			if (health->r == 0)
			{
				system("cls");
				cout << "������� �������� ������������" << endl;
				Sleep(1500);
				system("cls");

			}
			else
			{
				system("cls");
				health->clean();
				cout << "�������" << endl;
				Sleep(1500);
				system("cls");
			}
		}
		break;
		case'4':
		{
			system("cls");
			hospital run;
			 run.main_menu_hospital();
		}
		}
	} while (key1 != 27);
}
#pragma once
#include "ambulance.h"
#include <iostream>
#include "conio.h"
#include <cstdio>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstring>
#pragma warning (disable:4244)

using namespace std;

class service 
{
protected:
	int time;
	int time_s;
	int n;
	int repair;
	char *car;
	char *null_str;
public:
	service()
	{
		time += 300;
		time_s += 3;
		car = new char[15];
		null_str = "";
		strcpy(car, null_str);
	}
	void repair_car();
	void add_car();
	void delete_car();
	void take_new_car();
	void clean();
};

void service::clean()
{
	time = 300;
	strcpy(car, null_str);
}

void service::delete_car()
{
	clean();
}

void service::take_new_car()
{
	const int LENGHT = 15;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_car.txt";
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
		car = new char[str.length() + 1];
		strcpy(car, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void service::add_car()
{
	n = rand() % 2;
	if (n == 1)
	{
		cout << "������ ������� �� ������������" << endl;
		take_new_car();
	}
	else
	{
		cout << "��� ��������� �����" << endl;
	}
}

void service::repair_car()
{
	add_car();
	if (n == 1)
	{
		cout << "������ �����" << endl;
		time--;
		Sleep(1000);
		{
			repair = rand() % 2;
			if (repair == 1)
			{
				cout << "������ ������ � �������������" << endl;
			}
			else
			{
				cout << "� ���������, ������ �� �������� ��������������" << endl;
				cout << "������ ����� �������� ����� " << time_s-- << endl;
				Sleep(1000);
				delete_car();
			}
		}
	}
}
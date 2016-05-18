#pragma once
#include "hospital.h"
#include <iostream>
#include "conio.h"
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <locale.h>
#pragma warning (disable:4244)

using namespace std;

class bro:public hospital
{
public:
	char *name, *status, *ag;
	short age;
	char *null_str;
	int num;
public:
	bro()
	{
		null_str = "";
		name = new char[30];
		status = new char[15];
		ag = new char[5];
		age = NULL;
		num = NULL;
		strcpy(name, null_str);
		strcpy(status, null_str);
		strcpy(ag, null_str);
	}
	virtual void get_name();
	virtual void get_status();
	void get_age();
	void rus_loc();
	virtual void display_param();
	void clean();
};

void bro::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void bro::rus_loc()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void bro::get_name()
{
	rus_loc();
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_male_staff_m.txt";
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
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void bro::get_status()
{
	const int LENGHT = 15;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "stat_staff_m.txt";
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
		int index = 1 + rand() % 6;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void bro::get_age()
{
	const int LENGHT = 5;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "age_staff_m.txt";
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
	    /*num = strtod(str.c_str(), 0);*/
		str = "";
		coll.clear();
	

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
}

void bro::display_param()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << endl;
	cout << "ФИО: " << name << endl;
	cout << "Стастус сотрудника: " << status << endl;
	cout << "Возраст сотрудника: " << age << endl;
	cout << "Должность: Медбрат" << endl;
	cout << endl;
}

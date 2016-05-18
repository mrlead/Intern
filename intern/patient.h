#pragma once
#include "doctor.h"
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#pragma warning (disable:4244)

using namespace std;

class patient:public doctor
{
protected:
	char *name;
	char *disease;
	short age;
	char *place;
	char *ag;
	char *null_str;
public:
	patient()
	{
		null_str = "";
		name = new char[30];
		disease = new char[30];
		place = new char[30];
		ag = new char[5];
		age = NULL;
		strcpy(name, null_str);
		strcpy(place, null_str);
		strcpy(disease, null_str);
		strcpy(ag, null_str);
	}
	void get_info();
	void display_param();
	void clean();
};

void patient::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(place, null_str);
	strcpy(disease, null_str);
	strcpy(ag, null_str);
}

void patient::get_info()
{
	//set_name
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "name_pat.txt";
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
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
	//set_age
	const int LENGHT = 36;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "age_pat.txt";
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
		int index = 1 + rand() % 36;
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
	//set_disease
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "disease.txt";
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
		disease = new char[str.length() + 1];
		strcpy(disease, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "Не удалось выделить память под коллекцию" << endl;
	}
	//set_place
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "place_pat.txt";
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

void patient::display_param()
{
	cout << "ФИО пациента: " << name << endl;
	cout << "Возраст пациента: " << age << endl;
	cout << "Место жительства пациента: " << place << endl;
	cout << "Диагноз: " << disease << endl;
	cout << "Метод лечения: " << heal << endl;
}
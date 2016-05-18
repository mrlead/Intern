#pragma once
#include "private_hospital.h"
#include <iostream>
#include "conio.h"
#include <cstdio>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstring>
#pragma warning (disable:4244)

using namespace std;

class head_private_doctor: public private_hospital
{
protected:
	char *name;
	short age;
	char *ag;
	char *num;
	char *null_str;
public:
	head_private_doctor()
	{
		null_str = "";
		name = new char[30];
		ag = new char[15];
		num = new char[5];
		age = NULL;
		strcpy(name, null_str);
		strcpy(num, null_str);
	}
	virtual void get_info();
	virtual void display_param();
	void clean();
	void number();
};

void head_private_doctor::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(ag, null_str);
	strcpy(num, null_str);
}

void head_private_doctor::get_info()
{
	//set_name
	strcpy(name, head_doctor);
	//set_age
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "doct_age.txt";
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
		int index = rand()*coll.size() / RAND_MAX;
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
	char yn;
	do
	{
		cout << "Присвоить доктору номер больницы, или выбрать случайное число(y/n)?: ";
		cin >> yn;
		if (yn = 'y')
		{
			sprintf(num, "%d", number);//присваиваем номер больницы к номеру боигады скорой помощи доктора
		}
		else
		{
			const int LENGHT = 30;
			vector<string> coll;
			vector<string>::iterator it_deep, it_submit, pos;
			char *filename = "doct_num.txt";
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
	} while (yn = 'n');
}
#pragma once
#include "hospital.h"
#include "rus_localization.h"
#include "eng_localization.h"
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

class person: public hospital
{
protected:
	char *file_name;
	char *file_age;
	char *file_status;
	int count;
	char *ag;
	char *name;
	char *status;
	short age;
	char *null_str;
	const char *fileout;
	const char *file_private;
public:
	person()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[30];
		count++;
		file_name = "data_base/data_female_staff_s.txt";
		count++;
		file_age = new char[150];
		count++;
		file_status = new char[150];
		count++;
		status = new char[20];
		count++;
		ag = new char[5];
		count++;
		age = NULL;
		count++;
		fileout = "output/person_origin.txt";
		count++;
		file_private = "output/person_private.txt";
		count++;
		strcpy(name, null_str);
		strcpy(status, null_str);
		strcpy(ag, null_str);
	}
	void get_name(string);
	void get_status();
	void get_age();
	void display_param();
	void main_menu_staff();
	void clean();
	void main_private_staff();
	void save_origin();
	void save_private();
	void display_eng();
};

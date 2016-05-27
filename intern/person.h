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
	int count;
	char *ag;
	char *name;
	char *status;
	short age;
	char *null_str;
public:
	person()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[30];
		count++;
		status = new char[20];
		count++;
		ag = new char[5];
		count++;
		age = NULL;
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
};

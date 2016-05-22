#pragma once
#include "hospital.h"
#include "rus_localization.h"
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
	char *ag;
	char *name;
	char *status;
	short age;
	char *null_str;
public:
	person()
	{
		null_str = "";
		name = new char[30];
		status = new char[20];
		ag = new char[5];
		age = NULL;
		strcpy(name, null_str);
		strcpy(status, null_str);
		strcpy(ag, null_str);
	}
	void get_name();
	void get_status();
	void get_age();
	void rus_loc();
	void display_param();
	void main_menu_staff();
	void clean();
};

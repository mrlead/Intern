#pragma once
#include "doctor.h"
#include <iostream>
#include "conio.h"
#include <cstdio>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <sstream>

#pragma warning (disable:4244);

class patient:public doctor
{
protected:
	char *name;
	short age;
	char *place;
	char *ag;
	char *null_str;
	int n;
public:
	char *disease;
	patient()
	{
		null_str = "";
		name = new char[30];
		disease = new char[30];
		place = new char[30];
		ag = new char[5];
		n = NULL;
		age = NULL;
		strcpy(name, null_str);
		strcpy(place, null_str);
		strcpy(disease, null_str);
		strcpy(ag, null_str);
	}
	void get_name();
	void get_age();
	void get_place();
	void get_disease();
	void display_param();
	void clean();
	void main_menu_pat();
};
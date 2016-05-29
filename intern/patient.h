#pragma once
#include "doctor.h"
#include "private_doctor.h"
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

#pragma warning (disable:4244)

class patient:public doctor, private_doctor
{
protected:
	int count;
	char *name;
	short age;
	char *place;
	char *ag;
	char *null_str;
	int n;
	const char *file_pat;
public:
	char *disease;
	patient()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[30];
		count++;
		disease = new char[30];
		count++;
		place = new char[30];
		count++;
		ag = new char[5];
		count++;
		n = NULL;
		count++;
		age = NULL;
		count++;
		file_pat = "output/patient.txt";
		count++;
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
	void save();
};
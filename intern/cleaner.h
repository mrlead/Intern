#pragma once
#include "hospital.h"
#include <iostream>
#include "conio.h"
#include <cstdio>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstring>

using namespace std;

class cleaner:public hospital
{
public:
	char *name, *status, *ag;
	short age;
	char *null_str;
public:
	cleaner()
	{
		null_str = "";
		name = new char[30];
		status = new char[20];
		ag = new char[15];
		age = NULL;
		strcpy(name, null_str);
		strcpy(status, null_str);
		strcpy(ag, null_str);
	}
	void get_name();
	void get_status();
	void get_age();
	void display_param();
	void clean();
};
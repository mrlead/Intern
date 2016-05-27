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
	int count;
	char *name, *status, *ag;
	short age;
	char *null_str;
public:
	cleaner()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[30];
		count++;
		status = new char[20];
		count++;
		ag = new char[15];
		count++;
		age = NULL;
		count++;
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
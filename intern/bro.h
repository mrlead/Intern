#pragma once
#include "hospital.h"
#include <iostream>
#include "conio.h"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <locale.h>
#pragma warning (disable:4244)

using namespace std;

class bro:public hospital
{
public:
	int count;
	char *name, *status, *ag;
	short age;
	char *null_str;
	int num;
public:
	bro()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[30];
		count++;
		status = new char[15];
		count++;
		ag = new char[5];
		count++;
		age = NULL;
		count++;
		num = NULL;
		count++;
		strcpy(name, null_str);
		strcpy(status, null_str);
		strcpy(ag, null_str);
	}
	virtual void get_name();
	virtual void get_status();
	void get_age();
	virtual void display_param();
	void clean();
};
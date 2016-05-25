#pragma once
#include "hospital.h"
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

class head_doctor:public hospital
{
protected:
	char *name;
	short age;
	char *ag;
	char *null_str;
	char *status;
	int num;
public:
	head_doctor()
	{
		status = new char[20];
		null_str = "";
		name = new char[30];
		ag = new char[15];
		age = NULL;
		strcpy(status, null_str);
		strcpy(name, null_str);
		strcpy(ag, null_str);
	}
	void get_age();
	void get_name();
	void clean();
	virtual void GetNumber();
	void get_status();
	void display_param();
	void main_head_doctor();
};


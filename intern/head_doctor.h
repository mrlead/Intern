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
	int count;
	char *name;
	short age;
	char *ag;
	char *null_str;
	char *status;
	int num;
	const char *file_head_o;
public:
	head_doctor()
	{
		count = 0;
		count++;
		status = new char[20];
		count++;
		null_str = "";
		count++;
		name = new char[30];
		count++;
		ag = new char[15];
		count++;
		age = NULL;
		count++;
		file_head_o = "output/head_origin.txt";
		count++;
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
	void save_origin();
	void display_eng();
};


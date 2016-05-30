#pragma once
#include "private_hospital.h"
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

class head_private_doctor: public private_hospital
{
protected:
	int count;
	char *name;
	short age;
	char *ag;
	char *num;
	char *null_str;
	char *status;
	const char *file_head_p;
public:
	head_private_doctor()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		status = new char[30];
		count++;
		name = new char[30];
		count++;
		ag = new char[15];
		count++;
		num = new char[5];
		count++;
		age = NULL;
		count++;
		file_head_p = "output/head_private.txt";
		count++;
		strcpy(name, null_str);
		strcpy(num, null_str);
		strcpy(status, null_str);
	}
	virtual void get_name();
	virtual void get_age();
	virtual void get_status();
	virtual void display_param();
	void main_p_head();
	void clean();
	void number();
	void save_private();
	void display_eng();
};
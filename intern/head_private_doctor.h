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
	char *name;
	short age;
	char *ag;
	char *num;
	char *null_str;
	char *status;
public:
	head_private_doctor()
	{
		null_str = "";
		status = new char[30];
		name = new char[30];
		ag = new char[15];
		num = new char[5];
		age = NULL;
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
};
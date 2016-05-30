#pragma once
#include "person.h"
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

class security: public person
{
public:
	int count;
	char *name, *status, *ag;
	short age;
	char *null_str;
	const char *file_security_o;
	const char *file_security_p;
public:
	security()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[30];
		count++;
		status = new char[15];
		count++;
		ag = new char[15];
		count++;
		age = NULL;
		count++;
		file_security_o = "output/security_origin.txt";
		count++;
		file_security_p = "output/security_private.txt";
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
	void save_origin();
	void save_private();
	void display_eng();
};
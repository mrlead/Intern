#pragma once
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include "rus_localization.h"
#pragma warning (disable:4244)

using namespace std;

class min_health
{
protected:
	char *name;
	char *place;
	char *null_str;
	int r;
	
public:
	char *name_hosp;
	min_health()
	{
		name_hosp = new char[15];
		r = NULL;
		null_str = "";
		name = new char[60];
		place = new char[40];
		strcpy(name, null_str);
		strcpy(place, null_str);
	}
	virtual void get_name();
	void display_param();
	virtual void get_place();
	void clean();
	void main_menu_min_health();
};
#pragma once
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include "rus_localization.h"
#include "eng_localization.h"
#pragma warning (disable:4244)

using namespace std;

class min_health
{
protected:
	int count;
	char *name;
	char *place;
	char *null_str;
	int r;
	const char *health;
public:
	char *name_hosp;
	min_health()
	{
		count = 0;
		count++;
		name_hosp = new char[15];
		count++;
		r = NULL;
		count++;
		null_str = "";
		count++;
		name = new char[60];
		count++;
		place = new char[40];
		count++;
		health = "output/min_health.txt";
		count++;
		strcpy(name, null_str);
		strcpy(place, null_str);
	}
	virtual void get_name();
	void display_param();
	virtual void get_place();
	void clean();
	void main_menu_min_health();
	void save();
};
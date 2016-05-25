#pragma once
#include "min_health.h"
#include <iostream>
#include "stdio.h"
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#pragma warning (disable:4244)

using namespace std;

class hospital :public min_health 
{
protected:
	char *name;
	char *place;
	int room, vip_room;
	int number;
	int cost;
	char *number_s;
	char *null_str;
public:
	hospital()
	{
		null_str = "";
		name = new char[15];
		place = new char[40];
		number_s = new char[5];
		number = NULL;
		cost = NULL;
		room = NULL;
		vip_room = NULL;
		strcpy(name, null_str);
		strcpy(place, null_str);
		strcpy(number_s, null_str);
	}
	virtual void get_name();
	void get_number();
	void display_param();
	void get_room();
	void get_place();
	void get_cost();
	void clean();
	void main_menu_hospital();
};
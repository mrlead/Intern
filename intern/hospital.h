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
	int count;
	char *name;
	char *place;
	int room, vip_room;
	int number;
	int cost;
	char *number_s;
	char *null_str;
	const char *file_hospital_o;
public:
	hospital()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[15];
		count++;
		place = new char[40];
		count++;
		number_s = new char[5];
		count++;
		number = NULL;
		count++;
		cost = NULL;
		count++;
		room = NULL;
		count++;
		vip_room = NULL;
		count++;
		file_hospital_o = "output/hospital_origin.txt";
		count++;
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
	void save_origin();
};
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

class private_hospital:public min_health
{
protected:
	int count;
	char *name;
	char *place;
	int vip_room;
	int number;
	int cost;
	char *number_s;
	char *null_str;
	char *company;
public:
	private_hospital()
	{
		count = 0;
		count++;
		null_str = "";
		count++;
		name = new char[15];
		count++;
		company = new char[30];
		count++;
		place = new char[40];
		count++;
		number_s = new char[5];
		count++;
		number = NULL;
		count++;
		cost = NULL;
		count++;
		vip_room = NULL;
		count++;
		strcpy(name, null_str);
		strcpy(place, null_str);
		strcpy(number_s, null_str);
	}
	void get_name();
	void get_number();
	virtual void display_param();
	void get_room();
	void get_place();
	void get_cost();
	void get_company();
	void clean();
	void main_menu_private();
};


#pragma once
#include "hospital.h"
#include "private_hospital.h"
#include "service.h"
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

class ambulance : public hospital, private_hospital
{
protected:
	int col_car;
	char *destination;
	int send_time;
	char *car_name;
	int count;
	char *null_str;
public:
	ambulance()
	{
		null_str = "";
		col_car = NULL;
		destination = new char[30];
		car_name = new char[15];
		send_time = NULL;
		count = NULL;
		strcpy(car_name, null_str);
	}
	void get_car();
	void send_car();
	void accept_patient();
	void clean();
	void display_param();
};

void ambulance::clean()
{
	col_car = NULL;
	send_time = NULL;
	count = NULL;
	strcpy(car_name, null_str);
}

void ambulance::get_car()
{
	service *car = new service;
	car->take_new_car();
}

void ambulance::send_car()
{
	
}
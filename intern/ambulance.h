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
public:
	ambulance()
	{
		col_car = NULL;
		destination = new char[30];
		car_name = new char[15];
		send_time = NULL;
		count = NULL;
	}
	void get_info();
	void get_car();
	void send_car();
	void accept_patient();
	void clean();
	void display_param();
};


void ambulance::get_car()
{
	service *car = new service;
	car->take_new_car();
}

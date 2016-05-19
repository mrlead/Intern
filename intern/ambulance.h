#pragma once
#include "hospital.h"
#include "private_hospital.h"
#include "leaving_call.h"
#include "service.h"

class ambulance : public hospital, private_hospital
{
protected:
	int col_car;
	int col_fuel;
	int destination_time;
public:
	ambulance()
	{
		col_car = NULL;
		col_fuel = 500;
		destination_time = NULL;
	}
	void get_info();
	void set_info();
	void get_car();
	void get_fuel();
	void send_car();
	void accept_patient();
	void clean();
};


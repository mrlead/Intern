#pragma once
#include "hospital.h"
#include "private_hospital.h"
#include "leaving_call.h"
#include "service.h"

class ambulance : public hospital, private_hospital
{
public:
	//���������� ��� service
	service *num;
	service *time;
	//����� ����������
	//���������� ��� leaving_call
	leaving_call *num;
	leaving_call *patient;
	leaving_call *place;
	//����� ����������

	ambulance();
	void get_info();
	void set_info();
	void get_car(int col_car);
	void get_fuel(int col_fuel);
	void send_car();
	void accept_patient(char *patient);
	~ambulance();
};


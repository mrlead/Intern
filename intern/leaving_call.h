#pragma once
#include "ambulance.h"
#include "false.h"
#include "emergency.h"

class leaving_call 
{
public:
	//���������� ��� false
	false_call *price_f;
	//����� ����������
	//���������� ��� emergency
	emergency *time_e;
	//����� ����������

 	leaving_call();
	void get_place();
	void get_num();
	void get_patient();
	~leaving_call();
};
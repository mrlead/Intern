#pragma once
#include "ambulance.h"
#include "false.h"
#include "emergency.h"

class leaving_call 
{
public:
	//Объявление для false
	false_call *price_f;
	//конец объявления
	//Объявление для emergency
	emergency *time_e;
	//конец объявления

 	leaving_call();
	void get_place();
	void get_num();
	void get_patient();
	~leaving_call();
};
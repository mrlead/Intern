#pragma once
#include <iostream>

using namespace std;

class Errors_s
{
public:
	Errors_s()
	{
		cerr << "Файл не открыт" << endl;
	}
};
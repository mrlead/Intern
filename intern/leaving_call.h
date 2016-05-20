#pragma once
#include "ambulance.h"
#include "false.h"
#include "emergency.h"

class leaving_call 
{
protected:
	char *destination;
	char *null_str;
public:
 	leaving_call()
	{
		null_str = "";
		destination = new char[30];
		strcpy(destination, null_str);
	}
	void get_place();
	void get_patient();
	void clean();
};

void leaving_call::clean()
{
	strcpy(destination, null_str);
}

void leaving_call::get_place()
{
	//������ ��������� ������
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
    char *filename = "data_base/destination.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//������ ���������� ����� � ���������
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//������ ������ �� ����� ���������
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//��������� ������
		srand(time(NULL));
		int index = rand() % 11;
		str = coll[index];
		destination = new char[str.length() + 1];
		strcpy(destination, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void leaving_call::get_patient()
{

}
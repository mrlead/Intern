//#include "person.h"
#include "head_doctor.h"
#include <iostream>
#include "conio.h"
#include <cstdio>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <sstream>
#pragma warning (disable:4244)

using namespace std;

class doctor:public head_doctor
{
protected:
	char *name, *ag;
	short age;
	char *status;
	int r;
	char *heal;
	char *rank;
	char *rank_2;
	char *rank_3;
	char *default_rank;
	char *null_str;
	char *nums;
public:
	doctor()
	{
		null_str = "";
		nums = new char[5];
		ag = new char[15];
		name = new char[30];
		status = new char[17];
		rank = new char[15];
		rank_2 = new char[15];
		rank_3 = new char[15];
		default_rank = new char[15];
		heal = new char[30];
		r = 1;
		age = NULL;
		strcpy(name, null_str);
		strcpy(status, null_str);
		strcpy(heal, null_str);
		strcpy(default_rank, null_str);
	}
	void get_name();
	void Heal();
	void GetRank();
	void GetNumber();
	void exam();
	virtual void display_param();
	void clean();
	void get_status();
	//������ ���������� ��� ��������� ������������
	void operator ++ ()
	{
		int r1 = r;
		r1 + 1;
		cout << r1 << endl;
	}
};

void doctor::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(heal, null_str);
	strcpy(default_rank, null_str);
}

void doctor::get_name()
{
	//set_name
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "doct_name.txt";
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
		int index = 1 + rand() % 12;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
	//set_age
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "age_staff_m.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{

			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		srand(time(NULL));
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void doctor::GetRank()
{
	rank = "���� ������� ������";
	rank_2 = "���� �������� ������";
	rank_3 = "���� �������� ������";
	strcpy(default_rank, rank);
}

void doctor::GetNumber()
{
	char yn;
	do
	{
		cout << "��������� ������� ����� ��������, ��� ������� ��������� �����(y/n)?: ";
		cin >> yn;
		if (yn = 'y')
		{
			sprintf(nums, "%d", number);
			//����������� ����� �������� � ������ ������� ������ ������ �������
		}
		else
		{
			const int LENGHT = 30;
			vector<string> coll;
			vector<string>::iterator it_deep, it_submit, pos;
			char *filename = "doct_num.txt";
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
				int index = 1 + rand() % 40;
				str = coll[index];
				nums = new char[str.length() + 1];
				strcpy(nums, str.c_str());

				fclose(fp);
			}
			catch (bad_alloc)
			{
				cout << "�� ������� �������� ������ ��� ���������" << endl;
			}
		}
	}while (yn = 'n');	
}

void doctor::Heal()
{
	//����� ������� 
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "heal.txt";
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
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		heal = new char[str.length() + 1];
		strcpy(heal, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void doctor::exam()
{
	//���������� ������� �� ��������� ������������
	srand(time(NULL));
	int ex = 1 + rand() % 2;
	if(ex == 1 && ex != 3)
	{
	//�������� ������������ � ������ �������� ����� ��������
	++r;
	if (r == 2 && r !=6)
	{
		strcpy(default_rank, rank_2);
	}
	else
		if(r == 3 && r != 6)
		{
			strcpy(default_rank, rank_3);
		}
		else 
			if (r == 4 && r != 6)
			{
				cout << "������������ ��� ���������� �� ������������� ������" << endl;
			}
			else 
				if (r == 5 && r != 6)
				{
					cout << "�� ��� ��������" << endl;
				}
	}
	else
		if(ex == 2 && ex !=3)
		{
			cout << "������ �������� �������" << endl;
		}
}

void doctor::get_status()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "stat_staff_m.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{

		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{

			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);


		srand(time(NULL));
		int index = rand()*coll.size() / RAND_MAX;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void doctor::display_param()
{
	cout << "���: " << name << endl;
	cout << "������������: " << default_rank << endl;
	cout << "����� �������: " << nums << endl;
}
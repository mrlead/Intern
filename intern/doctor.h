#pragma once
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
	int count;
	char *name, *ag;
	short age;
	char *status;
	int r;
	char *heal;
	char *heal1;
	char *heal2;
	char *heal3;
	char *heal4;
	char *heal5;
	char *heal6;
	char *heal7;
	char *heal8;
	char *heal9;
	char *heal10;
	char *rank;
	char *rank_2;
	char *rank_3;
	char *rank_4;
	char *default_rank;
	char *null_str;
	int nums;
	char *dis;
public:
	doctor()
	{
		count = 0;
		count++;
		dis = new char[20];
		count++;
		null_str = "";
		count++;
		nums = NULL;
		count++;
		ag = new char[15];
		count++;
		name = new char[30];
		count++;
		status = new char[17];
		count++;
		rank = new char[15];
		count++;
		rank_2 = new char[15];
		count++;
		rank_3 = new char[15];
		count++;
		rank_4 = new char[30];
		count++;
		default_rank = new char[15];
		count++;
		heal = new char[60];
		count++;
		r = 1;
		count++;
		age = NULL;
		count++;
		strcpy(name, null_str);
		strcpy(status, null_str);
		strcpy(heal, null_str);
		strcpy(default_rank, null_str);
		strcpy(rank, null_str);
		strcpy(rank_2, null_str);
		strcpy(rank_3, null_str);
		strcpy(rank_4, null_str);
	}
	virtual void get_name();
	void Heal();
	void GetRank();
	void get_number();
	virtual void get_age();
	void exam();
	virtual void display_param();
	void clean();
	void get_status();
	void main_menu_doct();
	//void err();
	//������ ���������� ��� ��������� ������������
	void operator ++ ()
	{
		int r1 = r;
		r1 += 1;
		cout << r1 << endl;
	}
};
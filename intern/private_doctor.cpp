#pragma once
#include "private_doctor.h"
#include "patient.h"
#include "lang.h"
#include <fstream>

static patient* pat_p = new patient();
lang* l_p_doct = new lang();

void private_doctor::operator ++()
{
	int r1 = r;
	r1 += 1;
	cout << r1 << endl;
}

void private_doctor::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(heal, null_str);
	strcpy(default_rank, null_str);
}

void private_doctor::get_name()
{
	//set_name
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/doct_name.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_p_doct->rus == 1)
		{
			cout << "���� �� ������" << endl;
		}
		else
			if (l_p_doct->rus == 0)
			{
				cout << "File not open" << endl;
			}
	}
	else
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
		int index = 1 + rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");

		fclose(fp);
	}
}

void private_doctor::GetRank()
{
	rank = "���� ������� ������";
	rank_2 = "���� �������� ������";
	rank_3 = "���� �������� ������";
	rank_4 = "��� ��������";
	strcpy(default_rank, rank);
}

void private_doctor::GetNumber()
{
		const int LENGHT = 30;
		vector<string> coll;
		vector<string>::iterator it_deep, it_submit, pos;
		char *filename = "data_base/doct_num.txt";
		char input[LENGHT];
		string str;
		FILE *fp;

		ifstream f(filename);
		if (!f.good())
		{
			if (l_p_doct->rus == 1)
			{
				cout << "���� �� ������" << endl;
			}
			else
				if (l_p_doct->rus == 0)
				{
					cout << "File not open" << endl;
				}
		}
		else
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
}

void private_doctor::Heal()
{
	heal1 = "����� �� 4 ���� � ����, 10 ����";
	heal2 = "����������� �������, �������� ��� ���� � ����, 10 ����";
	heal3 = "���������� ����, ����� ��� ����, 7 ����";
	heal4 = "������� �����, ����������, 15 ����";
	heal5 = "����������, 10 ����";
	heal6 = "������, 30 ����";
	heal7 = "��������������, ���������� 14 ����";
	heal8 = "��������, � ���������� � �����";
	heal9 = "�����, ���� ��������, �� �������������";
	heal10 = "������� � ���������";

	char *dis1 = "���������";
	char *dis2 = "��������";
	char *dis3 = "��������";
	char *dis4 = "������� �������";
	char *dis5 = "�������";
	char *dis6 = "������������";
	char *dis7 = "������� ��������";
	char *dis8 = "����";
	char *dis9 = "������ �������";
	char *dis10 = "����������";
	pat_p->get_disease();

	cout << "�������: " << pat_p->disease << endl;

	if (strcmp(pat_p->disease, dis1) == 0)
	{
		strcpy(heal, heal1);
	}
	else
		if (strcmp(pat_p->disease, dis2) == 0)
		{
			strcpy(heal, heal2);
		}
		else
			if (strcmp(pat_p->disease, dis3) == 0)
			{
				strcpy(heal, heal3);
			}
			else
				if (strcmp(pat_p->disease, dis4) == 0)
				{
					strcpy(heal, heal4);
				}
				else
					if (strcmp(pat_p->disease, dis5) == 0)
					{
						strcpy(heal, heal5);
					}
					else
						if (strcmp(pat_p->disease, dis6) == 0)
						{
							strcpy(heal, heal6);
						}
						else
							if (strcmp(pat_p->disease, dis7) == 0)
							{
								strcpy(heal, heal7);
							}
							else
								if (strcmp(pat_p->disease, dis8) == 0)
								{
									strcpy(heal, heal8);
								}
								else
									if (strcmp(pat_p->disease, dis9) == 0)
									{
										strcpy(heal, heal9);
									}
									else
										if (strcmp(pat_p->disease, dis10) == 0)
										{
											strcpy(heal, heal10);
										}
	if (l_p_doct->rus == 1)
	{
		cout << "����� �������: " << heal << endl;
	}
	else
		if (l_p_doct->rus == 0)
		{
			cout << "Health method: " << heal << endl;
		}
}

void private_doctor::exam()
{
	//���������� ������� �� ��������� ������������
	srand(time(NULL));
	int ex = 1 + rand() % 2;
	if (ex == 1 && ex != 3)
	{
		//�������� ������������ � ������ �������� ����� ��������
		++r;
		if (r == 2 && r != 6)
		{
			strcpy(default_rank, rank_2);
			if (l_p_doct->rus == 1)
			{
				cout << "������ ���� �������" << endl;
			}
			else
				if (l_p_doct->rus == 0)
				{
					cout << "Doctor exam" << endl;
				}
		}
		else
			if (r == 3 && r != 6)
			{
				strcpy(default_rank, rank_3);
				if (l_p_doct->rus == 1)
				{
					cout << "������ ���� �������" << endl;
				}
				else
					if (l_p_doct->rus == 0)
					{
						cout << "Doctor exam" << endl;
					}
			}
			else
				if (r == 4 && r != 6)
				{
					if (l_p_doct->rus == 1)
					{
						cout << "������������ ��� ��������� �� ������������� ������" << endl;
						cout << "�� �� ������ ����������� ��� �����)" << endl;
					}
					else
						if (l_p_doct->rus == 0)
						{
							cout << "Qualification already elevated to the maximum level" << endl;
							cout << "But you can try one more time )" << endl;
						}
				}
				else
					if (r == 5 && r != 6)
					{
						if (l_p_doct->rus == 1)
						{
							cout << "�� ��� ��������" << endl;
						}
						else
							if (l_p_doct->rus == 0)
							{
								cout << "You are God of medicine" << endl;
							}
						strcpy(default_rank, rank_4);
					}
	}
	else
		if (ex == 2 && ex != 3)
		{
			if (l_p_doct->rus == 1)
			{
				cout << "\a������ �������� �������" << endl;
			}
			else
				if (l_p_doct->rus == 0)
				{
					cout << "\aDoctor fail exam" << endl;
				}
		}
}

void private_doctor::get_age()
{
	//set_age
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_m.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_p_doct->rus == 1)
		{
			cout << "���� �� ������" << endl;
		}
		else
			if (l_p_doct->rus == 0)
			{
				cout << "File not open" << endl;
			}
	}
	else
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
		int index = 1 + rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);

		fclose(fp);
	}
}

void private_doctor::get_status()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_m.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	ifstream f(filename);
	if (!f.good())
	{
		if (l_p_doct->rus == 1)
		{
			cout << "���� �� ������" << endl;
		}
		else
			if (l_p_doct->rus == 0)
			{
				cout << "File not open" << endl;
			}
	}
	else
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
		int index = 1 + rand() % 6;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str()); 
		strtok(status, "\n");

		fclose(fp);
	}
}

void private_doctor::display_param()
{
	cout << GetIniString("1", "answer_p_doct", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_p_doct", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_p_doct", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_p_doct", "ini_base/menu_list_rus.ini") << default_rank << endl;
	cout << GetIniString("5", "answer_p_doct", "ini_base/menu_list_rus.ini") << nums << endl;
	cout << endl;
	cout << GetIniString("10", "objects", "ini_base/menu_list_rus.ini") << count << endl;
}

void private_doctor::display_eng()
{
	cout << GetIniString("1", "answer_p_doct", "ini_base/menu_list_eng.ini") << name << endl;
	cout << GetIniString("2", "answer_p_doct", "ini_base/menu_list_eng.ini") << status << endl;
	cout << GetIniString("3", "answer_p_doct", "ini_base/menu_list_eng.ini") << age << endl;
	cout << GetIniString("4", "answer_p_doct", "ini_base/menu_list_eng.ini") << default_rank << endl;
	cout << GetIniString("5", "answer_p_doct", "ini_base/menu_list_eng.ini") << nums << endl;
	cout << endl;
	cout << GetIniString("10", "objects", "ini_base/menu_list_eng.ini") << count << endl;
}

void private_doctor::save_private()
{
	ofstream fout(file_doctor_p, ios_base::out | ios_base::trunc);
	if (!fout.good())
	{
		if (l_p_doct->rus == 1)
		{
			cout << "���� ��������" << endl;
		}
		else
			if (l_p_doct->rus == 0)
			{
				cout << "Bad file" << endl;
			}
	}
	else
	{
		fout << GetIniString("1", "answer_p_doct", "ini_base/menu_list_rus.ini") << name << endl;
		fout << GetIniString("2", "answer_p_doct", "ini_base/menu_list_rus.ini") << status << endl;
		fout << GetIniString("3", "answer_p_doct", "ini_base/menu_list_rus.ini") << age << endl;
		fout << GetIniString("4", "answer_p_doct", "ini_base/menu_list_rus.ini") << default_rank << endl;
		fout << GetIniString("5", "answer_p_doct", "ini_base/menu_list_rus.ini") << nums << endl;
		fout << endl;
		fout << GetIniString("10", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	}
}

static private_doctor* pr_doctor = new private_doctor();

void private_doctor::main_menu_pr_doctor()
{

	text* text_doct = new text();

	l_p_doct->check();

	int key1, key2;
	do
	{
		system("cls");
		l_p_doct->main_pr_doct(l_p_doct);
		key1 = _getch();
		switch (key1)
		{
		case'1':
		{
			if (pr_doctor->age != 0)
			{
				if (l_p_doct->rus == 1)
				{
					cout << "��� ������ ����������� ����������" << endl;
					Sleep(1500);
				}
				else
					if (l_p_doct->rus == 0)
					{
						cout << "To start make a dismissal" << endl;
						Sleep(1500);
					}
			}
			else
			{
				private_doctor::private_doctor();
				pr_doctor->get_name();
				pr_doctor->get_age();
				pr_doctor->get_status();
				pr_doctor->GetNumber();
				pr_doctor->GetRank();
				if (l_p_doct->rus == 1)
				{
					cout << "�������" << endl;
					Sleep(1500);
				}
				else
					if (l_p_doct->rus == 0)
					{
						cout << "Successfully" << endl;
						Sleep(1500);
					}
			}
		}
		l_p_doct->check();
		break;
		case'2':
		{
			if (pr_doctor->age == 0)
			{
				if (l_p_doct->rus == 1)
				{
					system("cls");
					cout << "������� �������� �������" << endl;
					Sleep(1500);
				}
				else
					if (l_p_doct->rus == 0)
					{
						system("cls");
						cout << "First, create a doctor" << endl;
						Sleep(1500);
					}
			}
			else
			{
				if (l_p_doct->rus == 1)
				{
					system("cls");
					pr_doctor->get_status();
					pr_doctor->display_param();
					pr_doctor->save_private();
					_getch();
				}
				else
					if (l_p_doct->rus == 0)
					{
						system("cls");
						pr_doctor->get_status();
						pr_doctor->display_eng();
						pr_doctor->save_private();
						_getch();
					}
			}
		}
		l_p_doct->check();
		break;
		case'3':
		{
			if (pr_doctor->nums == 0)
			{
				if (l_p_doct->rus == 1)
				{
					cout << "��������� ��� ������!" << endl;
					Sleep(1500);
				}
				else
					if (l_p_doct->rus == 0)
					{
						cout << "Dismiss more certain!" << endl;
						Sleep(1500);
					}
			}
			else
			{
				system("cls");
				pr_doctor->clean();
				if (l_p_doct->rus == 1)
				{
					cout << "�������" << endl;
					Sleep(1500);
				}
				else
					if (l_p_doct->rus == 0)
					{
						cout << "Successfully" << endl;
						Sleep(1500);
					}
			}
		}
		l_p_doct->check();
		break;
		case'4':
		{
			system("cls");
			pat_p->main_menu_pat();
		}
		l_p_doct->check();
		break;
		case'5':
		{
			if (pr_doctor->age == 0)
			{
				if (l_p_doct->rus == 1)
				{
					system("cls");
					cout << "������� �������� �������" << endl;
					Sleep(1500);
				}
				else
					if (l_p_doct->rus == 0)
					{
						system("cls");
						cout << "First, create a doctor" << endl;
						Sleep(1500);
					}
			}
			else
			{
				system("cls");
				pr_doctor->exam();
				Sleep(3000);
			}
		}
		l_p_doct->check();
		break;
		}
	} while (key1 != 27);
}
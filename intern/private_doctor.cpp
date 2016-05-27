#pragma once
#include "private_doctor.h"
#include "Errors_c.h"
#include "patient.h"

static patient* pat_p = new patient();

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
		int index = 1 + rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
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
	cout << "����� �������: " << heal << endl;
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
			cout << "������ ���� �������" << endl;
		}
		else
			if (r == 3 && r != 6)
			{
				strcpy(default_rank, rank_3);
				cout << "������ ���� �������" << endl;
			}
			else
				if (r == 4 && r != 6)
				{
					cout << "������������ ��� ���������� �� ������������� ������" << endl;
					cout << "�� �� ������ ����������� ��� �����)" << endl;
				}
				else
					if (r == 5 && r != 6)
					{
						cout << "�� ��� ��������" << endl;
						strcpy(default_rank, rank_4);
					}
	}
	else
		if (ex == 2 && ex != 3)
		{
			cout << "\a������ �������� �������" << endl;
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

	try
	{
		//throw Errors_s();
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
	catch (Errors_s)
	{
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
		int index = 1 + rand() % 6;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str()); 
		strtok(status, "\n");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
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

static private_doctor* pr_doctor = new private_doctor();

void private_doctor::main_menu_pr_doctor()
{

	text* text_doct = new text();

	int key1, key2;
	do
	{
		setlocale(0, "");
		system("cls");
		text_doct->main_doct();
		key1 = _getch();
		switch (key1)
		{
		case'1':
		{
			if (pr_doctor->age != 0)
			{
				cout << "��� ������ ����������� ����������" << endl;
				Sleep(900);
				system("cls");
			}
			else
			{
				private_doctor::private_doctor();
				pr_doctor->get_name();
				pr_doctor->get_age();
				pr_doctor->get_status();
				pr_doctor->GetNumber();
				pr_doctor->GetRank();
				cout << "�������� ������������" << endl;
				Sleep(900);
			}
		}
		break;
		case'2':
		{
			if (pr_doctor->age == 0)
			{
				system("cls");
				cout << "\a������� �������� �����" << endl;
				Sleep(1500);
				system("cls");
			}
			else
			{
				do
				{
					system("cls");
					pr_doctor->get_status();
					pr_doctor->display_param();
					cout << "'ESC' - �����" << endl;
					key2 = _getch();
					switch (key2)
					{
					}
				} while (key2 != 27);
				break;
			}
		}
		break;
		case'3':
		{
			if (pr_doctor->nums == 0)
			{
				system("cls");
				cout << "\a��������� ��� ������" << endl;
				Sleep(1500);
				system("cls");
			}
			else
			{
				system("cls");
				pr_doctor->clean();
				cout << "��������" << endl;
				Sleep(1500);
			}
		}
		break;
		case'4':
		{
			system("cls");
			pat_p->main_menu_pat();
		}
		break;
		case'5':
		{
			if (pr_doctor->age == 0)
			{
				system("cls");
				cout << "\a������� �������� �����" << endl;
				Sleep(1500);
				system("cls");
			}
			else
			{
				system("cls");
				pr_doctor->exam();
				Sleep(3000);
			}
		}
		break;
		}
	} while (key1 != 27);
}
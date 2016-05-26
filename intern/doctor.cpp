#pragma once
#include "doctor.h"
#include "patient.h"


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
	char *filename = new char[40];
	filename = "data_base/doct_name.txt";
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
		strtok(name, "\n");

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cerr << "�� ������� �������� ������ ��� ���������" << endl;
		Sleep(900);
	}

}
void doctor::get_age()
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
	rank_4 = "��� ��������";
	strcpy(default_rank, rank);
}

void doctor::get_number()
{
	nums = 1 + rand() % 99;
}

patient* pat_n = new patient();

void doctor::Heal()
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
	pat_n->get_disease();

	cout << "�������: " << pat_n->disease << endl;

	if (strcmp(pat_n->disease,dis1) == 0)
	{
		strcpy(heal, heal1);
	}
	else
		if (strcmp(pat_n->disease, dis2) == 0)
		{
			strcpy(heal, heal2);
		}
		else
			if(strcmp(pat_n->disease, dis3) == 0)
		{
			strcpy(heal, heal3);
		}
			else
				if (strcmp(pat_n->disease, dis4) == 0)
				{
					strcpy(heal, heal4);
				}
				else
					if(strcmp(pat_n->disease, dis5) == 0)
				{
					strcpy(heal, heal5);
				}
					else
						if (strcmp(pat_n->disease, dis6) == 0)
						{
							strcpy(heal, heal6);
						}
						else
							if (strcmp(pat_n->disease, dis7) == 0)
							{
								strcpy(heal, heal7);
							}
							else
								if (strcmp(pat_n->disease, dis8) == 0)
								{
									strcpy(heal, heal8);
								}
								else
									if (strcmp(pat_n->disease, dis9) == 0)
									{
										strcpy(heal, heal9);
									}
									else
										if (strcmp(pat_n->disease, dis10) == 0)
										{
											strcpy(heal, heal10);
										}
	cout << "����� �������: " << heal << endl;
}

void doctor::exam()
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

void doctor::get_status()
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
		int index = rand()*coll.size() / RAND_MAX;
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

void doctor::display_param()
{
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "������ ����������: " << status << endl;
	cout << "������������: " << default_rank << endl;
	cout << "����� �������: " << nums << endl;
}

static doctor* doct = new doctor();

void doctor::main_menu_doct()
{
	
	text* text_doct = new text();

	int key1, key2;
	do
	{
		system("cls");
		text_doct->main_doct();
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{
				if (doct->age != 0)
				{
					cout << "��� ������ ����������� ����������" << endl;
					Sleep(900);
					system("cls");
				}
				else
				{
					doctor::doctor();
					doct->get_name();
					doct->get_age();
					doct->get_status();
					doct->get_number();
					doct->GetRank();
					cout << "�������" << endl;
					Sleep(900);
				}
			}
			break;
		case'2':
			{
				if (doct->age == 0)
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
						doct->display_param();
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
				if (doct->nums == 0)
				{
					system("cls");
					cout << "\a��������� ��� ������" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					system("cls");
					doct->clean();
					cout << "�������" << endl;
					Sleep(1500);
				}
			}
			break;
		case'4':
			{
					system("cls");
					pat_n->main_menu_pat();
			}
			break;
		case'5':
			{
				if (doct->age == 0)
				{
					system("cls");
					cout << "\a������� �������� �����" << endl;
					Sleep(1500);
					system("cls");
				}
				else
				{
					system("cls");
					doct->exam();
					Sleep(3000);
				}
			}
			break;
		}
	} while (key1 != 27);
}
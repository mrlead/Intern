#pragma once
#include "person.h"
#include "bro.h"
#include "cleaner.h"
#include "security.h"
#include <fstream>
#include <iostream>
#include "conio.h"
#include <Windows.h>
#include <locale.h>

#pragma warning(disable:4060)

/*����������� ��� person
------------------------
-----------------------*/

void person::clean()
{
	age = NULL;
	//strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void person::rus_loc()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void person::get_name(string)
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_female_staff_s.txt";
	char *filename_s = "intermediate_files/person_name.txt";
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
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		str = "";
		coll.clear();
		

		fclose(fp);
		FILE *fo;
		fopen_s(&fo, filename_s, "w");
		fprintf(fo, name);
		fclose(fo);

		//p_name->get_name(name);

	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void person::get_status()
{
	const int LENGHT = 20;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_s.txt";
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
		int index = rand() % 5;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void person::get_age()
{
	const int LENGHT = 5;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_s.txt";
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void person::display_param()
{
	string nams;
	ifstream myfile("intermediate_files/person_name.txt");
	FILE *of;
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, nams);
		}
		myfile.close();
	}
	strcpy(name, nams.c_str());
	cout << endl;
	cout << "���: " << name << endl;
	cout << "������ ����������: " << status << endl;
	cout << "������� ����������: " << age << endl;
	cout << "���������: ���������" << endl;
	cout << endl;
}

/*����������� ��� bro
------------------------
-----------------------*/

void bro::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void bro::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_male_staff_m.txt";
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
		int index = rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void bro::get_status()
{
	const int LENGHT = 15;
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
		int index = rand() % 6;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void bro::get_age()
{
	const int LENGHT = 5;
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		/*num = strtod(str.c_str(), 0);*/
		str = "";
		coll.clear();


		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void bro::display_param()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << endl;
	cout << "���: " << name << endl;
	cout << "������� ����������: " << status << endl;
	cout << "������� ����������: " << age << endl;
	cout << "���������: �������" << endl;
	cout << endl;
}

/*����������� ��� cleaner
------------------------
-----------------------*/

void cleaner::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void cleaner::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_female_staff_c.txt";
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
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void cleaner::get_status()
{
	const int LENGHT = 20;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_c.txt";
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
		int index = rand() % 5;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void cleaner::get_age()
{
	const int LENGHT = 36;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_c.txt";
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void cleaner::display_param()
{
	cout << endl;
	cout << "���: " << name << endl;
	cout << "������ ����������: " << status << endl;
	cout << "������� ����������: " << age << endl;
	cout << "���������: ��������" << endl;
	cout << endl;
}

/*����������� ��� cleaner
------------------------
-----------------------*/

void security::clean()
{
	age = NULL;
	strcpy(name, null_str);
	strcpy(status, null_str);
	strcpy(ag, null_str);
}

void security::rus_loc()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void security::get_name()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/data_male_staff_se.txt";
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
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void security::get_status()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/stat_staff_se.txt";
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
		int index = rand() % 5;
		str = coll[index];
		status = new char[str.length() + 1];
		strcpy(status, str.c_str());
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void security::get_age()
{
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
	char *filename = "data_base/age_staff_se.txt";
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
		int index = rand() % 35;
		str = coll[index];
		ag = new char[str.length() + 1];
		strcpy(ag, str.c_str());
		age = (short)strtoul(ag, NULL, 0);
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

void security::display_param()
{
	cout << endl;
	cout << "���: " << name << endl;
	cout << "������ ����������: " << status << endl;
	cout << "������� ����������: " << age << endl;
	cout << "���������: ��������" << endl;
	cout << endl;
}

/*�������� ���� ��� ����� ���������
------------------------
-----------------------*/

void person::main_menu_staff()
{
	person* sister = new person();
	bro* medbro = new bro();
	cleaner* cleane = new cleaner();
	security* securit = new security();
	text show;
	int key1, key2, key3, key4;
	do
	{
		system("cls");
		show.main_staff();
		key1 = _getch();
		switch (key1)
		{
		case '1':
		{
			do
			{
				system("cls");
				show.menu_create_staff();
				key2 = _getch();
				//system("cls");
				switch (key2)
				{
					system("cls");
				case '1':
				{
					if (sister->age != 0)
					{
						cout << "��� ������ ����������� ����������" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						person::person();
						sister->get_name(name);
						sister->get_status();
						sister->get_age();
						cout << "�������" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '2':
				{
					if (medbro->age != 0)
					{
						cout << "��� ������ ����������� ����������" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						bro::bro();
						medbro->get_name();
						medbro->get_status();
						medbro->get_age();
						cout << "�������" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '3':
				{
					if (cleane->age != 0)
					{
						cout << "��� ������ ����������� ����������" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						cleaner::cleaner();
						cleane->get_name();
						cleane->get_status();
						cleane->get_age();
						cout << "�������" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '4':
				{
					if (securit->age != 0)
					{
						cout << "��� ������ ����������� ����������" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						security::security();
						securit->get_name();
						securit->get_status();
						securit->get_age();
						cout << "�������" << endl;
						Sleep(500);
					}
					break;
				}
				}
			} while (key2 != 27);
			break;
		}

		case '2':
		{
			do
			{
				system("cls");
				sister->display_param();
				medbro->display_param();
				cleane->display_param();
				securit->display_param();
				key4 = _getch();
				switch (key4)
				{}
			} while (key4 != 27);
			break;
		}
		case '3':
		{
			do
			{
				system("cls");
			show.remove_staff();
			key3 = _getch();
			switch (key3)
			{
					case '1':
					{
						if (sister->age == 0)
						{
							system("cls");
							cout << "��������� ��� ������!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							sister->clean();
							cout << "�������" << endl;
							Sleep(1500);
						}
							break;
					}
					case '2':
					{
						if (medbro->age == 0)
						{
							system("cls");
							cout << "��������� ��� ������!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							medbro->clean();
							cout << "�������" << endl;
							Sleep(1500);
						}
						break;
					}
					case '3':
					{
						if (cleane->age == 0)
						{
							system("cls");
							cout << "��������� ��� ������!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							cleane->clean();
							cout << "�������" << endl;
							Sleep(1500);
						}
						break;
					}
					case '4':
					{
						if (securit->age == 0)
						{
							system("cls");
							cout << "��������� ��� ������!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							securit->clean();
							cout << "�������" << endl;
							Sleep(1500);
						}
						break;
					}
				} 
			} while (key3 != 27);
			break;
		}
		}
		}while (key1 != 27);
}

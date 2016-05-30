#pragma once
#include "doctor.h"
#include "patient.h"
#include "lang.h"
#include <fstream>

lang* l_doct = new lang();

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

	ifstream f(filename);
	if (!f.good())
	{
		if (l_doct->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_doct->rus == 0)
			{
				cout << "File not open" << endl;
			}
	}
	else
	{
		//Читаем содержимое файла в коллекцию
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//Читаем строку из файла источника
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//Случайная строка
		srand(time(NULL));
		int index = 1 + rand() % 11;
		str = coll[index];
		name = new char[str.length() + 1];
		strcpy(name, str.c_str());
		strtok(name, "\n");

		fclose(fp);
		
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

	ifstream f(filename);
	if (!f.good())
	{
		if (l_doct->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_doct->rus == 0)
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

void doctor::GetRank()
{
	rank = "Врач низкого уровня";
	rank_2 = "Врач среднего уровня";
	rank_3 = "Врач высокого уровня";
	rank_4 = "Бог медицины";
	strcpy(default_rank, rank);
}

void doctor::get_number()
{
	nums = 1 + rand() % 99;
}

static patient* pat_n = new patient();

void doctor::Heal()
{
	heal1 = "Уколы по 4 раза в день, 10 дней";
	heal2 = "Обмазывание зелёнкой, таблетки два раза в день, 10 дней";
	heal3 = "Промывание носа, капли для носа, 7 дней";
	heal4 = "Строгая диета, капельница, 15 дней";
	heal5 = "Капельница, 10 дней";
	heal6 = "Массаж, 30 дней";
	heal7 = "Успокаительное, капельница 14 дней";
	heal8 = "Таблетки, и наблюдение у врача";
	heal9 = "Уколы, приём таблеток, до выздоровления";
	heal10 = "Лечение у психиатра";
	
	char *dis1 = "Бешенство";
	char *dis2 = "Ветрянка";
	char *dis3 = "Гайморит";
	char *dis4 = "Гастрит желудка";
	char *dis5 = "Инсульт";
	char *dis6 = "Остеохондроз";
	char *dis7 = "Инфаркт Миокарда";
	char *dis8 = "Корь";
	char *dis9 = "Острый бронхит";
	char *dis10 = "Дальтонизм";
	pat_n->get_disease();

	cout << "Диагноз: " << pat_n->disease << endl;

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
	cout << "Метод лечения: " << heal << endl;
}

void doctor::exam()
{
	//отправляем доктора на повышение квалификации
	srand(time(NULL));
	int ex = 1 + rand() % 2;
	if (ex == 1 && ex != 3)
	{
		//повышаем квалификацию в случае успешной сдачи экзамена
		++r;
		if (r == 2 && r != 6)
		{
			strcpy(default_rank, rank_2);
			if (l_doct->rus == 1)
			{
				cout << "Доктор сдал экзамен" << endl;
			}
			else
				if (l_doct->rus == 0)
				{
					cout << "Doctor exam" << endl;
				}
		}
		else
			if (r == 3 && r != 6)
			{
				strcpy(default_rank, rank_3);
				if (l_doct->rus == 1)
				{
					cout << "Доктор сдал экзамен" << endl;
				}
				else
					if (l_doct->rus == 0)
					{
						cout << "Doctor exam" << endl;
					}
			}
			else
				if (r == 4 && r != 6)
				{
					
					if (l_doct->rus == 1)
					{
						cout << "Квалификация уже повышенна до максимального уровня" << endl;
						cout << "Но вы можете попробовать ещё разок)" << endl;
					}
					else
						if (l_doct->rus == 0)
						{
							cout << "Qualification already elevated to the maximum level" << endl;
							cout << "But you can try one more time )" << endl;
						}
				}
				else
					if (r == 5 && r != 6)
					{
						if (l_doct->rus == 1)
						{
							cout << "Вы Бог медицины" << endl;
						}
						else
							if (l_doct->rus == 0)
							{
								cout << "You are God of medicine" << endl;
							}
						strcpy(default_rank, rank_4);
					}
	}
	else
		if (ex == 2 && ex != 3)
		{
			if (l_doct->rus == 1)
			{
				cout << "\aДоктор провалил экзамен" << endl;
			}
			else
				if (l_doct->rus == 0)
				{
					cout << "\aDoctor fail exam" << endl;
				}
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

	ifstream f(filename);
	if (!f.good())
	{
		if (l_doct->rus == 1)
		{
			cout << "Файл не открыт" << endl;
		}
		else
			if (l_doct->rus == 0)
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

void doctor::display_param()
{
	cout << endl;
	cout << GetIniString("1", "answer_doct", "ini_base/menu_list_rus.ini") << name << endl;
	cout << GetIniString("2", "answer_doct", "ini_base/menu_list_rus.ini") << status << endl;
	cout << GetIniString("3", "answer_doct", "ini_base/menu_list_rus.ini") << age << endl;
	cout << GetIniString("4", "answer_doct", "ini_base/menu_list_rus.ini") << default_rank << endl;
	cout << GetIniString("5", "answer_doct", "ini_base/menu_list_rus.ini") << nums << endl;
	cout << endl;
	cout << GetIniString("5", "objects", "ini_base/menu_list_rus.ini") << count << endl;
	cout << endl;
}

void doctor::display_eng()
{
	cout << endl;
	cout << GetIniString("1", "answer_doct", "ini_base/menu_list_eng.ini") << name << endl;
	cout << GetIniString("2", "answer_doct", "ini_base/menu_list_eng.ini") << status << endl;
	cout << GetIniString("3", "answer_doct", "ini_base/menu_list_eng.ini") << age << endl;
	cout << GetIniString("4", "answer_doct", "ini_base/menu_list_eng.ini") << default_rank << endl;
	cout << GetIniString("5", "answer_doct", "ini_base/menu_list_eng.ini") << nums << endl;
	cout << endl;
	cout << GetIniString("5", "objects", "ini_base/menu_list_eng.ini") << count << endl;
	cout << endl;
}

void doctor::save_origin()
{
		ofstream fout(file_doctor_o, ios_base::out | ios_base::trunc);
		if (!fout.good())
		{
			if (l_doct->rus == 1)
			{
				cout << "Файл повреждён" << endl;
			}
			else
				if (l_doct->rus == 0)
				{
					cout << "Bad file" << endl;
				}
		}
		else
		{
			fout << GetIniString("1", "answer_doct", "ini_base/menu_list_rus.ini") << name << endl;
			fout << GetIniString("2", "answer_doct", "ini_base/menu_list_rus.ini") << status << endl;
			fout << GetIniString("3", "answer_doct", "ini_base/menu_list_rus.ini") << age << endl;
			fout << GetIniString("4", "answer_doct", "ini_base/menu_list_rus.ini") << default_rank << endl;
			fout << GetIniString("5", "answer_doct", "ini_base/menu_list_rus.ini") << nums << endl;
			fout << endl;
			fout << GetIniString("5", "objects", "ini_base/menu_list_rus.ini") << count << endl;
		}
}

static doctor* doct = new doctor();

void doctor::main_menu_doct()
{	
	text* text_doct = new text();

	l_doct->check();

	int key1, key2;
	do
	{
		setlocale(0, "");
		system("cls");
		l_doct->main_doct(l_doct);
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{
				if (doct->age != 0)
				{
					if (l_doct->rus == 1)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(1500);
					}
					else
						if (l_doct->rus == 0)
						{
							cout << "To start make a dismissal" << endl;
							Sleep(1500);
						}
				}
				else
				{
					doctor::doctor();
					doct->get_name();
					doct->get_age();
					doct->get_status();
					doct->get_number();
					doct->GetRank();
					if (l_doct->rus == 1)
					{
						cout << "Успешно" << endl;
						Sleep(1500);
					}
					else
						if (l_doct->rus == 0)
						{
							cout << "Successfully" << endl;
							Sleep(1500);
						}
				}
			}
			l_doct->check();
			break;
		case'2':
			{
				if (doct->age == 0)
				{
					if (l_doct->rus == 1)
					{
						system("cls");
						cout << "Сначала создайте доктора" << endl;
						Sleep(1500);
					}
					else
						if (l_doct->rus == 0)
						{
							system("cls");
							cout << "First, create a doctor" << endl;
							Sleep(1500); 
						}
				}
				else
				{
					if (l_doct->rus == 1)
					{
						system("cls");
						doct->get_status();
						doct->display_param();
						doct->save_origin();
						_getch();
					}
					else
						if (l_doct->rus == 0)
						{
							system("cls");
							doct->get_status();
							doct->display_eng();
							doct->save_origin();
							_getch();
						}
				}
			}
			l_doct->check();
			break;
		case'3':
			{
				if (doct->nums == 0)
				{
					if (l_doct->rus == 1)
					{
						cout << "Увольнять ещё некого!" << endl;
						Sleep(1500);
					}
					else
						if (l_doct->rus == 0)
						{
							cout << "Dismiss more certain!" << endl;
							Sleep(1500);
						}
				}
				else
				{
					system("cls");
					doct->clean();
					if (l_doct->rus == 1)
					{
						cout << "Успешно" << endl;
						Sleep(1500);
					}
					else
						if (l_doct->rus == 0)
						{
							cout << "Successfully" << endl;
							Sleep(1500);
						}
				}
			}
			l_doct->check();
			break;
		case'4':
			{
					system("cls");
					pat_n->main_menu_pat();
			}
			l_doct->check();
			break;
		case'5':
			{
				if (doct->age == 0)
				{
					if (l_doct->rus == 1)
					{
						system("cls");
						cout << "Сначала создайте доктора" << endl;
						Sleep(1500);
					}
					else
						if (l_doct->rus == 0)
						{
							system("cls");
							cout << "First, create a doctor" << endl;
							Sleep(1500);
						}
				}
				else
				{
					system("cls");
					doct->exam();
					Sleep(3000);
				}
			}
			l_doct->check();
			break;
		}
	} while (key1 != 27);
}
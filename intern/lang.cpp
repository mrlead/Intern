#include "lang.h"

text_eng* tit_en = new text_eng();
text* titu = new text();

void lang::check()
{
	if (rus == 0)
	{
		rus = 1;
	}
	else
		if (rus == 1)
		{
			rus = 0;
		}
}

void lang::main_lang(bool l)
{
	if (rus == 1)
	{
		system("cls");
		titu->main();
		rus = 0;
	}
	else
		if (rus == 0)
		{
			system("cls");
			tit_en->main_eng();
			rus = 1;
		}
}

void lang::main_health(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->main_health();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->main_health_eng();
			rus = 0;
		}
}

void lang::about(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->main_set();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->about_eng();
			rus = 0;
		}
}

void lang::about_programm(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->about_rus();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->about_pr_eng();
			rus = 0;
		}
}

void lang::instruct(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->inst_rus();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->inst_eng();
			rus = 0;
		}
}

void lang::about_author_l(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->author_rus();
		cout << endl;
		cout << endl;
		cout << endl;
		titu->titulka_rus();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->author_eng();
			cout << endl;
			cout << endl;
			cout << endl;
			tit_en->titulka_eng();
			rus = 0;
		}
}

void lang::main_hospital(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->main_hospital();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->main_hospital_eng();
			rus = 0;
		}
}

void lang::main_person(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->main_staff();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->main_staff_eng();
			rus = 0;
		}
}

void lang::main_create(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->menu_create_staff();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->menu_create_staff_eng();
			rus = 0;
		}
}

void lang::main_remove(bool l)
{
	if (rus == 0)
	{
		system("cls");
		titu->remove_staff();
		rus = 1;
	}
	else
		if (rus == 1)
		{
			system("cls");
			tit_en->remove_staff_eng();
			rus = 0;
		}
}

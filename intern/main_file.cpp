#pragma once
#include "min_health.h"
#include "person.h"
#include <locale.h>
#include <fstream>
#include <string>
#define TITRUS titul->titulka_rus()
#define TITENG tit_eng->titulka_eng()
#define TITUL rus?TITENG:TITRUS

text_eng* tit_eng = new text_eng();
text* titul = new text();
int main()
{
	
	min_health health;
	bool rus=1;
	int key1, key2, key3, key4, key5, key6;
	do
	{
		//tit_eng->titulka_eng();
		//titul->titulka_rus();
		//TITUL;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		titul->main();
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{	
				system("cls");
				health.main_menu_min_health();
			}
		case'2':
			{
				do
				{
					system("cls");
					titul->main_set();
					key2 = _getch();
					switch (key2)
					{
					case'1':
					{
						do
						{
							system("cls");
							titul->about_rus();
							key4 = _getch();
							switch(key4)
							{}
						} while (key4 != 27);
					}
					break;
					case'2':
					{
						do
						{
							system("cls");
							titul->inst_rus();
							key5 = _getch();
							switch (key5)
							{}
						} while (key5 != 27);
					}
					break;
					case'3':
					{
						do
						{
							system("cls");
							titul->author_rus();
							key6 = _getch();
							switch(key6)
							{}
						} while (key6 != 27);
					}
					break;
					}
				} while (key2 != 27);
			}
			break;
		case'3':
			{
				do
				{
					system("cls");
					cout << GetIniString("1", "set", "ini_base/menu_list_rus.ini") << endl;
					key3 = _getch();
					switch (key3)
					{
					case'1':
					{
						system("cls");
						person run_rename;
						run_rename.rename();
					}
					}
				} while (key3 != 27);
			}
			break;
		case'l':
			{
			/*
				if(TITUL == TITRUS)
				else
					TITENG*/
			}
		}
		
	} while (key1 != 27);
	system("pause");
	return 0;
}

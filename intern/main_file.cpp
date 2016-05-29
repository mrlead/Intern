#pragma once
#include "min_health.h"
#include "person.h"
#include "lang.h"
#include <locale.h>
#include <fstream>
#include <string>

//lang* Lang = new lang();
text_eng* tit_eng = new text_eng();
text* titul = new text();

int main()
{
	
	min_health health;
	bool rus=1;
	int key1, key2, key3, key4, key5, key6;
	char lang;
	do
	{
	//	Lang->main_lang(Lang, Lang);
	/*	cin >> lang;
		if (lang = 1)
		{
			titul->main();
		}
		else 
			if (lang = 2)
			{
				tit_eng->main_eng();
			}*/
		tit_eng->main_eng();
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{	
				system("cls");
				health.main_menu_min_health();
			}
			break;
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
		}
		
	} while (key1 != 27);
	system("pause");
	return 0;
}

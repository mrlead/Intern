#pragma once
#include "min_health.h"
#include "person.h"
#include "lang.h"
#include <locale.h>
#include <fstream>
#include <string>

text_eng* tit_eng = new text_eng();
text* titul = new text();
lang* sw = new lang();

int main()
{
	min_health health;
	int key1, key2, key3;
	do
	{
		sw->main_lang(sw);
		key1 = _getch();
		switch (key1)
		{
		case'1':
			{	
				system("cls");
				health.main_menu_min_health();
			}
			sw->check();
			break;
		case'2':
			{
				do
				{
					system("cls");
					sw->about(sw);
					sw->check();
					key2 = _getch();
					switch (key2)
					{
					case'1':
					{
							system("cls");
							sw->about_programm(sw); 
							_getch();
							sw->check();
					}
					sw->check();
					break;
					sw->check();
					case'2':
					{
							system("cls");
							sw->instruct(sw);
							_getch();
							sw->check();
					}
					sw->check();
					break;
					case'3':
					{
							system("cls");
							sw->about_author_l(sw);
							_getch();
							sw->check();
					}
					sw->check();
					break;
					}
					sw->check();
				} while (key2 != 27);
			}
			break;
		}
	} while (key1 != 27);
	system("pause");
	return 0;
}

#include "person.h"
#include "bro.h"
#include "cleaner.h"
#include "security.h"
#include "rus_localization.h"
#include <iostream>
#include "conio.h"
#include <Windows.h>
#include <locale.h>

void person::main_menu_staff()
{
	person* sister = new person();
	bro* medbro = new bro();
	cleaner* cleane = new cleaner();
	security* securit = new security();
	text* tex = new text();
	int key1, key2;
	do
	{
		tex->main_staff();
		key1 = _getch();
		switch (key1)
		{

		case '1':
		{
			do
			{
				system("cls");
				tex->menu_create_staff();
				key2 = _getch();
				system("cls");
				switch (key2)
				{
					system("cls");
				case '1':
				{
					sister->clean();
					sister->get_name();
					sister->get_status();
					sister->get_age();
					cout << "Успешно" << endl;
					Sleep(500);
					break;
				}
				system("cls");
				case '2':
				{
					medbro->clean();
					medbro->get_name();
					medbro->get_status();
					medbro->get_age();
					cout << "Успешно" << endl;
					Sleep(500);
					break;
				}
				system("cls");
				case '3':
				{
					cleane->clean();
					cleane->get_name();
					cleane->get_status();
					cleane->get_age();
					cout << "Успешно" << endl;
					Sleep(500);
					break;
				}
				system("cls");
				case '4':
				{
					securit->clean();
					securit->get_name();
					securit->get_status();
					securit->get_age();
					cout << "Успешно" << endl;
					Sleep(500);
					break;
				}
				}
				} while (key2 != 27);
			break;
			}
		system("cls");

		case '2':
			{
				system("cls");
			sister->display_param();
			medbro->display_param();
			cleane->display_param();
			securit->display_param();
			break;
			}
		case '3':
		{
			system("cls");
			if (sister->age == 0 && medbro->age == 0 && cleane->age == 0 && securit->age == 0)
			{
				cout << "Увольнять ещё некого!" << endl;
				Sleep(900);
				system("cls");
			}
			else
			{
				sister->clean();
				medbro->clean();
				cleane->clean();
				securit->clean();
				cout << "Увольнение выполнено успешно" << endl;
				Sleep(900);
				system("cls");
			}
			break;
		}
		}
		}while (key1 != 27);
}

int main()
{ 
	person* newp = new person();
	newp->main_menu_staff();
	system("pause >> void");
	return 0;
}
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
	int key1, key2, key3, key4;
	do
	{
		system("cls");
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
					if (sister->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						person::person();
						sister->get_name();
						sister->get_status();
						sister->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '2':
				{
					if (medbro->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						bro::bro();
						medbro->get_name();
						medbro->get_status();
						medbro->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '3':
				{
					if (cleane->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						cleaner::cleaner();
						cleane->get_name();
						cleane->get_status();
						cleane->get_age();
						cout << "Успешно" << endl;
						Sleep(500);
					}
					break;
				}
				system("cls");
				case '4':
				{
					if (securit->age != 0)
					{
						cout << "Для начала произведите увольнение" << endl;
						Sleep(900);
						system("cls");
					}
					else
					{
						security::security();
						securit->get_name();
						securit->get_status();
						securit->get_age();
						cout << "Успешно" << endl;
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
				switch (key4);
				{}
			} while (key4 != 27);
			break;
		}
		case '3':
		{
			do
			{
				system("cls");
			tex->remove_staff();
			key3 = _getch();
			switch (key3)
			{
					case '1':
					{
						if (sister->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							sister->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
							break;
					}
					case '2':
					{
						if (medbro->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							medbro->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
						break;
					}
					case '3':
					{
						if (cleane->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							cleane->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
						break;
					}
					case '4':
					{
						if (securit->age == 0)
						{
							system("cls");
							cout << "Увольнять ещё некого!" << endl;
							Sleep(1500);
							system("cls");
						}
						else
						{
							system("cls");
							securit->clean();
							cout << "Успешно" << endl;
							Sleep(1500);
						}
						break;
					}
				} 
			} while (key3 != 27);
			break;
		}
		}
		//system("cls");
		}while (key1 != 27);
}

int main()
{ 
	person* newp = new person();
	newp->main_menu_staff();
	system("pause");
	return 0;
}
#include "min_health.h"
#include <locale.h>
#include <fstream>
#include <string>

int main()
{
	text* titul = new text();
	min_health health;
	int key1;
	do
	{
		titul->titulka_rus();
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
				health.main_menu_min_health();
			}
		}
		
	} while (key1 != 27);
	system("pause");
	return 0;
}

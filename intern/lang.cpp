#include "lang.h"

text_eng* tit_en = new text_eng();
text* titu = new text();

bool rus = 0;

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

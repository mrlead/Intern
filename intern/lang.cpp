#include "lang.h"

//lang* Lang = new lang();
text* print = new text();
text_eng* print_eng = new text_eng();

void lang::main_lang(bool l, bool z)
{
	if (l)
	{
		print->titulka_rus();
	}
	while (z);
	{
		print_eng->titulka_eng();
	}
}

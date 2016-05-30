#pragma once
#include "rus_localization.h"
#include "eng_localization.h"



class lang
{
public:
	bool rus = 1;
	void check();
	void main_lang(bool);
	void main_health(bool);
	void about_author_l(bool);
	void titulka(bool);
	void about(bool);
	void about_programm(bool);
	void instruct(bool);
};
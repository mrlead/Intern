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
	void about(bool);
	void about_programm(bool);
	void instruct(bool);
	void main_hospital(bool);
	void main_person(bool);
	void main_create(bool);
	void main_remove(bool);
	void main_doct(bool);
	void main_pat(bool);
	void main_head(bool);
	void main_pr_hosp(bool);
	void main_pr_doct(bool);
	void main_pr_he(bool);
};
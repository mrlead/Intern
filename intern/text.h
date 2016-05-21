#pragma once
#include <iostream>
#include "conio.h"

using namespace std;

class text
{
public:
	text() {}
	void menu_create_per();
	void main_per();
};

void text::main_per()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << GetIniString("1", "person_main", "ini_base/menu_list.ini") << endl;
	cout << GetIniString("2", "person_main", "ini_base/menu_list.ini") << endl;
	cout << GetIniString("3", "person_main", "ini_base/menu_list.ini") << endl;
	cout << GetIniString("4", "person_main", "ini_base/menu_list.ini") << endl;
}

/*void text::menu_m_per()
{
	cout << "---------Меню персонала---------" << endl;
	cout << "'1' - Создать персонал" << endl;
	cout << "'2' - Посмотреть персонал" << endl;
	cout << "'3' - Уволить персонал" << endl;
	cout << "'ESC' - Возврат" << endl;
}

void text::menu_per()
{
	cout << "---------Меню создания персонала---------" << endl;
	cout << "'1' - Создать медсестру" << endl;
	cout << "'2' - Создать медбрата" << endl;
	cout << "'3' - Создать уборщицу" << endl;
	cout << "'4' - Создать охранника" << endl;
	cout << "'ESC' - Возврат" << endl;
}
*/
#pragma once
#include "IniMethod.h"
#include <iostream>
#include "conio.h"

using namespace std;

class text
{
public:
	text() {}
	void menu_create_staff();
	void main_staff();
};

void text::main_staff()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << GetIniString("1", "main_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("2", "main_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("3", "main_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("4", "main_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("5", "main_staff", "ini_base/menu_list_rus.ini") << endl;
}

void text::menu_create_staff()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << GetIniString("1", "create_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("2", "create_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("3", "create_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("4", "create_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("5", "create_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("6", "create_staff", "ini_base/menu_list_rus.ini") << endl;
}

/*void text::menu_per()
{
	cout << "---------Меню создания персонала---------" << endl;
	cout << "'1' - Создать медсестру" << endl;
	cout << "'2' - Создать медбрата" << endl;
	cout << "'3' - Создать уборщицу" << endl;
	cout << "'4' - Создать охранника" << endl;
	cout << "'ESC' - Возврат" << endl;
}
*/
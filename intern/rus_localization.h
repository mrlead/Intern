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
	void remove_staff();
	void main_health();
	void main_hospital();
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

void text::remove_staff()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << GetIniString("1", "remove_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("2", "remove_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("3", "remove_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("4", "remove_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("5", "remove_staff", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("6", "remove_staff", "ini_base/menu_list_rus.ini") << endl;
}

void text::main_health()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << GetIniString("1", "min_health", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("2", "min_health", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("3", "min_health", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("4", "min_health", "ini_base/menu_list_rus.ini") << endl;
}

void text::main_hospital()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << GetIniString("1", "hospital", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("2", "hospital", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("3", "hospital", "ini_base/menu_list_rus.ini") << endl;
	cout << GetIniString("4", "hospital", "ini_base/menu_list_rus.ini") << endl;
}
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
	cout << "---------���� ���������---------" << endl;
	cout << "'1' - ������� ��������" << endl;
	cout << "'2' - ���������� ��������" << endl;
	cout << "'3' - ������� ��������" << endl;
	cout << "'ESC' - �������" << endl;
}

void text::menu_per()
{
	cout << "---------���� �������� ���������---------" << endl;
	cout << "'1' - ������� ���������" << endl;
	cout << "'2' - ������� ��������" << endl;
	cout << "'3' - ������� ��������" << endl;
	cout << "'4' - ������� ���������" << endl;
	cout << "'ESC' - �������" << endl;
}
*/
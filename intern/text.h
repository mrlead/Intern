#pragma once
#include <iostream>
#include "conio.h"

using namespace std;

class text
{
public:
	text() {}
	void menu_m_per();
	void menu_per();
};

void text::menu_m_per()
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

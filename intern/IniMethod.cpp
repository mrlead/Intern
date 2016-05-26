#include <iostream>
#include <Windows.h>
#include "winnt.h"

using namespace std;

string GetIniString(string value, string section, string file)
{
	string result = "0";

	wchar_t *Nvalue = new wchar_t[value.size()+1];
	mbstowcs(Nvalue, value.c_str(), value.size());
	Nvalue[value.size()] = '\0';

	wchar_t *Nsection = new wchar_t[section.size()+1];
	mbstowcs(Nsection, section.c_str(), section.size());
	Nsection[section.size()] = '\0';

	wchar_t *Nfile = new wchar_t[file.size()+1];
	mbstowcs(Nfile, file.c_str(), file.size());
	Nfile[file.size()] = '\0';

	wchar_t *Nresult = new wchar_t[200];

	GetPrivateProfileString(Nsection, Nvalue, NULL, Nresult, 200, Nfile);

	delete []Nvalue;
	delete []Nsection;
	delete []Nfile;

	Nresult[199] = '\0';
	char * Cresult = new char[200];
	wcstombs(Cresult, Nresult, 200);
	result = Cresult;
	
	delete []Nresult;
	delete []Cresult;

	return result;
}
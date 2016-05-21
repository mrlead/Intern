#include <iostream>
#include <Windows.h>
#include "winnt.h"

using namespace std;

string GetIniString(string value, string section, string file) {
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

void WriteIniString(string info, string value, string section, string file) {
	wchar_t *Nvalue = new wchar_t[value.size()+1];
	mbstowcs(Nvalue, value.c_str(), value.size());
	Nvalue[value.size()] = '\0';

	wchar_t *Nsection = new wchar_t[section.size()+1];
	mbstowcs(Nsection, section.c_str(), section.size());
	Nsection[section.size()] = '\0';

	wchar_t *Nfile = new wchar_t[file.size()+1];
	mbstowcs(Nfile, file.c_str(), file.size());
	Nfile[file.size()] = '\0';

	wchar_t *Ninfo = new wchar_t[info.size()+1];
	mbstowcs(Ninfo, info.c_str(), info.size());
	Ninfo[info.size()] = '\0';

	WritePrivateProfileString(Nsection, Nvalue, Ninfo, Nfile);
	delete []Nvalue;
	delete []Ninfo;
	delete []Nsection;
	delete []Nfile;
}

void DeleteIniSection(string section, string file) {
	wchar_t *Nsection = new wchar_t[section.size()+1];
	mbstowcs(Nsection, section.c_str(), section.size());
	Nsection[section.size()] = '\0';

	wchar_t *Nfile = new wchar_t[file.size()+1];
	mbstowcs(Nfile, file.c_str(), file.size());
	Nfile[file.size()] = '\0';

	WritePrivateProfileSection(Nsection, NULL, Nfile);
	delete []Nsection;
	delete []Nfile;
}

void SetIniSectionID(string sectionNew, string sectionOld, string file) {
	wchar_t *Nbuffer = new wchar_t[2000+1];

	wchar_t *NsectionOld = new wchar_t[sectionOld.size()+1];
	mbstowcs(NsectionOld, sectionOld.c_str(), sectionOld.size());
	NsectionOld[sectionOld.size()] = '\0';

	wchar_t *NsectionNew = new wchar_t[sectionNew.size()+1];
	mbstowcs(NsectionNew, sectionNew.c_str(), sectionNew.size());
	NsectionNew[sectionNew.size()] = '\0';

	wchar_t *Nfile = new wchar_t[file.size()+1];
	mbstowcs(Nfile, file.c_str(), file.size());
	Nfile[file.size()] = '\0';

	GetPrivateProfileSection(NsectionOld, Nbuffer, 2000, Nfile);
	Nbuffer[2000] = '\0';
	WritePrivateProfileSection(NsectionOld, NULL, Nfile);
	WritePrivateProfileSection(NsectionNew, Nbuffer, Nfile);

	delete []Nbuffer;
	delete []NsectionOld;
	delete []NsectionNew;
	delete []Nfile;
}
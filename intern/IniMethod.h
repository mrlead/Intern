#include <iostream>
#include <Windows.h>
#include "winnt.h"

using namespace std;

string GetIniString(string value, string section, string file);
void WriteIniString(string info, string value, string section, string file);
void DeleteIniSection(string section, string file);
void SetIniSectionID(string sectionNew, string sectionOld, string file);
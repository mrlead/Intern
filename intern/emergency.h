#include "leaving_call.h"

class emergency 
{
protected:
	char *name_pat;
	char *place_pat;
	int age_pat;
	char *gender;
	char *null_str;
public:
	emergency()
	{
		gender = new char[10];
		name_pat = new char[30];
		place_pat = new char[30];
		age_pat = NULL;
		null_str = "";
		strcpy(name_pat, null_str);
		strcpy(place_pat, null_str);
		strcpy(gender, null_str);
	}
	void get_return_car();
	void clean();
	void add_patient();
};

void emergency::clean();
{
	age_pat = NULL;
	strcpy(name_pat, null_str);
	strcpy(place_pat, null_str);
	strcpy(gender, null_str);
}

void emergency::add_patient()
{
	//���������� ��������� ��� ��� ������������
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
    char *filename = "data_base/data_female_staff_s.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//������ ���������� ����� � ���������
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//������ ������ �� ����� ���������
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//��������� ������
		srand(time(NULL));
		int index = rand() % 11;
		str = coll[index];
		name_pat = new char[str.length() + 1];
		strcpy(name_pat, str.c_str());
		//�������, �� ��������� ������������
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}

	//���������� ��������� �����
	const int LENGHT = 30;
	vector<string> coll;
	vector<string>::iterator it_deep, it_submit, pos;
    char *filename = "data_base/data_female_staff_s.txt";
	char input[LENGHT];
	string str;
	FILE *fp;

	try
	{
		//������ ���������� ����� � ���������
		fopen_s(&fp, filename, "r");
		while (!feof(fp))
		{
			//������ ������ �� ����� ���������
			fgets(input, LENGHT, fp);
			str = input;
			coll.push_back(str);
		}
		fclose(fp);

		//��������� ������
		srand(time(NULL));
		int index = rand() % 11;
		str = coll[index];
		place_pat = new char[str.length() + 1];
		strcpy(place_pat, str.c_str());
		//�������, �� ��������� ������������
		str = "";
		coll.clear();

		fclose(fp);
	}
	catch (bad_alloc)
	{
		cout << "�� ������� �������� ������ ��� ���������" << endl;
	}
}

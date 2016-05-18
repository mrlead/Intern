#include "doctor.h"

enum duty
{
	yes, no
};

enum reception
{
	yes, no
};

class interns:public doctor
{
public:
	interns();
	void get_col_interns(int col_interns);
	~interns();
};
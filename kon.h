#ifndef _KON_H
#define _KON_H
#include "users.h"


class Kon : public users //상속
{
	const char* passward; //const화
	unsigned int kon;
public:
	Kon() {}

	Kon(char* _pw) :passward(_pw)
	{
		this->kon = 10;//this 포인터형
		cout << "개설 기념 콘 10개가 충전되었습니다!" << endl;
	}


	int GetKonNum()
	{
		return kon;
	}
};


#endif
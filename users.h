#ifndef _USERS_H
#define _USERS_H
#include <iostream>
using namespace std;

class users
{
public:
	char* name;
	static int num;
	int paymoney;
	int index = 0;
	virtual int GetMoney() //오버라이딩
	{
		return paymoney;
	}
	void NameDef(int _n, const char* _nam, users*& _u) //디폴트복사생성자
	{
		_u->name = new char[strlen(_nam) + 1];
		strcpy_s(_u->name, strlen(_nam) + 1, _nam);
	}
};


class Profile : public users //상속
{
public:
	char phone[20];
	string stmessage;
	bool musicOX(int num) //bool형
	{
		if (num == 1)
			return true;
		else
			return false;
	}
	string music;
	char email[50];
	bool choosemusic = false; //bool형
	int k = 0;
};

#endif
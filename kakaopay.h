#ifndef _KAKAOPAY_H
#define _KAKAOPAY_H
#include "users.h"

class KakaoPay :public users //»ó¼Ó
{
public:
	KakaoPay() {}

	int GetMoney()
	{
		return paymoney;
	}
	void AddMoney(int val)
	{
		paymoney += val;
	}
	void MinMoney(int val)
	{
		paymoney -= val;
	}
	char* Getname()
	{
		return name;
	}
};

#endif

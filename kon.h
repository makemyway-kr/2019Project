#ifndef _KON_H
#define _KON_H
#include "users.h"


class Kon : public users //���
{
	const char* passward; //constȭ
	unsigned int kon;
public:
	Kon() {}

	Kon(char* _pw) :passward(_pw)
	{
		this->kon = 10;//this ��������
		cout << "���� ��� �� 10���� �����Ǿ����ϴ�!" << endl;
	}


	int GetKonNum()
	{
		return kon;
	}
};


#endif
#ifndef _DAYINFO_H
#define _DAYINFO_H
#include "users.h"
#include <string>


const char* Yo[7] = { "Sun","Mon","Tus","Wed","Thu","Fri","Sat" };
class DayInfo
{
public:
	int Date;
	int num = 0; //��������
	string scedule[10];

	DayInfo(int _D)
	{
		this->Date = _D; //this ������
	}


	void ShowDayinfo()
	{
		cout <<"==="<< Date << "�� " << "�����Դϴ�." <<"==="<< endl;
		if (num != 0)
		{
			for (int a = 0; a < num; a++)
			{
				cout << "����" << a + 1 << ". " << scedule[a] << endl;
			}
			cout << num << "���� ������ �ֽ��ϴ�." << endl;
			cout << "=====================================" << endl;
		}
		else
		{
			cout << num << "���� ������ �ֽ��ϴ�." << endl;
			cout << "=====================================" << endl;
		}

	}

	void AddScedule()
	{
		while (1)
		{
			cout << "����" << num + 1 << ". "; 
			cin >> scedule[num];
			
			num++;
			int OX;
			cout << "�� �߰��Ͻðڽ��ϱ�? (Y:1,N:2) "; cin >> OX;
			if (OX == 1) {
				continue;
			}
			else
				break;
		}
	}
};
#endif
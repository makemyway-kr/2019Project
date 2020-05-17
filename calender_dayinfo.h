#ifndef _DAYINFO_H
#define _DAYINFO_H
#include "users.h"
#include <string>


const char* Yo[7] = { "Sun","Mon","Tus","Wed","Thu","Fri","Sat" };
class DayInfo
{
public:
	int Date;
	int num = 0; //일정개수
	string scedule[10];

	DayInfo(int _D)
	{
		this->Date = _D; //this 포인터
	}


	void ShowDayinfo()
	{
		cout <<"==="<< Date << "일 " << "일정입니다." <<"==="<< endl;
		if (num != 0)
		{
			for (int a = 0; a < num; a++)
			{
				cout << "일정" << a + 1 << ". " << scedule[a] << endl;
			}
			cout << num << "개의 일정이 있습니다." << endl;
			cout << "=====================================" << endl;
		}
		else
		{
			cout << num << "개의 일정이 있습니다." << endl;
			cout << "=====================================" << endl;
		}

	}

	void AddScedule()
	{
		while (1)
		{
			cout << "일정" << num + 1 << ". "; 
			cin >> scedule[num];
			
			num++;
			int OX;
			cout << "더 추가하시겠습니까? (Y:1,N:2) "; cin >> OX;
			if (OX == 1) {
				continue;
			}
			else
				break;
		}
	}
};
#endif
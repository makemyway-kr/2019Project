#ifndef _CALENDER_H
#define _CALENDER_H
#include "users.h"
#include "calender_dayinfo.h"

int isyoon(int a)
{
	if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

class calendar
{
public:
	int k; // ����� ����
	int sum = 0; // ������ ��� �� ��� ����
	int chk = 0; // ���� Ȯ�� ����
	int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // �⺻ 1~12�� �ϼ�
	DayInfo* DayArr[32]; //��ü�����͹迭

	calendar(int _y, int _m)
	{
		//���� Ȯ��
		if (isyoon(_y)==1)
		{
			chk = 1;
			basicyear[1]++;
		}
		else
			chk = 0;

		//0����� �۳���� ��ĥ���� ��
		sum = 365;
		for (int i = 1; i < _y; i++)
		{
			if (isyoon(i)==1)
				sum += 366;
			else
				sum += 365;
		}

		//�Է��� �ޱ��� ��ĥ���� 
		for (int i = 0; i < _m - 1; i++)
		{
			sum += basicyear[i];
		}

		//1��1�� ���� �������� ���
		k = sum % 7;
		int _k = k;


		for (int i = 0; i + 1 <= basicyear[_m - 1]; i++)
		{
			DayArr[i] = new DayInfo(i + 1);
			if (_k == 6) {
				_k = -1;
			}
			_k++;
		}

		PrintCalendar(_m);
	}
	void PrintCalendar(int _m)
	{
		cout << " SUN    MON    TUS    WED    THU    FRI    SAT " << endl;
		cout << "===================================================" << endl;

		//���� ���Ͽ� ���� ����
		for (int j = 0; j < k; j++)
		{
			cout << "	";
		}

		for (int i = 1; i <= basicyear[_m - 1]; i++)
		{
			cout << i << "	";
			if (k == 6) {
				k = -1;
				cout << endl;
			}
			k++;
		}
		cout << endl;
	}
};

#endif
#include "users.h"
#include "chats.h"
#include <string>


void chats::chatting()
{

	cout << "������ ä��" << endl;
	while (1)
	{
		int z = 1;
		cout << endl << "�����ϰ� �����ø� 0,��� �Ϸ��� 2�� ��������" << endl;
		cin >> z;
		if (z == 0)
			break;
		else if (z == 2)
		{
			cout << "�޼����� �Է��ϼ���" << endl;
			string message;
			cin >> message;
			getline(cin, message);
			cout << endl;
		}
		else
			cout << "�ĺ��������� ��ȣ�Դϴ�." << endl;
	}
}
#include "users.h"
#include "chats.h"
#include <string>


void chats::chatting()
{

	cout << "나와의 채팅" << endl;
	while (1)
	{
		int z = 1;
		cout << endl << "종료하고 싶으시면 0,계속 하려면 2를 누르세요" << endl;
		cin >> z;
		if (z == 0)
			break;
		else if (z == 2)
		{
			cout << "메세지를 입력하세요" << endl;
			string message;
			cin >> message;
			getline(cin, message);
			cout << endl;
		}
		else
			cout << "식별되지않은 번호입니다." << endl;
	}
}
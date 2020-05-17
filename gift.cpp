#include "users.h"
#include "gift.h"



void Gift::SelectFriend()
{
	cout << "누구에게 선물하시겠습니까?: "; cin >> mate;
	cout << endl;
}

void Gift::WriteGift()
{
	cout << "1.생일" << endl;
	cout << "2.따듯한 선물" << endl;
	cout << "3.부담없는 선물" << endl;
	cout << "4.프렌즈 선물" << endl;

}

void Gift::SelectGift()
{
	cin >> number;
}

void Gift::WriteMessage()
{
	string message;
	cout << "친구에게 메세지를 작성하시오 : ";
	cin >> message;
	getline(cin, message);
	cout << message;
}

void Gift::ShowMenu() {
	cout << "—선물하기—" << endl;
	cout << "-1-선물할 친구 " << endl;
	SelectFriend();
	cout << "-2-선물 종류 " << endl;
	WriteGift();
	cout << "선물 종류를 선택하시오:";
	SelectGift();
	cout << endl;
	cout << "-3-메세지" << endl;
	WriteMessage();
}

int mm(void)
{
	Gift g;
	g.ShowMenu();

	return 0;
}
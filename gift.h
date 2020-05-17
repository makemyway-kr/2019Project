#ifndef _GIFT_H
#define _GIFT_H
#include <string>

class Gift
{
private:
	string mate;
	int number;
	string message;
public:
	void SelectFriend();
	void WriteGift();
	void SelectGift();
	void WriteMessage();
	void ShowMenu();

};

#endif
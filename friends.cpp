#include "friends.h"
#include "users.h"


friends::friends(const char* _name, const char* _message, const char* _music)
{
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);

	message = new char[strlen(_message) + 1];
	strcpy_s(message, strlen(_message) + 1, _message);

	music = new char[strlen(_music) + 1];
	strcpy_s(music, strlen(_music) + 1, _music);

}

friends::~friends() //¼Ò¸êÀÚ
{
	delete[]name;
	delete[]message;
	delete[]music;
}

void friends::ShowFriends()
{
	cout << name << endl;
	cout << message << endl;
	cout << music << endl;
}
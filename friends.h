#ifndef _FRIENDS_H
#define _FRIENDS_H
#include "users.h"

class friends :public users
{
public:
	char* message;
	char* music;
public:
	friends(const char*, const char*, const char*);
	~friends();
	void ShowFriends();
};


#endif
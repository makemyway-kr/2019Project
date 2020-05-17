#include "users.h"
#include "MusicChart.h"

MusicChart::MusicChart(const char* _title, const char* _singer)
{
	title = new char[strlen(_title) + 1];
	strcpy_s(title, strlen(_title) + 1, _title);
	singer = new char[strlen(_singer) + 1];
	strcpy_s(singer, strlen(_singer) + 1, _singer);
}


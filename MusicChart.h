#ifndef _MUSICCHART_H
#define _MUSICCHART_H

class MusicChart
{
public:
	char* title;
	char* singer;
	char* song;

	MusicChart() {};

	MusicChart(const char* _title, const char* _singer);
};

#endif
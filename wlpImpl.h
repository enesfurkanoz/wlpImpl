#pragma once


#include<string>
#include<Shobjidl.h>

// TODO: Reference additional headers your program requires here.


class wlpImpl
{
public:
	wlpImpl();
	~wlpImpl();
	unsigned int getMonitorCount();
	const wchar_t* getMonitorID(int monitorIndex);
	void setWallpaper(const wchar_t* id, const wchar_t* s);
	const wchar_t* getWallpaper(const wchar_t* monitorID);
private:
	IDesktopWallpaper* wallPaper;
};


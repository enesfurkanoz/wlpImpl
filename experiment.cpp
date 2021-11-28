#include"wlpImpl.h"
#include <iostream>
int main()
{
	wlpImpl walpaper;
	std::cout << walpaper.getMonitorCount() << std::endl;
	const wchar_t* id1 = walpaper.getMonitorID(0);
	std::wcout << walpaper.getWallpaper(id1) << std::endl;
	std::wcout << id1;
	return 0;
}
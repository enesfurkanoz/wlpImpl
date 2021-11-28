#include "wlpImpl.h"
#include<iostream>

static const wchar_t* guidToString(const GUID& guid)
{
	LPOLESTR string = new wchar_t[40];
	auto x = StringFromGUID2(guid, string, 40);
	return string;
}

wlpImpl::wlpImpl()
{
	HRESULT r;
	r = CoInitialize(NULL);
	GUID x;
	wchar_t* y = L"{b92b56a9-8b55-4e14-9a89-0199bbb6f93b}";
	r = CLSIDFromString(y,&x);
	r = CoCreateInstance(__uuidof(DesktopWallpaper), 0, CLSCTX_LOCAL_SERVER, x, (LPVOID*)&this->wallPaper);
	std::wcout << "CLSID: " << guidToString(__uuidof(DesktopWallpaper)) << std::endl;
	std::wcout << "IID: " << guidToString(__uuidof(IDesktopWallpaper)) << std::endl;
	
}



wlpImpl::~wlpImpl()
{
	this->wallPaper->Release();
	CoUninitialize();
}

unsigned int wlpImpl::getMonitorCount()
{
	HRESULT result;
	UINT monitorCount;
	result = wallPaper->GetMonitorDevicePathCount(&monitorCount);
	return monitorCount;
}

const wchar_t* wlpImpl::getMonitorID(int monitorIndex)
{
	HRESULT result;
	WCHAR* monitorID = new WCHAR[200];

	memset(monitorID, 0, 200 * 2);
	result = wallPaper->GetMonitorDevicePathAt(monitorIndex, &monitorID);
	return monitorID;
}

void wlpImpl::setWallpaper(const wchar_t* id, const wchar_t* s)
{
	HRESULT result;
	result = this->wallPaper->SetWallpaper(id,s);
}

const wchar_t* wlpImpl::getWallpaper(const wchar_t* monitorID)
{
	HRESULT result;
	WCHAR* monitorwWallpaper = new WCHAR[200];
	memset(monitorwWallpaper,0,200*2);
	result = wallPaper->GetWallpaper(monitorID, &monitorwWallpaper);
	return monitorwWallpaper;
}

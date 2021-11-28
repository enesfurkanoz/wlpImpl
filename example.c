#include<Shobjidl.h>
#include<stdio.h>
int main() 
{
	HRESULT r;
	const IID clsid;
	const IID iid;
	r = CoInitialize(NULL);
	void* x = NULL;
	r = CLSIDFromString(L"{b92b56a9-8b55-4e14-9a89-0199bbb6f93b}", &iid);
	r = CLSIDFromString(L"{c2cf3110-460e-4fc1-b9d0-8a1c0c9cc4bd}", &clsid);
	r = CoCreateInstance(&clsid, 0, CLSCTX_LOCAL_SERVER, &iid,(void**)&x);
	printf("%ld",r);
}
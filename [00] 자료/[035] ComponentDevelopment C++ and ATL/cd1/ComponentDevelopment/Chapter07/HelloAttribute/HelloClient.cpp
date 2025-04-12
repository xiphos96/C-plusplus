#include <iostream>
#define _WIN32_DCOM	
#include "atlbase.h"
#import "progid:HelloServer.Hello.1" no_namespace named_guids
using namespace std;

int main()
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	{
		CComPtr<IUnknown> pUnk;
		pUnk.CoCreateInstance(__uuidof(CHello));
		CComQIPtr<IHello, &IID_IHello> pHello(pUnk);
		
		wchar_t* message = NULL;
		wchar_t* name;
		char buffer[256];
		cout << "이름을 입력하세요 : ";
		cin >> buffer;
		name = (wchar_t*)buffer;
		
		pHello->sayHello(name, &message);
		
		cout << (char*)message << endl;
		
		::CoTaskMemFree((LPVOID)message);
	}
	::CoUninitialize();
}

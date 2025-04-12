// HelloClient.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#import "progid:HelloServer.Hello.1" no_namespace

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	try {
		IHelloPtr pIHello(__uuidof(Hello));

		wchar_t* message = NULL;
		wchar_t* name;
		char buffer[256];
		cout << "이름을 입력하세요 : ";
		cin >> buffer;
		name = (wchar_t*)buffer;

		pIHello->sayHello(name, &message);

		cout << (char*)message << endl;

		cout << "이름을 저장합니다." << endl;
		pIHello->name = _com_util::ConvertStringToBSTR((char*)name);
		cout << "이름을 읽습니다." << endl;
		name = (wchar_t*)_com_util::ConvertBSTRToString(pIHello->name);
		cout << "읽어온 이름 : " << (char*)name << endl;
		
		::CoTaskMemFree((LPVOID)message);
	}
	catch(_com_error& e) {
		cout << e.ErrorMessage() << endl;
	}


	::CoUninitialize();

	return 0;
}


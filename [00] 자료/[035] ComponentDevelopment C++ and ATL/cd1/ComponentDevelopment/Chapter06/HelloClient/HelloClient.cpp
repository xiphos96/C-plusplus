// HelloClient.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		cout << "�̸��� �Է��ϼ��� : ";
		cin >> buffer;
		name = (wchar_t*)buffer;

		pIHello->sayHello(name, &message);

		cout << (char*)message << endl;

		cout << "�̸��� �����մϴ�." << endl;
		pIHello->name = _com_util::ConvertStringToBSTR((char*)name);
		cout << "�̸��� �н��ϴ�." << endl;
		name = (wchar_t*)_com_util::ConvertBSTRToString(pIHello->name);
		cout << "�о�� �̸� : " << (char*)name << endl;
		
		::CoTaskMemFree((LPVOID)message);
	}
	catch(_com_error& e) {
		cout << e.ErrorMessage() << endl;
	}


	::CoUninitialize();

	return 0;
}


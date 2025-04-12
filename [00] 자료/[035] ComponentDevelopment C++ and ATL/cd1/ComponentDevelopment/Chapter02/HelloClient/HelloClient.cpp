// HelloClient.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include "SmartPtr.h"
#include "SmartQIPtr.h"

using namespace std;

void Foo(IUnknown* pUnk);
void Foo2(IUnknown* pUnk);

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr;
	
	hr = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if(hr != S_OK) {
		cout << "�ʱ�ȭ�� �� �����ϴ�!" << endl;
		return 0;
	}
	
	CLSID clsid;
	
	hr = ::CLSIDFromProgID(L"HelloServer.Hello.1", &clsid);
	if(hr != S_OK) {
		cout << "������Ʈ���� ��ϵ��� �ʾҽ��ϴ�!" << endl;
		return 0;
	}
	
	IUnknown* pUnk = NULL;
	    
	hr = ::CoCreateInstance(clsid, NULL, CLSCTX_ALL,
						IID_IUnknown, (void**)&pUnk);
	if(hr != S_OK) {
		cout << "�ν��Ͻ��� ������ �� �����ϴ�!" << endl;
		return 0;
	}
	
	IHello* pHello = NULL;
	
	hr = pUnk->QueryInterface(IID_IHello, (void**)&pHello);
	if(hr != S_OK) {
		cout << "IHello �������̽��� ���� �� �����ϴ�!" << endl;
		return 0;
	}
	
	pUnk->Release();
	
	wchar_t* message = NULL;
	wchar_t* name;
	char buffer[256];
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> buffer;
	name = (wchar_t*)buffer;
	
	hr = pHello->sayHello(name, &message);
	if(hr != S_OK) {
		cout << "�޼��带 ȣ���� �� �����ϴ�!" << endl;
		return 0;
	}
	cout << (char*)message << endl;
	
	::CoTaskMemFree((LPVOID)message);
	
	pHello->Release();

	::CoUninitialize();
	
	return 0;
}

void Foo(IUnknown* pUnk)
{
	HRESULT hr;
	CSmartPtr<IHello> pIHello;
	
	hr = pUnk->QueryInterface(IID_IHello, (void**)&pIHello);
	if(hr != S_OK)
		return;

	wchar_t* message = NULL;
	wchar_t* name;
	char buffer[256];
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> buffer;
	name = (wchar_t*)buffer;

	hr = pIHello->sayHello(name, &message);
	if(hr != S_OK) {
		cout << "�޼��带 ȣ���� �� �����ϴ�!" << endl;
		return;
	}
	cout << (char*)message << endl;
	
	::CoTaskMemFree((LPVOID)message);

	CSmartPtr<IHello> pIHello2;
	pIHello2 = pIHello;

	hr = pIHello2->sayHello(name, &message);
	if(hr != S_OK) {
		cout << "�޼��带 ȣ���� �� �����ϴ�!" << endl;
		return;
	}
	cout << (char*)message << endl;
	
	::CoTaskMemFree((LPVOID)message);
}	

void Foo2(IUnknown* pUnk)
{
	HRESULT hr;
	CSmartQIPtr<IHello, &IID_IHello> pIHello = pUnk;

	wchar_t* message = NULL;
	wchar_t* name;
	char buffer[256];
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> buffer;
	name = (wchar_t*)buffer;

	hr = pIHello->sayHello(name, &message);
	if(hr != S_OK) {
		cout << "�޼��带 ȣ���� �� �����ϴ�!" << endl;
		return;
	}
	cout << (char*)message << endl;
	
	::CoTaskMemFree((LPVOID)message);
}	


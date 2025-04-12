// AddFront.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "EventHandler.h"

[ module(name="AddFront") ];

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	{
		IAddBackPtr pAddBack(__uuidof(CAddBack));

		CEventHandler handler;
		handler.HookEvent(pAddBack);


		SHORT sum;

		cout << "AddEnd : 20" << endl;
		pAddBack->put_AddEnd(20);
		pAddBack->Add();
		pAddBack->get_Sum(&sum);
		cout << "Sum : " << sum << endl;

		cout << "AddEnd : 30" << endl;
		pAddBack->put_AddEnd(30);
		pAddBack->Add();
		pAddBack->get_Sum(&sum);
		cout << "Sum : " << sum << endl;


		handler.UnhookEvent(pAddBack);
	}

	::CoUninitialize();

	return 0;
}


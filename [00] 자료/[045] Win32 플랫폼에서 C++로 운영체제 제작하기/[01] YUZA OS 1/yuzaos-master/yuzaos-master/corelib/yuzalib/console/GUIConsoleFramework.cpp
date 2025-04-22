#include "GUIConsoleFramework.h"
#include <memory.h>
#include <skyoswindow.h>
#include <systemcall_impl.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <yuzaapi.h>
#include "GUIConsole.h"


GUIConsole* pConsole = 0;
QWORD g_qwWindowID = 0;

DWORD WINAPI GUIConsoleProc(LPVOID parameter)
{
	Syscall_RegisterWindowId(&g_qwWindowID);
	CONSOLE_START_STRUCT* console = (CONSOLE_START_STRUCT*)(parameter);
	return console->entry(console->argc, console->argv);
}

bool GUIConsoleFramework::Run(int argc, char** argv, MAIN_IMPL entry)
{
	bool isGrahpicMode = Syscall_IsGraphicMode();

	if (isGrahpicMode)
	{
		CONSOLE_START_STRUCT consoleStruct;
		consoleStruct.argc = argc;
		consoleStruct.argv = argv;
		consoleStruct.entry = entry;

		return MainLoop(&consoleStruct);
	}
		
	return entry(argc, argv);
}

bool GUIConsoleFramework::MainLoop(CONSOLE_START_STRUCT* args)
{
	QWORD qwWindowID = WINDOW_INVALIDID;
	int iWindowWidth, iWindowHeight;
	EVENT stReceivedEvent;
	KEYEVENT* pstKeyEvent;
	WINDOWEVENT* windowEvent;
	RECT stScreenArea;
	KEYDATA stKeyData;


	Syscall_GetScreenArea(&stScreenArea);

	// �������� ũ�� ����, ȭ�� ���ۿ� ���� ������ �ִ� �ʺ�� ���̸� ����ؼ� ���
	iWindowWidth = CONSOLE_WIDTH * FONT_ENGLISHWIDTH + 4;
	iWindowHeight = CONSOLE_HEIGHT * FONT_ENGLISHHEIGHT + WINDOW_TITLEBAR_HEIGHT + 2;

	// ������ ���� �Լ� ȣ��, ȭ�� ����� ����
	RECT rect;
	rect.left = (stScreenArea.right - iWindowWidth) / 2;
	rect.top = (stScreenArea.bottom - iWindowHeight) / 2;
	rect.right = rect.left + iWindowWidth;
	rect.bottom = rect.top + iWindowHeight;

	bool result = Syscall_CreateWindow(&rect, args->argv[0], WINDOW_FLAGS_DEFAULT | WINDOW_FLAGS_RESIZABLE, &qwWindowID);
	// �����츦 �������� �������� ����
	if (qwWindowID == WINDOW_INVALIDID)
	{
		return 0;
	}

	g_qwWindowID = qwWindowID;

	pConsole = new GUIConsole();
	pConsole->Initialize(0, 0);
	pConsole->SetWindowId(qwWindowID);

	Syscall_CreateThread(GUIConsoleProc, args->argv[0], args, 16, 0);
	CONSOLE_START_STRUCT* console = (CONSOLE_START_STRUCT*)args;
	// ���� ȭ�� ���۸� �ʱ�ȭ
	CHARACTER* vstPreviousScreenBuffer = new CHARACTER[CONSOLE_WIDTH * CONSOLE_HEIGHT];
	memset(vstPreviousScreenBuffer, (char)0xFF, CONSOLE_WIDTH * CONSOLE_HEIGHT * sizeof(CHARACTER));

	//--------------------------------------------------------------------------
	// GUI �½�ũ�� �̺�Ʈ ó�� ����
	//--------------------------------------------------------------------------
	while (1)
	{
		// ȭ�� ������ ����� ������ �����쿡 ������Ʈ
		pConsole->ProcessConsoleBuffer(qwWindowID, vstPreviousScreenBuffer);

		// �̺�Ʈ ť���� �̺�Ʈ�� ����
		if (Syscall_ReceiveEventFromWindowQueue(&qwWindowID, &stReceivedEvent) == FALSE)
		{
			Syscall_Sleep(1);
			continue;
		}

		// ���ŵ� �̺�Ʈ�� Ÿ�Կ� ���� ������ ó��
		switch (stReceivedEvent.qwType)
		{
			// Ű �̺�Ʈ ó��
		case EVENT_KEY_DOWN:
		case EVENT_KEY_UP:
			// ���⿡ Ű���� �̺�Ʈ ó�� �ڵ� �ֱ�
			pstKeyEvent = &(stReceivedEvent.stKeyEvent);
			stKeyData.bASCIICode = pstKeyEvent->bASCIICode;
			stKeyData.bFlags = pstKeyEvent->bFlags;
			stKeyData.bScanCode = pstKeyEvent->bScanCode;

			
			// Ű�� �׷��� ���� Ű ť�� �����Ͽ� �� �½�ũ�� �Է����� ����
			pConsole->PutKeyToGUIKeyQueue(&stKeyData);		

			break;
		case EVENT_CONSOLE_KEY:
		{
			pstKeyEvent = &(stReceivedEvent.stKeyEvent);
			if (pstKeyEvent->bFlags & KEY_FLAGS_DOWN)
			{
				//int iNextPrintOffset = pConsole->ConsolePrintString((char*)windowEvent->stringEvent);
				//if (strlen((char*)windowEvent->stringEvent) == 0)
					//break;
				if(pstKeyEvent->bASCIICode != '\n')
					pConsole->ProcessKey(pstKeyEvent->bASCIICode);
				//pConsole->SetCursor(iNextPrintOffset % CONSOLE_WIDTH, iNextPrintOffset / CONSOLE_WIDTH);
			}
			break;
		}

		case EVENT_CONSOLE_PRINT:
		{
			windowEvent = &(stReceivedEvent.stWindowEvent);

			int iNextPrintOffset = pConsole->ConsolePrintString((char*)windowEvent->stringEvent);
			if (strlen((char*)windowEvent->stringEvent) == 0)
				break;

			pConsole->SetCursor(iNextPrintOffset % CONSOLE_WIDTH, iNextPrintOffset / CONSOLE_WIDTH);

			break;
		}
		case EVENT_CONSOLE_COMMAND_END:
		{
			pConsole->PrintPrompt();

			break;
		}
		// ������ �̺�Ʈ ó��
		case EVENT_WINDOW_CLOSE:
		{
			Syscall_Sleep(1);
		}

		Syscall_DeleteWindow(&qwWindowID);
		qwWindowID = WINDOW_INVALIDID;
		return 0;

		break;

		default:
			break;
		}
	}

	return true;
}
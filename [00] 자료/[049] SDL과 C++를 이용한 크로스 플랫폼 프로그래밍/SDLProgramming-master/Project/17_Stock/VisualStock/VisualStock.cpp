// VisualStock.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "VisualStock.h"
#include "IXingDefine.h"
#include "packet\t8407.h"
#include "packet\t8413.h"
#include "packet\t8430.h"
#include "packet\t1302.h"
#include "Company.h"
#include "DayStockGraph.h"

#include "SDL.h"
#include "SDL_gfxPrimitives.h"

#include <stdlib.h>
#include <iostream>

#ifdef WIN32
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "sdl_gfx.lib")
#endif

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];					// ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];			// �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

#include "StockFacade.h"

SDL_Window *pWindow;
SDL_Renderer *pRenderer;
SDL_Texture* pTexture;
SDL_Surface* screen;

HWND g_hWnd = 0;

bool SDLInit();
void SDLFinally();
void PrintEvent(const SDL_Event * event);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ���⿡ �ڵ带 �Է��մϴ�.
	MSG msg;
	HACCEL hAccelTable;

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VISUALSTOCK));
	
	if (!SDLInit())
	{
		return FALSE;
	}

	SDL_EventState(SDL_USEREVENT, SDL_ENABLE);

	bool bGotMsg;
	bool bRunning = true;
	msg.message = WM_NULL;
	PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);

	SDL_RegisterEvents(WM_USER + XM_RECEIVE_DATA);

	bool bGraphRender = false;
	IGraph* pGraph = new DayStockGraph();

	char* pCompanyCode = "036570"; //��������Ʈ ���� �ڵ�
	char* szID = ""; //���̵�
	char* szPassword = ""; //�н�����

	HWND hWnd = GetActiveWindow();
	while (bRunning == true)
	{
		// Use PeekMessage() so we can use idle time to render the scene. 
		bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0);

		if (bGotMsg)
		{
			// Translate and dispatch the message
			if (hAccelTable == NULL || hWnd == NULL ||
				0 == TranslateAccelerator(hWnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				if (msg.message == WM_USER + XM_RECEIVE_DATA)
				{
					StockFacade::GetInstance()->ProcessReceiveData(msg.wParam, msg.lParam);
				}
			}
		}
		else
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						bRunning = false;
					}
					else if (event.key.keysym.sym == SDLK_1)
					{
						
						HWND hWnd = GetActiveWindow();
						StockFacade::GetInstance()->Initialize();
						bool bResult = StockFacade::GetInstance()->Connect(hWnd, szID, szPassword);
						bGraphRender = true;
					}
					else if (event.key.keysym.sym == SDLK_2)
					{
						bool bResult = StockFacade::GetInstance()->RequestT1302(pCompanyCode);
					}
				}
				else if (event.type == SDL_QUIT)
				{
					bRunning = false;
				}
				else if (event.type == SDL_WINDOWEVENT)
				{
					PrintEvent(&event);
				}
			}

			SDL_FillRect(screen, NULL, 0x008800);

			if (bGraphRender == true)
			{
				StockFacade::GetInstance()->Update();
				pGraph->OnRender(pCompanyCode);
			}			
			
			SDL_RenderClear(pRenderer);
			SDL_UpdateTexture(pTexture, NULL, screen->pixels, screen->pitch);
			SDL_RenderCopy(pRenderer, pTexture, NULL, NULL);
			SDL_RenderPresent(pRenderer);
		}
	}

	SDLFinally();

	return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VISUALSTOCK));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_VISUALSTOCK);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	//Company company;
	//company.SerializeToFile(true);
   HWND hWnd;

   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);



   g_hWnd = hWnd;

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND	- ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT	- �� â�� �׸��ϴ�.
//  WM_DESTROY	- ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_USER + XM_RECEIVE_DATA:
	{
									  StockFacade::GetInstance()->ProcessReceiveData(wParam, lParam);
	}
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

bool SDLInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 0;
	}

#ifndef WIN32 
	if (SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &pWindow, &pRenderer) < 0)
#else
	if (SDL_CreateWindowAndRenderer(800, 600, 0, &pWindow, &pRenderer) < 0)
#endif
	{
		std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	int width, height;
	SDL_GetWindowSize(pWindow, &width, &height);

	// if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
	screen = SDL_CreateRGBSurface(0, width, height, 32,
		0,
		0,
		0,
		0);

	if (screen == 0)
	{
		std::cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << std::endl;
		return false;
	}

	pTexture = SDL_CreateTexture(pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		width, height);

	if (pTexture == 0)
	{
		std::cout << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void SDLFinally()
{
	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}

void PrintEvent(const SDL_Event * event)
{
	if (event->type == SDL_WINDOWEVENT) {
		switch (event->window.event) {
		case SDL_WINDOWEVENT_SHOWN:
			SDL_Log("Window %d shown", event->window.windowID);
			break;
		case SDL_WINDOWEVENT_HIDDEN:
			SDL_Log("Window %d hidden", event->window.windowID);
			break;
		case SDL_WINDOWEVENT_EXPOSED:
			SDL_Log("Window %d exposed", event->window.windowID);
			break;
		case SDL_WINDOWEVENT_MOVED:
			SDL_Log("Window %d moved to %d,%d",
				event->window.windowID, event->window.data1,
				event->window.data2);
			break;
		case SDL_WINDOWEVENT_RESIZED:
			SDL_Log("Window %d resized to %dx%d",
				event->window.windowID, event->window.data1,
				event->window.data2);
			break;
		case SDL_WINDOWEVENT_MINIMIZED:
			SDL_Log("Window %d minimized", event->window.windowID);
			break;
		case SDL_WINDOWEVENT_MAXIMIZED:
			SDL_Log("Window %d maximized", event->window.windowID);
			break;
		case SDL_WINDOWEVENT_RESTORED:
			SDL_Log("Window %d restored", event->window.windowID);
			break;
		case SDL_WINDOWEVENT_ENTER:
			SDL_Log("Mouse entered window %d",
				event->window.windowID);
			break;
		case SDL_WINDOWEVENT_LEAVE:
			SDL_Log("Mouse left window %d", event->window.windowID);
			break;
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			SDL_Log("Window %d gained keyboard focus",
				event->window.windowID);
			break;
		case SDL_WINDOWEVENT_FOCUS_LOST:
			SDL_Log("Window %d lost keyboard focus",
				event->window.windowID);
			break;
		case SDL_WINDOWEVENT_CLOSE:
			SDL_Log("Window %d closed", event->window.windowID);
			break;
		default:
			SDL_Log("Window %d got unknown event %d",
				event->window.windowID, event->window.event);
			break;
		}
	}

	if (event->type >= SDL_USEREVENT)
	{
		int i = 1;
	}
}
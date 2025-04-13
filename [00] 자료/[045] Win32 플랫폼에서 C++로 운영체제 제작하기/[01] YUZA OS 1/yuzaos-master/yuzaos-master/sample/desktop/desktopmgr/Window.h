#pragma once

#include "windef.h"
#include "skyoswindow.h"
#include "2DGraphics.h"
#include <InputList.h>
#include <InputQueue.h>
#include <Keyboard.h>
#include <_spinlock.h>

// �������� ������ �����ϴ� �ڷᱸ��
typedef struct kWindowStruct
{
    // ���� �������� ��ġ�� ���� �������� ID
    LISTLINK stLink;

    // �ڷᱸ�� ����ȭ�� ���� ���ɶ�
	Spinlock_t stLock;

    // ������ ���� ����
    RECT stArea;

    // �������� ȭ�� ���� ��巹��
    COLOR* pstWindowBuffer;

    // �����츦 ������ �ִ� �½�ũ�� ID
    QWORD qwTaskID;

    // ������ �Ӽ�
    DWORD dwFlags;

    // �̺�Ʈ ť�� ť���� ����� ����
    QUEUE stKeyEventQueue;
    QUEUE stEventQueue;
    EVENT* pstEventBuffer;
    EVENT* pstKeyEventBuffer;
    
    // ������ ����
    char vcWindowTitle[ WINDOW_TITLEMAXLENGTH + 1 ];
} WINDOW;

// ������ Ǯ�� ���¸� �����ϴ� �ڷᱸ��
typedef struct kWindowPoolManagerStruct
{
    // �ڷᱸ�� ����ȭ�� ���� ���ɶ�
	Spinlock_t stLock;

    // ������ Ǯ�� ���� ����
    WINDOW* pstStartAddress;
    int iMaxCount;
    int iUseCount;

    // �����찡 �Ҵ�� Ƚ��
    int iAllocatedCount;
} WINDOWPOOLMANAGER;

// ������ �Ŵ��� �ڷᱸ��
typedef struct kWindowManagerStruct
{
    // �ڷᱸ�� ����ȭ�� ���� ���ɶ�
	Spinlock_t stLock;

    // ������ ����Ʈ
    LIST stWindowList;

    // ���� ���콺 Ŀ���� X, Y��ǥ
    int iMouseX;
    int iMouseY;

    // ȭ�� ���� ����
    RECT stScreenArea;

    // ���� �޸��� ��巹��
    COLOR* pstVideoMemory;

    // ��� �������� ID
    QWORD qwBackgroundWindowID;
    
    // �̺�Ʈ ť�� ť���� ����� ����
    QUEUE stEventQueue;
    EVENT* pstEventBuffer;

    // ���콺 ��ư�� ���� ����
    BYTE bPreviousButtonStatus;
    
    // �̵� ���� �������� ID�� ������ �̵� ���
    QWORD qwMovingWindowID;
	bool bWindowMoveMode;
    
    // ������ ũ�� ���� ���� ũ�� ���� ���� �������� ID, ���� ���� �������� ����
    bool bWindowResizeMode;    
    QWORD qwResizingWindowID;
    RECT stResizingWindowArea;
    
    // ȭ�� ������Ʈ�� ��Ʈ�� ������ ��巹��
    BYTE* pbDrawBitmap;
} WINDOWMANAGER;


// ȭ�鿡 ������Ʈ�� ������ ��Ʈ�� ������ �����ϴ� �ڷᱸ��
typedef struct kDrawBitmapStruct
{
    // ������Ʈ�� ȭ�� ����
    RECT stArea;
    // ȭ�� ������ ������ ����� ��Ʈ���� ��巹��
    BYTE* pbBitmap;
} DRAWBITMAP;

// ������ Ǯ ����
static void kInitializeWindowPool( void );
static WINDOW* kAllocateWindow( void );
static void kFreeWindow( QWORD qwID );

// ������� ������ �Ŵ��� ����
void kInitializeGUISystem(LinearBufferInfo* bufferInfo);
WINDOWMANAGER* kGetWindowManager( void );
QWORD kGetBackgroundWindowID( void );
void kGetScreenArea( RECT* pstScreenArea );
QWORD kCreateWindow( int iX, int iY, int iWidth, int iHeight, DWORD dwFlags, const char* pcTitle );
QWORD kCreateSkyWindow(int iX, int iY, int iWidth, int iHeight, DWORD dwFlags, const char* pcTitle);
bool kDeleteWindow( QWORD qwWindowID );
bool kDeleteAllWindowInTaskID( QWORD qwTaskID );
WINDOW* kGetWindow( QWORD qwWindowID );
WINDOW* kGetWindowWithWindowLock( QWORD qwWindowID );
bool kShowWindow( QWORD qwWindowID, bool bShow );
bool kRedrawWindowByArea( const RECT* pstArea, QWORD qwDrawWindowID );
static void kCopyWindowBufferToFrameBuffer( const WINDOW* pstWindow,
        DRAWBITMAP* pstDrawBitmap );
QWORD kFindWindowByPoint( int iX, int iY );
QWORD kFindWindowByTitle( const char* pcTitle );
bool kIsWindowExist( QWORD qwWindowID );
QWORD kGetTopWindowID( void );
bool kMoveWindowToTop( QWORD qwWindowID );
bool kIsInTitleBar( QWORD qwWindowID, int iX, int iY );
bool kIsInCloseButton( QWORD qwWindowID, int iX, int iY );
bool kMoveWindow( QWORD qwWindowID, int iX, int iY );
static bool kUpdateWindowTitle( QWORD qwWindowID, bool bSelectedTitle );
bool kResizeWindow( QWORD qwWindowID, int iX, int iY, int iWidth, int iHeight );
bool kIsInResizeButton(QWORD qwWindowID, int iX, int iY);

// ��ǥ ��ȯ ����
bool kGetWindowArea( QWORD qwWindowID, RECT* pstArea );
bool kConvertPointScreenToClient( QWORD qwWindowID, const POINT* pstXY,
        POINT* pstXYInWindow );
bool kConvertPointClientToScreen( QWORD qwWindowID, const POINT* pstXY,
        POINT* pstXYInScreen );
bool kConvertRectScreenToClient( QWORD qwWindowID, const RECT* pstArea,
        RECT* pstAreaInWindow );
bool kConvertRectClientToScreen( QWORD qwWindowID, const RECT* pstArea,
        RECT* pstAreaInScreen );

// ȭ�� ������Ʈ ����
bool kUpdateScreenByID( QWORD qwWindowID );
bool kUpdateScreenByWindowArea( QWORD qwWindowID, const RECT* pstArea );
bool kUpdateScreenByScreenArea( const RECT* pstArea );

//  �̺�Ʈ ť ����
bool kSendEventToWindow( QWORD qwWindowID, const EVENT* pstEvent );
bool kReceiveEventFromWindowQueue( QWORD qwWindowID, EVENT* pstEvent );
char kGetKeyFromConsoleWindow(QWORD qwWindowID);

bool kSendEventToWindowManager( const EVENT* pstEvent );
bool kReceiveEventFromWindowManagerQueue( EVENT* pstEvent );
bool kSetMouseEvent( QWORD qwWindowID, QWORD qwEventType, int iMouseX, int iMouseY,
        BYTE bButtonStatus, EVENT* pstEvent );
bool kSetWindowEvent( QWORD qwWindowID, QWORD qwEventType, EVENT* pstEvent );
void kSetKeyEvent( QWORD qwWindow, const KEYDATA* pstKeyData, EVENT* pstEvent );

// ������ ���ο� �׸��� �Լ��� ���콺 Ŀ�� ����
bool kDrawWindowFrame( QWORD qwWindowID );
bool kDrawWindowBackground( QWORD qwWindowID );
bool kDrawWindowTitle( QWORD qwWindowID, const char* pcTitle, bool bSelectedTitle );
bool kDrawButton( QWORD qwWindowID, RECT* pstButtonArea, COLOR stBackgroundColor,
        const char* pcText, COLOR stTextColor );
bool kDrawPixel( QWORD qwWindowID, int iX, int iY, COLOR stColor );
bool kDrawLine( QWORD qwWindowID, int iX1, int iY1, int iX2, int iY2, COLOR stColor );
bool kDrawRect( QWORD qwWindowID, int iX1, int iY1, int iX2, int iY2,
        COLOR stColor, bool bFill );
bool kDrawCircle( QWORD qwWindowID, int iX, int iY, int iRadius, COLOR stColor,
	bool bFill );
bool kDrawText( QWORD qwWindowID, int iX, int iY, COLOR stTextColor,
        COLOR stBackgroundColor, const char* pcString, int iLength );
static void kDrawCursor( int iX, int iY );
void kMoveCursor( int iX, int iY );
void kGetCursorPosition( int* piX, int* piY );
bool kBitBlt( QWORD qwWindowID, int iX, int iY, COLOR* pstBuffer, int iWidth,
        int iHeight , bool bTitleBar = true);
bool kBitBltWithRect(QWORD qwWindowID, RECT* rect, COLOR* pstBuffer, int width, int height);
void kDrawBackgroundImage( void );

//  ȭ�� ������Ʈ�� ����ϴ� ȭ�� ������Ʈ ��Ʈ�� ����
bool kCreateDrawBitmap( const RECT* pstArea, DRAWBITMAP* pstDrawBitmap );
static bool kFillDrawBitmap( DRAWBITMAP* pstDrawBitmap, RECT* pstArea, bool bFill );
inline bool kGetStartPositionInDrawBitmap( const DRAWBITMAP* pstDrawBitmap,
        int iX, int iY, int* piByteOffset, int* piBitOffset );
inline bool kIsDrawBitmapAllOff( const DRAWBITMAP* pstDrawBitmap );

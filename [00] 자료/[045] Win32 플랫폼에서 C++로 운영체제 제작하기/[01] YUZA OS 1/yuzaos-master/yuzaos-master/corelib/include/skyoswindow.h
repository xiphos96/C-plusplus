#pragma once
#include <minwindef.h>

#define FONT_ENGLISHWIDTH   8
#define FONT_ENGLISHHEIGHT  16

// �ѱ� ��Ʈ�� �ʺ�� ����
#define FONT_HANGULWIDTH   16
#define FONT_HANGULHEIGHT  16

// �����츦 ������ �� �ִ� �ִ� ����
#define WINDOW_MAXCOUNT             2048
// ������ ID�� ������ Ǯ ���� �������� ����ϴ� ��ũ��
// ���� 32��Ʈ�� Ǯ ���� �������� ��Ÿ��
#define GETWINDOWOFFSET( x )        ( ( x ) & 0xFFFFFFFF )
// ������ ������ �ִ� ����
#define WINDOW_TITLEMAXLENGTH       40
// ��ȿ���� ���� ������ ID
#define WINDOW_INVALIDID            0xFFFFFFFFFFFFFFFF

// �������� �Ӽ�
// �����츦 ȭ�鿡 ��Ÿ��
#define WINDOW_FLAGS_SHOW               0x00000001
// ������ �׵θ� �׸�
#define WINDOW_FLAGS_DRAWFRAME          0x00000002
// ������ ���� ǥ���� �׸�
#define WINDOW_FLAGS_DRAWTITLE          0x00000004
// ������ ũ�� ���� ��ư�� �׸�
#define WINDOW_FLAGS_RESIZABLE          0x00000008
// ������ �⺻ �Ӽ�, ���� ǥ���ٰ� �������� ��� �׸��� ȭ�鿡 �����츦 ���̰� ����
#define WINDOW_FLAGS_DEFAULT        ( WINDOW_FLAGS_SHOW | WINDOW_FLAGS_DRAWFRAME | \
                                      WINDOW_FLAGS_DRAWTITLE )

// ���� ǥ������ ����
#define WINDOW_TITLEBAR_HEIGHT      21
// �������� �ݱ� ��ư�� ũ��
#define WINDOW_XBUTTON_SIZE         19
// �������� �ּ� �ʺ�, ��ư 2���� �ʺ� 30�ȼ��� ���� ���� Ȯ��
#define WINDOW_WIDTH_MIN            ( WINDOW_XBUTTON_SIZE * 2 + 30 )
// �������� �ּ� ����, ���� ǥ������ ���̿� 30�ȼ��� ���� ���� Ȯ��
#define WINDOW_HEIGHT_MIN           ( WINDOW_TITLEBAR_HEIGHT + 30 )

// �������� ����
#define WINDOW_COLOR_FRAME                      RGB( 109, 218, 22 )
#define WINDOW_COLOR_BACKGROUND                 RGB( 255, 255, 255 )
#define WINDOW_COLOR_TITLEBARTEXT               RGB( 255, 255, 255 )
#define WINDOW_COLOR_TITLEBARACTIVEBACKGROUND   RGB( 79, 204, 11 )
#define WINDOW_COLOR_TITLEBARINACTIVEBACKGROUND RGB( 55, 135, 11 )
#define WINDOW_COLOR_TITLEBARBRIGHT1            RGB( 183, 249, 171 )
#define WINDOW_COLOR_TITLEBARBRIGHT2            RGB( 150, 210, 140 )
#define WINDOW_COLOR_TITLEBARUNDERLINE          RGB( 46, 59, 30 )
#define WINDOW_COLOR_BUTTONBRIGHT               RGB( 229, 229, 229 )
#define WINDOW_COLOR_BUTTONDARK                 RGB( 86, 86, 86 )
#define WINDOW_COLOR_SYSTEMBACKGROUND           RGB( 232, 255, 232 )
#define WINDOW_COLOR_XBUTTONLINECOLOR           RGB( 71, 199, 21 )

// ��� �������� ����
#define WINDOW_BACKGROUNDWINDOWTITLE            "SYS_BACKGROUND"


// ���콺 Ŀ���� �ʺ�� ����
#define MOUSE_CURSOR_WIDTH                  20
#define MOUSE_CURSOR_HEIGHT                 20

// Ŀ�� �̹����� ����
#define MOUSE_CURSOR_OUTERLINE              RGB(0, 0, 0 )
#define MOUSE_CURSOR_OUTER                  RGB( 79, 204, 11 )
#define MOUSE_CURSOR_INNER                  RGB( 232, 255, 232 )

// �̺�Ʈ ť�� ũ��
#define EVENTQUEUE_WINDOWMAXCOUNT           100
#define EVENTQUEUE_WNIDOWMANAGERMAXCOUNT    WINDOW_MAXCOUNT

// ������� ������ �Ŵ��� �½�ũ ���̿��� ���޵Ǵ� �̺�Ʈ�� ����
// ���콺 �̺�Ʈ
#define EVENT_UNKNOWN                                   0
#define EVENT_MOUSE_MOVE                                1
#define EVENT_MOUSE_LBUTTONDOWN                         2
#define EVENT_MOUSE_LBUTTONUP                           3
#define EVENT_MOUSE_RBUTTONDOWN                         4
#define EVENT_MOUSE_RBUTTONUP                           5
#define EVENT_MOUSE_MBUTTONDOWN                         6
#define EVENT_MOUSE_MBUTTONUP                           7
// ������ �̺�Ʈ
#define EVENT_WINDOW_SELECT                             8
#define EVENT_WINDOW_DESELECT                           9
#define EVENT_WINDOW_MOVE                               10
#define EVENT_WINDOW_RESIZE                             11
#define EVENT_WINDOW_CLOSE                              12
// Ű �̺�Ʈ
#define EVENT_KEY_DOWN                                  13
#define EVENT_KEY_UP                                    14
// ȭ�� ������Ʈ �̺�Ʈ
#define EVENT_WINDOWMANAGER_UPDATESCREENBYID            15
#define EVENT_WINDOWMANAGER_UPDATESCREENBYWINDOWAREA    16
#define EVENT_WINDOWMANAGER_UPDATESCREENBYSCREENAREA    17

// ȭ�鿡 ������Ʈ�� �� ������ ������Ʈ�� ������ �����ص� ����
#define WINDOW_OVERLAPPEDAREALOGMAXCOUNT                20

#define EVENT_CONSOLE_PRINT							    21
#define EVENT_CONSOLE_COMMAND_END						22
#define EVENT_CONSOLE_KEY								23


typedef DWORD                COLOR;

#pragma pack(push, 1)

#ifdef WIN32STUB
typedef long long			QWORD;
#else
//32��Ʈ ó�� ARGB
#define ARGB(a, r, g, b)  (( BYTE )( r ) << 24) | (( BYTE )( r ) << 16) | (( BYTE )( g ) << 8 ) | (( BYTE )( b ) << 0 )
#define RGB(r, g, b)  (( BYTE )( r ) << 16) | (( BYTE )( g ) << 8 ) | (( BYTE )( b ) << 0 )

//16��Ʈ ó��
// 0~255 ������ R, G, B�� 16��Ʈ �� �������� ��ȯ�ϴ� ��ũ��
// 0~255�� ������ 0~31, 0~63���� ����Ͽ� ����ϹǷ� ���� 8�� 4�� ��������� ��
// ������ 8�� ������ 4�� >> 3�� >> 2�� ��ü
//#define RGB( r, g, b )      ( ( ( BYTE )( r ) >> 3 ) << 11 | \
  //              ( ( ( BYTE )( g ) >> 2 ) ) << 5 |  ( ( BYTE )( b ) >> 3 ) )

//16��Ʈ�� ��ȯ�ϴ� ���
//16��Ʈ �κ��� RGB ��ũ�θ� ����ϰ�
//kMemSetDWord �Լ��� kMemSetWord �Լ��� ��ȯ�� ��

// �簢���� ������ ��� �ڷᱸ��
typedef struct kRectangleStruct
{
	int left;
	int top;
	int right;
	int bottom;
} RECT;


typedef struct tag_RectangleInfo
{
	int left;
	int top;
	int width;
	int height;
} RECTINFO;


// ���� ������ ��� �ڷᱸ��
typedef struct kPointStruct
{
	// X�� Y�� ��ǥ
	int iX;
	int iY;
} POINT;

#endif

typedef struct kTEXTCOLOR
{
	COLOR textColor;
	COLOR backgroundColor;
} TEXTCOLOR;

// ���콺 �̺�Ʈ �ڷᱸ��
typedef struct kMouseEventStruct
{
	// ������ ID
	QWORD qwWindowID;

	// ���콺 X,Y��ǥ�� ��ư�� ����
	POINT stPoint;
	BYTE bButtonStatus;
} MOUSEEVENT;

// Ű �̺�Ʈ �ڷᱸ��
typedef struct kKeyEventStruct
{
	// ������ ID
	QWORD qwWindowID;

	// Ű�� ASCII �ڵ�� ��ĵ �ڵ�
	BYTE bASCIICode;
	BYTE bScanCode;

	// Ű �÷���
	BYTE bFlags;
} KEYEVENT;

// ������ �̺�Ʈ �ڷᱸ��
typedef struct kWindowEventStruct
{
	// ������ ID
	QWORD qwWindowID;

	// ���� ����
	RECT stArea;
	//���ڿ� ��� �̺�Ʈ ���� ������
	char stringEvent[4096];
} WINDOWEVENT;

// �̺�Ʈ �ڷᱸ��
typedef struct kEventStruct
{
	// �̺�Ʈ Ÿ��
	QWORD qwType;

	// �̺�Ʈ ������ ������ ������ ����ü
	union
	{
		// ���콺 �̺�Ʈ ���� ������
		MOUSEEVENT stMouseEvent;

		// Ű �̺�Ʈ ���� ������
		KEYEVENT stKeyEvent;

		// ������ �̺�Ʈ ���� ������
		WINDOWEVENT stWindowEvent;

		// ���� �̺�Ʈ �ܿ� ���� �̺�Ʈ�� ���� ������
		DWORD vqwData[3];
	};
} EVENT;

#pragma pack(pop)
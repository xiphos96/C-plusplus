#pragma once
#include <windef.h>
#include <skyoswindow.h>

////////////////////////////////////////////////////////////////////////////////
//
// ��ũ��
//
////////////////////////////////////////////////////////////////////////////////
// ������� �ִ� ����
#define MAXBUBBLECOUNT      50
// ������� ������
#define RADIUS              16
// ������� �⺻ �ӵ�
#define DEFAULTSPEED        3
// �÷��̾��� �ִ� ����
#define MAXLIFE             20

// �������� �ʺ�� ����
#define WINDOW_WIDTH        250
#define WINDOW_HEIGHT       350

// ���� ���� ������ ����
#define INFORMATION_HEIGHT  20


////////////////////////////////////////////////////////////////////////////////
//
// ����ü
//
////////////////////////////////////////////////////////////////////////////////
// ������� ������ �����ϴ� �ڷᱸ��
typedef struct BubbleStruct
{
	// X, Y ��ǥ
	int qwX;
	int qwY;

	// �������� �ӵ�(Y�� ��ȭ��)
	int qwSpeed;

	// ����� ����
	COLOR stColor;

	// ����ִ��� ����
	bool bAlive;
} BUBBLE;

// ���� ������ �����ϴ� �ڷᱸ��
typedef struct GameInfoStruct
{
	//-------------------------------------------------------------------------
	// ������� �����ϴµ� �ʿ��� �ʵ�
	//-------------------------------------------------------------------------
	// ������� ������ �����ϴ� ����
	BUBBLE* pstBubbleBuffer;

	// ��� �ִ� ������� ��
	int iAliveBubbleCount;

	//-------------------------------------------------------------------------
	// ������ �����ϴµ� �ʿ��� �ʵ�
	//-------------------------------------------------------------------------
	// �÷��̾��� ����
	int iLife;

	// ������ ����
	QWORD qwScore;

	// ������ ���� ����
	bool bGameStart;
} GAMEINFO;

////////////////////////////////////////////////////////////////////////////////
//
// �Լ�
//
////////////////////////////////////////////////////////////////////////////////
bool Initialize(void);
bool CreateBubble(void);
void MoveBubble(void);
void DeleteBubbleUnderMouse(POINT* pstMouseXY);
void DrawInformation(QWORD qwWindowID);
void DrawGameArea(QWORD qwWindowID, POINT* pstMouseXY);
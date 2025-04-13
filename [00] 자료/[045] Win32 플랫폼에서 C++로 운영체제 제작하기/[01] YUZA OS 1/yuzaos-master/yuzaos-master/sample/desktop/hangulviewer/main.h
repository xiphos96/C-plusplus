#pragma once
#include <minwindef.h>

 // �ִ�� ǥ���� �� �ִ� ������ ��
#define MAXLINECOUNT        ( 256 * 1024 )
// ������ ������ ���� ���� ǥ�� ���� ������ ���� ����
#define MARGIN              5
// ���� �����ϴ� ũ��
#define TABSPACE            4

////////////////////////////////////////////////////////////////////////////////
//
// ����ü
//
////////////////////////////////////////////////////////////////////////////////
// �ؽ�Ʈ ������ �����ϴ� ����ü
typedef struct TextInformationStruct
{
	// ���� ���ۿ� ������ ũ��
	BYTE* pbFileBuffer;
	DWORD dwFileSize;

	// ���� ���� ǥ�� ������ ����� �� �ִ� ���� ���� ���� �� ���� ��
	int iColumnCount;
	int iRowCount;

	// ���� ��ȣ�� ���� ���� �������� �����ϴ� ����
	DWORD* pdwFileOffsetOfLine;

	// ������ �ִ� ���� ��
	int iMaxLineCount;
	// ���� ������ �ε���
	int iCurrentLineIndex;

	// ���� �̸�
	char vcFileName[100];

} TEXTINFO;

////////////////////////////////////////////////////////////////////////////////
//
// �Լ�
//
////////////////////////////////////////////////////////////////////////////////
bool ReadFileToBuffer(const char* pcFileName, TEXTINFO* pstInfo);
void CalculateFileOffsetOfLine(int iWidth, int iHeight, TEXTINFO* pstInfo);
bool DrawTextBuffer(QWORD qwWindowID, TEXTINFO* pstInfo);

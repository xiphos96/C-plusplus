#pragma once
#include "minwindef.h"

class GUIConsole;

#define CONSOLESHELL_MAXCOMMANDBUFFERCOUNT  300
//#define CONSOLESHELL_PROMPTMESSAGE          "SKYOS32>"

// ���ڿ� �����͸� �Ķ���ͷ� �޴� �Լ� ������ Ÿ�� ����
typedef void ( * CommandFunction ) (GUIConsole* pConsole, const char* pcParameter );

#pragma pack( push, 1 )

// ���� Ŀ�ǵ带 �����ϴ� �ڷᱸ��
typedef struct kShellCommandEntryStruct
{
    // Ŀ�ǵ� ���ڿ�
    char* pcCommand;
    // Ŀ�ǵ��� ����
    char* pcHelp;
    // Ŀ�ǵ带 �����ϴ� �Լ��� ������
    CommandFunction pfFunction;
} SHELLCOMMANDENTRY;

// �Ķ���͸� ó���ϱ����� ������ �����ϴ� �ڷᱸ��
typedef struct kParameterListStruct
{
    // �Ķ���� ������ ��巹��
    const char* pcBuffer;
    // �Ķ������ ����
    int iLength;
    // ���� ó���� �Ķ���Ͱ� �����ϴ� ��ġ
    int iCurrentPosition;
} PARAMETERLIST;

#pragma pack( pop )

// ���� �� �ڵ�
int StartConsoleShell(int argc, char** argv);
void kInitializeParameter( PARAMETERLIST* pstList, const char* pcParameter );
int kGetNextParameter( PARAMETERLIST* pstList, char* pcParameter );

// Ŀ�ǵ带 ó���ϴ� �Լ�
void kHelp(GUIConsole* pConsole, const char* pcParameterBuffer );
void kCls(GUIConsole* pConsole, const char* pcParameterBuffer );
void kShowTotalRAMSize(GUIConsole* pConsole, const char* pcParameterBuffer );
void kShutdown(GUIConsole* pConsole, const char* pcParamegerBuffer );

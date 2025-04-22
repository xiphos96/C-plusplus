#pragma once

#include <windows.h>
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "pefile.h"
#include "mydbg2.h"

#define CM_PRINTF			printf
#define CM_MALLOC			malloc
#define CM_FREE				free

#define CM_DEFAULT_ENT		128



typedef enum {
	KWT_UNKNOWN = 0,
	KWT_NUMBER,				// ����
	KWT_STR,				// ���ڿ�

	KWT_COLON,				// �ݷ�
	KWT_SEMI_COLON,			// �����ݷ�
	KWT_QUESTION,			// ����ǥ
	KWT_F,					// F
	KWT_I,					// I
	KWT_TEXT,
	KWT_SEGMENT,
	KWT_PROC,
	KWT_ASSIGN,
	KWT_ENDP,
	KWT_PARA,
	KWT_NEAR,
	KWT_PREFERRED,

	END_OF_KWT
} KWT_TAG;

#pragma pack( push, 1 )

struct HashEntTag {
	int					nSymIndex;			// �ɺ� �ε����� ����Ų��.
	struct HashEntTag	*pNext;				// ���� �ؽ� ��Ʈ���� ������ (�浹�� ����� ��ũ)
};
typedef struct HashEntTag HashEntStt;

#define MAX_HASH_ENT	8192		

typedef struct tag_CodeMap 
{
	MyCoffDbg2Stt	d;
	int				nMaxFileEnt;			// ���� �Ҵ�Ǿ� �ִ� ���� ��Ʈ���� ����
	int				nMaxFuncEnt;			// ���� �Ҵ�Ǿ� �ִ� �Լ� ��Ʈ���� ����
	int				nMaxLineEnt;			// ���� �Ҵ�Ǿ� �ִ� ���� ��Ʈ���� ����
	int				nMaxLocalEnt;			// ���� �Ҵ�Ǿ� �ִ� ���� ��Ʈ���� ����
	int				nMaxStrTblSize;			// ���� �Ҵ�Ǿ� �ִ� �ɺ� ������ ũ��
	int				nTotalProcessedFiles;	// ó���� �� ���� �� (ASM�� OBJ�� COD ������ ����.)
	int				nTotalUselessFunction;	// COD ���Ͽ��� ������ MAP ���Ͽ��� �������� ����(LINK���� ����) �Լ�
	
	int				*pSymIndex;				// �ɺ��� �ε���
	int				nTotalSymIndex;			// �Էµ� �ɺ� �ε��� ����
	int				nMaxSymIndex;			// ���� �ε��� ��Ʈ���� ����

	HashEntStt		*hash_index[8192];		// �ؽ� �ε���
	int				nTotalCollision;		// �浹�� ����	
	int				nMaxCollision;			// �ִ�� �� �浹 ����
	DWORD			dwLinkerBaseAddr;		// ��Ŀ�� ������ ���̽� �ּ�

} CodeMap;

#pragma pack( pop )
							 
int MakeCodeMap( char *pExeFile, char *pDbgFile );
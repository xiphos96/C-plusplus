#pragma once

#pragma pack( push, 1 )

struct _MY_IMAGE_LINENUMBER;

typedef struct tag_MY_MyCoffDbg2FileStt {
	int				nNameIndex;
	int				nLineIndex;
	int				nTotalLine;
	unsigned long	dwAddr;
	unsigned long	dwSize;
}MyCoffDbg2FileStt;


typedef struct tag_MyCoffDbg2FuncStt {
	int				nNameIndex;
	int				nFileIndex;
	int				nLineIndex;
	int				nLocalIndex;
	int				nTotalLocal;
	unsigned long	dwAddr;
	unsigned long   dwSize;
}MyCoffDbg2FuncStt;

// �Լ��� nLocalIndex���� ���� ���� parameter, local variable�� �迭�� ����.
// nEBPAdder�� '-'�̸� Local Variable, '+'�̸� �ķ����ͷ� �ν�.
typedef struct tag_MY_COFF_DBG2_LOCAL_TAG {
	int				nNameIndex;		// �Լ� �ķ����ͳ� �������� �̸� �ε���.  
	int				nEBPAdder;		// EBP�� ���ϰų� �� ��.
} MyCoffDbg2LocalStt;

#define MY_COFF_DBG2_MAGIC_STR "COFF"

typedef struct tag_MyCoffDbg2Stt {
	char				szMagicStr[5];			// magic string "COFF"
	DWORD				dwSize;					// debug info size

	MyCoffDbg2FileStt* pFileTbl;
	int					nTotalFileEnt;

	MyCoffDbg2FuncStt* pFuncTbl;
	int					nTotalFuncEnt;

	int* pFuncNameIndex;
	int* pFuncAddrIndex;

	struct _MY_IMAGE_LINENUMBER* pLineTbl;
	int					nTotalLineEnt;

	MyCoffDbg2LocalStt* pLocalTbl;
	int					nTotalLocalEnt;

	char* pStrTbl;
	int					nStrTblSize;
}MyCoffDbg2Stt;

#pragma pack( pop )


#ifdef __cplusplus
extern "C" {
#endif
	int is_coff_dbg2(char* pB);
	MyCoffDbg2Stt* get_coff_dbg2(char* pB);
	MyCoffDbg2Stt* load_mydbg2_info(char* pFileName);
	MyCoffDbg2FuncStt* get_func_ent_by_name(MyCoffDbg2Stt* pMy, char* pS);
	MyCoffDbg2FuncStt* get_func_ent_by_addr(MyCoffDbg2Stt* pMy, DWORD dwAddr);
	MY_IMAGE_DEBUG_DIRECTORY* find_coff_dbg_info(MY_IMAGE_DEBUG_DIRECTORY* pDbgDir);
	MyCoffDbg2FuncStt* get_nearest_func_ent_by_addr(MyCoffDbg2Stt* pMy, DWORD dwAddr);
	int get_file_func_lineno(MyCoffDbg2Stt* pMy, char* pFileName, char* pFuncName, DWORD dwAddr);

	DWORD dwHexValue(char* pS);

#ifdef __cplusplus
}
#endif

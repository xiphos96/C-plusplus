#pragma once
#include "common.h"
#include "MirrorFileModel.h"


typedef  SYSTEMTIME CTime;

#ifdef _MAC_UNIX
#include "winapi.h"
#include "Support.h"
typedef  SYSTEMTIME CTime;
#endif
#include "MemFS.h"	// Added by ClassView

//#ifdef _WINDOWS
//#define printmsg(x)	AfxMessageBox(_T(x))
//#endif

#define			DEFAULT_VOLUME_NAME		"NO NAME"

struct ImgFileStatus
{	
	CTime m_ctime;          // creation date/time of file
	CTime m_mtime;          // last modification date/time of file
	CTime m_atime;          // last access date/time of file
	LONG m_size;            // logical size of file in bytes
	BYTE m_attribute;       // logical OR of CFile::Attribute enum values
	BYTE _m_padding;        // pad the structure to a WORD
	TCHAR m_szFullName[MAX_PATH]; // absolute path name
};

struct ImgFileHandle		// �����ļ��������
//class ImageFileHandle
{
	HANDLE _handle;
	UINT  _stAddr;			// �ļ���������ʼ��ַ
	UINT  _curPos;			// �ھ����ļ��и��ļ���ǰ��ʵ�ʵ�ַ
	UINT  _tabStAddr;		// �ļ�Ŀ¼���ڵ�ַ
	UINT  _curRetpos;		// �ļ����λ��(������)--�ļ���ǰ��������λ��
	DWORD _accMode;
	DWORD _shareMode;		// ������Ϣ
	Fat_Directory _fileTab; 
	UINT _exceedsize;
};

struct ImgFindHandle // ������Ҿ��
{
	HANDLE _handle;
	UINT   _nIndex;	// ��ǰĿ¼��Directory entry ������
	UINT   _curCluster; // ��ǰ�صı��
	UINT   _nRetIndex; // ���ڵ�ǰλ��
	WIN32_FIND_DATA _findData;
	Fat_Directory _curFileTab;
};



enum
{
	ATTR_READ_ONLY  = 0x01,
	ATTR_HIDDEN		= 0x02,
	ATTR_SYSTEM		= 0x04,
	ATTR_VOLUME_ID  = 0x08,
	ATTR_DIRECTORY  = 0x10,
	ATTR_ARCHIVE    = 0x20,
	ATTR_NORMAL		= 0x80,
	ATTR_LONG_NAME  = ATTR_READ_ONLY 
					  |ATTR_HIDDEN 
					  |ATTR_SYSTEM 
					  |ATTR_VOLUME_ID,
					  
	ATTR_LONG_NAME_MASK = ATTR_READ_ONLY 
					|ATTR_HIDDEN 
					|ATTR_SYSTEM 
					|ATTR_VOLUME_ID 
					|ATTR_DIRECTORY
					|ATTR_ARCHIVE,
	LAST_LONG_ENTRY = 0x40,
};

BOOL IsVolLabel(Flag fAttr);
BOOL IsFile(Flag fAttr);
BOOL IsLongDir(Flag fAttr);
BOOL IsFoulder(Flag fAttr);
BOOL IsReadOnly(Flag fAttr);
/*

BOOL IsHide(Flag fAttr);
BOOL IsSystem(Flag fAttr);
BOOL IsReadOnly(Flag fAttr);
BOOL Is(Flag fAttr);*/

class DiskImgFile:public MirrorFile 
{
public:
	DiskImgFile();
	virtual ~DiskImgFile();
public:
//////////////////////////////////////////////////////////////////////////
// Assite Function
	//-----------------------------------------------------------------------------
	// ChkSum()
	// Returns an unsigned byte checksum computed on an unsigned byte
	// array. The array must be 11 bytes long and is assumed to contain
	// a name stored in the format of a MS-DOS directory entry.
	// Passed: pFcbName Pointer to an unsigned byte array assumed to be
	// 11 bytes long.
	// Returns: Sum An 8-bit unsigned checksum of the array pointed
	// to by pFcbName.
	//------------------------------------------------------------------------------
	unsigned char ChkSum (LPCSTR pFcbName);
	BOOL  GenerateShortName(LPCTSTR lpName, LPSTR lpShortName);//LPSTR GenerateShortName(LPCSTR lpName);
	INT	  CalcNeedTabCount(LPCTSTR lptName);									// �������ֳ��ȼ�����ҪĿ¼��Ŀ��Ŀ
	BOOL  IsExit(LPCTSTR lpName);											// �ж�Ŀ¼(�ļ�)���ڵ�ǰĿ¼���Ƿ����
	BOOL  GetShortNameNumicTail(LPCSTR basicName, char& tailNumic);			// ���������ֺ�׺
	
	virtual UINT  RelatAddrToCluster(IN UINT uRetAddr);								// ӳ�亯����ʵ��ʵ��ƫ��λ�õ���
	virtual UINT  ClusterToRelatAddr(IN UINT uCluNm);								// ӳ�亯���Ӵص�ʵ��ƫ��λ��
	virtual void  InitializeClus(IN UINT clusNum);									// ��ʼ����
	virtual BOOL  SetClus(IN UINT clusNum, IN UINT nValue);							// ���ô���
	virtual BOOL  SetClusEx(IN UINT StartClusNum, IN UINT nNeedMoreClus);			// ���ô��� , Add by Joelee
	virtual BOOL  SetClusFreeStatus(IN UINT StartClusNum);							// ɾ������ , Add by Joelee
	virtual UINT  GetFirstFreeClusNum();									// ���ؿ��еĴغţ���2��ʼ
	virtual UINT  GetNextFreeClusNum(UINT StartClusNum);						// ���ؿ��еĴغţ���StartClusNum��ʼ , Add by Joelee

	BOOL  SetCurrentDirectory(IN LPCTSTR lptPathName);						// ���õ�ǰ·��
	BOOL  GetCurrentDirectory(OUT LPTSTR lpBuffer, IN DWORD nBufferLen);		// ���ص�ǰ·��

	BOOL  ParaDirectoryFromStr(IN LPCTSTR lptDirName, OUT vector<Fat_Directory>& fatDir); // ����imgĿ¼·��
	BOOL  ParaPathFromStr(IN LPCTSTR lpPath, OUT vector<DirPaths>& paths);			// ����·��
	virtual BOOL  TrimDirEntrySpace();		// ����ɾ���ļ�����Ŀ¼��FAT_Directory Entries�Ŀռ�


	virtual BOOL  GetDirectoryTabEx(OUT Fat_Directory& dir, OUT LPTSTR lptLongName, IN OUT INT& nIndex);	// ���ص�ǰĿ¼�µ�nIndex��Ŀ¼
	virtual BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN OUT INT& nIndex);							// ���ص�ǰĿ¼�µ�nIndex��Ŀ¼
	virtual BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN LPCTSTR longName);							// ���ص�ǰĿ¼����ΪlongName ��Ŀ¼

	
	virtual BOOL  GetDirectoryTabEx(OUT Fat_Directory& dir, IN UINT clus, OUT LPTSTR lptLongName, IN OUT INT& nIndex); // ���ش�clus��Ŀ¼�µ�nIndex��Ŀ¼
	virtual BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN UINT clus, IN OUT INT& nIndex);						 // ���ش�clus��Ŀ¼�µ�nIndex��Ŀ¼
	virtual BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN UINT clus, IN LPCTSTR longName);						 // ���ش�clus��Ŀ¼�³���ΪlongName��Ŀ¼

	virtual BOOL  GetDirectoryLongName(OUT LPTSTR lpBuffer, IN DWORD nBufferLen, IN Fat_Directory dir);	 // ��ȡ����

	virtual int  strcmpnocase(LPCTSTR string1,LPCTSTR string2 );//strcmp ,���Դ�Сд

	virtual BOOL RefreshFatTable();
	virtual BOOL  CheckFatType(IN LPCSTR lpFileName , OUT UINT& FATTYPE);

//////////////////////////////////////////////////////////////////////////
// GetFreeSpace 

	virtual LPTSTR RootPath();
	virtual DWORD SectorsPerCluster();
	virtual DWORD BytesPerSector();
	virtual DWORD NumberOfFreeClusters();
	virtual DWORD TotalNumberOfClusters();
		
public:
//////////////////////////////////////////////////////////////////////////
// inside operator
	virtual BOOL  ImgCreateDirectory(IN LPCTSTR lptDirName);							// �ڵ�ǰĿ¼�½���Ŀ¼���� -- 

	
	virtual BOOL  ImgCreateFile(IN const LPCTSTR lpFileName, 
						IN PBYTE pbuffer, 
						IN const BYTE bFileAttr,
						IN const UINT nSize,
						HANDLE& hFile);										// �����ļ�����

	virtual BOOL  ImgDeleteDirectory(IN LPCTSTR lptDirName);							// ��ǰĿ¼��ɾ��Ŀ¼����

	virtual BOOL  ImgDeleteDirectory(UINT clusNum);									// ɾ���ڸôؿ�ʼ�ط���Ŀ¼ �ݹ���� 

	virtual BOOL  ImgDeleteFile(IN LPCTSTR lptFileName);								// ��ǰĿ¼��ɾ���ļ�����

	virtual BOOL  ImgMoveFile(IN LPCSTR lpFileName, 
					  IN LPCSTR lpSrcDir, 
					  IN LPCSTR lpDesFileName,
					  IN LPCSTR lpDesDir);									// �ƶ��ļ�����

	virtual BOOL  ImgMoveDirectory(IN LPCSTR lpSrcDir, 
						   IN LPCSTR lpDesDir);								// �ƶ�Ŀ¼����


	virtual BOOL  ImgGetFileStaus(IN LPCTSTR lptFileName,
						  OUT ImgFileStatus& status);
	virtual BOOL  ImgOpenFile(IN LPCSTR lpFileName,									// ���ļ�����
					  OUT PBYTE pBuffer, 
					  IN DWORD nBufferLen) ;	


//////////////////////////////////////////////////////////////////////////
// Outside Operator
	virtual BOOL  CreateImageFile(IN LPCSTR lpFileName, IN UINT fatType = FAT16_TYPE, IN LONGLONG diskSize = 134217728);	 // 134217728 = 128M						// ���������ļ�

	virtual BOOL  FormatImgFile(IN LPCSTR lpVolLab, IN UINT fatType = FAT16_TYPE, IN LONGLONG diskSize = 134217728);		// ��ʽ�������ļ�

	virtual void  Iinitialize(LPCSTR lpVolab, IN UINT fatType, IN LONGLONG diskSize);					// ��ʼ��

	

	virtual BOOL  OpenImgFile(IN LPCSTR lpFileName, IN UINT fatType, IN LONGLONG diskSize = 134217728);								// �򿪾����ļ�

	virtual BOOL  CloseImgFile();

	virtual DWORD SetFilePointerEx(HANDLE hFile,				// handle of file
						LONG lDistanceToMove,		// number of bytes to move file pointer
						PLONG lpDistanceToMoveHigh,	// pointer to high-order DWORD of distance to move
						DWORD dwMoveMethod			// how to move
						);

	virtual BOOL  SetVolLabel(LPCSTR lpVolLabel);
	virtual BOOL  GetVolLabel(LPSTR lpLabel);


	BOOL  DeleteDirectoryEx(LPCTSTR lptDirectoryPath);
	BOOL  DeleteFileEx(LPCTSTR lptFilePath);

	BOOL  CreateDirectoryEx(IN LPCTSTR lptFullDir);						// ����һ��·��Ŀ¼

	virtual HANDLE  CreateFileEx(LPCTSTR lptFileName,     
						DWORD dwDesiredAccess,      
						DWORD dwShareMode,          
						LPSECURITY_ATTRIBUTES lpSecurityAttributes,	
						DWORD dwCreationDisposition, 
						DWORD dwFlagsAndAttributes,  
						HANDLE hTemplateFile         
						); 

	BOOL  CloseFileEx(HANDLE hFile);										// �ر��ļ�����

	virtual BOOL  ReadFileEx(HANDLE hFile,  OUT PBYTE pBuffer, IN DWORD nBufferLen,   OUT PDWORD nRead);

	virtual BOOL  WriteFileEx(HANDLE hFile, IN PBYTE pBuffer, IN DWORD nBufferLen,OUT PDWORD nWrite);
	
	virtual BOOL  MoveFileEx(LPCSTR lpSrcName, LPCSTR lpNewFileName);
	
	virtual BOOL  RenameFileEx(LPCSTR lpSrcName, LPCSTR lpNewFileName);
	
	
	virtual HANDLE FindFirstFile(LPCTSTR lptFileName,					// pointer to name of file to search for
		LPWIN32_FIND_DATA lpFindFileData	// pointer to returned information
		);
/*
	virtual HANDLE FindFirstFileEx(
		LPCSTR lpFileName,					// pointer to the name of the file to search for
		FINDEX_INFO_LEVELS fInfoLevelId,	// information level of the returned data
		LPVOID lpFindFileData,				// pointer to the returned information
		FINDEX_SEARCH_OPS fSearchOp,		// type of filtering to perform
		LPVOID lpSearchFilter,				// pointer to search criteria
		DWORD dwAdditionalFlags				// additional search control flags
		);
*/
	virtual BOOL FindNextFile(
		HANDLE hFindFile,					// handle to search
		LPWIN32_FIND_DATA lpFindFileData	// pointer to structure for data on found file
		) ;

	virtual BOOL FindClose(HANDLE hFindFile);



	//////////////////////////////////////////////////////////////////////////
	// virtual Function
	virtual int BytesPerSec()	{return _imgBpb.BPB_BytsPerSec;}
	virtual int SecPerClus()	{return _imgBpb.BPB_SecPerClus;}
	virtual int RsvdSecCnt()	{return _imgBpb.BPB_RsvdSecCnt;}
	virtual int RootEntCnt()	{return _imgBpb.BPB_RootEntCnt;}
	virtual int TolSec()		{return _imgBpb.BPB_TotSec16 + _imgBpb.BPB_TotSec32;}
	virtual int FatSz()			{return _imgBpb.BPB_FATSz16;}

	virtual UINT FatType(){return FAT16_TYPE;}
	virtual UINT ImgFileType() ;
	virtual LPTSTR GetMirrorFileName();
	virtual LONGLONG TotoleSpace();
	virtual BOOL TestFunc();
	virtual BOOL DeleteDirEntry(UINT nClus , int nStartIndex , int nEndIndex );//delete short name entry
//////////////////////////////////////////////////////////////////////////
//	virtual BOOL  IsFileExist(LPCSTR lpFileName);
//////////////////////////////////////////////////////////////////////////
//

public:
	void IniFatType(UINT fatType);
	BOOL RefreshFat12Table();

	LPTSTR	_lpImgFileName;			// �ļ�����
	BootSector_BPB _imgBpb;			//����������Ϣ
	UINT	_imgSpace;				// �����ļ��Ŀռ����� 		/*  DISK_32M,	DISK_64M,	DISK_128M,	DISK_256M DISK_512M,	DISK_1G,	DISK_2G*/
	UINT	_stOfClusterAddr;		// ��ǰ�����ļ��صĿ�ʼλ�ã���Ե�ַ��
	UINT    _stOfRootAddr;			// ��Ŀ¼�����λ��
	UINT	_stOfFATAddr;			// FAT�����λ��
	vector<Fat_Directory> _curDirectory;	//��ǰ�Ĳ���·��

//#ifdef _FAT32_VERSION
	vector<DWORD>  _fats;
//#else
//	vector<WORD>   _fats;		
//#endif	
	BYTE*	_imgContent;

protected:
	HANDLE _hFile;
	UINT	m_CodePage;
	//virtual BOOL  CalcNewPos(HANDLE hFile);
	virtual BOOL	IniWrite(HANDLE hFile , DWORD dwWriteLen);

private:
	void	GetCRCStr(char* CRCSrcBuf , UINT srclen , char* CRCStr);//CRCStrΪ4��BYTE
	unsigned short crc16(char *crcarray,int Length);//CRCУ��
	UINT m_FatType;
	WORD m_EOC_STATUS;
	

};


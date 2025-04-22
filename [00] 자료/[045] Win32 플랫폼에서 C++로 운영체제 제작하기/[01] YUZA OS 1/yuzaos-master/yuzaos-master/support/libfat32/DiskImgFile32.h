#pragma once
#include "DiskImgFile.h"

class DiskImgFile32 : public DiskImgFile  
{
public:
	DiskImgFile32();
	virtual ~DiskImgFile32();
public:
	virtual UINT  RelatAddrToCluster(IN UINT uRetAddr);								// ӳ�亯����ʵ��ʵ��ƫ��λ�õ���
	virtual UINT  ClusterToRelatAddr(IN UINT uCluNm);								// ӳ�亯���Ӵص�ʵ��ƫ��λ��
	
	BOOL SetCurrentDirectory(IN LPCTSTR lptPathName);						// ���õ�ǰ·��	
	BOOL ParaDirectoryFromStr(IN LPCTSTR lptDirName, OUT vector<Fat_Directory>& fatDir);

	BOOL GetDirectoryTab(OUT Fat_Directory& dir, IN UINT clus, IN LPCTSTR longName)	;
	BOOL CreateDirectoryEx(IN LPCTSTR lpFullDir);

	UINT  GetFirstFreeClusNum();											// ���ؿ��еĴغţ���2��ʼ
	BOOL  GetDirectoryTabEx(OUT Fat_Directory& dir, OUT LPTSTR lptLongName, IN OUT INT& nIndex);	// ���ص�ǰĿ¼�µ�nIndex��Ŀ¼
	BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN OUT INT& nIndex);							// ���ص�ǰĿ¼�µ�nIndex��Ŀ¼
//	BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN LPCSTR longName);							// ���ص�ǰĿ¼����ΪlongName ��Ŀ¼

	BOOL  GetDirectoryTabEx(OUT Fat_Directory& dir, IN UINT clus, OUT LPTSTR lptLongName, IN OUT INT& nIndex); // ���ش�clus��Ŀ¼�µ�nIndex��Ŀ¼
//	BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN UINT clus, IN OUT INT& nIndex);						 // ���ش�clus��Ŀ¼�µ�nIndex��Ŀ¼
//	BOOL  GetDirectoryTab(OUT Fat_Directory& dir, IN UINT clus, IN LPCSTR longName);						 // ���ش�clus��Ŀ¼�³���ΪlongName��Ŀ¼

	BOOL  TrimDirEntrySpace();		// ����ɾ���ļ�����Ŀ¼��FAT_Directory Entries�Ŀռ�

//////////////////////////////////////////////////////////////////////////
// GetFreeSpace 
		
public:
//////////////////////////////////////////////////////////////////////////
// inside operator
	BOOL  ImgCreateDirectory(IN LPCTSTR lptDirName);							// �ڵ�ǰĿ¼�½���Ŀ¼���� -- 

	
	BOOL  ImgCreateFile(IN const LPCTSTR lptFileName, 
						IN PBYTE pbuffer, 
						IN const BYTE bFileAttr,
						IN const UINT nSize,
						HANDLE& hFile);										// �����ļ�����

	BOOL  ImgDeleteDirectory(IN LPCTSTR lptDirName);							// ��ǰĿ¼��ɾ��Ŀ¼����

	BOOL  ImgDeleteDirectory(UINT clusNum);									// ɾ���ڸôؿ�ʼ�ط���Ŀ¼ �ݹ���� 

	BOOL  ImgDeleteFile(IN LPCTSTR lptFileName);								// ��ǰĿ¼��ɾ���ļ�����

	BOOL  ImgMoveFile(IN LPCSTR lpFileName, 
					  IN LPCSTR lpSrcDir, 
					  IN LPCSTR lpDesFileName,
					  IN LPCSTR lpDesDir);									// �ƶ��ļ�����

	BOOL  ImgMoveDirectory(IN LPCSTR lpSrcDir, 
						   IN LPCSTR lpDesDir);								// �ƶ�Ŀ¼����


//	BOOL  ImgGetFileStaus(IN LPCSTR lpFileName,
	//					  OUT ImgFileStatus& status);
//	BOOL  ImgOpenFile(IN LPCSTR lpFileName,									// ���ļ�����
//					  OUT PBYTE pBuffer, 
//					  IN DWORD nBufferLen) ;	


	//////////////////////////////////////////////////////////////////////////
	// virtual Function
	virtual int BytesPerSec()	{return _imgBpb.BPB_BytsPerSec;}
	virtual int SecPerClus()	{return _imgBpb.BPB_SecPerClus;}
	virtual int RsvdSecCnt()	{return _imgBpb.BPB_RsvdSecCnt;}
	virtual int RootEntCnt()	{return _imgBpb.BPB_RootEntCnt;}
	virtual int TolSec()		{return _imgBpb.BPB_TotSec16 + _imgBpb.BPB_TotSec32;}
	virtual int FatSz()			{return _imgBpb.BPB_FATSz16;}
	virtual UINT FatType()		{return FAT32_TYPE;}

	virtual BOOL  SetVolLabel(LPCSTR lpVolLabel);
	virtual BOOL  GetVolLabel(LPSTR lpLabel);

	virtual void  InitializeClus(IN UINT clusNum);									// ��ʼ����
	virtual BOOL  SetClus(IN UINT clusNum, IN UINT nValue);							// ���ô���
	virtual BOOL  SetClusEx(IN UINT StartClusNum, IN UINT nNeedMoreClus);			// ���ô��� , Add by Joelee
	virtual BOOL  SetClusFreeStatus(IN UINT StartClusNum);

	virtual DWORD SetFilePointerEx(HANDLE hFile,				// handle of file
						LONG lDistanceToMove,		// number of bytes to move file pointer
						PLONG lpDistanceToMoveHigh,	// pointer to high-order DWORD of distance to move
						DWORD dwMoveMethod			// how to move
						);
	virtual BOOL  ReadFileEx(HANDLE hFile,  OUT PBYTE pBuffer, IN DWORD nBufferLen,   OUT PDWORD nRead);

	virtual BOOL  WriteFileEx(HANDLE hFile, IN PBYTE pBuffer, IN DWORD nBufferLen,OUT PDWORD nWrite);

	virtual BOOL  RenameFileEx(LPCSTR lpSrcName, LPCSTR lpNewFileName);

	virtual HANDLE  CreateFileEx(LPCTSTR lpFileName,     
						DWORD dwDesiredAccess,      
						DWORD dwShareMode,          
						LPSECURITY_ATTRIBUTES lpSecurityAttributes,	
						DWORD dwCreationDisposition, 
						DWORD dwFlagsAndAttributes,  
						HANDLE hTemplateFile         
						); 

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
// GetFreeSpace 

	virtual LPTSTR RootPath();
	virtual DWORD SectorsPerCluster();
	virtual DWORD BytesPerSector();
	virtual DWORD NumberOfFreeClusters();

	
	virtual UINT ImgFileType();


	virtual LPTSTR GetMirrorFileName();
	virtual LONGLONG TotoleSpace();
//////////////////////////////////////////////////////////////////////////
// Outside Operator
	BOOL  CreateImageFile(IN LPCSTR lpFileName, IN UINT fatType = FAT32_TYPE, IN LONGLONG diskSize = 536870912);	 // 536870912 = 256M						// ���������ļ�

	BOOL  FormatImgFile(IN LPCSTR lpVolLab, IN UINT fatType = FAT16_TYPE, IN LONGLONG diskSize = 536870912);		// ��ʽ�������ļ�

	void  Iinitialize(LPCSTR lpVolab, IN UINT fatType, IN LONGLONG diskSize);					// ��ʼ��

	

	BOOL  OpenImgFile(IN LPCSTR lpFileName, IN LONGLONG diskSize = 536870912 );								// �򿪾����ļ�

	BOOL RefreshFatTable();
	//BOOL IsFileExist(LPCSTR lpFileName);
	BootSector_BPB32 _imgBpb;	//����������Ϣ
	
protected:
	//virtual BOOL  CalcNewPos(HANDLE hFile);
	virtual BOOL	IniWrite(HANDLE hFile , DWORD dwWriteLen) override;
private:
		
		//BootSector_BPB32 _imgBpb_sFat;	//����������Ϣ
		Fat_FsInfo  _fsInfo;
	//	vector<DWORD>  _fats;
		BYTE*	_imgContent;
};

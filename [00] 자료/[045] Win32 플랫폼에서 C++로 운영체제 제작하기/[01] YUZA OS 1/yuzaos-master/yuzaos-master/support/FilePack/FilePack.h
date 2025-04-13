#pragma once
#include <minwindef.h>
#include "LiteZip.h"
#include "LiteUnzip.h"

class File;
class Unzip;


class CFilePack
{
public:
	CFilePack(void);
	virtual ~CFilePack(void);


	bool OpenFile(const char *fname);
	File* LoadFileMem(File *fp);
	bool  Store(const char *fname);
	bool OpenFileFromZip(const char *fname);

protected:

private:
	Unzip* m_Unzip;
	File* m_pFile;
};

namespace Orange
{

	class CFilePackSys
	{
		
	public:
		CFilePackSys(void);
		virtual ~CFilePackSys(void);

		BOOL Initialize();
		BOOL Finally();

		void show_errmsg(void);
		
		bool PackMemory(TCHAR* pZipFileName, TCHAR* pFileName, unsigned char* pBuffer, int BufferSize);
		bool UnPackMemory( TCHAR* pZipFileName, TCHAR* pFileName );
		
		bool PackMemoryRaw(TCHAR* pZipFileName, unsigned char* pBuffer, int UnCompressedSize, int& CompressedSize);
		unsigned char* UnPackMemoryRaw( TCHAR* pZipFileName, unsigned char* pBuffer, int BufferSize );


////////////////////////////////////////////////////////////////////////////////////////////
//PackDir : ������ ���丮 ���� �������� �����Ѵ�. �����ڵ� �Լ��� ����� �������� �ʴ� �� ��
////////////////////////////////////////////////////////////////////////////////////////////
		bool PackFile( TCHAR* pZipFileName, TCHAR* pTargetFileName, bool bNewZipFile = true);

////////////////////////////////////////////////////////////////////////////////////////////
//PackDir : ������ ���丮 ���� �������� �����Ѵ�. �����ڵ� �Լ��� ����� �������� �ʴ� �� ��
////////////////////////////////////////////////////////////////////////////////////////////
		bool PackDir(TCHAR* pFileName, TCHAR* pDirFullPath, int DirFullPathLen );

////////////////////////////////////////////////////////////////////////////////////////////
//UnPackRes : ���������� ���ҽ��� �ִ� zip���Ͽ��� �����͸� ��� �´�. �̸��� �����ϸ� �ϳ��� ���ϸ� ����� �� �ִ�.
////////////////////////////////////////////////////////////////////////////////////////////
		bool UnPackRes(TCHAR* pExtractedFileName = NULL);
		unsigned char* UnPackResMem( TCHAR* pExtractedFileName, int& BufferSize);
		bool UnPackResMemAll( TCHAR* pResourceName);

////////////////////////////////////////////////////////////////////////////////////////////
//UnPackFile : Zip ������ ������ Ǯ� ���Ϸ� �����Ѵ�.
//pExtractedFileName �̸��� �����ϸ� �������Ͽ��� �ϳ��� ���ϸ� ������ ���� ������ �� �ִ�.
////////////////////////////////////////////////////////////////////////////////////////////
		bool UnPackFile(TCHAR* pZipFileName, TCHAR* pExtractedFileName = NULL);

	protected:

	private:
		// Where we store the pointers to LiteZip.dll's functions that we call
		ZipCreateFilePtr		*lpZipCreateFile;
		ZipAddDirPtr			*lpZipAddDir;
		ZipClosePtr				*lpZipClose;
		ZipFormatMessagePtr		*lpZipFormatMessage;
		ZipAddFilePtr			*lpZipAddFile;
		ZipAddBufferPtr			*lpZipAddBuffer;
		ZipCreateBufferPtr		*lpZipCreateBuffer;
		ZipAddBufferRawPtr		*lpZipAddBufferRaw;
		ZipGetMemoryPtr			*lpZipGetMemory;

		UnzipOpenFilePtr		*lpUnzipOpenFile;
		UnzipGetItemPtr			*lpUnzipGetItem;
		UnzipItemToBufferPtr	*lpUnzipItemToBuffer;
		UnzipClosePtr			*lpUnzipClose;
		UnzipFormatMessagePtr	*lpUnzipFormatMessage;		
		UnzipOpenBufferPtr		*lpUnzipOpenBuffer;				
		UnzipItemToFilePtr		*lpUnzipItemToFile;		
		UnzipFindItemPtr		*lpUnzipFindItem;		
		UnzipOpenFileRawPtr		*lpUnzipOpenFileRaw;
		

		HMODULE		m_zipDll;
		HMODULE		m_unzipDll;
	};
}
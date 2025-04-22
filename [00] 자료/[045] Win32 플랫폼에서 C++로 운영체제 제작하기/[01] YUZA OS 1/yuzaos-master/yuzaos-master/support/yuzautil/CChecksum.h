/** 
 *  @file		CChecksum.h
 *  @brief		CChecksum ���� Ŭ����
 *  @remarks	
 *  @author		������(edith2580@gmail.com)
 *  @date		2009-04-02
 */


#pragma once

/** 
*  @class        CChecksum
*  @brief        üũ���� �����մϴ�.
*  @remarks    DWORD dwCrc = 0;													\r\n
*				DWORD dwTemp;														\r\n
*				sprintf(strScriptPath, "data1.z");									\r\n
*				if (CChecksum::FromFileWin32(strScriptPath, dwTemp) != NO_ERROR)	\r\n
*				{																	\r\n
*					return FALSE;													\r\n
*				}																	\r\n
*				dwCrc = dwCrc^dwTemp;												\r\n
*                
*  @par          
*  @author  Edith
*  @date    2009-04-03
*/
class CChecksum
{
public:
	/**
	* @brief		�޸𸮿��� üũ���� ���Ѵ�
	* @param buffer	üũ���� ���� ����
	* @param size		buffer�� ������
	* @param &dwCrc32	CRC�� ��
	* @return			�������� ������ NO_ERROR ����
	*/
	static DWORD FromBuffer(BYTE* buffer, size_t size, DWORD &dwCrc32);

	/**
	* @brief		Win32 �Լ��� �̿��� üũ���� ���Ѵ�.
	* @param filename	���ϸ�
	* @param &dwCrc32  CRC�� ��
	* @return			�������� ������ NO_ERROR ����
	*/
	static DWORD FromFileWin32(LPCWSTR filename, DWORD &dwCrc32);

	/**
	* @brief		Filemap �Լ��� �̿��� üũ���� ���Ѵ�.
	* @param filename	���ϸ�
	* @param &dwCrc32  CRC�� ��
	* @return			�������� ������ NO_ERROR ����
	*/

	static DWORD FromFileFilemap(LPCWSTR filename, DWORD &dwCrc32);

	/**
	* @brief		Assembly �� �̿��� üũ���� ���Ѵ�.
	* @param filename	���ϸ�
	* @param &dwCrc32  CRC�� ��
	* @return			�������� ������ NO_ERROR ����
	*/
	static DWORD FromFileAssembly(LPCWSTR filename, DWORD &dwCrc32);
};

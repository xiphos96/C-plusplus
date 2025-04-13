/** 
*  @file		NFLog.h
*  @brief		Log ��� Ŭ����
*  @remarks	
*  @author		������(edith2580@gmail.com)
*  @date		2009-04-02
*/

#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <string>

#define _DELETE(x) if(x){ delete x; x = 0;}  

#include "LogManager.h"

class CLog
{
public:
	/// �� �α��� Index Ÿ��
	enum Groups {
		Info = 1 << 0,			
		Warning = 1 << 1,		
		Error = 1 << 2,
		Exception = 1 << 3,
		Important = 1 << 4,
	};

	/// �α� ��¿� ����ü
	struct Proxy 
	{
		/// �αװ� ȣ��� �Լ�
		const char* func;
		/// �αװ� ȣ��� ����
		const char* file;
		/// �αװ� ȣ��� ���ι�ȣ
		int			linenum;
		/// �α��� �׷���̵�
		int			group;

		Proxy(int pGroup, const char* pFile, int pLinenum, const char* pFunc);
		void Log(const char* msg, ...);
	};

	/// Message�� ����� ������ �ڵ��� �����Ѵ�.
	static void SetLogHandle(HWND hListWnd);
	/// ȭ�鿡 �ΰ� ��������
	static void SetLogPrint(BOOL enable = TRUE);
	/// ���Ϸ� �α׸� ��������
	static void SetLogOutput(BOOL enable = TRUE, DWORD dwSize = 100 * 1024 * 1024);
	/// �α��� ��� �����͸� �����մϴ�. NFLog::Info ~ NFLog::Important
	static void SetLogLimit(int limit);
	/// �� �α׸� ����ϴ�.
	static void SetLogDetail(BOOL detail);

	/// �α׸� �����մϴ�. (�ӽú����� ����� �α׸� ���Ϸ� �����մϴ�.)
	static void CloseLog();

private:
	/**
	* @brief	hWnd�� String�� ����Ѵ�.
	* @param hWnd		������ �ڵ�
	* @param String	�޽���
	* @param Len		�޽�������
	*/
	static void AddLogMsg( HWND hWnd, char* String, int Len );

	/**
	* @brief		�޽����� ����Ѵ�. �ܼ��϶� printf�� ���������϶� Msg������� ���
	* @param *msg	��� �޽���
	* @param ...	����
	*/
	static void LogPrintf(char* msg, ... );

	/**
	* @brief		�޽����� ����Ѵ�. �ܼ��϶� printf�� ���������϶� Msg������� ���
	* @param group	�׷��ε���
	* @param *msg	�޽���
	*/
	static void LogPrintf( int group, char* msg );

	/**
	* @brief		�޽����� ����Ѵ�. �ܼ��϶� printf�� ���������϶� Msg������� ���
	* @param group		�׷��ε���
	* @param pFile		ȣ�����ϸ�
	* @param pLinenum	ȣ�����
	* @param pFunc		ȣ���Լ�
	* @param *msg		�޽���
	*/
	static void LogPrintf( int group, const char* pFile, int pLinenum, const char* pFunc, char* msg );

	/// �α� ���ڿ��� �߰��մϴ�. 
	static void OutputLog(const char* log);

private:
	/// Message�� ����� ������ �ڵ�
	static HWND		s_hLogHandle;
	/// �α������ Ȱ��ȭ �մϴ�.
	static BOOL		s_bEnableLogPrint;
	/// �α׸� ���Ϸ� �����մϴ�.
	static BOOL		s_bSaveLogFile;
	/// �α� Limit
	static int		s_iLogLimit;
	/// �α� Detail 
	static BOOL		s_bLogDetail;

	/// �α׸� ������ �����ϴ� �Ŵ���
	static CLogManager*	s_pLogManager;
};

/// ���ڿ� �տ� L�� �����Ͽ� char Ÿ������ ��ȯ��
#define WIDEN2(x) L ## x
/// CHAR�� ���� char�� ��ȯ�ϱ� ���� ����
#define WIDEN(x) WIDEN2(x)
/// __FILE__ �� char�� ����
#define __WFILE__ WIDEN(__FILE__)
/// __FUNCSIG__ �� char�� ����
#define __WFUNCSIG__ WIDEN(__FUNCSIG__)

/// Info Log
#define LOG_INFO(LOGMESSAGE) {CLog::Proxy(CLog::Info, __FILE__, __LINE__,__FUNCSIG__).Log LOGMESSAGE;} 
/// Warning Log
#define LOG_WARNING(LOGMESSAGE) {CLog::Proxy(CLog::Warning,__WFILE__, __LINE__,__FUNCSIG__).Log LOGMESSAGE;} 
/// Error Log
#define LOG_ERROR(LOGMESSAGE) {CLog::Proxy(CLog::Error,__FILE__, __LINE__,__FUNCSIG__).Log LOGMESSAGE;} 
/// Exeption Log
#define LOG_EXCEPTION(LOGMESSAGE) {CLog::Proxy(CLog::Exception,__FILE__, __LINE__,__FUNCSIG__).Log LOGMESSAGE;}
/// Important Log
#define LOG_IMPORTANT(LOGMESSAGE) {CLog::Proxy(CLog::Important,__FILE__, __LINE__,__FUNCSIG__).Log LOGMESSAGE;} 

// stdafx.h : �� ������� �ʰ� ���� ����ϴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Windows ������� ���� ������ �ʴ� ������ ���ܽ�ŵ�ϴ�.
#endif

// �Ʒ� ������ �÷������� �켱�ϴ� �÷����� ������� �ϴ� ��� ���� ���Ǹ� �����Ͻʽÿ�.
// �ٸ� �÷����� ���Ǵ� �ش� ���� �ֽ� ������ MSDN�� �����Ͻʽÿ�.
#ifndef WINVER				// Windows 95 �� Windows NT 4 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define WINVER 0x0400		// Windows 98�� Windows 2000 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_WINNT		// Windows NT 4 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_WINNT 0x0400		// Windows 98�� Windows 2000 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif						

#ifndef _WIN32_WINDOWS		// Windows 98 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_WINDOWS 0x0410 // Windows Me ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#ifndef _WIN32_IE			// IE 4.0 ���� ���������� ����� ����� �� �ֽ��ϴ�.
#define _WIN32_IE 0x0400	// IE 5.0 ���� ������ �µ��� ������ ������ ������ �ֽʽÿ�.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ���
#include <afxext.h>         // MFC �ͽ��ټ�
#include <afxdisp.h>        // MFC �ڵ�ȭ Ŭ����

#include <afxdtctl.h>		// Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC ����
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Windows ���� ��Ʈ�ѿ� ���� MFC ����
#endif // _AFX_NO_AFXCMN_SUPPORT

// C2660: 'new' : function does not take 3 parameters ������ ���� ��ġ����
// PRB: Microsoft Foundation Classes DEBUG_NEW Does Not Work with GDI+
#define iterator _iterator

#ifdef _DEBUG

namespace Gdiplus
{
	namespace DllExports
	{
		#include <GdiplusMem.h>
	};

	#ifndef _GDIPLUSBASE_H
	#define _GDIPLUSBASE_H
	class GdiplusBase
	{
		public:
			void (operator delete)(void* in_pVoid)
			{
				DllExports::GdipFree(in_pVoid);
			}

			void* (operator new)(size_t in_size)
			{
				return DllExports::GdipAlloc(in_size);
			}

			void (operator delete[])(void* in_pVoid)
			{
				DllExports::GdipFree(in_pVoid);
			}

			void* (operator new[])(size_t in_size)
			{
				return DllExports::GdipAlloc(in_size);
			}

			void * (operator new)(size_t nSize, LPCSTR lpszFileName, int nLine)
			{
				return DllExports::GdipAlloc(nSize);
			}

			void operator delete(void* p, LPCSTR lpszFileName, int nLine)
			{
				DllExports::GdipFree(p);
			}

		};
	#endif // #ifndef _GDIPLUSBASE_H
}
#endif // #ifdef _DEBUG

// GDI+�� ��� ���� ��ũ���
#include <gdiplus.h>
#undef iterator

// GDI+ ���̺귯�� ��ũ
#pragma comment(lib,"gdiplus.lib")

// GDI+ ���ӽ����̽� ���
using namespace Gdiplus;

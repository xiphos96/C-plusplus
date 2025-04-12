#if !defined(AFX_STDAFX_H__7DCBFD2C_42C8_11D4_B08A_00C0268E7D02__INCLUDED_)
#define AFX_STDAFX_H__7DCBFD2C_42C8_11D4_B08A_00C0268E7D02__INCLUDED_

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxcmn.h>			// MFC support for Windows 95 Common Controls
#include "debug.h"			// For ASSERT, VERIFY, and TRACE
#include <customaw.h>		// Custom AppWizard interface

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__7DCBFD2C_42C8_11D4_B08A_00C0268E7D02__INCLUDED_)

#ifndef DEFINE_DICTIONARY
#define DEFINE_DICTIONARY

#define d GAWizardaw.m_Dictionary
//#define i M.Format
//GAWizardaw.m_Dictionary.SetAt("popsize",PopSize);
#define ds(n,v) d[_T(#n)]=#v
#define dsi(n,v) M.Format("%d",v);d.SetAt(_T(#n),M)
#define dsf(n,v) M.Format("%4.2f",v);d.SetAt(_T(#n),M)
#define dr(n) d.RemoveKey(_T(#n))

#endif





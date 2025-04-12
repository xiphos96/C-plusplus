//{{AFX_INCLUDES()
#include "MSPropShell.h"
//}}AFX_INCLUDES
#if !defined(AFX_ENCCONTROLCONFIG_H__D03B7C28_867D_4EC6_9403_42DC47A9F998__INCLUDED_)
#define AFX_ENCCONTROLCONFIG_H__D03B7C28_867D_4EC6_9403_42DC47A9F998__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EncoderConfigDlg.h : header file
//

// Windows Media Encoder SDK
#include "wmencode.h"
#include "wmencvu.h"

// ATL : CComBSTR과 CComVariant를 사용하기 위한 헤더 파일
#include "Atlbase.h"


/////////////////////////////////////////////////////////////////////////////
// CEncoderConfigDlg dialog


// 동영상 녹화 및 방송에 관한 옵션 설정 다이얼로그 클래스

class CEncoderConfigDlg : public CDialog
{
// Construction
public:
	CEncoderConfigDlg(CWnd* pParent = NULL);   // standard constructor
	void SetEncoder(IWMEncoder* pEncoder);

// Dialog Data
	//{{AFX_DATA(CEncoderConfigDlg)
	enum { IDD = IDD_ENCODER_CONFIG_DLG };
	CMSPropShell	m_PropShellConfig;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEncoderConfigDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	IWMEncoder		*m_pEncoder;		// 미디어 인코더 인터페이스

	// Generated message map functions
	//{{AFX_MSG(CEncoderConfigDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCCONTROLCONFIG_H__D03B7C28_867D_4EC6_9403_42DC47A9F998__INCLUDED_)

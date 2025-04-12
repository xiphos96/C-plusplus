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

// ATL : CComBSTR�� CComVariant�� ����ϱ� ���� ��� ����
#include "Atlbase.h"


/////////////////////////////////////////////////////////////////////////////
// CEncoderConfigDlg dialog


// ������ ��ȭ �� ��ۿ� ���� �ɼ� ���� ���̾�α� Ŭ����

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
	IWMEncoder		*m_pEncoder;		// �̵�� ���ڴ� �������̽�

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

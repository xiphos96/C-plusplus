#if !defined(AFX_SYMBOLDLG_H__38AB538F_4338_4A8E_84E5_EF08383D8504__INCLUDED_)
#define AFX_SYMBOLDLG_H__38AB538F_4338_4A8E_84E5_EF08383D8504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SymbolDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSymbolDlg dialog

#include "SymbolChart.h"
#include "SymbolPreviewStatic.h"

// Ư�� ����ǥ ��� ���̾�α�
class CSymbolDlg : public CDialog
{
// Construction
public:
	CSymbolDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSymbolDlg)
	enum { IDD = IDD_SYMBOL_SELECT_DLG };
	CSymbolPreviewStatic	m_CodePreview;			// Ư�� ���� �̸����� ��Ʈ��
	CSymbolChart			m_CodeChart;			// Ư�� ����ǥ ��Ʈ��
	CEdit					m_CodeEdit;				// Ư�� ���� �ڵ� ��¿� ����Ʈ ��Ʈ��
	CString					m_CodeString;			// Ư�� ���� �ڵ�
	//}}AFX_DATA

	void UpdateButton();					// ���� �ڵ� ������ ���� ��ư���� Ȱ��ȭ ��Ű�� �Լ�
	CString GetSelectedChar();				// ���� ���õ� ������ ���� ����Ʈ�� �����ϴ� �Լ�

	void SetFontName(LPCTSTR pFontName);	// Ư�� ����ǥ�� ����� ��Ʈ ���� �Լ�
	void SetCodeType(BOOL bUnicode);		// Ư�� ����ǥ�� ����� ���� �ڵ� ���� �Լ�

	void OnLeft();							// ���� ���ڷ� �̵� �Լ�
	void OnRight();							// ������ ���ڷ� �̵� �Լ�
	void OnUp();							// ���ٷ� �̵� �Լ�
	void OnDown();							// �Ʒ� �ٷ� �̵� �Լ�

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSymbolDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
public:

	// Generated message map functions
	//{{AFX_MSG(CSymbolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPageUpButton();
	afx_msg void OnPageDownButton();
	afx_msg void OnGoButton();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYMBOLDLG_H__38AB538F_4338_4A8E_84E5_EF08383D8504__INCLUDED_)

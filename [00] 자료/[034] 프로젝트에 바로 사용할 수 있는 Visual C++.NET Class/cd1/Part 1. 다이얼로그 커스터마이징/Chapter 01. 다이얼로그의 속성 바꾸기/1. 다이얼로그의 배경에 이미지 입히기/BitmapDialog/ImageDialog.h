#if !defined(AFX_IMAGEDIALOG_H__9B74A250_9077_4E93_8849_C6DA10D751C0__INCLUDED_)
#define AFX_IMAGEDIALOG_H__9B74A250_9077_4E93_8849_C6DA10D751C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImageDialog dialog

// ��Ʈ�� ���̾�α��� ���� Ŭ����
class CImageDialog : public CDialog
{
// Construction
public:
	CImageDialog(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor
	virtual ~CImageDialog();

	// ��� �̹��� ��� ���
	enum { MODE_CENTER = 0, MODE_TILE, MODE_STRETCH };

protected:
	int		m_nBkgndMode;					// ��� �̹��� ��� ���

	CBitmap	m_bmpBkgnd;						// ��� �̹����� ���� ��Ʈ�� ��ü
	CBrush	m_NullBrush;					// ��Ʈ�ѵ��� ���� ���� �귯��
	COLORREF m_clrBkgnd;					// ��ȭ���� ����

	BITMAP	m_bmpInfo;						// ��� �̹����� ���� ����
	CRect	m_rcClient;						// Ŭ���̾�Ʈ ����

public:
	int GetBkgndMode();						// ���� ��� ��� ��� ���� �Լ�
	void SetBkgndMode(int nMode);			// ���ο� ��� ��� ��� ���� �Լ�

	BOOL SetBitmap(UINT nResourceID);		// ���ҽ��� ��Ʈ���� ������� �����ϴ� �Լ�
	BOOL SetBitmap(LPCTSTR pFileName);		// ��Ʈ�� ������ ������� �����ϴ� �Լ�

// Dialog Data
	//{{AFX_DATA(CImageDialog)
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImageDialog)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEDIALOG_H__9B74A250_9077_4E93_8849_C6DA10D751C0__INCLUDED_)

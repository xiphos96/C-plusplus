#if !defined(AFX_FILENAMEEDIT_H__48444A6E_7E88_40C8_AB8D_9719B96C8277__INCLUDED_)
#define AFX_FILENAMEEDIT_H__48444A6E_7E88_40C8_AB8D_9719B96C8277__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileNameEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileNameEdit window

// ����/���� ���� ��ư Ŭ���� ��� ����
#include "FileBrowseButton.h"

// ����/���� ���� ��ư�� ��
#define CONST_BROWSE_BTN_WIDTH		18

// CFileNameEdit�� ����Ͽ� DDX/DDV�� �����ϱ� ���� �Լ�
void AFXAPI DDX_FileName(CDataExchange* pDX, int nIDC, CString& strText);


// ���ϸ� �Է¿� ����Ʈ Ŭ����
class CFileNameEdit : public CEdit
{
// Construction
public:
	CFileNameEdit();

// Attributes
public:
	// ����Ʈ ��Ʈ���� ��ü Ŭ���̾�Ʈ ����
	CRect				m_rcEntireArea;
	// ��ư ������ ������ Ŭ���̾�Ʈ ����
	CRect				m_rcClipArea;
	// ��ư ����
	CRect				m_rcButton;
	// ����/���� ���� ��ư
	CFileBrowseButton	m_btnBrowse;
	// ���� ������� ���� ������� ����
	BOOL				m_bIsFileMode;
	// ���� �б� �������� ����
	BOOL				m_bIsReadOnly;
	// �б� ������ ��� �� ��θ��� ������ ����
	CString				m_strLongPath;

// Operations
public:
	// ����Ʈ ��Ʈ���� ���� ������ ��ü Ŭ���̾�Ʈ�� �����ϴ� �Լ�
	void RestoreArea();
	// ����/���� ���� ��ȭ���ڸ� ����ϴ� �Լ�
	void OnBrowse();

	// ���� ������� �����ϴ� �Լ�
	BOOL IsFileMode()					{ return m_bIsFileMode; }
	// ���� ��� Ȥ�� ���� ��� ���� �Լ�
	void SetFileMode(BOOL bFile)		{ m_bIsFileMode = bFile; }

	// ª�� ��θ� ����Ʈ ��Ʈ�ѿ� �����ϴ� �Լ�
	void SetShortText(LPCTSTR lpszString);
	// �б� ���� ���ο� ���� ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϴ� �Լ�
	int GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const;
	// �б� ���� ���ο� ���� ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϴ� �Լ�
	void GetWindowText(CString& rString) const;
	// �б� ���� ���ο� ���� ����Ʈ ��Ʈ�ѿ� �ؽ�Ʈ�� �����ϴ� �Լ�
	void SetWindowText(LPCTSTR lpszString);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileNameEdit)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFileNameEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFileNameEdit)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnDestroy();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS FAR* lpncsp);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILENAMEEDIT_H__48444A6E_7E88_40C8_AB8D_9719B96C8277__INCLUDED_)

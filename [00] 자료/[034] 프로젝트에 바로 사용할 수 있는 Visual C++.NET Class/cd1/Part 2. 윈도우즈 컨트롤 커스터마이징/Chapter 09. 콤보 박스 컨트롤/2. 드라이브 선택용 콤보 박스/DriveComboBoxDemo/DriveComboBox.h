#if !defined(AFX_DRIVECOMBOBOX_H__F57B8311_F25E_40D0_90DE_1CCA54D709A1__INCLUDED_)
#define AFX_DRIVECOMBOBOX_H__F57B8311_F25E_40D0_90DE_1CCA54D709A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DriveComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDriveComboBox window

// ����̺� �޺� �ڽ� ��Ʈ�� Ŭ����
class CDriveComboBox : public CComboBox
{
// Construction
public:
	CDriveComboBox();

// Attributes
	CImageList		m_BigImageList;					// ū �̹��� ����Ʈ
	CImageList		m_SmallImageList;				// ���� �̹��� ����Ʈ
	CSize 			m_szBigIcon;					// ū �̹����� ũ��
	CSize			m_szSmallIcon;					// ���� �̹����� ũ��
	int				m_nDriveCount;					// ����̺� ����
	BOOL			m_bBigIcon;						// ���� ū �̹������� ����

	COLORREF		m_clrBkgnd;						// ���� ������ �׸� ����
	COLORREF		m_clrSelected;					// ���õ� ������ �׸� ����
	COLORREF		m_clrText;						// �ؽ�Ʈ ����
	COLORREF		m_clrTextDisabled;				// ��Ȱ��ȭ �ؽ�Ʈ ����

public:

// Operations
public:
	// ���� �ý����� ����̺� ������ �����ϴ� �Լ�
	int GetDriveCount()			{ return m_nDriveCount; }
	// ���� ū �̹����� ����ϴ��� �����ϴ� �Լ�
	BOOL IsBigIcon()			{ return m_bBigIcon; }
	// ū �̹����� ����� ������ �����ϴ� �Լ�
	BOOL SetBigIcon(BOOL bBig);
	// ū �̹����� ���̸� �����ϴ� �Լ�
	int GetBigIconHeight()		{ return m_szBigIcon.cy; }
	// ���� �̹����� ���̸� �����ϴ� �Լ�
	int GetSmallIconHeight()	{ return m_szSmallIcon.cy; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDriveComboBox)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDriveComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDriveComboBox)
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRIVECOMBOBOX_H__F57B8311_F25E_40D0_90DE_1CCA54D709A1__INCLUDED_)

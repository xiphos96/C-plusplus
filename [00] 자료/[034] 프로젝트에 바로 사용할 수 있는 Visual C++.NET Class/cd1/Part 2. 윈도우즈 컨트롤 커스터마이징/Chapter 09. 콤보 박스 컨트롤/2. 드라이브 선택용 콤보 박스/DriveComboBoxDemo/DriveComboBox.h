#if !defined(AFX_DRIVECOMBOBOX_H__F57B8311_F25E_40D0_90DE_1CCA54D709A1__INCLUDED_)
#define AFX_DRIVECOMBOBOX_H__F57B8311_F25E_40D0_90DE_1CCA54D709A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DriveComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDriveComboBox window

// 드라이브 콤보 박스 컨트롤 클래스
class CDriveComboBox : public CComboBox
{
// Construction
public:
	CDriveComboBox();

// Attributes
	CImageList		m_BigImageList;					// 큰 이미지 리스트
	CImageList		m_SmallImageList;				// 작은 이미지 리스트
	CSize 			m_szBigIcon;					// 큰 이미지의 크기
	CSize			m_szSmallIcon;					// 작은 이미지의 크기
	int				m_nDriveCount;					// 드라이브 갯수
	BOOL			m_bBigIcon;						// 현재 큰 이미지인지 여부

	COLORREF		m_clrBkgnd;						// 보통 상태의 항목 배경색
	COLORREF		m_clrSelected;					// 선택된 상태의 항목 배경색
	COLORREF		m_clrText;						// 텍스트 색상
	COLORREF		m_clrTextDisabled;				// 비활성화 텍스트 색상

public:

// Operations
public:
	// 현재 시스템의 드라이브 갯수를 리턴하는 함수
	int GetDriveCount()			{ return m_nDriveCount; }
	// 현재 큰 이미지를 사용하는지 리턴하는 함수
	BOOL IsBigIcon()			{ return m_bBigIcon; }
	// 큰 이미지를 사용할 것인지 설정하는 함수
	BOOL SetBigIcon(BOOL bBig);
	// 큰 이미지의 높이를 리턴하는 함수
	int GetBigIconHeight()		{ return m_szBigIcon.cy; }
	// 작은 이미지의 높이를 리턴하는 함수
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

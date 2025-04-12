#if !defined(AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_)
#define AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlatListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlatListCtrl window

// 평면 헤더 컨트롤 헤더
#include "FlatHeaderCtrl.h"

class CFlatListCtrl : public CListCtrl
{
// Construction
public:
	CFlatListCtrl();

// Attributes
public:
	// 평면 헤더 컨트롤 멤버 변수
	CFlatHeaderCtrl		m_wndHeaderCtrl;
	// 평면 헤더 컨트롤에 사용할 이미지 리스트
	CImageList			m_ImageList;

// Operations
public:
	// 평면 헤더 컨트롤에 사용할 이미지 리스트 설정 함수
	void SetHeaderImage(UINT nBitmap, int cx, int nGrow);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlatListCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlatListCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlatListCtrl)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLATLISTCTRL_H__C532D6FC_E7AF_4A2C_BED1_9A3C2935CA00__INCLUDED_)

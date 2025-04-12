#if !defined(AFX_SPEEDBMPBUTTON_H__9819129F_98F8_4975_A353_8AD7FACE6283__INCLUDED_)
#define AFX_SPEEDBMPBUTTON_H__9819129F_98F8_4975_A353_8AD7FACE6283__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpeedBmpButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpeedBmpButton window

// 빠른 클릭을 처리를 위한 비트맵 버튼 클래스
class CSpeedBmpButton : public CBitmapButton
{
// Construction
public:
	CSpeedBmpButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeedBmpButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpeedBmpButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSpeedBmpButton)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEEDBMPBUTTON_H__9819129F_98F8_4975_A353_8AD7FACE6283__INCLUDED_)

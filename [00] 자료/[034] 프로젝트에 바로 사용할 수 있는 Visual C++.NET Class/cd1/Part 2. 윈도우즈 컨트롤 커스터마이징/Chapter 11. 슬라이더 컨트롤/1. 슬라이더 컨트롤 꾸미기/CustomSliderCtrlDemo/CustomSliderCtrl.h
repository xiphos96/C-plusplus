#if !defined(AFX_CUSTOMSLIDERCTRL_H__B4E88415_4E44_4B8E_B8C2_36B5DABD7730__INCLUDED_)
#define AFX_CUSTOMSLIDERCTRL_H__B4E88415_4E44_4B8E_B8C2_36B5DABD7730__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomSliderCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomSliderCtrl window


// 사용자 정의 슬라이더 컨트롤 클래스
class CCustomSliderCtrl : public CSliderCtrl
{
// Construction
public:
	CCustomSliderCtrl();

// Attributes
public:
	COLORREF	m_clrThumb;					// 핸들 색상
	COLORREF	m_clrSelection;				// 선택된 범위 색상
	COLORREF	m_clrChannel;				// 선택되지 않은 범위 색상
	CBrush		m_brsChannel;				// 선택되지 않은 범위 브러쉬

	BOOL		m_bHorz;					// 수평인지 수직인지 여부

// Operations
public:
	// 핸들 색상을 리턴/설정하는 함수
	COLORREF GetThumbColor()		{ return m_clrThumb; }
	void SetThumbColor(COLORREF clrThumb);
	// 선택된 범위의 색상을 리턴/설정하는 함수
	COLORREF GetSelectionColor()	{ return m_clrSelection; }
	void SetSelectionColor(COLORREF clrSelection);
	// 선택되지 않은 범위의 색상을 리턴/설정하는 함수
	COLORREF GetChannelColor()		{ return m_clrChannel; }
	void SetChannelColor(COLORREF clrChannel);

	// 핸들을 그리는 함수
	void DrawThumb(CDC *pDC, CRect rcItem);
	// 범위를 그리는 함수
	void DrawChannel(CDC *pDC, CRect rcItem);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomSliderCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomSliderCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomSliderCtrl)
	afx_msg void OnCustomdraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMSLIDERCTRL_H__B4E88415_4E44_4B8E_B8C2_36B5DABD7730__INCLUDED_)

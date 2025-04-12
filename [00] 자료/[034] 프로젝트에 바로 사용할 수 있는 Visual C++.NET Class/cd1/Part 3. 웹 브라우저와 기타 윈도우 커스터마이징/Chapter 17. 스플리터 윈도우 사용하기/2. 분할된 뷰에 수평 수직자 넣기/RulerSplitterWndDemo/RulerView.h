#if !defined(AFX_RULERVIEW_H__12A1FFB6_60A5_4F51_97FB_5A1B61E3AA7E__INCLUDED_)
#define AFX_RULERVIEW_H__12A1FFB6_60A5_4F51_97FB_5A1B61E3AA7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RulerView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRulerView view

class CScrollHint;


// 수평/수직자 구현 클래스
class CRulerView : public CView
{
protected:
	CRulerView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRulerView)

// Attributes
public:
	BOOL		m_bHorz;			// 수평자인지 수직자인지 여부
	int			m_nLastCursor;		// 마지막 마우스가 위치했던 수직 혹은 수평 위치
	CFont		m_HorzFont;			// 수평 줄자용 폰트
	CFont		m_VertFont;			// 수직 줄자용 폰트

	// 스크롤 및 커서 위치 정보 구조체 포인터
	CScrollHint	*m_pScrollHint;

// Operations
public:
	// 수평자 혹은 수직자 설정 함수
	void SetDirection(BOOL bHorz)			{ m_bHorz = bHorz; }
	// 현재 커서 위치를 표시하는 함수
	void DrawCursorLine(CDC *pDC, int nCursor);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRulerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CRulerView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULERVIEW_H__12A1FFB6_60A5_4F51_97FB_5A1B61E3AA7E__INCLUDED_)

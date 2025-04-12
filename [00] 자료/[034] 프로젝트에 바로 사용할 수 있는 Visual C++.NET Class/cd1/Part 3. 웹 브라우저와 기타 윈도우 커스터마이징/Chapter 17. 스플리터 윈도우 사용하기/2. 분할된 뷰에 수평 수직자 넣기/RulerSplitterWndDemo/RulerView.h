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


// ����/������ ���� Ŭ����
class CRulerView : public CView
{
protected:
	CRulerView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRulerView)

// Attributes
public:
	BOOL		m_bHorz;			// ���������� ���������� ����
	int			m_nLastCursor;		// ������ ���콺�� ��ġ�ߴ� ���� Ȥ�� ���� ��ġ
	CFont		m_HorzFont;			// ���� ���ڿ� ��Ʈ
	CFont		m_VertFont;			// ���� ���ڿ� ��Ʈ

	// ��ũ�� �� Ŀ�� ��ġ ���� ����ü ������
	CScrollHint	*m_pScrollHint;

// Operations
public:
	// ������ Ȥ�� ������ ���� �Լ�
	void SetDirection(BOOL bHorz)			{ m_bHorz = bHorz; }
	// ���� Ŀ�� ��ġ�� ǥ���ϴ� �Լ�
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

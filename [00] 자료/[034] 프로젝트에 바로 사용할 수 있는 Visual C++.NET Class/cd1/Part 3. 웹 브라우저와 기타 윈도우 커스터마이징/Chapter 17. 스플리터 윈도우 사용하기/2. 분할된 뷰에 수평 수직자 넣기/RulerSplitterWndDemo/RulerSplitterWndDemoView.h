// RulerSplitterWndDemoView.h : iCRulerSplitterWndDemoView Ŭ������ �������̽�
//


#pragma once

// ����/������ ���� ���ø��� ������ Ŭ���� ���
#include "RulerSplitterWnd.h"

class CRulerSplitterWndDemoView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CRulerSplitterWndDemoView();
	DECLARE_DYNCREATE(CRulerSplitterWndDemoView)

// Ư��
public:
	CRulerSplitterWndDemoDoc* GetDocument() const;

	// ����/�����ڿ��� ���� ���� ��ũ�Ѱ� Ŀ�� ��ġ�� �˸��� ���� ����ü ����
	CScrollHint			m_ScrollHint;

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CRulerSplitterWndDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����
public:
	virtual ~CRulerSplitterWndDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CRulerSplitterWndDemoView)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // RulerSplitterWndDemoView.cpp�� ����� ����
inline CRulerSplitterWndDemoDoc* CRulerSplitterWndDemoView::GetDocument() const
   { return reinterpret_cast<CRulerSplitterWndDemoDoc*>(m_pDocument); }
#endif


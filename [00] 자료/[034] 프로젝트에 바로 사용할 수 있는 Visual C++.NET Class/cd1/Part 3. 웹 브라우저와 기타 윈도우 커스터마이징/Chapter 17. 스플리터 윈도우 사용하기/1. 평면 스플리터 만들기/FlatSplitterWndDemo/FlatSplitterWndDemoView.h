// FlatSplitterWndDemoView.h : iCFlatSplitterWndDemoView Ŭ������ �������̽�
//


#pragma once


// ������������ ���� ��� �� Ŭ����
class CFlatSplitterWndDemoView : public CView
{
protected: // serialization������ ��������ϴ�.
	CFlatSplitterWndDemoView();
	DECLARE_DYNCREATE(CFlatSplitterWndDemoView)

// Ư��
public:
	CFlatSplitterWndDemoDoc* GetDocument() const;

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CFlatSplitterWndDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CFlatSplitterWndDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CFlatSplitterWndDemoView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FlatSplitterWndDemoView.cpp�� ����� ����
inline CFlatSplitterWndDemoDoc* CFlatSplitterWndDemoView::GetDocument() const
   { return reinterpret_cast<CFlatSplitterWndDemoDoc*>(m_pDocument); }
#endif


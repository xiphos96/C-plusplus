// ControlStatusBarDemoView.h : iCControlStatusBarDemoView Ŭ������ �������̽�
//


#pragma once


class CControlStatusBarDemoView : public CView
{
protected: // serialization������ ��������ϴ�.
	CControlStatusBarDemoView();
	DECLARE_DYNCREATE(CControlStatusBarDemoView)

// Ư��
public:
	CControlStatusBarDemoDoc* GetDocument() const;

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CControlStatusBarDemoView)
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
	virtual ~CControlStatusBarDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CControlStatusBarDemoView)
	//}}AFX_MSG
	afx_msg void OnStatusButton();
	afx_msg void OnStatusCheck();
	afx_msg void OnUpdateStatic(CCmdUI* pCmdUI);
	afx_msg void OnUpdateProgress(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ControlStatusBarDemoView.cpp�� ����� ����
inline CControlStatusBarDemoDoc* CControlStatusBarDemoView::GetDocument() const
   { return reinterpret_cast<CControlStatusBarDemoDoc*>(m_pDocument); }
#endif


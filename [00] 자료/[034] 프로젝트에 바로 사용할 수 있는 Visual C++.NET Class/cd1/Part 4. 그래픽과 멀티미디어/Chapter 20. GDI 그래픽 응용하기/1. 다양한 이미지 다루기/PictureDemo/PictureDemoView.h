// PictureDemoView.h : iCPictureDemoView Ŭ������ �������̽�
//


#pragma once

#include "Picture.h"


class CPictureDemoView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CPictureDemoView();
	DECLARE_DYNCREATE(CPictureDemoView)

// Ư��
public:
	CPictureDemoDoc* GetDocument() const;

	CPicture	m_Picture;

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CPictureDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CPictureDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CPictureDemoView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PictureDemoView.cpp�� ����� ����
inline CPictureDemoDoc* CPictureDemoView::GetDocument() const
   { return reinterpret_cast<CPictureDemoDoc*>(m_pDocument); }
#endif


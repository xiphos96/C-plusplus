// ChildFrm.h : CChildFrame Ŭ������ �������̽�
//


#pragma once


class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Ư��
public:

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CChildFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CChildFrame)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

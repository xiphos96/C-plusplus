// ControlStatusBarDemoDoc.h : CControlStatusBarDemoDoc Ŭ������ �������̽�
//


#pragma once

class CControlStatusBarDemoDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CControlStatusBarDemoDoc();
	DECLARE_DYNCREATE(CControlStatusBarDemoDoc)

// Ư��
public:

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CControlStatusBarDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CControlStatusBarDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CControlStatusBarDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



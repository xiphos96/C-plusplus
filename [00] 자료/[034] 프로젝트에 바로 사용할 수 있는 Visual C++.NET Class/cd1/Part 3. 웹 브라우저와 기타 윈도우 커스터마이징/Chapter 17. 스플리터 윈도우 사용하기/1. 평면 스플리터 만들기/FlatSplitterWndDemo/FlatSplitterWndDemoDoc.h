// FlatSplitterWndDemoDoc.h : CFlatSplitterWndDemoDoc Ŭ������ �������̽�
//


#pragma once

class CFlatSplitterWndDemoDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CFlatSplitterWndDemoDoc();
	DECLARE_DYNCREATE(CFlatSplitterWndDemoDoc)

// Ư��
public:

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CFlatSplitterWndDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CFlatSplitterWndDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CFlatSplitterWndDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



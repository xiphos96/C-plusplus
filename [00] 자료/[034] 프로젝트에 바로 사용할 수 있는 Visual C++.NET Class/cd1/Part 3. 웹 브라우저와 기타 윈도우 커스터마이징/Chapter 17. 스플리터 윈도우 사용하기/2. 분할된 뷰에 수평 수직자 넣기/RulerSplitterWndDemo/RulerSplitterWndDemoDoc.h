// RulerSplitterWndDemoDoc.h : CRulerSplitterWndDemoDoc Ŭ������ �������̽�
//


#pragma once

class CRulerSplitterWndDemoDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CRulerSplitterWndDemoDoc();
	DECLARE_DYNCREATE(CRulerSplitterWndDemoDoc)

// Ư��
public:
	// ���� ���� ���� ������ ��Ʈ�� ��ü
	CBitmap		m_Bitmap;

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CRulerSplitterWndDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CRulerSplitterWndDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CRulerSplitterWndDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



// PictureDemoDoc.h : CPictureDemoDoc Ŭ������ �������̽�
//


#pragma once

class CPictureDemoDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CPictureDemoDoc();
	DECLARE_DYNCREATE(CPictureDemoDoc)

// Ư��
public:

// �۾�
public:

// ������
	//{{AFX_VIRTUAL(CPictureDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// ����
public:
	virtual ~CPictureDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	//{{AFX_MSG(CPictureDemoDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



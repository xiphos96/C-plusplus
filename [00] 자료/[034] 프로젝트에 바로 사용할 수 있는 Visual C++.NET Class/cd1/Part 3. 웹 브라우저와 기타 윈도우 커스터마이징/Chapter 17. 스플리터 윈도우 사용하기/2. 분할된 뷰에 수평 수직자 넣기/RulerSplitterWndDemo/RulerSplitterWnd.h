#if !defined(AFX_RULERSPLITTERWND_H__7F1979E9_8381_4B23_8E9A_7CECD9C0EAC7__INCLUDED_)
#define AFX_RULERSPLITTERWND_H__7F1979E9_8381_4B23_8E9A_7CECD9C0EAC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RulerSplitterWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRulerSplitterWnd window

// ���� �信�� ����/�����ڿ��� ��ũ�� �� ���콺 ��ġ ��ȭ�� �˷��ֱ� ���� ����ϴ� ���� ��
enum UPDATE_KIND { UPDATE_HSCROLL, UPDATE_VSCROLL, UPDATA_CURSOR };

// ���� ���� ����/���� ��ũ�� ���¿� ���콺 ��ġ�� �˷��ִ� ����ü
class CScrollHint : public CObject
{
public:
	int m_nCX;
	int m_nCY;

	int m_nScrollX;
	int m_nScrollY;

	int m_nCursorX;
	int m_nCursorY;
};


// ����/������ ���� ���ø��� ������ Ŭ����
class CRulerSplitterWnd : public CSplitterWnd
{
// Construction
public:
	CRulerSplitterWnd();

// Attributes
public:

// Operations
public:
	// ����/������ ������ ���� ������ ���� �Լ�
	BOOL CreateRulerSplitter(CWnd *pFrame, CRuntimeClass *pView, CCreateContext* pContext);

	// ���ø����� �̵��� ���� ���� ���콺 ��Ʈ �׽�Ʈ �Լ�
	int HitTest(CPoint pt) const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerSplitterWnd)
	virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRulerSplitterWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRulerSplitterWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULERSPLITTERWND_H__7F1979E9_8381_4B23_8E9A_7CECD9C0EAC7__INCLUDED_)

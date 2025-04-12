// OpenglTestView.h : interface of the COpenglTestView class
//
/////////////////////////////////////////////////////////////////////////////

#include <ga.h>
#include "ProgressBar.h"

class COpenglTestView : public CView
{
protected: // create from serialization only
	COpenglTestView();
	DECLARE_DYNCREATE(COpenglTestView)

// Attributes
public:
	COpenglTestDoc* GetDocument();

	//유전자 알고리즘에서 사용될 변수들을 COpenglTestView 클래스의
	//멤버로 선언합니다.
public:
	int popsize;
	int ngen;
	float pmut;
	float pcross;
	int nvar;
	float min;   
	float max; 
	int nbit;

	GABin2DecPhenotype map;
	GABin2DecGenome* genome;
	GASimpleGA* ga;

	GASigmaTruncationScaling scaling;

	//OpenGL 관련 함수와 변수.
public:
	int height;
	int width;	
	float X1;
	float X2;
	float Y;

protected:
	HDC hDC;
	HGLRC hRC;

	void SetDCPixelFormat(HDC hDC);
	void InitOpenGL();
	void InitLight();
	void InitProjection();
	void DrawScene();
	void DrawSphere();	

	float m_spinx;
	float m_spiny;
	bool m_lbutton;
	POINT m_prevpoint;
	double m_y[50][50];
	GLUquadricObj *Obj;

	// 프로그레스 바
	CProgressBar* MyBar;
	bool m_Exec;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenglTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COpenglTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COpenglTestView)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OpenglTestView.cpp
inline COpenglTestDoc* COpenglTestView::GetDocument()
   { return (COpenglTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

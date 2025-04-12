// MyTestView.h : interface of the CMyTestView class
//
/////////////////////////////////////////////////////////////////////////////

#include <ga.h>

class CMyTestView : public CView
{
protected: // create from serialization only
	CMyTestView();
	DECLARE_DYNCREATE(CMyTestView)

// Attributes
public:
	CMyTestDoc* GetDocument();

//유전자 알고리즘에서 사용될 변수들을 CMyTestView 클래스의
//멤버로 선언합니다. genome, alleleset, ga는 포인터로 선언되므로 
//생성자에서 반드시 초기화해야 합니다.
public:
	int popsize;
	int ngen;
	float pmut;
	float pcross;
	float pconv;
	int length;
	int nvar;
	float min;   
	float max; 

	GAAlleleSet<int>* alleles;
	GA1DArrayAlleleGenome<int>* genome;
	GASimpleGA* ga;

	GARouletteWheelSelector selector;
	GASigmaTruncationScaling scaling;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTestView)
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
	virtual ~CMyTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyTestView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyTestView.cpp
inline CMyTestDoc* CMyTestView::GetDocument()
   { return (CMyTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

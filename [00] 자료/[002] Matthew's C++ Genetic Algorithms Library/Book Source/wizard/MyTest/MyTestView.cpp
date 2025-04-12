// MyTestView.cpp : implementation of the CMyTestView class
//

#include "stdafx.h"
#include "MyTest.h"

#include "MyTestDoc.h"
#include "MyTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

float Objective(GAGenome&);

/////////////////////////////////////////////////////////////////////////////
// CMyTestView

IMPLEMENT_DYNCREATE(CMyTestView, CView)

BEGIN_MESSAGE_MAP(CMyTestView, CView)
	//{{AFX_MSG_MAP(CMyTestView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTestView construction/destruction

CMyTestView::CMyTestView()
{
	//사용자가 선택한 값으로 CMyTestView.h 파일에서 
	//선언한 변수들을 초기화합니다.
	popsize = 50;
	ngen = 100;
	pmut = 0.01;
	pcross = 0.60;
	pconv = 0.99;
	length = 5;
	nvar = 1;
	min = 0.00;   
	max = 0.00; 
	//TODO : Define your own alleles.
	//Default alleles :
	int aset[] = {-1,0,1};
	alleles = new GAAlleleSet<int>(3, aset);
	genome = new GA1DArrayAlleleGenome<int>(length, *alleles, Objective);
	genome->mutator(GA1DArrayGenome<int>::SwapMutator);
	
	ga = new GASimpleGA(*genome);
	ga->crossover(GA1DArrayGenome<int>::TwoPointCrossover);
	ga->selector(selector);
	ga->scaling(scaling);
	ga->populationSize(popsize);
	ga->pMutation(pmut);
	ga->pCrossover(pcross);
	ga->pConvergence(pconv);
	ga->nConvergence(ngen);

	// TODO: add construction code here

}

CMyTestView::~CMyTestView()
{
	//동적으로 할당된 메모리를 제거합니다.
	delete genome;
	delete ga;
	delete alleles;
}

BOOL CMyTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyTestView drawing

void CMyTestView::OnDraw(CDC* pDC)
{
	CMyTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyTestView printing

BOOL CMyTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyTestView diagnostics

#ifdef _DEBUG
void CMyTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMyTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyTestDoc* CMyTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyTestDoc)));
	return (CMyTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Objective Function

float Objective(GAGenome& c)
{
	//TODO : Add your own Objective function here

	return 0;
}


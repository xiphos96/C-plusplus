// $$root$$View.h : interface of the C$$Safe_root$$View class
//
/////////////////////////////////////////////////////////////////////////////

#include <ga.h>
$$IF(genome_string)
#include <GAString.h>
$$ENDIF
$$IF(genome_real)
#include <GARealGe.h>
$$ENDIF

class C$$Safe_root$$View : public CView
{
protected: // create from serialization only
	C$$Safe_root$$View();
	DECLARE_DYNCREATE(C$$Safe_root$$View)

// Attributes
public:
	C$$Safe_root$$Doc* GetDocument();

	// 유전자 알고리즘에서 사용될 변수들을 C$$Safe_root$$View 클래스의
	// 멤버로 선언합니다. 
public:
	int popsize;
	int ngen;
	float pmut;
	float pcross;
$$IF(terminator_convergence || terminator_popconvergence)
	float pconv;
$$ENDIF
$$IF(ga_deme)
	float prepl;
	int nrepl;
$$ENDIF
$$IF(genome_1dbinarystring||genome_1darray||genome_1darrayallele||genome_string||genome_real)
	int length;
$$ELIF(genome_2dbinarystring||genome_2darray||genome_2darrayallele)
	int width;	
	int height;
$$ELIF(genome_3dbinarystring||genome_3darray||genome_3darrayallele)
	int width;	
	int height;
	int depth;	
$$ENDIF
$$IF(genome_1dbinarystring||genome_bin2dec||genome_2dbinarystring||genome_3dbinarystring)
	int nvar;
	int nbit;
	float min;   
	float max; 
$$ENDIF
$$IF(genome_1darrayallele||genome_2darrayallele||genome_3darrayallele||genome_real)
	float min;   
	float max;	
$$ENDIF
$$//

$$IF(genome_1dbinarystring)
	GA1DBinaryStringGenome* genome;
$$ELIF(genome_bin2dec)
	GABin2DecPhenotype map;
	GABin2DecGenome* genome;
$$ELIF(genome_2dbinarystring)
	GA2DBinaryStringGenome* genome;
$$ELIF(genome_3dbinarystring)
	GA3DBinaryStringGenome* genome;
$$ELIF(genome_1darray)
	GA1DArrayGenome<int>* genome;
$$ELIF(genome_1darrayallele)
	GAAlleleSet<int>* alleles;
	GA1DArrayAlleleGenome<int>* genome;
$$ELIF(genome_string)
	GAStringAlleleSet* alleles;
	GAStringGenome* genome;
$$ELIF(genome_real)
	GARealAlleleSet* alleles;
	GARealGenome* genome;
$$ELIF(genome_2darray)
	GA2DArrayGenome<int>* genome;
$$ELIF(2darrayallele)
	GAAlleleSet<int>* alleles;
	GA2DArrayAlleleGenome<int>* genome;
$$ELIF(genome_3darray)
	GA3DArrayGenome<int>* genome;
$$ELIF(genome_3darrayallele)
	GAAlleleSet<int>* alleles;
	GA3DArrayAlleleGenome<int>* genome;
$$ELIF(genome_list)
	GAListGenome<int>* genome;
$$ELIF(genome_tree)
	GATreeGenome<int>* genome;
$$ENDIF
$$//
$$IF(ga_simple)
	GASimpleGA* ga;
$$//
$$//
$$ELIF(ga_incremental)
	GAIncrementalGA* ga;
$$//
$$//
$$ELIF(ga_steadystate)
	GASteadyStateGA* ga;
$$//
$$ELIF(ga_deme)
	GADemeGA* ga;
$$ENDIF
$$//

$$IF(selector_rank)
	GARankSelector selector;
$$ELIF(selector_roulettewheel)
	GARouletteWheelSelector selector;
$$ELIF(selector_Tournament)
	GATournamentSelector selector;
$$ELIF(selector_ds)
	GADSSelector selector;
$$ELIF(selector_srs)
	GASRSSelector selector;
$$ELIF(selector_uniform)
	GAUniformSelector selector;
$$ENDIF
$$//
$$IF(scaling_no)
	GANoScaling scaling;
$$ELIF(scaling_linear)
	GALinearScaling scaling;
$$ELIF(scaling_sigmatruncation)
	GASigmaTruncationScaling scaling;
$$ELIF(scaling_powerlaw)
	GAPowerLawScaling scaling;
$$ELIF(scaling_sharing)
	GASharingScaling scaling;
$$ENDIF
$$//

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C$$Safe_root$$View)
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
	virtual ~C$$Safe_root$$View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(C$$Safe_root$$View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in $$root$$View.cpp
inline C$$Safe_root$$Doc* C$$Safe_root$$View::GetDocument()
   { return (C$$Safe_root$$Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

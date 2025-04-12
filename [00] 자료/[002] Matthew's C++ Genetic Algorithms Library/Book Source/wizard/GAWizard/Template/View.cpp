// $$root$$View.cpp : implementation of the C$$Safe_root$$View class
//

#include "StdAfx.h"
#include "$$root$$.h"

#include "$$root$$Doc.h"
#include "$$root$$View.h"

$$IF(genome_string)
#include <GAString.h>
#include <GAString.cpp>
$$ENDIF
$$IF(genome_real)
#include <GARealGe.h>
#include <GARealGe.cpp>
$$ENDIF

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

float Objective(GAGenome&);

/////////////////////////////////////////////////////////////////////////////
// C$$Safe_root$$View

IMPLEMENT_DYNCREATE(C$$Safe_root$$View, CView)

BEGIN_MESSAGE_MAP(C$$Safe_root$$View, CView)
	//{{AFX_MSG_MAP(C$$Safe_root$$View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C$$Safe_root$$View construction/destruction

C$$Safe_root$$View::C$$Safe_root$$View()
{
	// 사용자가 선택한 값으로 C$$Safe_root$$View.h 파일에서 
	// 선언한 변수들을 초기화합니다.
	popsize = $$popsize$$;
	ngen = $$ngen$$;
	pmut = $$pmut$$;
	pcross = $$pcross$$;
$$IF(terminator_convergence || terminator_popconvergence)
	pconv = $$pconv$$;
$$ENDIF
$$IF(ga_deme)
	prepl = $$prepl$$;
	nrepl = $$nrepl$$;
$$ENDIF
$$IF(genome_1dbinarystring||genome_1darray||genome_1darrayallele||genome_string||genome_real)
	length = $$width$$;
$$ELIF(genome_2dbinarystring||genome_2darray||genome_2darrayallele)
	width = $$width$$;	
	height = $$height$$;
$$ELIF(genome_3dbinarystring||genome_3darray||genome_3darrayallele)
	width = $$width$$;	
	height = $$height$$;
	depth = $$depth$$;	
$$ENDIF
$$IF(genome_1dbinarystring||genome_bin2dec||genome_2dbinarystring||genome_3dbinarystring)
	nvar = $$nvar$$;
	min = $$varmin$$;   
	max = $$varmax$$; 
	nbit = $$nbit$$;
$$ENDIF
$$IF(genome_1darrayallele||genome_2darrayallele||genome_3darrayallele||genome_real)
	min = $$varmin$$;   
	max = $$varmax$$; 
$$ENDIF
$$//
$$IF(genome_1dbinarystring)
	genome = new GA1DBinaryStringGenome(length, Objective);
$$IF(initializer_unset)
	genome->initializer(GA1DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
	genome->initializer(GA1DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
	genome->initializer(GA1DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
	genome->mutator(GA1DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(comparator_bit)
	genome->comparator(GA1DBinaryStringGenome::BitComparator);
$$ENDIF
$$//
$$//
$$ELIF(genome_bin2dec)
	for(int i=0;i<nvar;i++)
		map.add(nbit,min,max);
	genome = new GABin2DecGenome(map,Objective);
$$IF(initializer_unset)
	genome->initializer(GA1DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
	genome->initializer(GA1DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
	genome->initializer(GA1DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
	genome->mutator(GA1DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(comparator_bit)
	genome->comparator(GA1DBinaryStringGenome::BitComparator);
$$ENDIF
$$//
$$//
$$ELIF(genome_2dbinarystring)
	genome = new GA2DBinaryStringGenome(width, height, Objective);
$$IF(initializer_unset)
	genome->initializer(GA2DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
	genome->initializer(GA2DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
	genome->initializer(GA2DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
	genome->mutator(GA2DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(comparator_bit)
	genome->comparator(GA2DBinaryStringGenome::BitComparator);
$$ENDIF
$$//
$$//
$$ELIF(genome_3dbinarystring)
	genome = new GA3DBinaryStringGenome(width, height, depth, Objective);
$$IF(initializer_unset)
	genome->initializer(GA3DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
	genome->initializer(GA3DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
	genome->initializer(GA3DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
	genome->mutator(GA3DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(comparator_bit)
	genome->comparator(GA3DBinaryStringGenome::BitComparator);
$$ENDIF
$$//
$$//
$$ELIF(genome_1darray)
	genome = new GA1DArrayGenome<int>(length, Objective);
$$IF(mutatar_swap)
	genome->mutator(GA1DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(comparator_element)
	genome->comparator(GA1DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//
$$//
$$ELIF(genome_1darrayallele)
	// TODO : Define your own alleles.
	// Default alleles :
	int aset[] = {-1,0,1};
	alleles = new GAAlleleSet<int>(3, aset);
	genome = new GA1DArrayAlleleGenome<int>(length, *alleles, Objective);
$$IF(initializer_uniform)
	genome->initializer(GA1DArrayAlleleGenome<int>::UniformInitializer);
$$ELIF(initializer_ordered)
	genome->initializer(GA1DArrayAlleleGenome<int>::OrderedInitializer);
$$ENDIF
$$IF(mutator_swap)
	genome->mutator(GA1DArrayGenome<int>::SwapMutator);
$$ELIF(mutator_flip)
	genome->mutator(GA1DArrayGenome<int>::FlipMutator);
$$ENDIF
$$IF(comparator_element)
	genome->comparator(GA1DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//
$$ELIF(genome_string)
	// TODO : Define your own alleles.
	// Default alleles :
	alleles = new GAStringAlleleSet();
	for(int i=0; i<26; i++)
		alleles->add('a'+i);
	genome = new GAStringGenome(length, *alleles, Objective);
$$IF(initializer_ordered)
	genome->initializer(GAStringOrderedInitializer);
$$ELIF(initializer_uniform)
	genome->initializer(GAStringUniformInitializer);
$$ENDIF
$$IF(mutator_flip)
	genome->mutator(GAStringFlipMutator);
$$ELIF(mutator_swap)
	genome->mutator(GAStringSwapMutator);
$$ENDIF
$$//
$$ELIF(genome_real)
	// TODO : Define your own alleles.
	// Default alleles :
	float aset[] = {-1.0,0.2,1.1,2.4};
	alleles = new GARealAlleleSet(4, aset);
	genome = new GARealGenome(length, *alleles, Objective);
$$IF(initializer_uniform)
	genome->initializer(GARealUniformInitializer);
$$ELIF(initializer_ordered)
	genome->initializer(GARealOrderedInitializer);
$$ENDIF
$$IF(mutator_realuniform)
	genome->mutator(GARealUniformMutator);
$$ELIF(mutator_swap)
	genome->mutator(GARealSwapMutator);
$$ELIF(mutator_realgaussian)
	genome->mutator(GARealGaussianMutator);
$$ENDIF
$$//
$$ELIF(genome_2darray)
	genome = new GA2DArrayGenome<int>(width, height, Objective);
$$IF(mutator_swap)
	genome->mutator(GA2DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(comparator_element)
	genome->comparator(GA2DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//
$$ELIF(2darrayallele)
	// TODO : Define your own alleles.
	// Default alleles :
	int aset[] = {-1,0,1};
	alleles = new GAAlleleSet<int>(3, aset);
	genome = new GA2DArrayAlleleGenome<int>(width, height, *alleles, Objective);
$$IF(mutator_swap)
	genome->mutator(GA2DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(comparator_element)
	genome->comparator(GA2DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//
$$ELIF(genome_3darray)
	genome = new GA3DArrayGenome<int>(width, height, depth, Objective);
$$IF(mutator_swap)
	genome->mutator(GA3DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(comparator_element)
	genome->comparator(GA3DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//
$$ELIF(genome_3darrayallele)
	// TODO : Define your own alleles.
	// Default alleles :
	int aset[] = {-1,0,1};
	alleles = new GAAlleleSet<int>(3, aset);
	genome = new GA3DArrayAlleleGenome<int>(width, height, depth, *alleles, Objective);
$$IF(mutator_swap)
	genome->mutator(GA3DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(comparator_element)
	genome->comparator(GA3DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//
$$//
$$ELIF(genome_list)
	genome = new GAListGenome<int>(Objective);
$$IF(mutator_destructive)
	genome->mutator(GAListGenome<int>::DestructiveMutator);
$$ELIF(mutator_swap)
	genome->mutator(GAListGenome<int>::SwapMutator);
$$ENDIF
$$//
$$ELIF(genome_tree)
	genome = new GATreeGenome<int>(Objective);
$$IF(mutator_destructive)
	genome->mutator(GATreeGenome<int>::DestructiveMutator);
$$ELIF(mutator_swapnode)
	genome->mutator(GATreeGenome<int>::SwapNodeMutator);
$$ELIF(mutator_swapsubtree)
	genome->mutator(GATreeGenome<int>::SwapSubTreeMutator);
$$ENDIF
$$//
$$ENDIF
$$//

$$IF(ga_simple)
	ga = new GASimpleGA(*genome);
$$//
$$//
$$ELIF(ga_incremental)
	ga = new GAIncrementalGA(*genome);
$$//
$$//
$$ELIF(ga_steadystate)
	ga = new GASteadyStateGA(*genome);
$$//
$$ELIF(ga_deme)
	ga = new GADemeGA(*genome);
$$ENDIF
$$//
$$IF(genome_1dbinarystring)
$$IF(crossover_uniform)
	ga->crossover(GA1DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA1DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA1DBinaryStringGenome::OnePointCrossover);
$$ELIF(crossover_twopoint)
	ga->crossover(GA1DBinaryStringGenome::TwoPointCrossover);
$$ENDIF
$$//
$$ELIF(genome_bin2dec)
$$IF(crossover_uniform)
	ga->crossover(GA1DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA1DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA1DBinaryStringGenome::OnePointCrossover);
$$ELIF(crossover_twopoint)
	ga->crossover(GA1DBinaryStringGenome::TwoPointCrossover);
$$ENDIF
$$//
$$ELIF(genome_2dbinarystring)
$$IF(crossover_uniform)
	ga->crossover(GA2DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA2DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA2DBinaryStringGenome::OnePointCrossover);
$$ENDIF
$$//
$$ELIF(genome_3dbinarystring)
$$IF(crossover_uniform)
	ga->crossover(GA3DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA3DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA3DBinaryStringGenome::OnePointCrossover);
$$ENDIF
$$//
$$ELIF(genome_1darray)
$$IF(crossover_uniform)
	ga->crossover(GA1DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA1DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA1DArrayGenome<int>::OnePointCrossover);
$$ELIF(crossover_twopoint)
	ga->crossover(GA1DArrayGenome<int>::TwoPointCrossover);
$$ELIF(crossover_partialmatch)
	ga->crossover(GA1DArrayGenome<int>::PartialMatchCrossover);
$$ELIF(crossover_order)
	ga->crossover(GA1DArrayGenome<int>::OrderCrossover);
$$ELIF(crossover_cycle)
	ga->crossover(GA1DArrayGenome<int>::CycleCrossover);
$$ENDIF
$$//
$$ELIF(genome_1darrayallele)
$$IF(crossover_uniform)
	ga->crossover(GA1DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA1DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA1DArrayGenome<int>::OnePointCrossover);
$$ELIF(crossover_twopoint)
	ga->crossover(GA1DArrayGenome<int>::TwoPointCrossover);
$$ELIF(crossover_partialmatch)
	ga->crossover(GA1DArrayGenome<int>::PartialMatchCrossover);
$$ELIF(crossover_order)
	ga->crossover(GA1DArrayGenome<int>::OrderCrossover);
$$ELIF(crossover_cycle)
	ga->crossover(GA1DArrayGenome<int>::CycleCrossover);
$$ENDIF
$$//
$$ELIF(genome_string)
$$IF(crossover_uniform)
	ga->crossover(GAStringUniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GAStrintEvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GAStringOnePointCrossover);
$$ELIF(crossover_twopoint)
	ga->crossover(GAStringTwoPointCrossover);
$$ELIF(crossover_partialmatch)
	ga->crossover(GAStringPartialMatchCrossover);
$$ELIF(crossover_order)
	ga->crossover(GAStringOrderCrossover);
$$ELIF(crossover_cycle)
	ga->crossover(GAStringCycleCrossover);
$$ENDIF
$$//
$$ELIF(genome_real)
$$IF(crossover_uniform)
	ga->crossover(GARealUniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GARealEvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GARealOnePointCrossover);
$$ELIF(crossover_twopoint)
	ga->crossover(GARealTwoPointCrossover);
$$ELIF(crossover_partialmatch)
	ga->crossover(GARealPartialMatchCrossover);
$$ELIF(crossover_order)
	ga->crossover(GARealOrderCrossover);
$$ELIF(crossover_cycle)
	ga->crossover(GARealCycleCrossover);
$$ELIF(crossover_realarithmetic)
	ga->crossover(GARealArithmeticCrossover);
$$ELIF(crossover_realblend)
	ga->crossover(GARealBlendCrossover);
$$ENDIF
$$//
$$ELIF(genome_2darray)
$$IF(crossover_uniform)
	ga->crossover(GA2DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA2DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA2DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$//
$$ELIF(2darrayallele)
$$IF(crossover_uniform)
	ga->crossover(GA2DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA2DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA2DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$//
$$ELIF(genome_3darray)
$$IF(crossover_uniform)
	ga->crossover(GA3DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA3DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA3DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$//
$$ELIF(genome_3darrayallele)
$$IF(crossover_uniform)
	ga->crossover(GA3DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
	ga->crossover(GA3DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
	ga->crossover(GA3DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$//
$$ELIF(genome_list)
$$IF(crossover_onepoint)
	ga->crossover(GAListGenome<int>::OnePointCrossover);
$$ELIF(crossover_partialmatch)
	ga->crossover(GAListGenome<int>::PartialMatchCrossover);
$$ELIF(crossover_order)
	ga->crossover(GAListGenome<int>::OrderCrossover);
$$ELIF(crossover_cycle)
	ga->crossover(GAListGenome<int>::CycleCrossover);
$$ENDIF
$$//
$$ENDIF
$$//
$$IF(selector_rank||selector_roulettewheel||selector_tournament||selector_ds||selector_srs||selector_uniform)
	ga->selector(selector);
$$ENDIF
$$IF(!scaling_default)
$$//IF(scaling_no||scaling_linear||scaling_sigmatruncation||scaling_powerlaw||scaling_sharing)
	ga->scaling(scaling);
$$ENDIF
	ga->populationSize(popsize);
	ga->pMutation(pmut);
	ga->pCrossover(pcross);
$$//
$$IF(terminator_generation)
	ga->nGenerations(ngen);
$$ELIF(terminator_convergence)
	ga->pConvergence(pconv);
	ga->nConvergence(ngen);
	ga->terminator(GAGeneticAlgorithm::TerminateUponConvergence);
$$ELIF(terminator_popconvergence)
	ga->pConvergence(pconv);
	ga->terminator(GAGeneticAlgorithm::TerminatePopConvergence);
$$ENDIF
$$//

	// TODO: add construction code here

}

C$$Safe_root$$View::~C$$Safe_root$$View()
{
	// 동적으로 할당된 메모리를 제거합니다.
	delete genome;
	delete ga;
$$IF(genome_1darrayallele||genome_string||genome_real||genome_2darrayallele||genome_3darrayallele)
	delete alleles;
$$ENDIF
}

BOOL C$$Safe_root$$View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// C$$Safe_root$$View drawing

void C$$Safe_root$$View::OnDraw(CDC* pDC)
{
	C$$Safe_root$$Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// C$$Safe_root$$View printing

BOOL C$$Safe_root$$View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void C$$Safe_root$$View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void C$$Safe_root$$View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// C$$Safe_root$$View diagnostics

#ifdef _DEBUG
void C$$Safe_root$$View::AssertValid() const
{
	CView::AssertValid();
}

void C$$Safe_root$$View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C$$Safe_root$$Doc* C$$Safe_root$$View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C$$Safe_root$$Doc)));
	return (C$$Safe_root$$Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// Objective Function

float Objective(GAGenome& c)
{
	// TODO : Add your own Objective function here

	return 0;
}


int popsize = $$popsize$$;
int ngen = $$ngen$$;
float pmut = $$pmut$$;
float pcross = $$pcross$$;

$$IF(terminator_convergence || terminator_popconvergence)
float pconv = $$pconv$$;
$$ENDIF

$$IF(ga_deme)
float prepl = $$prepl$$;
int nrepl = $$nrepl$$;
$$ENDIF

$$IF(genome_1dbinarystring||genome_1darray||genome_1darrayallele||genome_string||genome_real)
int length = $$width$$;
$$ELIF(genome_2dbinarystring||genome_2darray||genome_2darrayallele)
int width = $$width$$;	
int height = $$height$$;
$$ELIF(genome_3dbinarystring||genome_3darray||genome_3darrayallele)
int width = $$width$$;	
int height = $$height$$;
int depth = $$depth$$;	
$$ENDIF

$$IF(!genome_list)
$$IF(!genome_tree)
int nvar = $$nvar$$;
float min = $$varmin$$;   
float max = $$varmax$$; 
$$ENDIF
$$ENDIF
$$IF(genome_1dbinarystring||genome_bin2dec||genome_2dbinarystring||genome_3dbinarystring)
int nbit = $$nbit$$;
$$ENDIF

$$//
$$IF(genome_1dbinarystring)
GA1DBinaryStringGenome genome(length, Objective);

$$IF(initializer_unset)
genome.initializer(GA1DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
genome.initializer(GA1DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
genome.initializer(GA1DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
genome.mutator(GA1DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA1DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA1DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA1DBinaryStringGenome::OnePointCrossover);
$$ELIF(crossover_twopoint)
genome.crossover(GA1DBinaryStringGenome::TwoPointCrossover);
$$ENDIF
$$IF(comparator_bit)
genome.comparator(GA1DBinaryStringGenome::BitComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_bin2dec)
GABin2DecPhenotype map;
for(int i=0;i<nvar;i++)
	map.add(nbit,min,max);
GABin2DecGenome genome(map,Objective);

$$IF(initializer_unset)
genome.initializer(GA1DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
genome.initializer(GA1DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
genome.initializer(GA1DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
genome.mutator(GA1DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA1DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA1DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA1DBinaryStringGenome::OnePointCrossover);
$$ELIF(crossover_twopoint)
genome.crossover(GA1DBinaryStringGenome::TwoPointCrossover);
$$ENDIF
$$IF(comparator_bit)
genome.comparator(GA1DBinaryStringGenome::BitComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_2dbinarystring)
GA2DBinaryStringGenome genome(width, height, objective);

$$IF(initializer_unset)
genome.initializer(GA2DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
genome.initializer(GA2DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
genome.initializer(GA2DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
genome.mutator(GA2DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA2DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA2DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA2DBinaryStringGenome::OnePointCrossover);
$$ENDIF
$$IF(comparator_bit)
genome.comparator(GA2DBinaryStringGenome::BitComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_3dbinarystring)
GA3DBinaryStringGenome genome(width, height, depth, objective);

$$IF(initializer_unset)
genome.initializer(GA3DBinaryStringGenome::UnsetInitializer);
$$ELIF(initializer_set)
genome.initializer(GA3DBinaryStringGenome::SetInitializer);
$$ELIF(initializer_uniform)
genome.initializer(GA3DBinaryStringGenome::UniformInitializer);
$$ENDIF
$$IF(mutator_flip)
genome.mutator(GA3DBinaryStringGenome::FlipMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA3DBinaryStringGenome::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA3DBinaryStringGenome::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA3DBinaryStringGenome::OnePointCrossover);
$$ENDIF
$$IF(comparator_bit)
genome.comparator(GA3DBinaryStringGenome::BitComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_1darray)
GA1DArrayGenome<int> genome(length, Objective);

$$IF(mutator_swap)
genome.mutator(GA1DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA1DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA1DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA1DArrayGenome<int>::OnePointCrossover);
$$ELIF(crossover_twopoint)
genome.crossover(GA1DArrayGenome<int>::TwoPointCrossover);
$$ELIF(crossover_partialmatch)
genome.crossover(GA1DArrayGenome<int>::PartialMatchCrossover);
$$ELIF(crossover_order)
genome.crossover(GA1DArrayGenome<int>::OrderCrossover);
$$ELIF(crossover_cycle)
genome.crossover(GA1DArrayGenome<int>::CycleCrossover);
$$ENDIF
$$IF(comparator_element)
genome.comparator(GA1DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_1darrayallele)
GAAlleleSet<int> alleles;
//TODO : define your own alleles
//ex) these alleles have -1, 0, 1
//		int aset[] = {-1,0,1};
//		GAAlleleSet<int> alleles(3, aset);
GA1DArrayAlleleGenome<int> genome(length, alleles, Objective);

$$IF(initializer_uniform)
genome.initializer(GA1DArrayAlleleGenome<int>::UniformInitializer);
$$ELIF(initializer_ordered)
genome.initializer(GA1DArrayAlleleGenome<int>::OrderedInitializer);
$$ENDIF
$$IF(mutator_swap)
genome.mutator(GA1DArrayGenome<int>::SwapMutator);
$$ELIF(mutator_flip)
genome.mutator(GA1DArrayGenome<int>::FlipMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA1DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA1DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA1DArrayGenome<int>::OnePointCrossover);
$$ELIF(crossover_twopoint)
genome.crossover(GA1DArrayGenome<int>::TwoPointCrossover);
$$ELIF(crossover_partialmatch)
genome.crossover(GA1DArrayGenome<int>::PartialMatchCrossover);
$$ELIF(crossover_order)
genome.crossover(GA1DArrayGenome<int>::OrderCrossover);
$$ELIF(crossover_cycle)
genome.crossover(GA1DArrayGenome<int>::CycleCrossover);
$$ENDIF
$$IF(comparator_element)
genome.comparator(GA1DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//

$$ELIF(genome_string)
GAStringAlleleSet alleles;
//TODO : define your own alleles
//ex) these alleles have a-z
//		for(i=0; i<26; i++)
//		alleles.add('a'+i);

GAStringGenome genome(length, alleles, objective);

$$IF(initializer_ordered)
genome.initializer(GAStringOrderedInitializer);
$$ELIF(initializer_uniform)
genome.initializer(GAStringUniformInitializer);
$$ENDIF
$$IF(mutator_flip)
genome.mutator(GAStringFlipMutator);
$$ELIF(mutator_swap)
genome.mutator(GAStringSwapMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GAStringUniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GAStrintEvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GAStringOnePointCrossover);
$$ELIF(crossover_twopoint)
genome.crossover(GAStringTwoPointCrossover);
$$ELIF(crossover_partialmatch)
genome.crossover(GAStringPartialMatchCrossover);
$$ELIF(crossover_order)
genome.crossover(GAStringOrderCrossover);
$$ELIF(crossover_cycle)
genome.crossover(GAStringCycleCrossover);
$$ENDIF
$$//

$$//
$$ELIF(genome_real)
GARealAlleleSet alleles(min, max);
GARealGenome genome(length, alleles, Objective);

$$IF(initializer_uniform)
genome.initializer(GARealUniformInitializer);
$$ELIF(initializer_ordered)
genome.initializer(GARealOrderedInitializer);
$$ENDIF
$$IF(mutator_realuniform)
genome.mutator(GARealUniformMutator);
$$ELIF(mutator_swap)
genome.mutator(GARealSwapMutator);
$$ELIF(mutator_realgaussian)
genome.mutator(GARealGaussianMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GARealUniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GARealEvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GARealOnePointCrossover);
$$ELIF(crossover_twopoint)
genome.crossover(GARealTwoPointCrossover);
$$ELIF(crossover_partialmatch)
genome.crossover(GARealPartialMatchCrossover);
$$ELIF(crossover_order)
genome.crossover(GARealOrderCrossover);
$$ELIF(crossover_cycle)
genome.crossover(GARealCycleCrossover);
$$ELIF(crossover_realarithmetic)
genome.crossover(GARealArithmeticCrossover);
$$ELIF(crossover_realblend)
genome.crossover(GARealBlendCrossover);
$$ENDIF
$$//

$$//
$$ELIF(genome_2darray)
GA2DArrayGenome<int> genome(width, height, Objective);

$$IF(mutator_swap)
genome.mutator(GA2DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA2DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA2DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA2DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$IF(comparator_element)
genome.comparator(GA2DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//

$$//
$$ELIF(2darrayallele)
GAAlleleSet<int> alleles;
//TODO : define your own alleles
//ex) these alleles have -1, 0, 1
//		int aset[] = {-1,0,1};
//		GAAlleleSet<int> alleles(3, aset);
GA2DArrayAlleleGenome<int> genome(width, height, alleles, Objective);

$$IF(mutator_swap)
genome.mutator(GA2DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA2DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA2DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA2DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$IF(comparator_element)
genome.comparator(GA2DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_3darray)
GA3DArrayGenome<int> genome(width, height, depth, Objective);

$$IF(mutator_swap)
genome.mutator(GA3DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA3DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA3DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA3DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$IF(comparator_element)
genome.comparator(GA3DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_3darrayallele)
GAAlleleSet<int> alleles;
//TODO : define your own alleles
//ex) these alleles have -1, 0, 1
//		int aset[] = {-1,0,1};
//		GAAlleleSet<int> alleles(3, aset);
GA3DArrayAlleleGenome<int> genome(width, height, depth, alleles, Objective);

$$IF(mutator_swap)
genome.mutator(GA3DArrayGenome<int>::SwapMutator);
$$ENDIF
$$IF(crossover_uniform)
genome.crossover(GA3DArrayGenome<int>::UniformCrossover);
$$ELIF(crossover_evenodd)
genome.crossover(GA3DArrayGenome<int>::EvenOddCrossover);
$$ELIF(crossover_onepoint)
genome.crossover(GA3DArrayGenome<int>::OnePointCrossover);
$$ENDIF
$$IF(comparator_element)
genome.comparator(GA3DArrayGenome<int>::ElementComparator);
$$ENDIF
$$//

$$//
$$ELIF(genome_list)
GAListGenome<int> genome(objective);

$$IF(mutator_destructive)
genome.mutator(GAListGenome<int>::DestructiveMutator);
$$ELIF(mutator_swap)
genome.mutator(GAListGenome<int>::SwapMutator);
$$ENDIF
$$IF(crossover_onepoint)
genome.crossover(GAListGenome<int>::OnePointCrossover);
$$ELIF(crossover_partialmatch)
genome.crossover(GAListGenome<int>::PartialMatchCrossover);
$$ELIF(crossover_order)
genome.crossover(GAListGenome<int>::OrderCrossover);
$$ELIF(crossover_cycle)
genome.crossover(GAListGenome<int>::CycleCrossover);
$$ENDIF
$$//

$$//
$$ELIF(genome_tree)
GATreeGenome<int> genome(objective);

$$IF(mutator_destructive)
genome.mutator(GATreeGenome<int>::DestructiveMutator);
$$ELIF(mutator_swapnode)
genome.mutator(GATreeGenome<int>::SwapNodeMutator);
$$ELIF(mutator_swapsubtree)
genome.mutator(GATreeGenome<int>::SwapSubTreeMutator);
$$ENDIF
$$//

$$ENDIF
$$//


$$//
$$IF(ga_simple)
GASimpleGA ga(genome);
$$//
$$//
$$ELIF(ga_incremental)
GAIncrementalGA ga(genome);
$$//
$$//
$$ELIF(ga_steadystate)
GASteadyStateGA ga(genome);
$$//
$$ELIF(ga_deme)
GADemeGA ga(genome);
$$ENDIF
$$//
$$IF(selector_rank)
GARankSelector selector;
ga.selector(selector);
$$ELIF(selector_roulettewheel)
GARouletteWheelSelector selector;
ga.selector(selector);
$$ELIF(selector_Tournament)
GATournamentSelector selector;
ga.selector(selector);
$$ELIF(selector_ds)
GADSSelector selector;
ga.selector(selector);
$$ELIF(selector_srs)
GASRSSelector selector;
ga.selector(selector);
$$ELIF(selector_uniform)
GAUniformSelector selector;
ga.selector(selector);
$$ENDIF
$$//
$$IF(scaling_no)
GANoScaling scaling;
ga.scaling(scaling);
$$ELIF(scaling_linear)
GALinearScaling scaling;
ga.scaling(scaling);
$$ELIF(scaling_sigmatruncation)
GASigmaTruncationScaling scaling;
ga.scaling(scaling);
$$ELIF(scaling_powerlaw)
GAPowerLawScaling scaling;
ga.scaling(scaling);
$$ELIF(scaling_sharing)
GASharingScaling scaling;
ga.scaling(scaling);
$$ENDIF
$$//

ga.ga.populationSize(popsize);
ga.pMutation(pmut);
ga.pCrossover(pcross);
$$//

$$IF(terminator_generation)
ga.nGenerations(ngen);
$$ELIF(terminator_convergence)
ga.pConvergence(pconv);
ga.nConvergence(ngen);
$$ELIF(terminator_popconvergence)
ga.pConvergence(pconv);
$$ENDIF
$$//

float
objective(GAGenome& c)
{
	//TODO : Add your objective function here.

}

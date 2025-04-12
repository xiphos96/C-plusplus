//Define global variables and global instances. You can access any
//Public members of these classes through the global instances.

float Objective(GAGenome& c){

}

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
$$IF(!genome_list)
$$IF(!genome_tree)
int nvar;
float min;
float max;
$$ENDIF
$$ENDIF
$$IF(genome_1dbinarystring||genome_bin2dec||genome_2dbinarystring||genome_3dbinarystring)
int nbit;
$$ENDIF
$$//

$$IF(genome_1dbinarystring)
GA1DBinaryStringGenome genome(length, Objective);
$$ELIF(genome_bin2dec)
GABin2DecPhenotype map;
//TODO : define your own maps.
//ex) for(int i=0;i<nvar;i++) 
//		map.add(nbit,min,max);
GABin2DecGenome genome(map,Objective);
$$ELIF(genome_2dbinarystring)
GA2DBinaryStringGenome genome(width, height, objective);
$$ELIF(genome_3dbinarystring)
GA3DBinaryStringGenome genome(width, height, depth, objective);
$$ELIF(genome_1darray)
GA1DArrayGenome<int> genome(length, Objective);
$$ELIF(genome_1darrayallele)
GAAlleleSet<int> alleles;
//TODO : define your own alleles
//ex) these alleles have -1, 0, 1
//		int aset[] = {-1,0,1};
//		GAAlleleSet<int> alleles(3, aset);
GA1DArrayAlleleGenome<int> genome(length, alleles, Objective);
$$ELIF(genome_string)
GAStringAlleleSet alleles;
//TODO : define your own alleles
//ex) these alleles have a-z
//		for(i=0; i<26; i++)
//		alleles.add('a'+i);
GAStringGenome genome(length, alleles, objective);
$$ELIF(genome_real)
GARealAlleleSet alleles(min, max);
GARealGenome genome(length, alleles, Objective);
$$ELIF(genome_2darray)
GA2DArrayGenome<int> genome(width, height, Objective);
$$ELIF(2darrayallele)
GAAlleleSet<int> alleles;
//TODO : define your own alleles
//ex) these alleles have -1, 0, 1
//		int aset[] = {-1,0,1};
//		GAAlleleSet<int> alleles(3, aset);
GA2DArrayAlleleGenome<int> genome(width, height, alleles, Objective);
$$ELIF(genome_3darray)
GA3DArrayGenome<int> genome(width, height, depth, Objective);
$$ELIF(genome_3darrayallele)
GAAlleleSet<int> alleles;
//TODO : define your own alleles
//ex) these alleles have -1, 0, 1
//		int aset[] = {-1,0,1};
//		GAAlleleSet<int> alleles(3, aset);
GA3DArrayAlleleGenome<int> genome(width, height, depth, alleles, Objective);
$$ELIF(genome_list)
GAListGenome<int> genome(objective);
$$ELIF(genome_tree)
GATreeGenome<int> genome(objective);
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

/* ----------------------------------------------------------------------------
  ex17.cpp
  mbwall 5may95
  Copyright (c) 1995-1996  Massachusetts Institute of Technology

 DESCRIPTION:
   Example program illustrating the use of a 2DArrayGenome with trinary
alleles (-1, 0, 1).  The objective function for this program tries to 
alternate 0 and 1 then put -1 in the corners.
---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>
#include <ga.h>


float objective(GAGenome &);

int
main(int argc, char *argv[])
{
  cout << "Example 17\n\n";
  cout << "This program illustrates the use of a 2DArrayGenome with\n";
  cout << "three alleles.  It tries to fill a 2D array with alternating\n";
  cout << "0s and 1s, and -1s at the corners.  You will have to run it\n";
  cout << "for something like 10000 generations to get the perfect score.\n\n";
  cout.flush();

// See if we've been given a seed to use (for testing purposes).  When you
// specify a random seed, the evolution will be exactly the same each time
// you use that seed number.

  unsigned int seed = 0;
  for(int ii=1; ii<argc; ii++) {
    if(strcmp(argv[ii++],"seed") == 0) {
      seed = atoi(argv[ii]);
    }
  }

  int aset[] = {-1,0,1};
  GAAlleleSet<int> alleles(3, aset);
  GA2DArrayAlleleGenome<int> genome(20, 20, alleles, objective);
  genome.initializer(GA2DArrayAlleleGenome<int>::UniformInitializer);
  genome.mutator(GA2DArrayAlleleGenome<int>::FlipMutator);
  genome.crossover(GA2DArrayGenome<int>::OnePointCrossover);

  GASteadyStateGA ga(genome);

  GASigmaTruncationScaling trunc;
  ga.scaling(trunc);
  ga.set(gaNpopulationSize, 40);
  ga.set(gaNpCrossover, 0.6); 
  ga.set(gaNpMutation, 0.001);
  ga.set(gaNnGenerations, 10000);
  ga.set(gaNpReplacement, 0.25);
  ga.parameters(argc, argv);
  ga.initialize(seed);

  cout << "evolving...";
  while(!ga.done()){
    ga.step();
    if(ga.generation() % 50 == 0){
      cout << "."; cout.flush();
    }
  }
  cout << "\n\n";

  cout << "the ga generated:\n" << ga.statistics().bestIndividual() << endl;

  return 0;
}
 


float
objective(GAGenome & c)
{
  GA2DArrayAlleleGenome<int> & genome = (GA2DArrayAlleleGenome<int> &)c;

  float value=0.0;
  int count=0;
  for(int i=0; i<genome.width(); i++){
    for(int j=0; j<genome.height(); j++){
      if(genome.gene(i,j) == 0 && count%2 == 0)
        value += 1.0;
      if(genome.gene(i,j) == 1 && count%2 != 0)
        value += 1.0;
      count++;
    }
  }
  value -= 4;
  value += 10*(genome.gene(0,0) == 
	       genome.alleleset().allele(0));
  value += 10*(genome.gene(genome.width()-1,0) == 
	       genome.alleleset().allele(0));
  value += 10*(genome.gene(0, genome.height()-1) == 
	       genome.alleleset().allele(0));
  value += 10*(genome.gene(genome.width()-1, genome.height()-1) == 
	       genome.alleleset().allele(0));
  return(value);
}


// Here we override the built-in write method for the 2DArray genome so
// that we get better spacing.  The default just stacks the characters one
// after another.  Here we do fixed spacing so that the -1 and 1 don't screw
// each other up.
int
GA2DArrayAlleleGenome<int>::write(ostream & os) const 
{
  for(unsigned int j=0; j<ny; j++){
    for(unsigned int i=0; i<nx; i++){
      os.width(3);
      os << gene(i,j);
    }
    os << "\n";
  }
  return os.fail() ? 1 : 0;
}





// If your compiler does not do automatic instantiation (e.g. g++ 2.6.8),
// then define the NO_AUTO_INST directive.
#ifdef NO_AUTO_INST
#include <GAAllele.cpp>
#include <GA2DArra.cpp>
#if defined(__GNUG__)
template class GAAlleleSet<int>;
template class GAAlleleSetCore<int>;
template class GAArray<int>;
template class GA2DArrayGenome<int>;
template class GA2DArrayAlleleGenome<int>;
#else
GAAlleleSet<int>;
GAAlleleSetCore<int>;
GAArray<int>;
GA2DArrayGenome<int>;
GA2DArrayAlleleGenome<int>;
#endif
#endif


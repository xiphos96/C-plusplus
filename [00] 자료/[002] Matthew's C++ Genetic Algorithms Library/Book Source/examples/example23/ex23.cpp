/* ----------------------------------------------------------------------------
  ex23.cpp
  mbwall 5jan96
  Copyright (c) 1995-1996  Massachusetts Institute of Technology

 DESCRIPTION:
   This example shows how to use max/min feature of GAlib to maximize or 
minimize your objective functions.
---------------------------------------------------------------------------- */
#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <ga.h>
#include <GARealGe.h>
#include <GARealGe.cpp>

#ifndef M_PI
#define M_PI            3.14159265358979323846
#endif

#define MIN_VALUE -2
#define MAX_VALUE 2
#define INC       0.005

float Objective(GAGenome &);
float Comparator(const GAGenome&, const GAGenome&);

int
main(int argc, char** argv)
{
  cout << "Example 23\n\n";
  cout << "This program tries to maximize or minimize, depending on the\n";
  cout << "command line argument that you give it.  Use the command-line\n";
  cout << "argument 'mm -1' to minimize (the default for this example), or\n";
  cout << "'mm 1' to maximize.  The objective function is a simple \n";
  cout << "sinusoidal.\n\n"; cout.flush();

// See if we've been given a seed to use (for testing purposes).  When you
// specify a random seed, the evolution will be exactly the same each time
// you use that seed number.

  for(int jj=1; jj<argc; jj++) {
    if(strcmp(argv[jj++],"seed") == 0) {
      GARandomSeed((unsigned int)atoi(argv[jj]));
    }
  }

  ofstream outfile;

  GARealAlleleSet alleles(MIN_VALUE, MAX_VALUE);
  GARealGenome genome(1, alleles, Objective);
  GASharing scale(Comparator);

  GASimpleGA ga(genome);
  ga.minimize();		// by default we want to minimize the objective
  ga.scaling(scale);		// set the scaling method to our sharing
  ga.populationSize(50);	// how many individuals in the population
  ga.nGenerations(25);		// number of generations to evolve
  ga.pMutation(0.001);		// likelihood of mutating new offspring
  ga.pCrossover(0.9);		// likelihood of crossing over parents
  ga.scoreFilename("bog.dat");	// name of file for scores
  ga.scoreFrequency(1);		// keep the scores of every generation
  ga.flushFrequency(10);	// specify how often to write the score to disk
  ga.selectScores(GAStatistics::AllScores);
  ga.parameters(argc, argv, gaTrue); // parse commands, complain if bogus args

  ga.initialize();

// dump the initial population to file

  cout << "printing initial population to file..." << endl;
  outfile.open("popi.dat", (ios::out | ios::trunc));
  for(int ii=0; ii<ga.population().size(); ii++){
    genome = ga.population().individual(ii);
    outfile << genome.gene(0) << "\t" << genome.score() << "\n";
  }
  outfile.close();

  while(!ga.done()) ga.step();

// dump the final population to file

  cout << "printing final population to file..." << endl;
  outfile.open("popf.dat", (ios::out | ios::trunc));
  for(int i=0; i<ga.population().size(); i++){
    genome = ga.population().individual(i);
    outfile << genome.gene(0) << "\t" << genome.score() << "\n";
  }
  outfile.close();

// dump the function to file so you can plot the population on it

  cout << "printing function to file..." << endl;
  outfile.open("sinusoid.dat", (ios::out | ios::trunc));
  for(float x=MIN_VALUE; x<=MAX_VALUE; x+=INC){
    outfile << genome.gene(0,x) << "\t" << genome.score() << "\n";
  }
  outfile.close();

  return 0;
}
 



// This objective function returns the sin of the value in the genome.
float
Objective(GAGenome& g){
  GARealGenome& genome = (GARealGenome &)g;
  return 1 + sin(genome.gene(0)*2*M_PI);
}

// The comparator returns a number in the interval [0,1] where 0 means that
// the two genomes are identical (zero diversity) and 1 means they are 
// completely different (maximum diversity).
float
Comparator(const GAGenome& g1, const GAGenome& g2) {
  GARealGenome& a = (GARealGenome &)g1;
  GARealGenome& b = (GARealGenome &)g2;
  return exp( -(a.gene(0) - b.gene(0)) * (a.gene(0) - b.gene(0)) / 1000.0);
}

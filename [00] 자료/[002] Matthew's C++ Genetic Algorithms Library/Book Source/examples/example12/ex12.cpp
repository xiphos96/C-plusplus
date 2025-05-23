/* ----------------------------------------------------------------------------
  ex12.cpp
  mbwall 13apr95
  Copyright (c) 1995-1996  Massachusetts Institute of Technology

 DESCRIPTION:
   This example shows how to use an order-based string genome.
---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>
#include <ga.h>
#include <GAString.h>
#include <GAString.cpp>

// This is the declaration of the objective function that we will use in this
// example.
float objective(GAGenome &);

// Every genome must have an initializer.  Here we declare our own initializer
// that will be used in this example.
void AlphabetInitializer(GAGenome &);


int
main(int argc, char *argv[])
{
  cout << "Example 12\n\n";
  cout << "This program illustrates the use of order-based strings.  The\n";
  cout << "string in this problem contains 26 letters, a to z.  It tries\n";
  cout << "to put them in alphabetic order.\n\n";
  cout.flush();

// See if we've been given a seed to use (for testing purposes).  When you
// specify a random seed, the evolution will be exactly the same each time
// you use that seed number.

  for(int ii=1; ii<argc; ii++) {
    if(strcmp(argv[ii++],"seed") == 0) {
      GARandomSeed((unsigned int)atoi(argv[ii]));
    }
  }

// Set the default values of the parameters then parse for command line changes

  int i;
  GAParameterList params;
  GASteadyStateGA::registerDefaultParameters(params);
  params.set(gaNpopulationSize, 25);	// population size
  params.set(gaNpCrossover, 0.9);	// probability of crossover 
  params.set(gaNpMutation, 0.01);	// probability of mutation
  params.set(gaNnGenerations, 400);	// number of generations
  params.parse(argc, argv, gaFalse);

// Now create the GA and run it.  We first create a genome with the
// operators we want.  Since we're using a template genome, we must assign
// all three operators.  We use the order-based crossover site when we assign
// the crossover operator.

  GAStringAlleleSet alleles;
  for(i=0; i<26; i++)
    alleles.add('a'+i);

  GAStringGenome genome(26, alleles, objective);
  genome.initializer(AlphabetInitializer);
  genome.mutator(GAStringSwapMutator);

  GASteadyStateGA ga(genome);
  ga.parameters(params);
  ga.crossover(GAStringPartialMatchCrossover);
  ga.evolve();
  
  genome = ga.statistics().bestIndividual();
  cout << "the ga generated the following string (objective score is ";
  cout << genome.score() << "):\n" << genome << "\n";
  cout << genome.className() << "\n";

  return 0;
}
 


/* ----------------------------------------------------------------------------
Objective function
  The objective function gives one point for every number in the correct
position.  We're trying to get a sequence of numbers from n to 0 in descending
order.
---------------------------------------------------------------------------- */
float
objective(GAGenome & c)
{
  GAStringGenome & genome = (GAStringGenome &)c;

  float score = 0;
  for(unsigned int i=0; i<genome.size(); i++)
    score += (genome.gene(i) == 'a' + i);
  return score;
}



/* ----------------------------------------------------------------------------
AlphabetInitializer
  This initializer creates a string genome with the letters a-z as its 
elements.  Once we have assigned all the values, we randomize the string.
---------------------------------------------------------------------------- */
void
AlphabetInitializer(GAGenome & c)
{
  GAStringGenome &genome=(GAStringGenome &)c;
  unsigned int i;
  for(i=0; i<genome.size(); i++)
    genome.gene(25-i, 'a'+i);

  for(i=0; i<genome.size(); i++)
    if(GARandomBit()) genome.swap(i, GARandomInt(0, genome.size()-1));
}

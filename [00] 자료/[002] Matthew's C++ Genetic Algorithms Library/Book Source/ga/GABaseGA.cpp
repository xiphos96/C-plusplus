// $Header: /usr/people/mbwall/src/galib/ga/RCS/GABaseGA.cpp,v 1.5 1999/03/27 19:19:46 mbwall Exp $
/* ----------------------------------------------------------------------------
  gabase.C
  mbwall 28jul94
  Copyright (c) 1995 Massachusetts Institute of Technology
                     all rights reserved

  Source file for the base genetic algorithm object.
---------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>
#include <GABaseGA.h>
#include <garandom.h>
#include <gaversio.h>	// gets the RCS string in for ident purposes


//#define GA_DEBUG

// Here we assign the default values of the GAlib default parameters.
int   gaDefNumGen           = 250;
float gaDefPConv            = 0.99;
int   gaDefNConv            = 20;
float gaDefPMut             = 0.01;
float gaDefPCross           = 0.90;
int   gaDefPopSize          = 50;
int   gaDefNPop             = 10;
float gaDefPRepl            = 0.5;
int   gaDefNRepl            = 10;
int   gaDefNumOff           = 2;
float gaDefPMig             = 0.1;
int   gaDefNMig             = 5;
int   gaDefSelectScores     = GAStatistics::Maximum;
int   gaDefMiniMaxi         = 1;
GABoolean gaDefDivFlag      = gaFalse;
GABoolean gaDefElitism      = gaTrue;




// Here are a few termination functions that you can use.
GABoolean
GAGeneticAlgorithm::TerminateUponGeneration(GAGeneticAlgorithm & ga){
  return(ga.generation() < ga.nGenerations() ? gaFalse : gaTrue);
}
// The test for convergence == 0 is a hack.  Technically convergence should be
// modified to return 1 or 0 depending on whether a maximization or minimize is
// happening, but on the other hand a stats object has no business knowing what
// the ga is trying to do.
GABoolean 
GAGeneticAlgorithm::TerminateUponConvergence(GAGeneticAlgorithm & ga){
  GABoolean val = gaFalse;
  if(ga.minimaxi() == GAGeneticAlgorithm::MINIMIZE) {
    if(ga.convergence() == 0 || ga.convergence() > ga.pConvergence())
      val = gaFalse;
    else 
      val = gaTrue;
  }
  else {
    if(ga.convergence() < ga.pConvergence())
      val = gaFalse;
    else 
      val = gaTrue;
  }
  return val;
}
GABoolean 
GAGeneticAlgorithm::TerminateUponPopConvergence(GAGeneticAlgorithm & ga){
  if(ga.statistics().current(GAStatistics::Mean) /
     ga.statistics().current(GAStatistics::Maximum) < ga.pConvergence())
    return gaTrue;
  else
    return gaFalse;
}







GAParameterList&
GAGeneticAlgorithm::registerDefaultParameters(GAParameterList& p) {
  p.add(gaNminimaxi, gaSNminimaxi, GAParameter::INT, &gaDefMiniMaxi);
  p.add(gaNnGenerations, gaSNnGenerations, GAParameter::INT, &gaDefNumGen);
  p.add(gaNnConvergence, gaSNnConvergence, GAParameter::INT, &gaDefNConv);
  p.add(gaNpConvergence, gaSNpConvergence, GAParameter::FLOAT, &gaDefPConv);
  p.add(gaNpCrossover, gaSNpCrossover, GAParameter::FLOAT, &gaDefPCross);
  p.add(gaNpMutation, gaSNpMutation, GAParameter::FLOAT, &gaDefPMut);
  p.add(gaNpopulationSize, gaSNpopulationSize, 
	GAParameter::INT, &gaDefPopSize);
  p.add(gaNnBestGenomes, gaSNnBestGenomes, 
	GAParameter::INT, &gaDefNumBestGenomes);
  p.add(gaNscoreFrequency, gaSNscoreFrequency,
	GAParameter::INT, &gaDefScoreFrequency1);
  p.add(gaNflushFrequency, gaSNflushFrequency,
	GAParameter::INT, &gaDefFlushFrequency);
  p.add(gaNrecordDiversity, gaSNrecordDiversity,
	GAParameter::INT, &gaDefDivFlag);
  p.add(gaNscoreFilename, gaSNscoreFilename, 
	GAParameter::STRING, gaDefScoreFilename);
  p.add(gaNselectScores, gaSNselectScores, 
	GAParameter::INT, &gaDefSelectScores);

  return p;
}

// When we create a GA, we stuff the parameters with the basics that will be
// needed by most genetic algorithms - num generations, p convergence, etc.
GAGeneticAlgorithm::GAGeneticAlgorithm(const GAGenome& g) : stats(), params() {
  pop = new GAPopulation(g, gaDefPopSize);
  pop->geneticAlgorithm(*this);

  ud = (void *)0;
  cf = GAGeneticAlgorithm::DEFAULT_TERMINATOR;

  minmax = gaDefMiniMaxi;
  params.add(gaNminimaxi, gaSNminimaxi, GAParameter::INT, &minmax);
  ngen = gaDefNumGen;
  params.add(gaNnGenerations, gaSNnGenerations, GAParameter::INT, &ngen);
  nconv = gaDefNConv; stats.nConvergence(nconv);
  params.add(gaNnConvergence, gaSNnConvergence, GAParameter::INT, &nconv);
  pconv = gaDefPConv;
  params.add(gaNpConvergence, gaSNpConvergence, GAParameter::FLOAT, &pconv);
  pcross = gaDefPCross;
  params.add(gaNpCrossover, gaSNpCrossover, GAParameter::FLOAT, &pcross);
  pmut = gaDefPMut;
  params.add(gaNpMutation, gaSNpMutation, GAParameter::FLOAT, &pmut);
  int psize = pop->size();
  params.add(gaNpopulationSize, gaSNpopulationSize, GAParameter::INT, &psize);

  stats.scoreFrequency(gaDefScoreFrequency1);
  params.add(gaNscoreFrequency, gaSNscoreFrequency,
	     GAParameter::INT, &gaDefScoreFrequency1);
  stats.flushFrequency(gaDefFlushFrequency);
  params.add(gaNflushFrequency, gaSNflushFrequency,
	     GAParameter::INT, &gaDefFlushFrequency);
  stats.recordDiversity(gaDefDivFlag);
  params.add(gaNrecordDiversity, gaSNrecordDiversity, 
	     GAParameter::INT, &gaDefDivFlag);
  stats.scoreFilename(gaDefScoreFilename);
  params.add(gaNscoreFilename, gaSNscoreFilename, 
	     GAParameter::STRING, gaDefScoreFilename);
  stats.selectScores(gaDefSelectScores);
  params.add(gaNselectScores, gaSNselectScores, 
	     GAParameter::INT, &gaDefSelectScores);
  stats.nBestGenomes(g, gaDefNumBestGenomes);
  params.add(gaNnBestGenomes, gaSNnBestGenomes,
	     GAParameter::INT, &gaDefNumBestGenomes);

  scross = g.sexual();
  across = g.asexual();
}

GAGeneticAlgorithm::GAGeneticAlgorithm(const GAPopulation& p) : 
stats(), params() {
  pop = new GAPopulation(p);
  pop->geneticAlgorithm(*this);

  ud = (void *)0;
  cf = GAGeneticAlgorithm::DEFAULT_TERMINATOR;

  minmax = gaDefMiniMaxi;
  params.add(gaNminimaxi, gaSNminimaxi, GAParameter::INT, &minmax);
  ngen = gaDefNumGen;
  params.add(gaNnGenerations, gaSNnGenerations, GAParameter::INT, &ngen);
  nconv = gaDefNConv; stats.nConvergence(nconv);
  params.add(gaNnConvergence, gaSNnConvergence, GAParameter::INT, &nconv);
  pconv = gaDefPConv;
  params.add(gaNpConvergence, gaSNpConvergence, GAParameter::FLOAT, &pconv);
  pcross = gaDefPCross;
  params.add(gaNpCrossover, gaSNpCrossover, GAParameter::FLOAT, &pcross);
  pmut = gaDefPMut;
  params.add(gaNpMutation, gaSNpMutation, GAParameter::FLOAT, &pmut);
  int psize = pop->size();
  params.add(gaNpopulationSize, gaSNpopulationSize, GAParameter::INT, &psize);

  stats.scoreFrequency(gaDefScoreFrequency1);
  params.add(gaNscoreFrequency, gaSNscoreFrequency,
	     GAParameter::INT, &gaDefScoreFrequency1);
  stats.flushFrequency(gaDefFlushFrequency);
  params.add(gaNflushFrequency, gaSNflushFrequency,
	     GAParameter::INT, &gaDefFlushFrequency);
  stats.recordDiversity(gaDefDivFlag);
  params.add(gaNrecordDiversity, gaSNrecordDiversity, 
	     GAParameter::INT, &gaDefDivFlag);
  stats.scoreFilename(gaDefScoreFilename);
  params.add(gaNscoreFilename, gaSNscoreFilename, 
	     GAParameter::STRING, gaDefScoreFilename);
  stats.selectScores(gaDefSelectScores);
  params.add(gaNselectScores, gaSNselectScores, 
	     GAParameter::INT, &gaDefSelectScores);
  stats.nBestGenomes(p.individual(0), gaDefNumBestGenomes);
  params.add(gaNnBestGenomes, gaSNnBestGenomes,
	     GAParameter::INT, &gaDefNumBestGenomes);

  scross = p.individual(0).sexual();
  across = p.individual(0).asexual();
}

GAGeneticAlgorithm::GAGeneticAlgorithm(const GAGeneticAlgorithm& ga) : 
stats(ga.stats), params(ga.params){
  pop = ga.pop->clone();
  pop->geneticAlgorithm(*this);

  cf = ga.cf; ud = ga.ud;
  ngen = ga.ngen; nconv = ga.nconv; pconv = ga.pconv;
  pcross = ga.pcross; pmut = ga.pmut; minmax = ga.minmax;
  scross = ga.scross; across = ga.across;
}

GAGeneticAlgorithm::~GAGeneticAlgorithm() {
  delete pop;
}

void
GAGeneticAlgorithm::copy(const GAGeneticAlgorithm& ga) {
  if(pop) pop->copy(*(ga.pop));
  else pop = ga.pop->clone();
  pop->geneticAlgorithm(*this);

  stats = ga.stats;
  params = ga.params;

  cf = ga.cf; ud = ga.ud;
  ngen = ga.ngen; nconv = ga.nconv; pconv = ga.pconv;
  pcross = ga.pcross; pmut = ga.pmut; minmax = ga.minmax;
  scross = ga.scross; across = ga.across;
}








const GAParameterList&
GAGeneticAlgorithm::parameters(const GAParameterList& list){
  for(int i=0; i<list.size(); i++)
    setptr(list[i].fullname(), list[i].value());
  return params;
}

const GAParameterList&
GAGeneticAlgorithm::parameters(int& argc, char **argv, GABoolean flag){
  params.parse(argc, argv, flag);	// get the args we understand
  for(int i=0; i<params.size(); i++)
    setptr(params[i].fullname(), params[i].value());
  return params;
}

#ifndef NO_STREAMS
const GAParameterList&
GAGeneticAlgorithm::parameters(const char* filename, GABoolean flag){
  params.read(filename, flag);
  for(int i=0; i<params.size(); i++)
    setptr(params[i].fullname(), params[i].value());
  return params;
}

const GAParameterList&
GAGeneticAlgorithm::parameters(istream& is, GABoolean flag){
  params.read(is, flag);
  for(int i=0; i<params.size(); i++)
    setptr(params[i].fullname(), params[i].value());
  return params;
}
#endif

// Return 0 if everything is OK, non-zero if error.  If we did not set anything
// then we return non-zero (this is not an error, but we indicate that we did
// not do anything).
//   The set method must set both the GA's parameter and the value in the
// parameter list (kind of stupid to maintain two copies of the same data, but
// oh well).  The call to set on params is redundant for the times when this
// method is called *after* the parameter list has been updated, but it is
// necessary when this method is called directly by the user.
int
GAGeneticAlgorithm::setptr(const char* name, const void* value){
  int status=1;

  params.set(name, value);	// redundant for some cases, but not others 

  if(strcmp(name, gaNnBestGenomes) == 0 ||
     strcmp(name, gaSNnBestGenomes) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    nBestGenomes(*((int*)value));
    status = 0;
  }
  else if(strcmp(name, gaNpopulationSize) == 0 ||
	  strcmp(name, gaSNpopulationSize) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    populationSize(*((int*)value));
    status = 0;
  }
  else if(strcmp(name, gaNminimaxi) == 0 ||
     strcmp(name, gaSNminimaxi) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    minimaxi(*((int*)value));
    status = 0;
  }
  else if(strcmp(name, gaNnGenerations) == 0 ||
     strcmp(name, gaSNnGenerations) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    nGenerations(*((int*)value));
    status = 0;
  }
  else if(strcmp(name, gaNpConvergence) == 0 || 
	  strcmp(name, gaSNpConvergence) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((float*)value) << "'\n";
#endif
    pConvergence(*((float*)value));
    status = 0;
  }
  else if(strcmp(name, gaNnConvergence) == 0 || 
	  strcmp(name, gaSNnConvergence) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    nConvergence(*((int*)value));
    status = 0;
  }
  else if(strcmp(name, gaNpCrossover) == 0 ||
	  strcmp(name, gaSNpCrossover) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((float*)value) << "'\n";
#endif
    pCrossover(*((float*)value));
    status = 0;
  }
  else if(strcmp(name, gaNpMutation) == 0 ||
	  strcmp(name, gaSNpMutation) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((float*)value) << "'\n";
#endif
    pMutation(*((float*)value));
    status = 0;
  }
  else if(strcmp(name,gaNscoreFrequency) == 0 ||
	  strcmp(name,gaSNscoreFrequency) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    stats.scoreFrequency(*((int*)value));
    status = 0;
  }
  else if(strcmp(name,gaNflushFrequency) == 0 ||
	  strcmp(name,gaSNflushFrequency) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    stats.flushFrequency(*((int*)value));
    status = 0;
  }
  else if(strcmp(name,gaNrecordDiversity) == 0 ||
	  strcmp(name,gaSNrecordDiversity) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    stats.recordDiversity(*((int*)value) ? gaTrue : gaFalse);
    status = 0;
  }
  else if(strcmp(name,gaNselectScores) == 0 ||
	  strcmp(name,gaSNselectScores)==0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << *((int*)value) << "'\n";
#endif
    stats.selectScores(*((int*)value));
    status = 0;
  }
  else if(strcmp(name,gaNscoreFilename) == 0 ||
	  strcmp(name,gaSNscoreFilename) == 0){
#ifdef GA_DEBUG
    cerr << "GAGeneticAlgorithm::setptr\n  setting '" << name << "' to '" << ((char*)value) << "'\n";
#endif
    char tmpname[64];
    memcpy(tmpname, value, strlen((char*)value)+1);
    stats.scoreFilename(tmpname);
    status = 0;
  }
  return status;
}

// This is a pretty ugly little hack to make doubles/floats work transparently.
int
GAGeneticAlgorithm::set(const char* name, double v) {
  int status=1;
  for(int i=0; i<params.size(); i++){
    if(strcmp(name, params[i].fullname()) == 0 ||
       strcmp(name, params[i].shrtname()) == 0){
      if(params[i].type() == GAParameter::FLOAT){
	float fval = (float)v;
	status = setptr(name, (void*)&fval);
      }
      else
	status = setptr(name, (void*)&v);
    }
  }
  return status;
}

int
GAGeneticAlgorithm::get(const char* name, void* value) const {
  int status=1;

  if(strcmp(name, gaNnBestGenomes) == 0 ||
     strcmp(name, gaSNnBestGenomes) == 0){
    *((int*)value) = stats.nBestGenomes();
    status = 0;
  }
  else if(strcmp(name, gaNpopulationSize) == 0 ||
	  strcmp(name, gaSNpopulationSize) == 0){
    *((int*)value) = pop->size();
    status = 0;
  }
  else if(strcmp(name, gaNminimaxi) == 0 ||
     strcmp(name, gaSNminimaxi) == 0){
    *((int*)value) = minmax;
    status = 0;
  }
  else if(strcmp(name, gaNnGenerations) == 0 ||
     strcmp(name, gaSNnGenerations) == 0){
    *((int*)value) = ngen;
    status = 0;
  }
  else if(strcmp(name, gaNpConvergence) == 0 ||
	  strcmp(name, gaSNpConvergence) == 0){
    *((float*)value) = pconv;
    status = 0;
  }
  else if(strcmp(name, gaNnConvergence) == 0 ||
	  strcmp(name, gaSNnConvergence) == 0){
    *((int*)value) = nconv;
    status = 0;
  }
  else if(strcmp(name, gaNpCrossover) == 0 ||
	  strcmp(name, gaSNpCrossover) == 0){
    *((float*)value) = pcross;
    status = 0;
  }
  else if(strcmp(name, gaNpMutation) == 0 ||
	  strcmp(name, gaSNpMutation) == 0){
    *((float*)value) = pmut;
    status = 0;
  }
  else if(strcmp(name,gaNscoreFrequency) == 0 ||
	  strcmp(name,gaSNscoreFrequency) == 0){
    *((int*)value) = stats.scoreFrequency();
    status = 0;
  }
  else if(strcmp(name,gaNflushFrequency) == 0 ||
	  strcmp(name,gaSNflushFrequency) == 0){
    *((int*)value) = stats.flushFrequency();
    status = 0;
  }
  else if(strcmp(name,gaNrecordDiversity) == 0 ||
	  strcmp(name,gaSNrecordDiversity) == 0){
    *((int*)value) = stats.recordDiversity();
    status = 0;
  }
  else if(strcmp(name,gaNselectScores) == 0 ||
	  strcmp(name,gaSNselectScores)==0){
    *((int*)value) = stats.selectScores();
    status = 0;
  }
  else if(strcmp(name,gaNscoreFilename) == 0 ||
	  strcmp(name,gaSNscoreFilename) == 0){
    *((const char**)value) = stats.scoreFilename();
    status = 0;
  }
  return status;
}






void 
GAGeneticAlgorithm::objectiveFunction(GAGenome::Evaluator f){
  for(int i=0; i<pop->size(); i++)
    pop->individual(i).evaluator(f);
}

void
GAGeneticAlgorithm::objectiveData(const GAEvalData& v){
  for(int i=0; i<pop->size(); i++)
    pop->individual(i).evalData(v);
}

const GAPopulation&
GAGeneticAlgorithm::population(const GAPopulation& p) {
  if(p.size() < 1) {
    GAErr(GA_LOC, className(), "population", gaErrNoIndividuals);
    return *pop;
  }
  
  pop->copy(p);
  pop->geneticAlgorithm(*this);

  return *pop;
}

int
GAGeneticAlgorithm::populationSize(unsigned int value){
  unsigned int ps = value;
  params.set(gaNpopulationSize, value);
  return pop->size(ps);
}

int 
GAGeneticAlgorithm::minimaxi(int m) { 
  if(m == MINIMIZE)
    pop->order(GAPopulation::LOW_IS_BEST);
  else
    pop->order(GAPopulation::HIGH_IS_BEST);
  params.set(gaNminimaxi, m);
  minmax = (m == MINIMIZE ? MINIMIZE : MAXIMIZE);
  return minmax;
}

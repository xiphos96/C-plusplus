// $Header: /usr/people/mbwall/src/galib/ga/RCS/GADCrowd.h,v 1.2 1999/04/03 19:03:52 mbwall Exp $
/* ----------------------------------------------------------------------------
  dcrowdingga.h
  mbwall 29mar99
  Copyright (c) 1999 Matthew Wall, all rights reserved

  Header file for the steady-state genetic algorithm class.
---------------------------------------------------------------------------- */
#ifndef _ga_deterministic_crowding_ga_h_
#define _ga_deterministic_crowding_ga_h_

#include <GABaseGA.h>

class GADCrowdingGA : public GAGeneticAlgorithm {
public:
  GADefineIdentity("GADeterministicCrowdingGA", 241);

  GADCrowdingGA(const GAGenome& g) : GAGeneticAlgorithm(g) {}
  virtual ~GADCrowdingGA() {}

  virtual void initialize(unsigned int seed=0);
  virtual void step();
  GADCrowdingGA& operator++() { step(); return *this; }
};

#endif

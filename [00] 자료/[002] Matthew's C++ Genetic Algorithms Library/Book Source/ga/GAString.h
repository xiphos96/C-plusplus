// $Header: /usr/people/mbwall/src/galib/ga/RCS/GAString.h,v 1.2 1998/10/05 21:30:09 mbwall Exp $
/* ----------------------------------------------------------------------------
  string.h
  mbwall 25feb95
  Copyright (c) 1995 Massachusetts Institute of Technology

 DESCRIPTION:
  This header defines the interface for the string genome.
---------------------------------------------------------------------------- */
#ifndef _ga_string_h_
#define _ga_string_h_

#include <GAAllele.h>
#include <GA1DArra.h>

typedef GAAlleleSet<char> GAStringAlleleSet;
typedef GAAlleleSet<char> GACharacterAlleleSet;
typedef GAAlleleSetArray<char> GAStringAlleleSetArray;

typedef GA1DArrayAlleleGenome<char> GAStringGenome;

inline void GAStringUniformInitializer(GAGenome& g){
  GA1DArrayAlleleGenome<char>::UniformInitializer(g);
}
inline void GAStringOrderedInitializer(GAGenome& g){
  GA1DArrayAlleleGenome<char>::OrderedInitializer(g);
}

inline int GAStringFlipMutator(GAGenome& g, float pmut){
  return GA1DArrayAlleleGenome<char>::FlipMutator(g, pmut);
}
inline int GAStringSwapMutator(GAGenome& g, float pmut){
  return GA1DArrayGenome<char>::SwapMutator(g, pmut);
}

inline int GAStringUniformCrossover(const GAGenome& a, const GAGenome& b,
				  GAGenome* c, GAGenome* d) {
  return GA1DArrayGenome<char>::UniformCrossover(a,b,c,d);
}
inline int GAStringEvenOddCrossover(const GAGenome& a, const GAGenome& b,
				  GAGenome* c, GAGenome* d) {
  return GA1DArrayGenome<char>::EvenOddCrossover(a,b,c,d);
}
inline int GAStringOnePointCrossover(const GAGenome& a, const GAGenome& b,
				  GAGenome* c, GAGenome* d) {
  return GA1DArrayGenome<char>::OnePointCrossover(a,b,c,d);
}
inline int GAStringTwoPointCrossover(const GAGenome& a, const GAGenome& b,
				  GAGenome* c, GAGenome* d) {
  return GA1DArrayGenome<char>::TwoPointCrossover(a,b,c,d);
}
inline int GAStringPartialMatchCrossover(const GAGenome& a, const GAGenome& b,
				  GAGenome* c, GAGenome* d) {
  return GA1DArrayGenome<char>::PartialMatchCrossover(a,b,c,d);
}
inline int GAStringOrderCrossover(const GAGenome& a, const GAGenome& b,
				  GAGenome* c, GAGenome* d) {
  return GA1DArrayGenome<char>::OrderCrossover(a,b,c,d);
}
inline int GAStringCycleCrossover(const GAGenome& a, const GAGenome& b,
				  GAGenome* c, GAGenome* d) {
  return GA1DArrayGenome<char>::CycleCrossover(a,b,c,d);
}

#endif

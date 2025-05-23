// $Header: /usr/people/mbwall/src/galib/ga/RCS/GAListGe.h,v 1.3 1999/03/27 19:18:59 mbwall Exp $
/* ----------------------------------------------------------------------------
  list.h
  mbwall 25feb95
  Copyright (c) 1995 Massachusetts Institute of Technology
                     all rights reserved

 DESCRIPTION:
  This header defines the interface for the list genome.
---------------------------------------------------------------------------- */
#ifndef _ga_list_h_
#define _ga_list_h_

#include <GAList.h>
#include <GAGenome.h>


/* ----------------------------------------------------------------------------
ListGenome
-------------------------------------------------------------------------------
---------------------------------------------------------------------------- */
template <class T>
class GAListGenome : public GAList<T>, public GAGenome {
public:
  GADeclareIdentity();

  static int DestructiveMutator(GAGenome &, float);
  static int SwapMutator(GAGenome &, float);
  static float NodeComparator(const GAGenome&, const GAGenome&);
  static int OnePointCrossover(const GAGenome&, const GAGenome&, 
			      GAGenome*, GAGenome*);
  static int PartialMatchCrossover(const GAGenome&, const GAGenome&, 
			      GAGenome*, GAGenome*);
  static int OrderCrossover(const GAGenome&, const GAGenome&, 
			      GAGenome*, GAGenome*);
  static int CycleCrossover(const GAGenome&, const GAGenome&, 
			      GAGenome*, GAGenome*);

public:
  GAListGenome(GAGenome::Evaluator f=0, void * u=(void *)0);
  GAListGenome(const GAListGenome<T> &);
  GAListGenome<T> & operator=(const GAGenome & orig)
    {copy(orig); return *this;}
  virtual ~GAListGenome();
  virtual GAGenome *clone(GAGenome::CloneMethod flag=CONTENTS) const;
  virtual void copy(const GAGenome &);

#ifndef NO_STREAMS
  virtual int write (ostream & os=cout) const;
#endif

  virtual int equal(const GAGenome & c) const;

// Here we do inlined versions of the access members of the super class.  We
// do our own here so that we can set/unset the _evaluated flag appropriately.

  int destroy() { _evaluated = gaFalse; return GAList<T>::destroy(); }
  int swap(unsigned int i, unsigned int j)
    { _evaluated = gaFalse; return GAList<T>::swap(i,j); }
  T * remove() { _evaluated = gaFalse; return GAList<T>::remove(); }
  int insert(GAList<T> * t, GAListBASE::Location where=GAListBASE::AFTER)
    { _evaluated = gaFalse; return GAList<T>::insert(t, where); }
  int insert(const T & t, GAListBASE::Location where=GAListBASE::AFTER)
    { _evaluated = gaFalse; return GAList<T>::insert(t, where); }
};

#ifdef USE_BORLAND_INST
#include <GAListGe.cpp>
#endif

#endif

// $Header: /usr/people/mbwall/src/galib/ga/RCS/GANode.h,v 1.3 1999/03/30 02:40:32 mbwall Exp $
/* ----------------------------------------------------------------------------
  node.h
  mbwall 25nov94
  Copyright 1995 Massachusetts Institute of Technology

 DESCRIPTION:
  This defines the node objects.
---------------------------------------------------------------------------- */
#ifndef _ga_node_h_
#define _ga_node_h_

#include <gaconfig.h>

/* ----------------------------------------------------------------------------
 GANodeBASE
-------------------------------------------------------------------------------
  This is the basic node object.  In its basic form it should be useful for
trees, lists, and some graphs.  I debated whether to make two different objects
for tree and list nodes, but decided for now to make them the same.
---------------------------------------------------------------------------- */
struct GANodeBASE {
  GANodeBASE *next, *prev, *parent, *child;
  GANodeBASE()
    {next=0; prev=0; parent=0; child=0;}
  GANodeBASE(GANodeBASE *n, GANodeBASE *p, GANodeBASE *par, GANodeBASE *chi)
    {next=n; prev=p; parent=par; child=chi;}
  virtual ~GANodeBASE() {}
};


#ifndef NO_STREAMS
inline ostream & operator<<(ostream & os, GANodeBASE & arg){
  os << "  node:   " << &arg << "\n";
  os << "  next:   " << arg.next << "\n";
  os << "  prev:   " << arg.prev << "\n";
  os << "  child:  " << arg.child << "\n";
  os << "  parent: " << arg.parent << "\n";
  return(os);
}
#endif



/* ----------------------------------------------------------------------------
 GANode
-------------------------------------------------------------------------------
  This node is a container for any kind of object you want to put into a list.
Since it is a sub-class of the BASE node object, it inherits all of the next,
prev, etc members of that class.  All we add here is support for the type-
specific contents.  
  Beware of what you put in for the type.  Remember that it
can be expensive to use an object rather than a pointer (if you have big
objects, for example).  We define this template using the object rather than 
a pointer so that it can be use for ints, chars, or other small objects.  If 
you are going to contain a large object, you should instantiate it as a pointer
to the object, not the object itself.
  Note also that we use the copy constructor to intialize the object rather 
than doing an assignment!  This assumes that the object you put into this
container has a properly functioning copy initializer and avoids the default
construction followed by assignment that you'd get with operator=.
  You must have a copy creator defined for any object that goes into the nodes.
The operator= must defined as well (it is used when the node contents get
reassigned).  We do not allow the nodes to be created without any arguments.
  Summary of methods your object must have:
       copy initializer
       operator=
  The node always owns its contents; when the node is destroyed, the contents 
of the node get destroyed as well.
---------------------------------------------------------------------------- */
template <class T>
struct GANode : public GANodeBASE {
  T contents;
//  GANode() : GANodeBASE(), contents() {}
  GANode(const T & t) : GANodeBASE(), contents(t) {}
  virtual ~GANode() {}
  T & operator()(const T & t){contents = t; return contents;}
};

#ifndef NO_STREAMS
template <class T> ostream & operator<<(ostream & os, GANode<T> & arg){
  os << "  node:   " << &arg << "\n";
  os << "  next:   " << arg.next << "\n";
  os << "  prev:   " << arg.prev << "\n";
  os << "  child:  " << arg.child << "\n";
  os << "  parent: " << arg.parent << "\n";
  return(os);
}
#endif

#endif

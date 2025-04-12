
#include "Graph.h"

void Graph::graph( char * filename, Graphable_Element_List & data )
{
  data.sort();

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Save graph to %s\n"), filename ));

  char h[10][10];
  for (int n = 0 ; n < 10 ; ++n )
    {
      for ( int j = 0 ; j < 10 ; ++j )
        {
          h[n][j] = ' ';
        }
    }

  int l[10];
  int n = 0;
  for ( Graphable_Element_List::iterator i = data.begin() ;
        i != data.end() ;
        ++i, ++n )
    {
      l[n] = (*i).when();

      int temp = (int) ((*i).temp() - 80.0);

      for ( int j = 0 ; j <= temp ; ++j )
        {
          h[n][j] = '#';
        }
    }

  for (int n = 0 ; n < 10 ; ++n )
    {
      ACE_DEBUG ((LM_INFO, ACE_TEXT ("%d  "), l[n] ));

      for ( int j = 0 ; j < 10 ; ++j )
        {
          ACE_DEBUG ((LM_INFO, ACE_TEXT ("%c"), h[n][j]));
        }
      ACE_DEBUG ((LM_INFO, ACE_TEXT ("\n")));
    }
}


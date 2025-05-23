/* ----------------------------------------------------------------------------
  ex3.cpp
  mbwall 28jul94
  Copyright (c) 1995-1996  Massachusetts Institute of Technology

 DESCRIPTION:
   Example program for the SimpleGA class and 2DBinaryStringGenome class.
This program reads in a 2D pattern from a data file then tries to match the
pattern in a 2D binary string genome.  We use a simple GA (with linear
scaled fitness selection and non-steady-state population generation) and
2D binary string genomes.
   This example also illustrates the use of the GAParameterList for setting
default parameters on the genetic algorithm and for parsing the command line.
---------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>

#include <GASimple.h>	// the header for the GA we'll use
#include <GA2DBinS.h> // and the header for the genome we need

float objective(GAGenome &);

int
main(int argc, char *argv[])
{
  cout << "Example 3\n\n";
  cout << "This program reads in a data file then runs a simple GA whose\n";
  cout << "objective function tries to match the pattern of bits that are\n";
  cout << "in the data file.\n\n";

// See if we've been given a seed to use (for testing purposes).  When you
// specify a random seed, the evolution will be exactly the same each time
// you use that seed number.

  for(int ii=1; ii<argc; ii++) {
    if(strcmp(argv[ii++],"seed") == 0) {
      GARandomSeed((unsigned int)atoi(argv[ii]));
    }
  }

//   Set the default values of the parameters and declare the params variable.
// We use the genetic algorithm's configure member to set up the parameter list
// so that it will parse for the appropriate arguments.  Notice that the
// params argument 'removes' from the argv list any arguments that it 
// recognized (actually it just re-orders them and changes the value of argc). 
//   Once the GA's parameters are registered, we set some values that we want
// that are different than the GAlib defaults.  Then we parse the command line.

  GAParameterList params;
  GASimpleGA::registerDefaultParameters(params);
  params.set(gaNscoreFilename, "bog.dat");
  params.set(gaNflushFrequency, 50);
  params.set(gaNpMutation, 0.001);
  params.set(gaNpCrossover, 0.8);
  params.parse(argc, argv, gaFalse);

  int i,j;
  char filename[128] = "smiley.txt";

// Parse the command line for arguments.

  for(i=1; i<argc; i++){
    if(strcmp("file", argv[i]) == 0 || strcmp("f", argv[i]) == 0){
      if(++i >= argc){
        cerr << argv[0] << ": the file option needs a filename.\n";
        exit(1);
      }
      else{
	sprintf(filename, argv[i]);
        continue;
      }
    }
    else if(strcmp("seed", argv[i]) == 0){
      if(++i < argc) continue;
      continue;
    }
    else {
      cerr << argv[0] << ":  unrecognized arguement: " << argv[i] << "\n\n";
      cerr << "valid arguments include standard GAlib arguments plus:\n";
      cerr << "  f\tfilename from which to read (" << filename << ")\n";
      cerr << "\n";
      exit(1);
    }
  }

// Read in the pattern from the specified file.  File format is pretty simple:
// two integers that give the height then width of the matrix, then the matrix
// of 1's and 0's (with whitespace inbetween).

  ifstream inStream(filename, ios :: in);
  if(!inStream){
    cerr << "Cannot open " << filename << " for input.\n";
    exit(1);
  }

  int height, width;
  inStream >> height >> width;

  short **target = new short*[width];
  for(i=0; i<width; i++)
    target[i] = new short[height];

  for(j=0; j<height; j++)
    for(i=0; i<width; i++)
      inStream >> target[i][j];

  inStream.close();

// Print out the pattern to be sure we got the right one.

  cout << "input pattern:\n";
  for(j=0; j<height; j++){
    for(i=0; i<width; i++)
      cout << (target[i][j] == 1 ? '*' : ' ') << " ";
    cout << "\n";
  }
  cout << "\n"; cout.flush();

// Now create the GA and run it.

  GA2DBinaryStringGenome genome(width, height, objective, (void *)target);
  GASimpleGA ga(genome);
  ga.parameters(params);
  ga.evolve();

  cout << "best of generation data are in '" << ga.scoreFilename() << "'\n";
  genome = ga.statistics().bestIndividual();
  cout << "the ga generated:\n";
  for(j=0; j<height; j++){
    for(i=0; i<width; i++)
      cout << (genome.gene(i,j) == 1 ? '*' : ' ') << " ";
    cout << "\n";
  }
  cout << "\n"; cout.flush();

  for(i=0; i<width; i++)
    delete target[i];
  delete [] target;

  return 0;
}
 



// For the objective function we compare the contents of the genome with the
// target.  If a bit is set in the genome and it is also set in the target, 
// then we add 1 to the score.  If the bits do not match, we don't do anything.
float
objective(GAGenome & c)
{
  GA2DBinaryStringGenome & genome = (GA2DBinaryStringGenome &)c;
  short **pattern = (short **)c.userData();

  float value=0.0;
  for(int i=0; i<genome.width(); i++)
    for(int j=0; j<genome.height(); j++)
      value += (float)(genome.gene(i,j) == pattern[i][j]);
  return(value);
}

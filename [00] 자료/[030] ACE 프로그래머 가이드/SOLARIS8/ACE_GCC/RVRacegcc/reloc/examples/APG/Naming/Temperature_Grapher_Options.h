
#ifndef TEMPERATURE_GRAPHER_OPTIONS_H
#define TEMPERATURE_GRAPHER_OPTIONS_H

class Temperature_Grapher_Options
  {
  public:
    Temperature_Grapher_Options( int argc, char ** argv )
    {
      ACE_UNUSED_ARG(argc);
      ACE_UNUSED_ARG(argv);
    }

    int poll_interval()
    {
      return 20; // every 20 seconds
    }
  };

#endif /* TEMPERATURE_GRAPHER_OPTIONS_H */

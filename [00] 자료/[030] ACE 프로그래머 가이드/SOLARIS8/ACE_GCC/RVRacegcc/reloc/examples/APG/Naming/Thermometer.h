/* -*- C++ -*- */

#ifndef THERMOMETER_H
#define THERMOMETER_H

class Thermometer
{
public:
  Thermometer (char *addr)
    : addr_(addr), threshold_(5)
  { }

  float temperature (void)
  {
    int success = ACE_OS::rand() % 10;
    if (success < this->threshold_)
      {
        this->threshold_ = 7;
        return -1.0;
      }

    this->threshold_ = 3;
    int itemp = 80 + ACE_OS::rand() % 10; // 80 <= t <= 90
    return (float)itemp;
  }

  char *address (void)
  {
    return this->addr_;
  }

  void reset (void)
  {
    this->threshold_ = 4;
    ACE_DEBUG ((LM_ERROR, ACE_TEXT ("Resetting thermometer %s\n"),
                this->address ()));
  }

private:
  char *addr_;
  int threshold_;
};

#endif /* THERMOMETER_H */

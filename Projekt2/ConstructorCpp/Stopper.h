#ifndef Stopper_h
#define Stopper_h
#include <iostream>
using namespace std;

class Stopper
{
private:
    /* data */
public:

    time_t time_start();
    time_t time_stop();
    time_t time_reset(time_t poczatek);
    void time_show(time_t poczatek, time_t stop);

    Stopper();
    ~Stopper();
};


#endif
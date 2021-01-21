#ifndef FabrykaPracownikow_h
#define FabrykaPracownikow_h

#include <iostream>
#include <vector>
#include "FabrykaOsob.h"
using namespace std;

class FabrykaPracownikow: public FabrykaOsob
{
private:
    /* data */
public:
    Osoba* utworz(void);
    FabrykaPracownikow(/* args */);
    ~FabrykaPracownikow();
};



#endif
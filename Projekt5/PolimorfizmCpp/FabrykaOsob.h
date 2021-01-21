#ifndef FabrykaOsob_h
#define FabrykaOsob_h

#include <iostream>
#include <vector>
#include "Osoba.h"
using namespace std;

class FabrykaOsob
{
private:
    vector <Osoba*> lista_osob;

public:
    virtual Osoba* utworz(void) = 0;
    FabrykaOsob();
    ~FabrykaOsob();
};


#endif
#ifndef FabrykaStudentow_h
#define FabrykaStudentow_h

#include <iostream>
#include <vector>
#include "FabrykaOsob.h"
#include "Osoba.h"
using namespace std;

class FabrykaStudentow: public FabrykaOsob
{
private:
    /* data */
public:
    Osoba* utworz(void);
    FabrykaStudentow(/* args */);
    ~FabrykaStudentow();
};



#endif

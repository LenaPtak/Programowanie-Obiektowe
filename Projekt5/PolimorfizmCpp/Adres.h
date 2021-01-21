#ifndef Adres_h
#define Adres_h
#include <iostream>
using namespace std;

class Adres
{
public:
    string ulica;
    int nr_domu;
    string miejscowosc;
public:
    Adres(string ulica=" ", int nr_domu=0, string miejscowosc=" ");
    ~Adres();
};

#endif
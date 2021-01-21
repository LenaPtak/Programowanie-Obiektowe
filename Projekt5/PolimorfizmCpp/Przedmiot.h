#ifndef Przedmiot_h
#define Przedmiot_h
#include <iostream>
#include <vector>
using namespace std;

class Przedmiot
{
public:
    string nazwa;
    int ocena;

public:
    Przedmiot(string nazwa = " ", int ocena = 0);
};


#endif
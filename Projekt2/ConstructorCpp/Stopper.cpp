#include <iostream>
#include <stdio.h>
#include <time.h>
#include "RadaNadzorcza.h"
#include "Logger.h"
#include "Stopper.h"


time_t Stopper::time_start() { 
    time_t start;
    time(&start);
    return start;   
}

time_t Stopper::time_stop(){
    time_t koniec;
    time(&koniec);
    return koniec;
}

time_t Stopper::time_reset(time_t poczatek) {
    time_t reset;
    poczatek = time(&reset);
    return poczatek;

}

void Stopper::time_show(time_t poczatek, time_t stop){
    int rozwiazanie;
    double roznica;

    roznica = difftime(stop, poczatek);
    cout << "\nCzas od startu do stopu to: " << roznica << " sekund";
}


Stopper::Stopper()
{
}

Stopper::~Stopper()
{
}


using namespace std;
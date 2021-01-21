#include <iostream>
#include <ctime>
#include <unistd.h>
#include "Przedmiot.h"
using namespace std;



Przedmiot::Przedmiot(string nazwa, int ocena){
    this->nazwa = nazwa;
    this->ocena = ocena;
}

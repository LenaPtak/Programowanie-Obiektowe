#include <iostream>
#include <time.h>
#include <ctime>
#include <unistd.h>
#include "Student.h"
#include "Osoba.h"
#include "Pracownik.h"
#include "Adres.h"
using namespace std;

Adres::Adres(string ulica, int nr_domu, string miejscowosc){
    this->ulica=ulica;
    this->nr_domu=nr_domu;
    this->miejscowosc=miejscowosc;
}

Adres::~Adres(){}


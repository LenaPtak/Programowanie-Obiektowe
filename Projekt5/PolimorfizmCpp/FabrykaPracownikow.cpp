#include "FabrykaOsob.h"
#include "FabrykaPracownikow.h"
#include "Pracownik.h"

Osoba* FabrykaPracownikow::utworz(void){
    return new Pracownik;
}

FabrykaPracownikow::FabrykaPracownikow(/* args */){}

FabrykaPracownikow::~FabrykaPracownikow(){}


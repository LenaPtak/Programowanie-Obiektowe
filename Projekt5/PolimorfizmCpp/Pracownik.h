#ifndef Pracownik_h
#define Pracownik_h
#include <iostream>
#include <vector>
#include "Osoba.h"
using namespace std;

class Pracownik: public Osoba
{
private:
    vector <string> przedmioty;         //lista przedmiotów prowadzonych przez danego pracownika

public:
    void dodaj_przedmiot(string nazwa);         //dodanie przedmiotu (o ile już nie istnieje)
    void usun_przedmiot(string nazwa);          //usunięcie przedmiotu (o ile istnieje)
    void sprawdz_przedmiot(string nazwa);       //sprawdzenie czy pracownik prowadzi dany przedmiot
    void przedstaw(void);               //wykonaj redefinicję metody przedstaw z klasy Osoba, tak, aby wyświetlała pełną informację na temat danego pracownika.
    void funkcja_abstrakcyjna(void){cout << "Konkretyzacja funkcji abstrakcyjnej (pkt 19)";}
    
    Pracownik(char* imie_nazwisko = nullptr, char* data_urodzenia = nullptr, char* ulica = nullptr, int nr_domu = 0, char* miejscowosc = nullptr);
    ~Pracownik();
};

#endif
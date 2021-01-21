#ifndef Student_h
#define Student_h

#include <iostream>
#include <vector>
#include "Przedmiot.h"
#include "Osoba.h"
using namespace std;


class Student: public Osoba
{
private:
    vector <Przedmiot*> lista_ocen;       //lista ocen indeksowana nazwą przedmiotu
    int daj_indeks(string nazwa);


public:
    int operator [](string nazw);                   //Indeksowanie od przedmiotu.

    void dodaj_ocene(string przedmiot, int ocena);  //dodanie oceny z danego przedmiotu (liczby z zakresu 1 do 5)
    int odczytaj_ocene(string przedmiot);           //odczytanie oceny dla wybranego przedmiotu (należy sprawdzić czy student ma ocenę z danego przedmiotu)
    vector <Przedmiot*>& odczytaj_liste_ocen(void);   //odczytanie listy ocen dla wszystkich przedmiotów
    void przedstaw(void);                           //wykonaj redefinicję metody przedstaw z klasy Osoba, tak, aby wyświetlała pełną informację na temat danego studenta.
    void funkcja_abstrakcyjna(void){cout << "Konkretyzacja funkcji abstrakcyjnej (pkt 19)" << endl;}

    Student(char* imie_nazwisko = nullptr, char* data_urodzenia = nullptr, char* ulica = nullptr, int nr_domu = 0, char* miejscowosc = nullptr);
    ~Student();
};

#endif
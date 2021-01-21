#include <iostream>
#include <time.h>
#include <ctime>
#include <unistd.h>

#include "Osoba.h"
#include "Pracownik.h"

using namespace std;



//Dodanie przedmiotu (o ile już nie istnieje).
void Pracownik::dodaj_przedmiot(string nazwa){         
    bool odp = true;
    for (int i=0; i < przedmioty.size(); i++){
        if (przedmioty[i] == nazwa){
            cout << nazwa << " - ten przedmiot jest juz na liscie!" << endl;
            odp = false;
        }
    }
    if (odp)
        przedmioty.push_back(nazwa);
    }


//Usunięcie przedmiotu (o ile istnieje).
void Pracownik::usun_przedmiot(string nazwa){          
    for (int i=0; i <= przedmioty.size(); i++)
    {
        if (przedmioty[i] == nazwa)
        {
            przedmioty.erase(przedmioty.begin()+i);
            break;
        }
        else if (i == przedmioty.size())
            cout << nazwa <<  " - takiego przedmiotu nie ma na liscie." << endl;

    }
    }


//Sprawdzenie czy pracownik prowadzi dany przedmiot.
void Pracownik::sprawdz_przedmiot(string nazwa){       
    bool odp = true;
    for (int i=0; i < przedmioty.size(); i++)
    {
        if (przedmioty[i] == nazwa)
        {
            cout << "Ten pracownik prowadzi przedmiot: " << nazwa << endl;
            odp = false;
        }
    }
    if (odp)
        cout << "Ten pracownik nie prowadzi przedmiotu: " << nazwa << endl;
    }


 //Wykonaj redefinicję metody przedstaw z klasy Osoba, tak, aby wyświetlała pełną informację na temat danego pracownika.
void Pracownik::przedstaw(void){                      
    Osoba::przedstaw();
    cout << "Lista przedmiotów prowadzonych przez pracownika:" << endl;
    for (int i=0; i < przedmioty.size(); i++){
        cout << "   - " << przedmioty[i] << endl;
    }
    }


//----KONSTRUKTOR I DESTRUKTOR-----------------------------------------------------------------------------------------------------
Pracownik::Pracownik(char* imie_nazwisko, char* data_urodzenia, char* ulica, int nr_domu, char* miejscowosc)
:Osoba(imie_nazwisko, data_urodzenia, ulica, nr_domu, miejscowosc){
 
}

Pracownik::~Pracownik(){}
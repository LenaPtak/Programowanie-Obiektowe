#include <iostream>
#include <time.h>
#include <ctime>
#include <unistd.h>
#include <vector>

#include "Student.h"
#include "Osoba.h"
#include "Pracownik.h"
#include "Adres.h"

using namespace std;



int Student::daj_indeks(string nazwa){
    int indeks = -1;
    for (int i=0; i<lista_ocen.size() && indeks==-1; i++){
        if (lista_ocen[i]->nazwa==nazwa){
            indeks=i;
        }
    }
    return indeks;
}


int Student::operator [](string nazwa){
    return odczytaj_ocene(nazwa);
}


//Odczytanie oceny dla wybranego przedmiotu (należy sprawdzić czy student ma ocenę z danego przedmiotu).
int Student::odczytaj_ocene(string przedmiot){    
    int indeks = daj_indeks(przedmiot);
    int ocena = 0;

    if (indeks>=0)
        ocena=lista_ocen[indeks]->ocena;
    return ocena;
}


//Dodanie oceny z danego przedmiotu (liczby z zakresu 1 do 5).
void Student::dodaj_ocene(string nazwa, int ocena){         
    if (ocena < 6 && ocena > 0){
        int indeks = daj_indeks(nazwa);
        if (indeks>=0)
            lista_ocen[indeks]->ocena=ocena;
        else
            lista_ocen.push_back(new Przedmiot (nazwa, ocena));
        }
    }


//Odczytanie listy ocen dla wszystkich przedmiotów.
vector <Przedmiot*>& Student::odczytaj_liste_ocen(){     
    return lista_ocen;
} 


//Wykonaj redefinicję metody przedstaw z klasy Osoba.
void Student::przedstaw(void){                          
    Osoba::przedstaw();
    cout << "Lista ocen studenta:" << endl;
    for (int i=0; i<lista_ocen.size(); i++)
    {
        cout << "Przedmiot: " << lista_ocen[i]->nazwa << endl;
        cout << "Ocena: " << lista_ocen[i]->ocena << endl;
    }
    }

//----KONSTRUKTOR I DESTRUKTOR--------------------------------------------------------------------------------

Student::Student(char* imie_nazwisko, char* data_urodzenia, char* ulica, int nr_domu, char* miejscowosc)
:Osoba(imie_nazwisko, data_urodzenia, ulica, nr_domu, miejscowosc){}   //Wywoła konstruktor osoby.

Student::~Student(){
    for (int i=0; i < lista_ocen.size(); i++)
    {
        delete lista_ocen[i];
    }
}

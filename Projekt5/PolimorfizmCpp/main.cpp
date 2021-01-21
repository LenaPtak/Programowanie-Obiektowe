#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <unistd.h>
#include <map>
#include <vector>

#include "Student.h"
#include "Osoba.h"
#include "Pracownik.h"
#include "Przedmiot.h"
#include "Adres.h"
#include "FabrykaOsob.h"
#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"

using namespace std;


void foo (Osoba &os){
    os.przedstaw();
    }

void bar (Osoba *os){
    os->przedstaw();
    }


int main() {

    //---RZUTOWANIE---------------------------------------------   
    //Sposoby rzutowania zostały sprawdzone, jednakże są wykomentowane żeby nie wpływać na kompilację kodu z racji, 
    //że część z nich jest niepoprawna albo ze względu na to, że klasa Osoba wraz z postępem miniprojektu stała się klasą abstrakcyjną,
    //a nie można utworzyć obiektów klasy abstrakcyjnej.

    // Pracownik *p1 = new Pracownik;
    // Osoba *o1 = static_cast<Osoba*>(p1);        //Niepotrzbne, ponieważ pracownik dziedziczy klasę po Osobie.
    // Osoba *o2 = static_cast<Pracownik*>(o1);    //Potrzebne, ponieważ Osoba jest klasą bazową dla pracownika.


    // Osoba *o3 = new Osoba;
    // Pracownik *p2 = static_cast<Pracownik*>(o3); 
    // //Niepoprawne, ponieważ klasa Pracownik dziedziczy po klasie Pracownik.
    // //p2 = o3;   //próby


    // Osoba o5;
    // Pracownik *p3 = new Pracownik;
    // Osoba *o4 = dynamic_cast<Osoba*>(p3);       //Działa poprawnie.

    // dynamic_cast<Pracownik*>(o4)->dodaj_przedmiot("wyjatkowy przedmiot");
    // o4 = &o5;       //próby
    // dynamic_cast<Pracownik*>(o4)->dodaj_przedmiot("wyjatkowy przedmiot2");
    //Pracownik *p4 = dynamic_cast<Osoba*>(o4); //To rzutowanie jest niepoprawne ze względu na różnicę typów. 
    //Nie można użyć wartości typu "Osoba *"" do zainicjowania jednostki typu "Pracownik *".

    // Osoba *o5 = new Osoba;
    // Pracownik *p5 = dynamic_cast<Pracownik*>(o5);
    // if (p5==nullptr) 
    //     cout << "Blad rzutowania!" << endl;
    // else 
    //     p5->przedstaw();



    //----OSOBA--------------------------------------------------
    //Osoba o2("Marek Nowak", "20-10-1999", "Warszawska", 23, "Warszawa");
    //o2.przedstaw();
    //foo(o2);
    //bar(&o2);


    //----STUDENT------------------------------------------------
    Student s1("Adam Kowalski", "18-03-2000", "Koszalińska", 12, "Poznań");
    s1.dodaj_ocene("geografia", 5);
    s1.dodaj_ocene("biologia", 3);
    int o1 = s1["geografia"];
    //cout << s1.odczytaj_ocene("biologia") << endl;


    //vector <Przedmiot*>& lista = s1.odczytaj_liste_ocen();
    //s1.przedstaw();
    //foo(s1);
    //bar(&s1);

    //----PRACOWNIK----------------------------------------------
    Pracownik p1("Halina Kalińska", "06-12-1998", "Truskawkowa", 5, "Poznań");
    p1.dodaj_przedmiot("biologia");
    p1.dodaj_przedmiot("biologia");
    p1.usun_przedmiot("biologia");
    //p1.usun_przedmiot("nieistniejacy przedmiot");
    p1.dodaj_przedmiot("matma");
    p1.dodaj_przedmiot("informatyka");

    // p1.sprawdz_przedmiot("informatyka");
    // p1.sprawdz_przedmiot("fizyka");
    p1.przedstaw();


    //foo(p1);
    //bar(&p1);
    //W funkcjach foo i bar występują odmienne sposoby metody odwołań do właściwości klasy, jednak efekt jest ten sam.

    Osoba* o = &p1;
    o->funkcja_abstrakcyjna();

    //Wywołanie oraz sprawdzenie poprawności konstruktora kopiującego (przy tymczasowej zmianie private na public zmiennych klasy Osoba).
    //cout << *(p1.imie_nazwisko) << endl;
    Pracownik kopiaObiektu(p1);
    *(kopiaObiektu.imie_nazwisko) = "Kopia nazwiska";
    //cout << *(p1.imie_nazwisko) << endl;
    //cout << *(kopiaObiektu.imie_nazwisko) << endl;

    //---FABRYKA------------------------------------------------------------------
    //Testy, czy działa:
    FabrykaStudentow fs1;
    Student* student = dynamic_cast<Student*>(fs1.utworz());
    delete student;

    FabrykaPracownikow fp1;
    Pracownik* pracownik = dynamic_cast<Pracownik*>(fp1.utworz());
    delete pracownik;


    //Pętla dla fabryk:
    map<string, FabrykaOsob*> m;

    //Używamy operatora indeksowania [], który jako indeks przyjmuje klucz i zwraca referencję na przechowywaną wartość.     
    m["pracownik"] = new FabrykaPracownikow();
    m["student"] = new FabrykaStudentow();
    vector<Osoba*> tablicaOsob;
    
    cout << endl << "Proszę wpisać:" << endl;
    cout << "   -pracownik              jeżeli chcesz utworzyć obiekt o typie Pracownik," << endl;
    cout << "   -student                jeżeli chcesz utworzyć obiekt o typie Student," << endl;
    cout << "   -wyswietl               jeżeli chcesz wyświetlić listę osób," << endl;
    cout << "   -wyjscie                jeżeli chcesz wyjść." << endl << endl;

    string klucz;
    while (cin >> klucz){
        if (klucz == "pracownik")
        {
            tablicaOsob.push_back(m[klucz]->utworz());
            cout << endl << "Utworzono obiekt typu Pracownik." << endl;
        }
        else if (klucz == "student")
        {
            tablicaOsob.push_back(m[klucz]->utworz());
            cout << endl << "Utworzono obiekt typu Student." << endl;
        }
        else if (klucz == "wyswietl")
        {
            for(int i=0; i <tablicaOsob.size(); i++)
            {
                cout << endl;
                tablicaOsob[i]->przedstaw();
                cout << endl;
            }
        }
        else if (klucz == "wyjscie")
        {
            break;
        }
        else
        {
            cout << endl << "Proszę wpisać:" << endl;
            cout << "   -pracownik              jeżeli chcesz utworzyć obiekt o typie Pracownik," << endl;
            cout << "   -student                jeżeli chcesz utworzyć obiekt o typie Student," << endl;
            cout << "   -wyswietl               jeżeli chcesz wyświetlić listę osób," << endl;
            cout << "   -wyjscie                jeżeli chcesz wyjść." << endl;
        }
    }

    return 0;
}
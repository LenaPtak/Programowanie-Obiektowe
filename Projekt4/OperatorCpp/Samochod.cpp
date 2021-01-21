#include <iostream>
#include <memory>
#include <stdio.h>
#include <time.h>
#include "Samochod.h"
using namespace std;



//Funkcja, w której odczytujemy pojemność baku.
float Samochod::odczytaj_pojemnosc_baku(void){
    return pojemnosc_baku;
}

//Funkcja, w której możemy zmieniac stan paliwa.
void Samochod::dodaj_paliwo(float wartosc){                    
    if ((poziom_paliwa + wartosc) >= 0) poziom_paliwa += wartosc;
}


//Funkcja, w której możemy zwiększyć licznik kilometrów.
void Samochod::dodaj_km(int wartosc){                        
    if ((liczba_kilometrow + wartosc) >= 0) liczba_kilometrow += wartosc;
}

//Funckja wyświetla dane o wywolanym obiekcie.
void Samochod::wyswietl_dane(){                   
    cout << "Model samochodu to " << model << endl;
    cout << "Poziom paliwa wynosi " << poziom_paliwa << endl;
    cout << "Pojemnosc baku wynosi " << pojemnosc_baku << endl;
    cout << "Liczba kilometrow wynosi " << liczba_kilometrow << endl;
}

//----KONSTRUKTORY I DESTRUKTOR----------------------------------------------------------------------------------------------------------

//Konstruktor z argumentami
Samochod::Samochod(float pojemnosc, string mod){  
    this->pojemnosc_baku = pojemnosc;
    this->model = mod;
    this->poziom_paliwa = 0.0;
    this->liczba_kilometrow = 0;

}

//Konstruktor domyślny
Samochod::Samochod()
{
    this->pojemnosc_baku = 0.0;
    this->poziom_paliwa = 0.0;
    this->liczba_kilometrow = 0;
    this->model = "Mercedes";
}

//Destruktor
Samochod::~Samochod(){}

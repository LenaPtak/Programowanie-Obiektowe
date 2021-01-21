#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <set>
#include "Samochod.h"
using namespace std;



int main() {

    struct cmp {
        bool operator () (const Samochod &a, const Samochod  &b) const{
            return a.pojemnosc_baku < b.pojemnosc_baku;}
    };

//=========================================================================================================

    //Tworzenie przykładowych obiektów.
    Samochod s1(123, "b");
    Samochod s2(2000, "a");
    Samochod s3(200, "zzzz");


//=========================================================================================================

    //Testy, czy przeciążenia operatorów działają.
    // if (s2) {
    //     printf("\n1\n");
    // }
    // if (!s1) {
    //     printf("\n2\n");
    // }

    // cout << s1 << endl;

    // if ((s2<s1)){
    //     printf("Warunek spełniony.\n");
    // }


//=========================================================================================================

    vector <Samochod> v;        //Tworzymy wektor v z elementami typu Samochod.
    v.push_back(s1);            //Dodajemy elementy do wektora v.
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());   //Sortujemy, opeartor "<" jest przeciążony i robi cout.
    printf("\n");
    for(auto it=v.begin(); it != v.end(); ++it){
        cout << "Pierwszy for:  " << *it << endl;
    }


//=========================================================================================================

    //std::set<> realizuje zbiór w matematycznym sensie tego słowa. 
    //Przechowuje różne wartości i pozwala efektywnie sprawdzać, czy wartość znajduje się w zbiorze.
    //Nie ma tu aspektu rezerwacji pamięci, ani dodawania elementów w określone miejsce
    //W set klucze zawsze są posortowane.
    set <Samochod, cmp> s;
    s.insert(s1);           //Dodajemy do kontenera asocjacyjnego s obiekty klasy Samochod za pomocą funkcji insert()
    s.insert(s2);
    s.insert(s3);

    //auto - Słowo kluczowe kieruje kompilator do użycia wyrażenia inicjującego zmiennej zadeklarowanej lub parametru wyrażenia lambda, aby ustalić jego typ.
    for(auto it=s.begin(); it != s.end(); ++it) 
    {
        cout <<  "Drugi for:    " << *it << endl;
    }


    return 0;
}
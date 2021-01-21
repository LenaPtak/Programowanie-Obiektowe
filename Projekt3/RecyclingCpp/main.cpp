#include <memory>
#include <iostream>
#include <ctime>
#include "Wezel.h"
using namespace std;

int main(){
    printf("\nBEDZIE DOBRZE\n");

    //Wskaźnik unikalny na obiekt typu Wezel, który zarządza pamięcią i od razu po sobie sprząta.
    // for (int i=0; i<10; i++) {
    //     std::unique_ptr<Wezel>(new Wezel());} 

    //Wskaźnik współdzielony na obiekt typu Wezel. 
    //Różnica względem wskaźnika std::unique_ptr<> polega na tym, że można go kopiować. 
    //Kopie wskaźników std::shared_ptr<> utrzymują między sobą licznik referencji, 
    //zwiększany w momencie utworzenia kopii, zmniejszany w momencie zniszczenia kopii. 
    //Pamięć zostaje zwolniona według reguły "kto ostatni, ten sprząta".
    // for (int i=0; i<10; i++){
    //     std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();} 

    for (int i=0; i<10; i++) {
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::weak_ptr<Wezel> w2 = std::make_shared<Wezel>();
        w1->next = w2;
        w2->next = w1;
    }



    return 0;
}
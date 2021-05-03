//
//  main.cpp
//  2021_Veicoli
//
//  Created by Alessandro Privitera on 28/04/21.
//

//Si implementi un programma che rappresenti una gerarchia di veicoli.
//Ogni veicolo ha un numero di ruote, un tipo dicarburante, una motorizzazione, una velocità massima, una marca ed un prezzo.
//Tra i veicoli distinguiamo motocicli, automobili, camion, mezzi speciali.
//Si simuli una gara tra 10 veicoli di tipo diverso, riportando posizioni iniziali, sorpassi e classifica finale.

#include <iostream>
#include "moto.h"
#include "auto.h"
#include "gara.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Moto m(100, 2000, "ducati", "1000cc");
    Automobile a(160, 5000, "fiat", "diesel" ,"1200cc");
    Moto m2(120, 3000, "honda", "1300cc");
    Automobile a2(200, 20000, "lamborghini", "diesel", "3000cc");
    
    Gara gara(10,10);
    gara.aggiungiPartecipante(m);
    gara.aggiungiPartecipante(a);
    gara.aggiungiPartecipante(m2);
    gara.aggiungiPartecipante(a2);
    
    gara.partenza();
    
    return 0;
}

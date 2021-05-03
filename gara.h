
#ifndef GARA_H
#define GARA_H
#include "veicolo.h"
#include <cstdlib>
#include <time.h>

class Gara{
    int durata;
    int numero_partecipanti;
    int numero_iscritti;
    void controlla(int t);
    Veicolo **veicoli;
    
public:
    Gara(int durata, int partecipanti) : durata(durata), numero_partecipanti(partecipanti){
        veicoli = new Veicolo*[numero_partecipanti];
        numero_iscritti = 0;
    }
    
    ~Gara(){
        delete [] veicoli;
    }
    
    void partenza();
    void stampaClassifica();
    void aggiungiPartecipante(Veicolo &v);
};

#endif

void Gara::aggiungiPartecipante(Veicolo &v){
    veicoli[numero_iscritti++] = &v;
}

void Gara::controlla(int t){
    
    int  max_temp = veicoli[0]->getVelocita();
    int pos_max = 0;
    
    for (int i = 1; i < numero_iscritti; i++) {
        if (veicoli[i]->getVelocita() > max_temp) {
            max_temp = veicoli[i]->getVelocita();
            pos_max = i;
        }
    }
    
    cout << "Il veicolo più veloce è " << *veicoli[pos_max] << " e ha velocità " << veicoli[pos_max]->getVelocita() << endl;
    
}

void Gara::partenza(){
    srand(time(NULL));
    for (int i = 0; i < durata; i++) {
        for (int j = 0; j < numero_iscritti; j++) {
            int scelta = rand() % 2;
            if(scelta == 1) veicoli[j]->accelera();
            else veicoli[j]->decelera();
            
        }
        this->controlla(i);
    }
    this->stampaClassifica();
}

void Gara::stampaClassifica(){
    
}

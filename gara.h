
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

void swap(Veicolo **v, int i, int j){
    Veicolo *t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void Gara::controlla(int t){
    
    for (int x = 0; x < numero_iscritti; x++) {
        int  max_temp = veicoli[x]->getVelocita();
        int pos_max = x;
        for (int i = x+1; i < numero_iscritti; i++) {
            if (veicoli[i]->getVelocita() > max_temp) {
                max_temp = veicoli[i]->getVelocita();
                swap(veicoli, i, pos_max);
            }
        }
    }
    cout << "\n>> Classifica istante " << t;
    this->stampaClassifica();
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
    
    cout << "\n\n---------------CLASSIFICA---------------\n\n";
    
    for (int i = 0; i < numero_iscritti; i++) {
        cout << i+1 << ") " << *veicoli[i] << "\n\n";
    }
    
}

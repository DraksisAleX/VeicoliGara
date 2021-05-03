#ifndef VEICOLO_H
#define VEICOLO_H
#include <iostream>

using namespace std;

class Veicolo {
protected:
    int numero_ruote;
    int velocita_max;
    int velocita;
    double prezzo;
    string marca;
    string carburante;
    string motorizzazione;
public:
    Veicolo (){}
    
    Veicolo(int _numero_ruote, int _vmax, double _prezzo, string _marca, string _carburante, string _motorizzazione) : numero_ruote(_numero_ruote), velocita_max(_vmax), marca(_marca), velocita(0), prezzo(_prezzo), carburante(_carburante), motorizzazione (_motorizzazione){}
    
    int getNumeroRuote(){
        return numero_ruote;
    }
    
    int getVelocitaMax(){
        return velocita_max;
    }
    
    int getVelocita(){
        return velocita;
    }
    
    double getPrezzo(){
        return prezzo;
    }
    
    string getMarca(){
        return marca;
    }
    
    string getMotor(){
        return motorizzazione;
    }
    
    string getCarburante(){
        return carburante;
    }
    
    void setNumeroRuote(int n){
        numero_ruote=n;
    }
    
    void setVelocitaMax(int n){
        velocita_max=n;
    }
    
    void setVelocita(int n){
        velocita=n;
    }
    
    void setPrezzo(double n){
        prezzo=n;
    }
    
    void setMarca(string s){
        marca=s;
    }
    
    void setCarburante(string s){
        carburante=s;
    }
    
    void setMotorizzazione(string s){
        motorizzazione=s;
    }
    
    void accelera(){
        if (velocita < velocita_max) {
            velocita++;
        }
    }
    
    void decelera(){
        if (velocita > 0) {
            velocita--;
        }
    }
    
    virtual string toString() const = 0;
    
    friend ostream& operator<<(ostream& out, const Veicolo& v){
        out << v.toString();
        return out;
    }
    
    void operator=(const Veicolo &v){
        this->numero_ruote = v.numero_ruote;
        this->velocita_max = v.velocita_max;
        this->motorizzazione = v.motorizzazione;
        this->carburante = v.carburante;
        this->prezzo = v.prezzo;
        this->marca = v.marca;
    }
};

#endif


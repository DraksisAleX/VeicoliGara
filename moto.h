
#include "veicolo.h"
#include <sstream>

using namespace std;

class Moto : public Veicolo {
    
public:
    Moto(int _vmax, double _prezzo, string _marca, string _motorizzazione) : Veicolo(2, _vmax, _prezzo, _marca, "benzina", _motorizzazione){}
    
    string toString() const{
        stringstream stream;
        stream << "Sono una moto di marca " << marca << ", motorizzazione " << motorizzazione << " " << carburante << "\n La mia velocita è " << velocita << "km/h";
        return stream.str();
    }
    
};

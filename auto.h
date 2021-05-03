
#include "veicolo.h"
#include <sstream>

using namespace std;

class Automobile : public Veicolo {
    
public:
    
    Automobile(int _vmax, double _prezzo, string _marca, string _carburante, string _motorizzazione) : Veicolo(4, _vmax, _prezzo, _marca, _carburante, _motorizzazione){}
    
    string toString() const{
        stringstream stream;
        stream << "Sono un auto di marca " << marca << ", motorizzazione " << motorizzazione << " " << carburante << "\n La mia velocita è " << velocita << "km/h";
        return stream.str();
    }
    
};



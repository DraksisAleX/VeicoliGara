#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <sstream>
using namespace std;

class Studente{
    string cognome, nome, matricola;
    int eta;

    int compareTo(const Studente& s){
        int GREATER = 1, LESS = -1, EQUAL = 0;
        if(this->cognome > s.get_cognome()) return GREATER;
        else if (this->cognome < s.get_cognome()) return LESS;
        else{
            if(this->nome > s.get_nome()) return GREATER;
            else if (this->nome < s.get_nome()) return LESS;
            else{
                if(this->matricola > s.get_matricola()) return GREATER;
                else if(this->matricola < s.get_matricola()) return LESS;
                else{
                    if(this->eta > s.get_eta()) return GREATER;
                    else if(this->eta < s.get_eta()) return LESS;
                    else return EQUAL;
                }
            }
        }
    }

    public:

    Studente(string cognome, string nome, string matricola, int eta) : 
        cognome(cognome), nome(nome), matricola(matricola), eta(eta) {}

    string get_cognome() const {return cognome;}
    string get_nome() const {return nome;}
    string get_matricola() const {return matricola;}
    int get_eta() const {return eta;}
    void set_cognome(string cognome){this->cognome = cognome;}
    void set_nome(string nome){this->nome = nome;}
    void set_matricola(string matricola){this->matricola = matricola;}
    void set_eta(int eta){this->eta = eta;}

    bool operator<(const Studente& s){
        return this->compareTo(s) == -1;
    }
    bool operator>(const Studente& s){
        return this->compareTo(s) == 1;
    }
    bool operator==(const Studente& s){
        return this->compareTo(s) == 0;
    }
    bool operator>=(const Studente& s){
        return this->compareTo(s) >= 0;
    }
    bool operator<=(const Studente& s){
        return this->compareTo(s) <= 0;
    }

    string toString() const {
        stringstream stream;
        stream << "Cognome: " << cognome << "| Nome: " << nome << "| Matricola: " << matricola << "| Eta: " << eta;
        return stream.str();
    }

    friend ostream& operator<<(ostream& out, const Studente& s){
        out << s.toString();
        return out;
    }
};

#endif
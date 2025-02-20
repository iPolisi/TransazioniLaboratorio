//
// Created by Cristian Polisi on 20/02/2025.
//

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Persona {
private:
    string nome;
    string cognome;
    string cF;

public:
    Persona(const string& nome, const string& cognome, const string& cF);

    // Getter
    string getNome() const;
    string getCognome() const;
    string getCodiceFiscale() const;
    static vector<Persona> caricaDaCSV(const string& filename);

    // Stampa informazioni
    void stampaDati() const;
};

#endif //PERSONA_H

//
// Created by Cristian Polisi on 20/02/2025.
//

#include "Persona.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Costruttore
Persona::Persona(const string& nome, const string& cognome, const string& cF)
    : nome(nome), cognome(cognome), cF(cF) {}

// Getter
string Persona::getNome() const {
    return nome;
}

string Persona::getCognome() const {
    return cognome;
}

string Persona::getCodiceFiscale() const {
    return cF;
}

// Stampa informazioni della persona
void Persona::stampaDati() const {
    cout << "Nome: " << nome << ", Cognome: " << cognome << ", Codice Fiscale: " << cF << endl;
}

// Metodo per caricare persone da un file CSV
vector<Persona> Persona::caricaDaCSV(const string& filename) {
    vector<Persona> persone;
    ifstream file(filename);

    if (!file) {
        cerr << "Errore nell'apertura del file " << filename << endl;
        return persone; // Restituisce un vettore vuoto
    }

    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string nome, cognome, codiceFiscale;

        // Legge i dati separati da virgola
        if (getline(ss, nome, ',') && getline(ss, cognome, ',') && getline(ss, codiceFiscale, ',')) {
            persone.emplace_back(nome, cognome, codiceFiscale);
        }
    }

    file.close();
    return persone;
}

//
// Created by Cristian Polisi on 20/02/2025.
//
#include "Stipendio.h"
#include <iostream>
#include <fstream>

using namespace std;

Stipendio::Stipendio(double importo, const string& descrizione, double trattenute)
    : Transazione(importo, descrizione, true), trattenute(trattenute) {}

bool Stipendio::eEntrata() const {
    return true;
}

void Stipendio::stampaTransazione() const {
    cout << "Stipendio: " << descrizione << ", Importo: " << importo << ", Trattenute: " << trattenute << endl;
}

void Stipendio::salvaSuFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Stipendio," << importo << "," << descrizione << "," << trattenute << endl;
        file.close();
    } else{}
        cerr << "Impossibile aprire il file " << filename << endl;
}

double Stipendio::calcolaImportoNetto() const {
    return importo - trattenute;
}

//
// Created by Cristian Polisi on 20/02/2025.
//
#include "Abbonamento.h"
#include <iostream>
#include <fstream>

using namespace std;

Abbonamento::Abbonamento(double importo, const string& descrizione, const string& servizio, double commissione)
    : Transazione(importo, descrizione, false), servizio(servizio), commissione(commissione) {}

bool Abbonamento::eEntrata() const {
    return false;
}

void Abbonamento::stampaTransazione() const {
    cout << "Abbonamento: " << descrizione << ", Importo: " << importo << ", Servizio: " << servizio << endl;
}

void Abbonamento::salvaSuFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Abbonamento," << importo << "," << descrizione << "," << servizio << "," << commissione << endl;
        file.close();
    }else {
        cerr << "Errore: impossibile aprire il file " << filename << endl;
    }
}

double Abbonamento::calcolaImportoNetto() const {
    return importo + commissione;
}

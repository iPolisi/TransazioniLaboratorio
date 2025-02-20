//
// Created by Cristian Polisi on 20/02/2025.
//
#include "Abbonamento.h"
#include <iostream>
#include <fstream>

Abbonamento::Abbonamento(double importo, const string& descrizione, const string& servizio, double commissione)
    : Transazione(importo, descrizione), servizio(servizio), commissione(commissione) {}

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
    }
}

double Abbonamento::calcolaImportoNetto() const {
    return importo + commissione;
}

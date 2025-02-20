//
// Created by Cristian Polisi on 20/02/2025.
//
#include "BonificoEntrata.h"
#include <iostream>
#include <fstream>

BonificoEntrata::BonificoEntrata(double importo, const string& descrizione, const string& mittente)
    : Transazione(importo, descrizione), mittente(mittente) {}

bool BonificoEntrata::eEntrata() const {
    return true;
}

void BonificoEntrata::stampaTransazione() const {
    cout << "Bonifico in entrata: " << descrizione << ", Importo: " << importo << ", Mittente: " << mittente << endl;
}

void BonificoEntrata::salvaSuFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Entrata," << importo << "," << descrizione << "," << mittente << endl;
        file.close();
    }
}

double BonificoEntrata::calcolaImportoNetto() const {
    return importo;
}


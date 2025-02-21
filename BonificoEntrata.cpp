//
// Created by Cristian Polisi on 20/02/2025.
//
#include "BonificoEntrata.h"
#include <iostream>
#include <fstream>

using namespace std;

BonificoEntrata::BonificoEntrata(double importo, const string& descrizione, const string& mittente)
    : Transazione(importo, descrizione, true), mittente(mittente) {}

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
    }else {
        cerr << "Errore: impossibile aprire il file " << filename << endl;

    }
}

double BonificoEntrata::calcolaImportoNetto() const {
    return importo;
}


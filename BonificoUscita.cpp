//
// Created by Cristian Polisi on 20/02/2025.
//
#include "BonificoUscita.h"
#include <iostream>
#include <fstream>

#define float commissione=2,5

BonificoUscita::BonificoUscita(double importo, const string& descrizione, const string& destinatario)
    : Transazione(importo, descrizione, false), destinatario(destinatario) {}

bool BonificoUscita::eEntrata() const {
    return false;
}

double BonificoUscita::getImporto() const{
    return importo;
}

void BonificoUscita::stampaTransazione() const {
    cout << "Bonifico in uscita: " << descrizione << ", Importo: " << importo << ", Destinatario: " << destinatario << endl;
}

void BonificoUscita::salvaSuFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Uscita," << importo << "," << descrizione << "," << destinatario << endl;
        file.close();
    }else {
        cerr << "Errore: impossibile aprire il file " << filename << endl;

    }
}

double BonificoUscita::calcolaImportoNetto() const {
    return importo + commissione;
}

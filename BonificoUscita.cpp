//
// Created by Cristian Polisi on 20/02/2025.
//
#include "BonificoUscita.h"
#include <iostream>
#include <fstream>

BonificoUscita::BonificoUscita(double importo, const string& descrizione, const string& destinatario, double commissione)
    : Transazione(importo, descrizione), destinatario(destinatario), commissione(commissione) {}

bool BonificoUscita::eEntrata() const {
    return false;
}

void BonificoUscita::stampaTransazione() const {
    cout << "Bonifico in uscita: " << descrizione << ", Importo: " << importo << ", Destinatario: " << destinatario << ", Commissione: " << commissione << endl;
}

void BonificoUscita::salvaSuFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Uscita," << importo << "," << descrizione << "," << destinatario << "," << commissione << endl;
        file.close();
    }
}

double BonificoUscita::calcolaImportoNetto() const {
    return importo + commissione;
}

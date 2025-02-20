//
// Created by Cristian Polisi on 20/02/2025.
//
#include "Conto.h"

#include <fstream>

#include "Transazione.h"
#include "BonificoEntrata.h"
#include "BonificoUscita.h"
#include "Stipendio.h"
#include "Abbonamento.h"

Conto::Conto(const string& IBAN, double saldoIniziale, Persona* intestatario)
    : IBAN(IBAN), saldo(saldoIniziale), intestatario(intestatario) {}

void Conto::aggiungiTransazione(Transazione* t) {
    transazioni.push_back(t);
    // Aggiorniamo il saldo in base al tipo di transazione
    if (t->eEntrata()) {
        saldo += t->getImporto();
    } else {
        saldo -= t->getImporto();
    }
}

double Conto::getSaldo() const {
    return saldo;
}

void Conto::stampaConto() const {
    cout << "IBAN: " << IBAN << endl;
    cout << "Saldo: " << saldo << endl;
    for (const auto& transazione : transazioni) {
        transazione->stampaTransazione();
    }
}

void Conto::salvaSuFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        for (const auto& transazione : transazioni) {
            transazione->salvaSuFile(filename);
        }
        file.close();
    } else {
        cerr << "Errore nell'aprire il file per il salvataggio." << endl;
    }
}

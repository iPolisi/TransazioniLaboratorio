//
// Created by Cristian Polisi on 20/02/2025.
//

#ifndef CONTO_H
#define CONTO_H

#include "Persona.h"
#include "Transazione.h"
#include <vector>

class Conto {
private:
    string IBAN;
    double saldo;
    Persona* intestatario;
    vector<Transazione*> transazioni; // Puntatori per il polimorfismo

public:
    // Costruttore
    Conto(const string &IBAN, double saldoIniziale, Persona *intestatario);

    // Getter
    string getIBAN() const;
    double getSaldo() const;

    void stampaConto() const;

    Persona getIntestatario() const;

    // Metodi per la gestione delle transazioni
    void aggiungiTransazione(Transazione* transazione);
    void stampaEstrattoConto() const;
    void salvaSuFile(const string& filename) const;

    // Distruttore
    ~Conto();
};

#endif // CONTO_H


//
// Created by Cristian on 25/02/2025.
//

#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include "Transazione.h"
#include <vector>
#include <string>

class ContoCorrente {
private:
    string iban;
    string intestatario;
    double saldo;
    vector<Transazione*> transazioni;
    string filePath;

public:
    ContoCorrente(string ib, string intest, string file);
    ~ContoCorrente();

    //agiunta di modifica, cercare, ed eliminare per ogni campo di una transazione con modifica del saldo
    void aggiungiTransazione(Transazione* t);
    void salvaSuFile(ostream &file, const string &iban) const;
    void caricaDaFile();
    void stampaTransazioni() const;
    string getIban() const;
    double getSaldo() const;

};

#endif // CONTOCORRENTE_H


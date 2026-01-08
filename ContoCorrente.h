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

    void rimuoviTransazione(int indice) ; //verrò rimossa una transazione tramite un indice (primo =0)
    void modificaTransazione(int indice, double nuovoImp, string nuovaDesc, Data nuovaData);
    vector<int> cercaDescrizione(string keyWord) const; //ricerca tramite descrizione (rende tutti gli indici matchati
    vector<int> cercaData(Data dataFind) const;

};

#endif // CONTOCORRENTE_H


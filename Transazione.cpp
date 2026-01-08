//
// Created by Cristian on 25/02/2025.
//
#include "Transazione.h"
//gestione del saldo

Transazione::Transazione(double imp, string desc, Data d) : importo(imp), descrizione(desc), data(d) {}

void Transazione::salvaSuFile(ostream &file, const string &iban) const {
    file << iban << "," << tipo() << "," << importo << "," << descrizione << ","  << data <<"\n";
}
//non puramente virtuale dato che non necessito (almeno per il momento se non apporto modifiche) di un'implementazione nelle derivate
//gestione dell'importo in transazione, ocn gestione eccezione
double Transazione::getImporto() const {
    return importo;
}

string Transazione::tipo() const {
    return "Generica"; // Può essere una stringa di default, oppure un comportamento generale
}

string Transazione::getDescrizione() const {
    return descrizione;
}

Data Transazione::getData() const {return data;}

void Transazione::setImporto(double imp) {
    importo = imp;
}

void Transazione::setDescrizione(string desc) {
    descrizione = desc;
}

void Transazione::setData(Data d) {
    data = d;
}
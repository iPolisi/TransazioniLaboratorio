//
// Created by Cristian on 25/02/2025.
//

#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>
#include <fstream>
#include "Data.h"

using namespace std;

class Transazione {
protected:
    double importo;
    string descrizione;
    Data data;
    //protected dato che sono attributi che verranno ereditati da Uscita ed Entrata

public:
    Transazione(double imp, string desc, Data d);
    virtual ~Transazione() = default;
    virtual string tipo() const;

    void salvaSuFile(ostream &file, const string &iban) const;

    virtual double getValore() const=0; //verrà gestito l'importo dalle derivate
    double getImporto() const;
    string getDescrizione() const;
    Data getData() const;

    void setImporto(double imp);
    void setDescrizione(string desc);
    void setData(const Data d);

};

#endif // TRANSAZIONE_H


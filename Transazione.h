//
// Created by Cristian Polisi on 20/02/2025.
//

#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>

using namespace std;

class Transazione {
protected:
    double importo;
    string descrizione;
    bool isEntrata;

public:
    // Costruttore
    Transazione(double importo, const string& descrizione, bool isEntrata);

    // Getter puramente virtuali (classe astratta)
    virtual double getImporto() const = 0;
    virtual string getDescrizione() const = 0;
    virtual bool eEntrata() const = 0;

    // Metodo per stampare la transazione
    virtual void stampaTransazione() const = 0;

    // Metodo per salvare la transazione su file
    virtual void salvaSuFile(const string& filename) const = 0;

    // Distruttore virtuale
    virtual ~Transazione() = default;
};

#endif // TRANSAZIONE_H

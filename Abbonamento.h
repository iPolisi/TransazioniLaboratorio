//
// Created by Cristian Polisi on 20/02/2025.
//

#ifndef ABBONAMENTO_H
#define ABBONAMENTO_H

#include "Transazione.h"
#include <string>

class Abbonamento : public Transazione {
private:
    string servizio;
    double commissione;

public:
    Abbonamento(double importo, const string& descrizione, const string& servizio, double commissione);

    bool eEntrata() const override;
    void stampaTransazione() const override;
    void salvaSuFile(const string& filename) const override;
    double calcolaImportoNetto() const;
};

#endif

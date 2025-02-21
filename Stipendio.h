//
// Created by Cristian Polisi on 20/02/2025.
//

#ifndef STIPENDIO_H
#define STIPENDIO_H

#include "Transazione.h"

class Stipendio : public Transazione {
private:
    double trattenute;

public:

    Stipendio(double importo, const string &descrizione, double trattenute);

    bool eEntrata() const override;
    void stampaTransazione() const override;
    void salvaSuFile(const string& filename) const override;
    double calcolaImportoNetto() const;
};

#endif

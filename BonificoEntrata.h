//
// Created by Cristian Polisi on 20/02/2025.
//

#ifndef BONIFICOENTRATA_H
#define BONIFICOENTRATA_H

#include "Transazione.h"

class BonificoEntrata : public Transazione {
private:
    string mittente;

public:
    BonificoEntrata(double importo, const string& descrizione, const string& mittente);

    bool eEntrata() const override;
    void stampaTransazione() const override;
    void salvaSuFile(const string& filename) const override;
    double calcolaImportoNetto() const;
};

#endif


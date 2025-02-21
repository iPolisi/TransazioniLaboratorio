//
// Created by Cristian Polisi on 20/02/2025.
//

#ifndef BONIFICOUscita_H
#define BONIFICOUscita_H

#include "Transazione.h"
#include <string>

using namespace std;

class BonificoUscita : public Transazione {
private:
    string destinatario;
    double commissione;

public:
    BonificoUscita(double importo, const string& descrizione, const string& destinatario);

    double getImporto() const override;
    string getDescrizione() const override;
    bool eEntrata() const override;
    void stampaTransazione() const override;
    void salvaSuFile(const string& filename) const override;
    double calcolaImportoNetto() const;
};

#endif


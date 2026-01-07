//
// Created by Cristian on 25/02/2025.
//

#ifndef USCITA_H
#define USCITA_H

#include "Transazione.h"

class Uscita : public Transazione {
public:
    Uscita(double imp, string desc, Data d);
    string tipo() const override;
    double getValore() const override;
};

#endif // USCITA_H


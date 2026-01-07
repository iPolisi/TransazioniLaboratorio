//
// Created by Cristian on 25/02/2025.
//

#ifndef ENTRATA_H
#define ENTRATA_H

#include "Transazione.h"

class Entrata : public Transazione {
public:
    Entrata(double imp, string desc,Data d);
    string tipo() const override;
    double getValore() const override;
};

#endif // ENTRATA_H


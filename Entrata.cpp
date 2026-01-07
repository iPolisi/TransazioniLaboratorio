//
// Created by Cristian on 25/02/2025.
//
#include "Entrata.h"

Entrata::Entrata(double imp, string desc, Data d) : Transazione(imp, desc, d) {}

string Entrata::tipo() const {
    return "Entrata";
}

double Entrata::getValore() const {
    return importo;
}
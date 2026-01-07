//
// Created by Cristian on 25/02/2025.
//
#include "Uscita.h"

Uscita::Uscita(double imp, string desc, Data d) : Transazione(imp, desc, d) {}

string Uscita::tipo() const {
    return "Uscita";
}

double Uscita::getValore() const{
    return -importo;
}

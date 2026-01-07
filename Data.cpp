//
// Created by Cristian Polisi on 07/01/2026.
//
#include "Data.h"
#include <iomanip>
#include <stdexcept>

using namespace std;

// Implementazione metodi privati
bool Data::isBisestile(int a) const {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

bool Data::isValida(int g, int m, int a) const {
    if (m < 1 || m > 12) return false;
    if (a < 1900 || a > 2100) return false;

    int giorniNelMese[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isBisestile(a)) {
        giorniNelMese[2] = 29;
    }

    return g > 0 && g <= giorniNelMese[m];
}

// Implementazione Costruttore
Data::Data(int g, int m, int a) {
    if (!isValida(g, m, a)) {
        throw invalid_argument("Data non valida: " + to_string(g) + "/" + to_string(m) + "/" + to_string(a));
    }
    giorno = g;
    mese = m;
    anno = a;
}

Data::Data() : giorno(1), mese(1), anno(2000) {}

int Data::getGiorno() const { return giorno; }
int Data::getMese() const { return mese; }
int Data::getAnno() const { return anno; }

// Implementazione operator<<
 ostream& operator<<(ostream& os, const Data& d) {
    os << setfill('0') << setw(2) << d.giorno << "/"
       << setfill('0') << setw(2) << d.mese << "/"
       << d.anno;
    return os;
}
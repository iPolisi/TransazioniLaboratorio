//
// Created by Cristian Polisi on 07/01/2026.
//

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

using namespace std;

class Data {
private:
    int giorno;
    int mese;
    int anno;

    // Funzioni di utilità interne
    bool isBisestile(int a) const;
    bool isValida(int g, int m, int a) const;

public:
    // Costruttore
    Data(int g, int m, int a);

    // Costruttore di default
    Data();

    // Metodi getter
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;

    // Operatore per l'output su stream (es. file o cout)
    friend ostream& operator<<(std::ostream& os, const Data& d);
};

#endif //DATA_H

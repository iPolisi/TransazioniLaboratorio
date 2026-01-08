//
// Created by Cristian on 25/02/2025.
//

#include "ContoCorrente.h"
#include "Entrata.h"
#include "Uscita.h"
#include <iostream>

using namespace std;

int main() {
    ContoCorrente conto1("IT60X0542811101000000123456", "Mario Rossi", "../transazioni.csv");

    ContoCorrente conto2("IT80Y0326812311000000987654", "Luigi Bianchi", "../transazioni.csv");


    ContoCorrente contoCaricato1("IT60X0542811101000000123456", "Mario Rossi", "../transazioni.csv");
    contoCaricato1.caricaDaFile();
    contoCaricato1.stampaTransazioni();

    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;

    ContoCorrente contoCaricato2("IT80Y0326812311000000987654", "Luigi Bianchi", "../transazioni.csv");
    contoCaricato2.caricaDaFile();
    contoCaricato2.stampaTransazioni();

    cout << "Modifica della transazione 1 di Mario Rossi(Stipendio: 1000 -> 2000)" << endl;
    contoCaricato1.modificaTransazione(0, 2000, "Stipendio+Bonus",Data(27,5,2025));

    contoCaricato1.stampaTransazioni();

    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;

    cout << "Ricerca per parola nel conto di Mario Rossi (Ristorante): " << endl;
    vector<int>res=contoCaricato1.cercaDescrizione("Ristorante");
    if (!res.empty()) {
        cout << "Risultato all'indice: " << res[0] <<endl;

    }

    cout << "Eliminazione per parola nel conto di Mario Rossi (Ristorante): " << endl;
    contoCaricato1.rimuoviTransazione(res[0]);

    contoCaricato1.stampaTransazioni();
 return 0;
}
//
// Created by Cristian on 25/02/2025.
//
#include "ContoCorrente.h"
#include "Entrata.h"
#include "Uscita.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


//tornare anche il numero delle transazioni presenti su un conto
ContoCorrente::ContoCorrente(string ib, string intest, string file)
        : iban(ib), intestatario(intest), saldo(0), filePath(file) {}

ContoCorrente::~ContoCorrente() {
    for (auto t : transazioni) {
        delete t;
    }
}

void ContoCorrente::aggiungiTransazione(Transazione* t) {
    transazioni.push_back(t);
    saldo += t->getValore();
}
//aggiornamento in positivo o in negativo del saldo in base al tipo di importo (entrata o uscita)

void ContoCorrente::salvaSuFile(ostream &file, const string &iban) const {
    for (const auto &t : transazioni) {
        t->salvaSuFile(file, iban);  // Scrive la transazione nello stream passato
    }
}
//modifica del metodo
void ContoCorrente::caricaDaFile() {
    for (auto t : transazioni) {
        delete t;
    }
    transazioni.clear();
    saldo = 0;
    //con questo for viene azzerata la memoria per poter ricalcolare il saldo grazie alle transazioni

    ifstream file(filePath); //ifstream è un tipo di oggetto per aprire in lettura un file. "filepath" indica la directory del file da aprire
    if (!file) {
        //lancio di una eccezione nel caso non andasse a buon fine (conto corrente non deve gestire) da rimuovere
        cerr << "Errore nell'apertura del file!" << endl; //controlla l'esistenza del file, se non c'è o è corrotto viene detto che non è possibile aprirlo
        return;
    }
    string linea;
    int rigaNum=0;//tiene conto della riga durante lettura file
    while (getline(file, linea)) { //prende in input il file "transazioni.csv" nel caso corrente e la riga letta viene salvata su linea
        rigaNum++;
        istringstream ss(linea); //istringstream permette di trattare l'imnput come se fosse un cin, quindi input da tastiera almeno è più semplice da gestire
        string fileIban, tipo, importoStr, descrizione, dataStr;
        if (getline(ss, fileIban, ',') && getline(ss, tipo, ',') &&
            getline(ss, importoStr, ',') && getline(ss, descrizione, ',') &&
            getline(ss, dataStr)) {

            if (fileIban == iban) {
                //si controlla se l'iban preso dalla stringa corrisponde ad un iban esistente, sennò viene saltata
                try {
                    double importo = stod(importoStr); //si converte la stringa dell'importo in un tipo double (string to double)
                    int g,m,a;
                    char slash;
                    stringstream ssData(dataStr);
                    ssData >> g >> slash >> m >> slash >> a; //parsing della data per controllare correttezza

                    if (ssData.fail()) throw runtime_error("Formato della data non corretta!");

                    Data dTrans(g,m,a);
                    if (tipo == "Entrata") {
                        transazioni.push_back(new Entrata(importo, descrizione, dTrans));
                        saldo += importo;
                    } else if (tipo == "Uscita") {
                        transazioni.push_back(new Uscita(importo, descrizione, dTrans));
                        saldo -= importo;
                    }
                } catch (const exception &e) {
                    cerr << "Errore nella riga " <<rigaNum << " (" << descrizione << "): " << e.what() << "-> saltata!" << endl;
                }
            }
        }
    }
}

void ContoCorrente::stampaTransazioni() const {
    cout << "Conto di " << intestatario << " (IBAN: " << iban << ")" << endl;
    for (const auto &t : transazioni) {
        cout << t->getData() << ": " << t->tipo() << " | " << t->getImporto() << " , " << t->getDescrizione() << endl;
    }
    cout << "Saldo attuale: " << saldo << endl;
}

string ContoCorrente::getIban() const {return iban;};

double ContoCorrente::getSaldo() const {
    return saldo;
}
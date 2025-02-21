#include <iostream>
#include <string>
#include <vector>
#include "Persona.h" // Assicurati di includere tutti gli header necessari
#include "Conto.h"
#include "Transazione.h"
#include "BonificoUscita.h"
#include "BonificoEntrata.h"

using namespace std;

// Funzione per stampare il menu
void stampaMenu() {
    cout << "Menu:" << endl;
    cout << "1. Crea una nuova persona e conto" << endl;
    cout << "2. Effettua una transazione" << endl;
    cout << "3. Stampa tutte le persone e i loro conti" << endl;
    cout << "4. Esci" << endl;
}

int main() {
    vector<Persona> persone;  // Lista delle persone
    vector<Conto> conti;      // Lista dei conti

    int scelta;
    do {
        // Stampa il menu
        stampaMenu();
        cout << "Scegli un'opzione: ";
        cin >> scelta;

        switch (scelta) {
            case 1: {
                // Creazione di una nuova persona e conto
                string nome, cognome, codiceFiscale;
                cout << "Inserisci il nome: ";
                cin >> nome;
                cout << "Inserisci il cognome: ";
                cin >> cognome;
                cout << "Inserisci il codice fiscale: ";
                cin >> codiceFiscale;

                Persona nuovaPersona(nome, cognome, codiceFiscale);
                persone.push_back(nuovaPersona);

                string numeroConto;
                double saldoIniziale;
                cout << "Inserisci il numero del conto: ";
                cin >> numeroConto;
                cout << "Inserisci il saldo iniziale: ";
                cin >> saldoIniziale;

                Conto nuovoConto(numeroConto, saldoIniziale, &nuovaPersona);
                conti.push_back(nuovoConto);

                cout << "Persona e conto creati con successo!" << endl;
                break;
            }

            case 2: {
                // Effettuare una transazione
                if (conti.empty()) {
                    cout << "Non ci sono conti disponibili!" << endl;
                    break;
                }

                string tipoTransazione;
                double importo;
                cout << "Inserisci il tipo di transazione (Entrata/Uscita): ";
                cin >> tipoTransazione;

                cout << "Inserisci l'importo: ";
                cin >> importo;

                if (tipoTransazione == "Entrata" || tipoTransazione == "entrata") {
                    // Creazione di una transazione di entrata
                    string descrizione;
                    cout << "Inserisci la descrizione della transazione: ";
                    cin >> descrizione;

                    string beneficiario;
                    cout << "Inserisci il beneficiario: ";
                    cin >> beneficiario;

                    BonificoEntrata entrata(importo, descrizione, beneficiario);
                    // Salvo la transazione nel conto
                    conti[0].aggiungiTransazione(&entrata);
                    cout << "Transazione di entrata effettuata con successo!" << endl;

                } else if (tipoTransazione == "Uscita" || tipoTransazione == "uscita") {

                    // Creazione di una transazione di uscita
                    string descrizione;
                    cout << "Inserisci la descrizione della transazione: ";
                    cin >> descrizione;

                    string beneficiario;
                    cout << "Inserisci il beneficiario: ";
                    cin >> beneficiario;

                    BonificoUscita uscita(importo, descrizione, beneficiario);
                    // Salvo la transazione nel conto
                    conti[0].aggiungiTransazione(&uscita);
                    cout << "Transazione di uscita effettuata con successo!" << endl;

                } else {
                    cout << "Tipo di transazione non valido!" << endl;
                }

                break;
            }

            case 3: {
                // Stampa tutte le persone e i loro conti
                if (persone.empty()) {
                    cout << "Non ci sono persone registrate!" << endl;
                    break;
                }

                cout << "Persone e conti registrati:" << endl;
                for (size_t i = 0; i < persone.size(); ++i) {
                    persone[i].stampaDati();
                    conti[i].stampaConto();
                    cout << endl;
                }
                break;
            }

            case 4:
                cout << "Arrivederci!" << endl;
                break;

            default:
                cout << "Scelta non valida! Riprova." << endl;
        }

    } while (scelta != 4);

    return 0;
}

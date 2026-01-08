#include "gtest/gtest.h"
#include "../ContoCorrente.h"
#include "../Entrata.h"
#include "../Uscita.h"
#include "../Data.h"
#include <fstream>

class ContoCorrenteTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Creiamo un file temporaneo per i test
        testFilePath = "test_transazioni.csv";
        std::ofstream file(testFilePath);
        if (file) {
            file << "IT123456789,Entrata,100,Stipendio,01/01/2023\n";
            file << "IT123456789,Uscita,50,Spesa,02/01/2023\n";
            file.close();
        }
    }

    void TearDown() override {
        // Puliamo il file dopo i test
        remove(testFilePath.c_str());
    }

    std::string testFilePath;
};


// **Test per la creazione del conto**
TEST_F(ContoCorrenteTest, CreazioneConto) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    EXPECT_EQ(conto.getIban(), "IT123456789");
    EXPECT_EQ(conto.getSaldo(), 0);
}

// **Test per aggiungere una transazione**
TEST_F(ContoCorrenteTest, AggiuntaTransazione) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    Transazione* entrata = new Entrata(200.0, "Bonus", Data(15,8,2025));
    conto.aggiungiTransazione(entrata);
    EXPECT_EQ(conto.getSaldo(), 200.0);
}

// **Test per salvare su file**
TEST_F(ContoCorrenteTest, SalvataggioSuFile) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    conto.aggiungiTransazione(new Entrata(150.0, "Bonus", Data(10,10,2025)));
    conto.aggiungiTransazione(new Uscita(50.0, "Spesa", Data(10,10,2025)));

    std::ofstream file(testFilePath);
    conto.salvaSuFile(file, "IT123456789");
    file.close();

    // Controlliamo se il file Ã¨ stato scritto correttamente
    std::ifstream inFile(testFilePath);
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    inFile.close();

    std::string output = buffer.str();
    EXPECT_NE(output.find("IT123456789,Entrata,150,Bonus,10/10/2025"), std::string::npos);
    EXPECT_NE(output.find("IT123456789,Uscita,50,Spesa,10/10/2025"), std::string::npos);
}

// **Test per caricare da file**
TEST_F(ContoCorrenteTest, CaricamentoDaFile) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    conto.caricaDaFile();

    EXPECT_EQ(conto.getSaldo(), 50.0);  // 100 - 50 = 50
}

TEST(DataTest, EccezioneDataInvalida) {
    EXPECT_THROW(Data(30, 2, 2025), std::invalid_argument); // 30 Febbraio deve lanciare errore
    EXPECT_THROW(Data(1, 13, 2025), std::invalid_argument); // Mese 13 deve lanciare errore
    EXPECT_NO_THROW(Data(29, 2, 2024)); // Anno bisestile, deve funzionare
}

// TEST di Rimozione Transazione
TEST_F(ContoCorrenteTest, RimozioneTransazione) {
    ContoCorrente conto("IT123", "Mario", testFilePath);

    // Aggiungiamo 3 transazioni
    conto.aggiungiTransazione(new Entrata(100.0, "Entrata1", Data(1,1,2025))); // Indice 0
    conto.aggiungiTransazione(new Uscita(20.0, "Uscita1", Data(2,1,2025)));    // Indice 1
    conto.aggiungiTransazione(new Uscita(10.0, "Uscita2", Data(3,1,2025)));    // Indice 2

    // Saldo iniziale: 100 - 20 - 10 = 70
    EXPECT_EQ(conto.getSaldo(), 70.0);

    // Rimozione dell'uscita 20 (Indice 1)
    // Il saldo dovrebbe salire: 70 + 20 = 90
    conto.rimuoviTransazione(1);
    EXPECT_EQ(conto.getSaldo(), 90.0);

    // Rimozione dell'entrata di 100 (Ora è all'Indice 0 perché la lista scala)
    // Il saldo dovrebbe scendere: 90 - 100 = -10
    conto.rimuoviTransazione(0);
    EXPECT_EQ(conto.getSaldo(), -10.0);
}

// TEST di Modifica Transazione
TEST_F(ContoCorrenteTest, ModificaTransazione) {
    ContoCorrente conto("IT123", "Mario", testFilePath);

    conto.aggiungiTransazione(new Entrata(50.0, "Bonus", Data(10,1,2025)));
    // Saldo: 50

    // Il Bonus passa da 50 a 200
    conto.modificaTransazione(0, 200.0, "Super Bonus", Data(12,1,2025));

    // Verifica nuovo saldo: 200
    EXPECT_EQ(conto.getSaldo(), 200.0);

    // Verifica cambio descrizione
    vector<int> trovati = conto.cercaDescrizione("Super");
    EXPECT_FALSE(trovati.empty());
}

//  TEST Ricerca
TEST_F(ContoCorrenteTest, RicercaTransazioni) {
    ContoCorrente conto("IT123", "Mario", testFilePath);

    conto.aggiungiTransazione(new Entrata(100, "Stipendio Gennaio", Data(1,1,2025)));
    conto.aggiungiTransazione(new Uscita(50, "Spesa Conad", Data(5,1,2025)));
    conto.aggiungiTransazione(new Entrata(100, "Stipendio Febbraio", Data(1,2,2025)));

    // Cerca per parola chiave "Stipendio"
    vector<int> risultatiDesc = conto.cercaDescrizione("Stipendio");
    EXPECT_EQ(risultatiDesc.size(), 2); // Deve trovarne 2

    // Cerca per parola chiave "Conad"
    vector<int> risultatiDesc2 = conto.cercaDescrizione("Conad");
    EXPECT_EQ(risultatiDesc2.size(), 1); // Deve trovarne 1

    // Cerca per Data (1 Febbraio 2025)
    vector<int> risultatiData = conto.cercaData(Data(1, 2, 2025));
    EXPECT_EQ(risultatiData.size(), 1);

    // Verifica che l'indice trovato corrisponda a "Stipendio Febbraio" (che è il terzo inserito, indice 2)
    // gli indici sono 0, 1, 2.
    int indiceTrovato = risultatiData[0];
    EXPECT_EQ(indiceTrovato, 2);
}

// TEST INTEGRITÀ: Modifica su Uscita ===
TEST_F(ContoCorrenteTest, ModificaUscita) {
    ContoCorrente conto("IT123", "Mario", testFilePath);

    // Saldo iniziale 1000
    conto.aggiungiTransazione(new Entrata(1000.0, "Base", Data(1,1,2025)));

    // Aggiunta uscita di 100. Saldo -> 900
    conto.aggiungiTransazione(new Uscita(100.0, "Errore", Data(1,1,2025)));
    EXPECT_EQ(conto.getSaldo(), 900.0);

    // Modifica dell'uscita: da 100 passa a 500.
    // Il saldo deve scendere di altri 400 -> 500.
    conto.modificaTransazione(1, 500.0, "Corretto", Data(1,1,2025));

    EXPECT_EQ(conto.getSaldo(), 500.0);
}

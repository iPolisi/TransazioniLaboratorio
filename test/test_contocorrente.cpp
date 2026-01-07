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
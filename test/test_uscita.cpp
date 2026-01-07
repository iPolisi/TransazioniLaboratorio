//
// Created by Cristian Polisi on 28/02/2025.
//
#include "gtest/gtest.h"
#include "../Uscita.h"
#include <sstream>

TEST(UscitaTest, CreazioneUscita) {
    Data dTest(1,1,2024);
    Uscita u(100.0, "Affitto casa",dTest);
    EXPECT_EQ(u.getImporto(), 100.0);
    EXPECT_EQ(u.getDescrizione(), "Affitto casa");
}

TEST(UscitaTest, TipoUscita) {
    Data dTest(1,1,2024);
    Uscita u(75.5, "Benzina auto",dTest);
    EXPECT_EQ(u.tipo(), "Uscita");
}

TEST(UscitaTest, ImportoNegativoUscita) {
    Data dTest(1,1,2024);
    Uscita u(-20.0, "Errore pagamento",dTest);
    EXPECT_LT(u.getImporto(), 0);  // L'importo deve essere negativo in questo caso
}

TEST(UscitaTest, SalvaSuFileUscita) {
    Data dTest(1,1,2024);
    Uscita u(30.0, "Ristorante",dTest);

    // Usa un stringstream per simulare un file
    std::stringstream ss;
    u.salvaSuFile(ss, "IT987654321");

    // Controlla il contenuto del "file"
    std::string output = ss.str();
    EXPECT_EQ(output, "IT987654321,Uscita,30,Ristorante,01/01/2024\n");
}
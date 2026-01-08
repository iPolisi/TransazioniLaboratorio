//
// Created by Cristian Polisi on 08/01/2026.
//

#include "gtest/gtest.h"
#include "../Data.h"
#include <stdexcept>

// 1. Test creazione data valida standard
TEST(DataTest, CostruttoreDataValida) {
    Data d(15, 8, 2025); // Ferragosto
    EXPECT_EQ(d.getGiorno(), 15);
    EXPECT_EQ(d.getMese(), 8);
    EXPECT_EQ(d.getAnno(), 2025);
}

// 2. Test Anni Bisestili (Il test più importante per le date)
TEST(DataTest, GestioneBisestile) {
    // 2024 è bisestile (divisibile per 4) -> 29 Febbraio DEVE esistere
    EXPECT_NO_THROW(Data(29, 2, 2024));

    // 2023 NON è bisestile -> 29 Febbraio DEVE lanciare errore
    EXPECT_THROW(Data(29, 2, 2023), std::invalid_argument);

    // 2000 è bisestile (divisibile per 400) -> OK
    EXPECT_NO_THROW(Data(29, 2, 2000));

    // 1900 NON è bisestile (divisibile per 100 ma non per 400) -> ERRORE
    EXPECT_THROW(Data(29, 2, 1900), std::invalid_argument);
}

// 3. Test lunghezza dei mesi (30 vs 31 giorni)
TEST(DataTest, LimitiGiorniMesi) {
    // Aprile ha 30 giorni -> 31 Aprile è errore
    EXPECT_THROW(Data(31, 4, 2023), std::invalid_argument);

    // Giugno ha 30 giorni -> 31 Giugno è errore
    EXPECT_THROW(Data(31, 6, 2023), std::invalid_argument);

    // Novembre ha 30 giorni -> 31 Novembre è errore
    EXPECT_THROW(Data(31, 11, 2023), std::invalid_argument);

    // Gennaio ha 31 giorni -> OK
    EXPECT_NO_THROW(Data(31, 1, 2023));
}

// 4. Test valori assurdi (Input Validation)
TEST(DataTest, InputFuoriRange) {
    // Giorno 0 o negativo
    EXPECT_THROW(Data(0, 5, 2025), std::invalid_argument);
    EXPECT_THROW(Data(-5, 5, 2025), std::invalid_argument);

    // Giorno 32
    EXPECT_THROW(Data(32, 1, 2025), std::invalid_argument);

    // Mese 0 o 13
    EXPECT_THROW(Data(1, 0, 2025), std::invalid_argument);
    EXPECT_THROW(Data(1, 13, 2025), std::invalid_argument);
}

// 5. Test Costruttore di Default
TEST(DataTest, CostruttoreDefault) {
    Data d;
    // Verifica che crei una data sensata (es. 01/01/2000 come avevamo definito)
    EXPECT_EQ(d.getGiorno(), 1);
    EXPECT_EQ(d.getMese(), 1);
    EXPECT_GT(d.getAnno(), 1900); // L'anno deve essere valido
}

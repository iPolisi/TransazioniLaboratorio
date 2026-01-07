//
// Created by Cristian Polisi on 28/02/2025.
//
#include "gtest/gtest.h"
#include "../Entrata.h"
#include "../Data.h"
#include <sstream>

TEST(EntrataTest, CreazioneEntrata) {
    Data dTest(15,8,2025);
    Entrata e(100.0, "Stipendio", dTest);

    EXPECT_EQ(e.getImporto(), 100.0);
    EXPECT_EQ(e.getDescrizione(), "Stipendio");
    EXPECT_EQ(e.tipo(), "Entrata");
}

TEST(EntrataTest, SalvaSuFile) {
    Data dTest(15,8,2025);
    Entrata e(50.0, "Bonus", dTest);

    std::stringstream ss;
    e.salvaSuFile(ss, "IT123456789");

    std::string output = ss.str();
    EXPECT_NE(output.find("IT123456789"), std::string::npos);
    EXPECT_NE(output.find("Entrata"), std::string::npos);
    EXPECT_NE(output.find("50"), std::string::npos);
    EXPECT_NE(output.find("Bonus"), std::string::npos);
    EXPECT_EQ(e.getData().getGiorno(), 15);
    EXPECT_EQ(e.getData().getMese(), 8);
    EXPECT_EQ(e.getData().getAnno(), 2025);
}
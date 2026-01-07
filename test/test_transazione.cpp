#include <gtest/gtest.h>
#include "../Transazione.h"
#include "../Entrata.h"
#include "../Uscita.h"
#include "../Data.h"
#include <sstream>

class TransazioneTestHelper : public Transazione {
public:
    // Costruttore che passa i dati alla base
    TransazioneTestHelper(double imp, string desc, Data d)
        : Transazione(imp, desc, d) {}

    // Implementazione obbligatoria del metodo virtuale puro
    double getValore() const override {
        return importo; // Implementazione banale, non ci interessa testare questo qui
    }

    // Implementazione obbligatoria per non essere astratta
    string tipo() const override {
        return "TestHelper";
    }
};

// Test del costruttore e dei metodi getter di Transazione
TEST(TransazioneTest, CostruttoreGetters) {
    Data dTest(25,12,2025);
    TransazioneTestHelper t(1000.0, "Stipendio",dTest);

    // Verifica che l'importo e la descrizione siano corretti
    EXPECT_EQ(t.getImporto(), 1000.0);
    EXPECT_EQ(t.getDescrizione(), "Stipendio");
}

// Test della funzione salvaSuFile per la classe Transazione
TEST(TransazioneTest, SalvaSuFile) {
    std::stringstream ss;
    Data dTest(25,12,2025);
    TransazioneTestHelper t(200.0, "Acquisto",dTest);

    // Salva la transazione su un "file" in memoria
    t.salvaSuFile(ss, "IT123456789");

    // Verifica che il formato sia corretto
    std::string content = ss.str();
    EXPECT_NE(content.find("IT123456789,TestHelper,200,Acquisto,25/12/2025"), std::string::npos);
}

// Test di Entrata (derivata da Transazione)
TEST(EntrataTest, Costruttore) {
    Data dTest(25,12,2025);
    Entrata entrata(500.0, "Stipendio",dTest);

    // Verifica che i metodi siano corretti
    EXPECT_EQ(entrata.getImporto(), 500.0);
    EXPECT_EQ(entrata.getDescrizione(), "Stipendio");
    EXPECT_EQ(entrata.tipo(), "Entrata");  // Assumendo che tipo() ritorni "Entrata"
}

// Test di Uscita (derivata da Transazione)
TEST(UscitaTest, Costruttore) {
    Data dTest(25,12,2025);
    Uscita uscita(150.0, "Benzina",dTest);

    // Verifica che i metodi siano corretti
    EXPECT_EQ(uscita.getImporto(), 150.0);
    EXPECT_EQ(uscita.getDescrizione(), "Benzina");
    EXPECT_EQ(uscita.tipo(), "Uscita");  // Assumendo che tipo() ritorni "Uscita"
}

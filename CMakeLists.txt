cmake_minimum_required(VERSION 3.10)
project(Prova)

# Imposta il C++ standard
set(CMAKE_CXX_STANDARD 20)

# Aggiungi GoogleTest come sottodirectory
add_subdirectory(_deps/googletest)

# Eseguibile principale (SENZA i test)
add_executable(Prova
        main.cpp
        Transazione.cpp
        Entrata.cpp
        Uscita.cpp
        ContoCorrente.cpp
        Data.h
        Data.cpp
)

# Eseguibile per i test (SEPARATO)
add_executable(runTests
        test/test_main.cpp
        test/test_transazione.cpp
        test/test_entrata.cpp
        test/test_uscita.cpp
        test/test_contocorrente.cpp
        Transazione.cpp
        Entrata.cpp
        Uscita.cpp
        ContoCorrente.cpp
        Data.h
        Data.cpp
)

# Linka GoogleTest solo ai test
target_link_libraries(runTests gtest gtest_main)

# Abilita i test
enable_testing()
add_test(NAME RunAllTests COMMAND runTests)

# Aggiungi esplicitamente il percorso degli header di GoogleTest
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR}/_deps/googletest/googletest/include)

# Messaggio di debug
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

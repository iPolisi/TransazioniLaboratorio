cmake_minimum_required(VERSION 3.30)
project(Trans)

set(CMAKE_CXX_STANDARD 20)

add_executable(Trans main.cpp
        Persona.h
        Persona.cpp
        Conto.h
        Transazione.h
        BonificoEntrata.h
        BonificoEntrata.cpp
        BonificoUscita.h
        BonificoUscita.cpp
        Abbonamento.h
        Abbonamento.cpp
        Stipendio.h
        Stipendio.cpp
        Conto.cpp
)

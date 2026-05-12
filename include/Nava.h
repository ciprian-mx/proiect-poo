#pragma once
#include <string>
#include <iostream>
#include "Locatie.h"
#include "Resursa.h"

class Nava{
private:
    std::string nume;
    Locatie locatieCurenta;
    Resursa** incarcatura;
    int numarResurse;
    int capacitateMaxima;
    static int numarNave;

public:
    Nava(const std::string& nume, const Locatie& start, int capacitate);
    Nava(const Nava& other);
    
    Nava& operator=(Nava other);
    
    virtual ~Nava();
    bool adaugaResursa(const Resursa& res);
    double calculeazaMasaTotala() const;
    const Locatie& getLocatie() const;
    double calculeazaTaxaTotalaTransport() const;
    friend std::ostream& operator<<(std::ostream& os, const Nava& nava);
    friend void swap(Nava& prima, Nava& aDoua) noexcept;
    static int getNumarNave();
    int calculeazaNivelRiscTotal () const;
};


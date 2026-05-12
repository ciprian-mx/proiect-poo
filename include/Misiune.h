#pragma once
#include <iostream>
#include <string>
#include "Nava.h"
#include "Locatie.h"
#include "Resursa.h"
class Misiune
{
private:
    std::string codMisiune;
    Nava navaAsignata;
    Locatie destinatie;

public:
    Misiune(const std::string& cod, const Nava& nava, const Locatie& dest);
    void evalueazaFezabilitatea() const;
    friend std::ostream& operator<<(std::ostream& os, const Misiune& misiune);
};
#pragma once
#include "Resursa.h"

class ResursaDeBaza : public Resursa{
    public:
    ResursaDeBaza(const std::string& denumire = "Necunoscut", double greutateKg = 0);
    double taxaTransport() const override;
    Resursa* clone() const override;

protected:
    void afiseazaSpecific(std::ostream& os) const override;
};
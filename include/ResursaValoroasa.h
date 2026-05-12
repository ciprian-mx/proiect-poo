#pragma once 
#include "Resursa.h"

class ResursaValoroasa : public Resursa{
private:
    double pretGram;
public:
    ResursaValoroasa(const std::string& denumire = "Necunoscut", double greutateKg = 0, double pretGram = 0);
    double getPretGram() const;
    double taxaTransport() const override;
    Resursa* clone() const override;

protected:
    void afiseazaSpecific(std::ostream& os) const override;
};
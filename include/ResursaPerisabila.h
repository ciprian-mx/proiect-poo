#pragma once
#include "Resursa.h"

class ResursaPerisabila : public Resursa{
    private:
    int zileValabilitate;

public:
    explicit ResursaPerisabila(const std::string& denumire= "Necunoscut", double greutateKg= 0, int zileValabilitate= 0);
    int getZileValabilitate() const;
    double taxaTransport () const override; 
    Resursa* clone() const override;
protected:
    void afiseazaSpecific(std::ostream& os) const override;
};
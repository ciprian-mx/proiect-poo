#pragma once
#include "Resursa.h"

class ResursaPericuloasa : public Resursa
{
private:
    int gradRisc;
public:
    explicit ResursaPericuloasa(const std::string& denumire = "Necunoscut", double greutateKg = 0, int gradRisc = 0);
    int getGradRisc() const;
    double taxaTransport() const override;
    Resursa* clone() const override;
protected:
    void afiseazaSpecific(std::ostream& os) const override;
};
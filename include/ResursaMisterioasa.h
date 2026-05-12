#pragma once
#include "Resursa.h"

class ResursaMisterioasa : public Resursa{
private:
    std::string descriere;
    bool volatila;

public:
    explicit ResursaMisterioasa(const std::string& denumire = "Necunoscut", double greutateKg = 0, const std::string& descriere = "N/A", bool volatila = true);
    std::string getDescriere() const;
    bool getVolatila() const;
    double taxaTransport() const override;
    Resursa* clone() const override;

protected:
    void afiseazaSpecific(std::ostream& os) const override;
};
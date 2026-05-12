#include "ResursaValoroasa.h"

ResursaValoroasa :: ResursaValoroasa (const std::string& denumire, double greutateKg, double pretGram)
: Resursa(denumire, greutateKg), pretGram(pretGram) {}

double ResursaValoroasa :: getPretGram() const { return pretGram; }

double ResursaValoroasa :: taxaTransport() const{
    return (getGreutate() * 2.0) + (getPretGram() * 0.5);
}

void ResursaValoroasa :: afiseazaSpecific(std::ostream& os) const{
    os << "Pretul per gram: " << pretGram;
}

Resursa* ResursaValoroasa :: clone() const
{
    return new ResursaValoroasa(*this);
}


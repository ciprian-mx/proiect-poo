#include "ResursaDeBaza.h"

ResursaDeBaza :: ResursaDeBaza(const std::string& denumire, double greutateKg)
: Resursa(denumire, greutateKg) {}

double ResursaDeBaza :: taxaTransport() const{
    return getGreutate() * 2.0;
}

void ResursaDeBaza :: afiseazaSpecific(std::ostream&) const {}

Resursa* ResursaDeBaza :: clone() const{
    return new ResursaDeBaza(*this);
}
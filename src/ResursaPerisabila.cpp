#include "ResursaPerisabila.h"

ResursaPerisabila::ResursaPerisabila(const std::string& denumire, double greutateKg, int zileValabilitate)
    : Resursa(denumire, greutateKg), zileValabilitate(zileValabilitate) {}

int ResursaPerisabila::getZileValabilitate() const {
    return zileValabilitate;
}

double ResursaPerisabila :: taxaTransport() const {
    return  getGreutate() * 5.0 * getZileValabilitate();
}

void ResursaPerisabila :: afiseazaSpecific(std::ostream& os) const{
    os << "Zile valabilitate: "<< zileValabilitate;
}

Resursa* ResursaPerisabila :: clone() const
{
    return new ResursaPerisabila(*this);
}
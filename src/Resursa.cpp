#include "Resursa.h"

Resursa :: Resursa (const std::string& denumire, double greutateKg)
: denumire(denumire), greutateKg(greutateKg){}

double Resursa :: getGreutate() const {return greutateKg;}

void Resursa :: afiseaza(std::ostream& os) const{
    os << "Resursa: "<< denumire << " ("<< greutateKg<<"kg) ";
    afiseazaSpecific(os);
}

std::ostream& operator<<(std::ostream& os, const Resursa& res)
{
    res.afiseaza(os);
    return os;
}
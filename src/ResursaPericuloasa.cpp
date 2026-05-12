#include "ResursaPericuloasa.h"

ResursaPericuloasa :: ResursaPericuloasa(const std::string& denumire, double greutateKg, int gradRisc)
: Resursa(denumire, greutateKg), gradRisc(gradRisc){}

int ResursaPericuloasa :: getGradRisc() const {return gradRisc;}

double ResursaPericuloasa :: taxaTransport() const
{
    return getGreutate() * getGradRisc() * 10.0 * 5.0;  
}

void ResursaPericuloasa :: afiseazaSpecific(std::ostream& os) const{
    os<< "Grad risc: "<<gradRisc;
}

Resursa* ResursaPericuloasa :: clone() const
{
    return new ResursaPericuloasa(*this);
}
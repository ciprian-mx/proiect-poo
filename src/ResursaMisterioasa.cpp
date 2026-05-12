#include "ResursaMisterioasa.h"

ResursaMisterioasa :: ResursaMisterioasa(const std::string& denumire, double greutateKg, const std::string& descriere, bool volatila) :
Resursa(denumire, greutateKg), descriere(descriere), volatila(volatila){}

std::string ResursaMisterioasa::getDescriere() const {return descriere;}
bool ResursaMisterioasa :: getVolatila() const {return volatila;}

double ResursaMisterioasa::taxaTransport() const{
    return getGreutate() * 20 + int(volatila) * 500;
}

void ResursaMisterioasa :: afiseazaSpecific(std::ostream& os) const{
    os<< "Descriere: "<<descriere<<"\n"<<"Volatila: "<<volatila;
}

Resursa* ResursaMisterioasa :: clone() const{
    return new ResursaMisterioasa(*this);
}
#include "Nava.h"
#include "ResursaPericuloasa.h"
#include "Exceptii.h"

int Nava :: numarNave = 0;

Nava :: Nava(const std::string& nume, const Locatie& start, int capacitate)
    : nume(nume), locatieCurenta(start), numarResurse(0), capacitateMaxima(capacitate) {

        if(capacitate <0)
        {
            throw ExceptieDateInvalide("Capacitatea navei trebuie sa fie strict mai mare decat zero!");
        }
        incarcatura = new Resursa*[capacitateMaxima];

        numarNave++;
}

Nava :: Nava(const Nava& other) 
        : nume(other.nume), locatieCurenta(other.locatieCurenta), 
          numarResurse(other.numarResurse), capacitateMaxima(other.capacitateMaxima) {
        incarcatura = new Resursa*[capacitateMaxima];
        for (int i = 0; i < numarResurse; ++i) {
            incarcatura[i] = other.incarcatura[i]->clone();
    }
    numarNave ++ ;
}

Nava :: ~Nava() {
    for (int i = 0; i < numarResurse; ++i) {
        delete incarcatura[i]; 
    }

    delete[] incarcatura;
    numarNave--;
}

int Nava::getNumarNave(){return numarNave;}

bool Nava :: adaugaResursa(const Resursa& res) {
        if(numarResurse >= capacitateMaxima)
        {
            throw ExceptieCapacitate();
        }
        incarcatura[numarResurse++] = res.clone();
        return true;
}

double Nava::calculeazaMasaTotala() const {
        double masa = 0;
        for (int i = 0; i < numarResurse; ++i) {
            masa += incarcatura[i]->getGreutate();
        }
        return masa;
}

const Locatie& Nava::getLocatie() const { return locatieCurenta; }

double Nava::calculeazaTaxaTotalaTransport() const{
    double costTotal = 0;

    for(int i{}; i <numarResurse;i++)
    {
        costTotal+= incarcatura[i]->taxaTransport();
    }
    return costTotal;
}

std::ostream& operator<<(std::ostream& os, const Nava& nava) {
        os << "Nava: " << nava.nume << " | Locatie: " << nava.locatieCurenta 
           << " | Sarcina utila: " << nava.numarResurse << "/" << nava.capacitateMaxima << " resurse\n";

        for (int i = 0; i < nava.numarResurse; ++i) {
            os << "  - " ;
            nava.incarcatura[i]->afiseaza(os);
            os<<"\n";
        }
        return os;
    }

void swap(Nava& prima, Nava& aDoua) noexcept{
    using std::swap;
    swap(prima.nume, aDoua.nume);
    swap(prima.locatieCurenta, aDoua.locatieCurenta);
    swap(prima.numarResurse, aDoua.numarResurse);
    swap(prima.capacitateMaxima, aDoua.capacitateMaxima);
    swap(prima.incarcatura, aDoua.incarcatura);
}

Nava& Nava::operator=(Nava other)
{
    swap(*this, other);

    return *this;
}

int Nava:: calculeazaNivelRiscTotal() const{
    int riscTotale = 0;

    for (int i{}; i<numarResurse;++i)
    {
        const ResursaPericuloasa* resPericuloasa = dynamic_cast<ResursaPericuloasa*> (incarcatura[i]);
        if(resPericuloasa != nullptr)
        {
            riscTotale+=resPericuloasa->getGradRisc();
        }
    }
    return riscTotale;
}
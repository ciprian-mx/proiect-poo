#pragma once
#include <string>
#include <iostream>

class Resursa
{
private:
    std :: string denumire;
    double greutateKg;
public:
    explicit Resursa(const std::string& denumire = "Necunoscut", double greutateKg = 0);

    virtual ~Resursa() = default;

    double getGreutate() const;
    
    virtual double taxaTransport () const = 0 ;

    virtual Resursa* clone() const = 0;

    void afiseaza (std:: ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Resursa& res);

protected:
    virtual void afiseazaSpecific(std :: ostream& os) const = 0;
};
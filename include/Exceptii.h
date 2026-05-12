#pragma once
#include <exception>
#include <string>

class ExceptieStellarLogix : public std::exception{
protected:
    std::string mesaj;

public:
    explicit ExceptieStellarLogix(const std::string& mesajEroare) : mesaj(mesajEroare){}

    const char* what() const noexcept override{
        return mesaj.c_str();
    }
};

class ExceptieCapacitate : public ExceptieStellarLogix{
public:
    ExceptieCapacitate() : ExceptieStellarLogix("Eroare de Capacitate: Nava este plina, nu mai poti adauga resurse!"){}
};

class ExceptieDateInvalide : public ExceptieStellarLogix{
public:
    explicit ExceptieDateInvalide(const std::string& detalii) : ExceptieStellarLogix("Eroare validare " + detalii){}
};

class ExceptieFunctionareNava : public ExceptieStellarLogix{
public:
    explicit ExceptieFunctionareNava(const std::string& detalii) : ExceptieStellarLogix("Eroare Sistem Nava: " + detalii){}
};
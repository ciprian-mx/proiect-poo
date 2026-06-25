#include "NavaBuilder.h"

NavaBuilder::NavaBuilder(const std::string& nume, const Locatie& start, int capacitate) 
    : navaInConstructie(nume, start, capacitate) {}

NavaBuilder& NavaBuilder::adaugaResursa(const Resursa& res) {
    navaInConstructie.adaugaResursa(res);
    return *this;
}

const Nava& NavaBuilder::build() const {
    return navaInConstructie;
}
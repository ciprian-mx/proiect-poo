#pragma once
#include "Nava.h"
#include "Locatie.h"
#include "Resursa.h"
#include <string>

class NavaBuilder {
private:
    Nava navaInConstructie;

public:
    NavaBuilder(const std::string& nume, const Locatie& start, int capacitate);

    NavaBuilder& adaugaResursa(const Resursa& res);

    Nava build();
};
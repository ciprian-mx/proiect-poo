#include "Locatie.h" 
#include <cmath>

Locatie::Locatie(double x, double y, double z, const std::string& numeSector) 
    : x(x), y(y), z(z), numeSector(numeSector) {}



double Locatie::calculeazaDistanta(const Locatie& alta) const {
    return std::sqrt(std::pow(x - alta.x, 2) + std::pow(y - alta.y, 2) + std::pow(z - alta.z, 2));
}

std::ostream& operator<<(std::ostream& os, const Locatie& loc) {
    os << loc.numeSector << " [" << loc.x << ", " << loc.y << ", " << loc.z << "]";
    return os;
}
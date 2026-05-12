#pragma once
#include <string>
#include <iostream>

class Locatie {
private:
    double x, y, z;
    std::string numeSector;

public:
    explicit Locatie(double x = 0, double y = 0, double z = 0, const std::string& numeSector = "Necunoscut");
    
    double calculeazaDistanta(const Locatie& alta) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Locatie& loc);
};
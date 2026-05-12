#include "Misiune.h"

Misiune :: Misiune(const std::string& cod, const Nava& nava, const Locatie& dest)
    : codMisiune(cod), navaAsignata(nava), destinatie(dest){}

void Misiune::evalueazaFezabilitatea() const {
        double distanta = navaAsignata.getLocatie().calculeazaDistanta(destinatie);
        double masa = navaAsignata.calculeazaMasaTotala();
        
        double combustibilNecesar = (distanta * 0.5) + (masa * 0.1);

        std::cout << "--- Evaluare Misiune: " << codMisiune << " ---\n";
        std::cout << "Distanta calculata: " << distanta << " unitati spatiale.\n";
        std::cout << "Masa totala transportata: " << masa << " kg.\n";
        std::cout << "Combustibil estimat necesar: " << combustibilNecesar << " tone.\n";
        std::cout << "Status: " << (combustibilNecesar < 10000 ? "Aprobata" : "Risc critic de combustibil") << "\n";
        std::cout << "--------------------------------------\n";
}

std::ostream& operator<<(std::ostream& os, const Misiune& misiune) {
        os << "MISIUNE: " << misiune.codMisiune << " | Destinatie: " << misiune.destinatie << "\n";
        os << misiune.navaAsignata; 
        return os;
}
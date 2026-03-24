#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Locatie
{
    private:
    double x,y,z;
    string numeSector;

    public:
    Locatie(double x = 0, double y  = 0, double z = 0, const string& numeSector = "Necunoscut")
    : x(x), y(y), z(z), numeSector(numeSector) {}

    double calculeazaDistanta(const Locatie& alta) const {
        return sqrt(pow(x - alta.x, 2) + pow(y - alta.y, 2) + pow(z - alta.z, 2));
    }

    friend ostream& operator<<(ostream& os, const Locatie& loc) {
        os << loc.numeSector << " [" << loc.x << ", " << loc.y << ", " << loc.z << "]";
        return os;
    }
};

class Resursa
{
    private:
    string denumire;
    double greutateKg;

    public:
    Resursa(const string& denumire = "Necunoscut", double greutateKg = 0)
    : denumire(denumire), greutateKg(greutateKg){}

    double getGreutate() const {return greutateKg;}

    friend ostream& operator<<(ostream& os, const Resursa& res) {
        os << res.denumire << " (" << res.greutateKg << " kg)";
        return os;
    }

};

class Nava
{
    private:
    string nume;
    Locatie locatieCurenta;
    Resursa* incarcatura;
    int numarResurse;
    int capacitateMaxima;

    public:
    Nava(const string& nume, const Locatie& start, int capacitate)
    : nume(nume), locatieCurenta(start), numarResurse(0), capacitateMaxima(capacitate) {
        incarcatura = new Resursa[capacitateMaxima];
    }

    Nava(const Nava& other) 
        : nume(other.nume), locatieCurenta(other.locatieCurenta), 
          numarResurse(other.numarResurse), capacitateMaxima(other.capacitateMaxima) {
        incarcatura = new Resursa[capacitateMaxima];
        for (int i = 0; i < numarResurse; ++i) {
            incarcatura[i] = other.incarcatura[i];
        }
    }

    Nava& operator=(const Nava& other) {
        if (this != &other) {
            delete[] incarcatura; 
            
            nume = other.nume;
            locatieCurenta = other.locatieCurenta;
            numarResurse = other.numarResurse;
            capacitateMaxima = other.capacitateMaxima;
            
            incarcatura = new Resursa[capacitateMaxima];
            for (int i = 0; i < numarResurse; ++i) {
                incarcatura[i] = other.incarcatura[i];
            }
        }
        return *this;
    }

    ~Nava() {
        delete[] incarcatura;
    }

    bool adaugaResursa(const Resursa& res) {
        if (numarResurse < capacitateMaxima) {
            incarcatura[numarResurse++] = res;
            return true;
        }
        return false;
    }

    double calculeazaMasaTotala() const {
        double masa = 0;
        for (int i = 0; i < numarResurse; ++i) {
            masa += incarcatura[i].getGreutate();
        }
        return masa;
    }

    const Locatie& getLocatie() const { return locatieCurenta; }

    friend ostream& operator<<(ostream& os, const Nava& nava) {
        os << "Nava: " << nava.nume << " | Locatie: " << nava.locatieCurenta 
           << " | Sarcina utila: " << nava.numarResurse << "/" << nava.capacitateMaxima << " resurse\n";
        for (int i = 0; i < nava.numarResurse; ++i) {
            os << "  - " << nava.incarcatura[i] << "\n";
        }
        return os;
    }

};

class Misiune
{
    private:
    string codMisiune;
    Nava navaAsignata;
    Locatie destinatie;
    public:
    Misiune(const string& cod, const Nava& nava, const Locatie& dest)
    : codMisiune(cod), navaAsignata(nava), destinatie(dest){}

    void evalueazaFezabilitatea() const {
        double distanta = navaAsignata.getLocatie().calculeazaDistanta(destinatie);
        double masa = navaAsignata.calculeazaMasaTotala();
        
        double combustibilNecesar = (distanta * 0.5) + (masa * 0.1);

        cout << "--- Evaluare Misiune: " << codMisiune << " ---\n";
        cout << "Distanta calculata: " << distanta << " unitati spatiale.\n";
        cout << "Masa totala transportata: " << masa << " kg.\n";
        cout << "Combustibil estimat necesar: " << combustibilNecesar << " tone.\n";
        cout << "Status: " << (combustibilNecesar < 10000 ? "Aprobata" : "Risc critic de combustibil") << "\n";
        cout << "--------------------------------------\n";
    }

    friend ostream& operator<<(ostream& os, const Misiune& misiune) {
        os << "MISIUNE: " << misiune.codMisiune << " | Destinatie: " << misiune.destinatie << "\n";
        os << misiune.navaAsignata; // Apeleaza operatorul<< din Nava, care apeleaza din Locatie si Resursa
        return os;
    }

};



int main()
{
    cout<< "=== Initializare Sisteme StellarLogix ===\n\n";

    Locatie pamant(0, 0, 0, "Terra Base");
    Locatie marte(140, 50, -20, "Mars Colony Prime");

    Nava navaApollo("Apollo-V", pamant, 5);
    navaApollo.adaugaResursa(Resursa("Alimente", 1500));
    navaApollo.adaugaResursa(Resursa("Oxigen Lichid", 3000));
    navaApollo.adaugaResursa(Resursa("Piese Schimb", 850));

    Nava navaBackup = navaApollo; 

    Misiune misiuneRosie("OP-RED-01", navaApollo, marte);

    cout << misiuneRosie << "\n";

    misiuneRosie.evalueazaFezabilitatea();
}


/*#include <iostream>
#include <array>
#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"

int main() {
    std::cout << "Hello, world!\n";
    Example e1;
    e1.g();
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for(int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
*/

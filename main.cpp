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
    explicit Locatie(double x = 0, double y  = 0, double z = 0, const string& numeSector = "Necunoscut")
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
    explicit Resursa(const string& denumire = "Necunoscut", double greutateKg = 0)
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



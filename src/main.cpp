#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "Locatie.h"
#include "Resursa.h"
#include "Nava.h"
#include "Misiune.h"
#include "ResursaPericuloasa.h"
#include "ResursaPerisabila.h"
#include "ResursaValoroasa.h"
#include "ResursaDeBaza.h"
#include "Exceptii.h"
#include "ResursaMisterioasa.h"
using namespace std;

int main()
{
    cout<< "=== Initializare Sisteme StellarLogix ===\n\n";

    Locatie pamant(0, 0, 0, "Terra Base");
    Locatie marte(140, 50, -20, "Mars Colony Prime");

    Nava navaApollo("Apollo-V", pamant, 5);
    navaApollo.adaugaResursa(ResursaDeBaza("Alimente", 1500));
    navaApollo.adaugaResursa(ResursaDeBaza("Oxigen Lichid", 3000));
    navaApollo.adaugaResursa(ResursaDeBaza("Piese Schimb", 850));
    navaApollo.adaugaResursa(ResursaMisterioasa("Artefact Extraterestru", 50, "Emite o lumina albastra", true));
    Nava navaBackup = navaApollo; 

    Misiune misiuneRosie("OP-RED-01", navaApollo, marte);

    cout << misiuneRosie << "\n";

    misiuneRosie.evalueazaFezabilitatea();

    cout<<"=== Test Exceptii ===\n\n";

    try{
        Locatie start(0, 0, 0, "Baza Alpha");
        Nava navaFantoma("Ghost", start, -3);
    }
    catch (const ExceptieDateInvalide& eroare)
    {
        cout<<eroare.what()<<endl;
    }

    try{
        Locatie luna(100, 120, 105, "Luna");
        Nava rider("Rider", luna, 2);

        ResursaDeBaza fier("Fier", 50);
        ResursaDeBaza apa("Apa", 150);
        ResursaDeBaza plastic("Plastic", 90);

        rider.adaugaResursa(fier);
        rider.adaugaResursa(apa);
        rider.adaugaResursa(plastic);
    }
    catch(const ExceptieCapacitate& eroare)
    {
        cout<<eroare.what()<<endl;
    }
    catch(const ExceptieStellarLogix* eroare)
    {
        cout<<eroare->what()<<endl;
    }

    cout << "Taxa totala: " << navaApollo.calculeazaTaxaTotalaTransport() << "\n";
    cout << "Nivel risc: " << navaApollo.calculeazaNivelRiscTotal() << "\n";
    cout << "Numar total de nave: " << Nava::getNumarNave() << "\n";


    ResursaMisterioasa testArtefact("Artefact Z", 15, "Lumina verde", false);
    cout << "Test getter descriere: " << testArtefact.getDescriere() << "\n";
    cout << "Test getter volatila: " << testArtefact.getVolatila() << "\n";
    
    return 0;
}



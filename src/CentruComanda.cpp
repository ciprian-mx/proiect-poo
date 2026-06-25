#include "CentruComanda.h"

CentruComanda& CentruComanda::getInstance() {
    static CentruComanda instanta; 
    return instanta;
}

void CentruComanda::logEveniment(const string& mesaj) {
    nrLoguri++;
    cout << "[LOG StellarLogix Centru Comanda] (Log #" << nrLoguri << "): " << mesaj << "\n";
}
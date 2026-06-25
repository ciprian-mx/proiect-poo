#include "CentruComanda.h"

CentruComanda& CentruComanda::getInstance() {
    static CentruComanda instanta; 
    return instanta;
}

void CentruComanda::logEveniment(const string& mesaj) {
    cout << "[LOG StellarLogix Centru Comanda]: " << mesaj << "\n";
}
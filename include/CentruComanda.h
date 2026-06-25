#pragma once
#include <iostream>
#include <string>
using namespace std;

class CentruComanda {
private:
    int nrLoguri = 0;
    CentruComanda() {}
    
    CentruComanda(const CentruComanda&) = delete;
    CentruComanda& operator=(const CentruComanda&) = delete;

public:
    static CentruComanda& getInstance();

    void logEveniment(const string& mesaj);
};
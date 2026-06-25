#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename T>
void logheazaDate(const std::string& prefix, const T& obiect) {
    std::cout << "[LOG - " << prefix << "]: " << obiect << "\n";
}

template <typename T>
class Depozit {
private:
    std::string numeDepozit;
    std::vector<T> elemente;

public:
    explicit Depozit(const std::string& nume) : numeDepozit(nume) {}

    void adaugaElement(const T& element) {
        elemente.push_back(element);
    }

    void afiseazaContinut() const {
        std::cout << "=== Continut Depozit: " << numeDepozit << " ===\n";
        for (const auto& el : elemente) {
            std::cout << el << "\n"; 
        }
        std::cout << "==========================\n";
    }
};
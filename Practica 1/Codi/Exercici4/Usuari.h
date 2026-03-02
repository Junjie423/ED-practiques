// Autor: Junjie Zhou

#ifndef USUARI_H
#define USUARI_H
#include <iostream>
#include "Llibre.h"
using namespace std;

// Declarem la clase Usuari:
class Usuari{
    // Declarem els atributs privats
    private:
    string nom;
    string adreca;
    string poblacio;
    string telefon;
    string dni;
    int edat;
    vector<Llibre> llibres;

    // Declarem els mètodes públics i el constructor
    public:
    Usuari (string nom, string adreca, string poblacio, string telefon, string dni, int edat);
    string getNom() const;
    string getAdreca() const;
    string getPoblacio() const;
    string getTelefon() const;
    string getDNI() const;
    int getEdat() const;
    void print() const;
    void afegeixLlibre(string titol, string autor, string isbn, int anyPublicacio);
    void eliminaLlibre(string titol);
    void mostraLlibres() const;
};
#endif
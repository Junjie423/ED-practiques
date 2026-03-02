// Autor: Junjie Zhou

#ifndef ESTUDIANT_H
#define ESTUDIANT_H

using namespace std;
#include<iostream>

// Declarem la classe Estudiant
class Estudiant
{
    // Declarem els mètodes públics i el constructor
    public:
        Estudiant(string nom, int any, int assignatures);

        int getEdat() const;
        void print();

    // Declarem els atributs privats
    private:
        string nom;
        int any;
        int assignatures;
};

#endif 
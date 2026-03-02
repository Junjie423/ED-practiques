// Autor: Junjie Zhou

#include <iostream>
#include "Estudiant.h"
using namespace std;

// Definim el constructor perque rebi els parametres per assignar-los als atributs
Estudiant::Estudiant(string nom, int any, int assignatures){
    this->nom = nom;
    this->any = any;
    this->assignatures = assignatures;
}
// Definim el mètode getEdat
int Estudiant::getEdat() const{
    return (2026 - any);
}
// Definim el mètode print
void Estudiant::print(){
    cout << "Estudiant(Nom ==> " << nom << ", Naixement ==> " << any << ", Assignatures ==> " << assignatures <<")" << endl;
}

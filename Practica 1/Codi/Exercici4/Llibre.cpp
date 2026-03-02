// Autor: Junjie Zhou

#include <iostream>
#include "Llibre.h"
using namespace std;

// Definim el constructor amb parametres que assignara valors als atributs 
Llibre::Llibre(string titol, string autor, string isbn, int anyPublicacio){
    this->titol = titol;
    this->autor = autor;
    this->isbn = isbn;
    this->anyPublicacio = anyPublicacio;
}
// Definim els mètodes getters
string Llibre::getTitol() const{
    return this->titol;
}
string Llibre::getAutor() const{
    return this->autor;
}
string Llibre::getIsbn() const{
    return this->isbn;
}
int Llibre::getAnyPublicacio() const{
    return this->anyPublicacio;
}
// Definim el mètode print() // Mostrara la informacío del llibre en una línia
// El mètode mostrarLlibres de la classe Usuari, demana llibre per línia
void Llibre::print() const{
    cout << "Títol ==> " << this->titol << " Autor ==> " << this->autor << " ISBN ==> " << this->isbn 
    << " Any de publicació ==> " << this->anyPublicacio << endl;
}

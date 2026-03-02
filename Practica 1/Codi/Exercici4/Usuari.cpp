// Autor: Junjie Zhou

#include <iostream>
#include <vector>
#include "Usuari.h"
#include "Llibre.h"
using namespace std;

// Definim el constructor amb parametres per assignar els valors als atributs
Usuari::Usuari(string nom, string adreca, string poblacio, string telefon, string dni, int edat){
    this->nom = nom;
    this->adreca = adreca;
    this->poblacio = poblacio;
    this->telefon = telefon;
    this->dni = dni;
    this->edat = edat;
    // El vector llibre està buit per defecte, no cal fer res en el constructor
}
// Definim els getters
string Usuari::getNom() const{
    return this->nom;
}
string Usuari::getAdreca() const{
    return this->adreca;
}
string Usuari::getPoblacio() const{
    return this-> poblacio;
}
string Usuari::getTelefon() const{
    return this->telefon;
}
string Usuari::getDNI() const{
    return this->dni;
}
int Usuari::getEdat() const{
    return this->edat;
}
// Definim el mètode print()
void Usuari::print() const{
    cout << "Nom de l'usuari ==> " << this->nom << " Adreça ==> " << this->adreca << " Poblacio ==> " << this->poblacio 
    << " Telefon ==> " << this->telefon << " DNI ==> " << this->dni << " Edat ==> " << this->edat << endl;
}
// Definim el mètode afegeixLlibre
void Usuari::afegeixLlibre(string titol, string autor, string isbn, int anyPublicacio){
    // Creem un nou objecte llibre i l'afegim al vector llibres
    Llibre l1 = Llibre(titol, autor, isbn, anyPublicacio);
    this->llibres.push_back(l1);
}
// Definim el mètode eliminarLlibre
void Usuari::eliminaLlibre(string titol){
    // Utilitzem un iterador que apuntara a l'element de posicio 0 fins al final del vector
    for (vector<Llibre>::iterator it = llibres.begin(); it != llibres.end(); ++it){
        // Si el titol de l'element (llibre) que apunta el punter es igual al parametre introduït, eliminem el llibre.
        if(it->getTitol() == titol){
            llibres.erase(it);
            // Retornem al main quan ja s'hagi eliminat el llibre
            return;
        }
    }
    // En cas de no trobar el llibre, no retorna abans al main i mostrara per pantalla:
    cout << "No s'ha pogut trobar el llibre: " << titol << endl;
}
// Definim el mètode mostrarLlibres
void Usuari::mostraLlibres() const{
    // Utilitzant un iterador que recorre el vector, fem que faci print (del llibre) cada posicio
    for(vector<Llibre>::const_iterator it = llibres.begin(); it != llibres.end(); ++it){
        it->print();
    }
}
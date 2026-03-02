// Autor: Junjie Zhou

# ifndef LLIBRE_H
# define LLIBRE_H

#include <iostream>
using namespace std;

// Creem la classe Llibre
class Llibre{
    // Declarem els atributs privats
    private:
        string titol;
        string autor;
        string isbn;
        int anyPublicacio;
    
    //Declarem els mètodes públics i el constructor
    public:
        Llibre(string titol, string autor, string isbn, int anyPublicacio);
        string getTitol() const;
        string getAutor() const;
        string getIsbn() const;
        int getAnyPublicacio () const;
    // Declarem el mètode print
        void print() const;
};
# endif 
// Autor: Junjie Zhou

#ifndef PILA_ESTATICA_H
#define PILA_ESTATICA_H
#include <initializer_list>
#include <vector>
using namespace std;

template <class Elemento> class PilaEstatica {

    public:
        PilaEstatica(int max = TAMANO_MAXIMO); // Constructor
        PilaEstatica(const PilaEstatica &original); // Constructor copia
        PilaEstatica( initializer_list<Elemento> elementos); //Inicializa la pila con una lista de elementos
        PilaEstatica(const vector<Elemento>& elementos); // Inicializa la pila a partir de un vector
        int tamano() const; // Devuelve la longitud de la pila
        bool estaVacia() const; // Devuelve true si la pila está vacía
        bool estaLlena() const; // Devuelve true si la pila está llena
        const Elemento &elementoEncima() const; // Devuelve el elemento de encima, exception si está vacía
        void anadirElemento(const Elemento &e); // Añade un nuevo elemento encima de
        // la pila, exception si no es posible
        void suprimirElemento(); // Elimina el elemento de encima de la pila,
        // exception si no es posible
        void print() const; // Imprime la pila completa por stdout
    private:
        enum { TAMANO_MAXIMO = 30 };
        vector<Elemento> _datos;
        int _capacidad;
        int _encima; // Posición del elemento de encima (el top) de la pila
};

#endif // PILA_ESTATICA_H
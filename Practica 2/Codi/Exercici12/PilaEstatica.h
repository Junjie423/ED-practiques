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
        PilaEstatica(initializer_list<Elemento> elementos); //Inicializa la pila con una lista de elementos
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

// Constructores
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(int max){
    this->_datos.reserve(max);
    this->_capacidad = max;
    this->_encima = 0;
}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(const PilaEstatica &original){
    for (vector<Elemento>::iterator itr = original._datos.begin(); itr != original._datos.end(); ++itr){
        this->_datos = original._datos[itr];
    }
    this->_capacitat = original._capacidad;
    this->_encima = original._encima;
}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(initializer_list<Elemento> elementos){
    for (int i = 0; i < elementos.size(); ++i){
        this->_datos[i] = elementos[i];
    }
    this->_capacitat = elementos.size();
    this->_encima = 0;
}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(const vector<Elemento>& elementos){
    for (vector<Elemento>::iterator itr = elementos.begin(); itr != elementos.end(); ++itr){
        this->_datos = elementos[itr];
    }
    this->_capacitat = elementos.size();
    this->_encima = elementos.begin();
}

template <class Elemento> int PilaEstatica<Elemento>::tamano() const{
    return this._datos.size();
}
template <class Elemento> bool PilaEstatica<Elemento>::estaVacia() const{
    if(this->_datos.empty()){
        return true;
    }
    return false;
}
template <class Elemento> bool PilaEstatica<Elemento>::estaLlena() const{
    if(this->_datos)
}
template <class Elemento> const Elemento& PilaEstatica<Elemento>::elementoEncima() const{
    if(this->estaVacia()){
        throw new out_of_range("La pila està buida");
    } else{
        cout << this->_datos[_encima] << endl;
    }
}

template <class Elemento> void PilaEstatica<Elemento>::anadirElemento(const Elemento &e){
    if(this->estaLlena()){
        throw new out_of_range("La pila està plena");
    } else{
        this._datos.insert(0,e);
    }
}
template <class Elemento> void PilaEstatica<Elemento>::suprimirElemento(){
    if(this.estaVacia()){
        throw new out_of_range("La pila està buida");
    } else{
        this->_datos.erase(this._encima)
        this->_encima++;
    }
}

template <class Elemento> void PilaEstatica<Elemento>::print() const{
    for(int i = 0; i < this->tamano(); ++i){
        cout << this->_datos[i] << endl;
    }
}

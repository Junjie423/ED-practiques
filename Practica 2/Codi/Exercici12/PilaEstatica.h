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

// Constructores
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(int max){
    this->_datos.reserve(max);
    this->_capacidad = max;
    this->_encima = -1;
}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(const PilaEstatica &original){
    this->_datos.reserve(original._capacidad);
    for (typename vector<Elemento>::const_iterator itr = original._datos.begin(); itr != original._datos.end(); ++itr){
        this->_datos.push_back(*itr);
    }
    this->_capacidad = original._capacidad;
    this->_encima = original._encima;
}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(initializer_list<Elemento> elementos){
    this->_capacidad = elementos.size();
    this->_encima = -1;
    this->_datos.reserve(this->_capacidad);
    for (typename initializer_list<Elemento>::const_iterator itr = elementos.begin(); itr != elementos.end(); ++itr){
        this->_datos.push_back(*itr);
        this->_encima++;
    }
}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(const vector<Elemento>& elementos){
    this->_capacidad = elementos.size();
    this->_encima = -1;
    this->_datos.reserve(this->_capacidad);
    for (typename vector<Elemento>::const_iterator itr = elementos.begin(); itr != elementos.end(); ++itr){
        this->_datos.push_back(*itr);
        this->_encima++;
    }
    
}
// Mètodos
template <class Elemento> int PilaEstatica<Elemento>::tamano() const{
    return this->_encima+1;
}
template <class Elemento> bool PilaEstatica<Elemento>::estaVacia() const{
    return this->_encima == -1;
}
template <class Elemento> bool PilaEstatica<Elemento>::estaLlena() const{
    return (this->_encima + 1) == this->_capacidad;
}
template <class Elemento> const Elemento& PilaEstatica<Elemento>::elementoEncima() const{
    if(this->estaVacia()){
        throw out_of_range("L'estructura està buida");
    } else{
        return this->_datos[this->_encima];
    }
}

template <class Elemento> void PilaEstatica<Elemento>::anadirElemento(const Elemento &e){
    if(this->estaLlena()){
        throw out_of_range("L'estructura està plena");
    } else{
        this->_datos.push_back(e);
        this->_encima++;
    }
}
template <class Elemento> void PilaEstatica<Elemento>::suprimirElemento(){
    if(this->estaVacia()){
        throw out_of_range("L'estructura està buida");
    } else{
        this->_datos.pop_back();
        this->_encima--;
    }
}

template <class Elemento> void PilaEstatica<Elemento>::print() const{
    if (!estaVacia()){
        cout << "[";
        typename vector<Elemento>::const_iterator itr = this->_datos.begin();
        for (; itr < this->_datos.end()-1; ++itr){
            cout << *itr << ", ";
        
        }
        cout << *itr << "]";
    } else{
        cout << "[]";
    }
}

#endif // PILA_ESTATICA_H
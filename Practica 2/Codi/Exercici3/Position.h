// Autor: Junjie Zhou

#ifndef POSITION_H
#define POSITION_H
#include "NodeList.h"
#include <stdexcept>
using namespace std;

template <class Element> class Position{

public:
    Position(NodeList<Element>* node); //inicialitza la classe Position amb el node que rep com a paràmetre.
    Position(const Position& origen);
    virtual ~Position();
    Position<Element> next() const; //retorna la següent posició a l’actual.
    // No es modifica el contingut de l’actual posició.
    // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.
    Position<Element> previous() const; // retorna l’anterior posició
    const Element& element() const; // retorna el contingut de l’actual posició
    NodeList<Element>* deletePosition();
    void setPrevious(NodeList<Element>* node); // assigna l’adreça de l’anterior node
    void setNext(NodeList<Element>* node); // assigna l’adreça del següent node
    Position<Element> operator++() const; // sobrecarrega operador ++
    Position<Element> operator--() const; // sobrecarrega operador --
    bool operator==(const Position<Element> & other) const; // sobrecarrega operador ==
    bool operator!=(const Position<Element> & other) const; // sobrecarrega operador !=
    const Element& operator*() const; // sobrecarrega operador contingut
private:
    NodeList<Element> * _node;
};

// Constructor
template <class Element> Position<Element>::Position(NodeList<Element>* node){
    this->_node = node;
}

template <class Element> Position<Element>::Position(const Position& origen){
    this->_node = origen._node;
}

template <class Element> Position<Element>::~Position(){
    this->_node = nullptr;
}

// Mètodes
template <class Element> Position<Element> Position<Element>::next() const{
    // Si no apunta a cap node o el seguent no apunta a res 
    if (this->_node == nullptr || this->_node->accessNext() == nullptr){
        throw out_of_range("No existeix següent posició");
    }
    return Position<Element> (this->_node->accessNext());
}

template <class Element> Position<Element> Position<Element>::previous() const{
    // Si no apunta a res o el anterior no apunta res
    if (this->_node == nullptr || this->_node->accessPrevious() == nullptr){
        throw out_of_range("No existeix anterior posició");
    }
    return Position<Element> (this->_node->accessPrevious());
}

template <class Element> const Element& Position<Element>::element() const{
    // Si no apunta a cap node
    if (this->_node == nullptr){
        throw runtime_error("No hi ha element en aquesta posició");
    }
    return this->_node->accessElement();
}

template <class Element> NodeList<Element>* Position<Element>::deletePosition(){ //Desconectar
    if (this->_node == nullptr){
        throw runtime_error("No hi ha element per eliminar");
    }
    
    // Creem dues NodeList que apunten el següent i el anterior node
    NodeList<Element>* seg = this->_node->accessNext();
    NodeList<Element>* ant = this->_node->accessPrevious();

    // Ara fem que el anterior i el següent s'apuntin saltant el _node
    // Si hi ha següent (no es null)A <-> B <-> C
    if (seg != nullptr){
        seg->setPrevious(ant);
    }
    // Si hi ha anterior (no es null). C <-> A ; A <- B -> C
    if (ant != nullptr){ 
        ant->setNext(seg);
    }       this->_node;
    
    this->_node->setNext(nullptr);
    this->_node->setPrevious(nullptr);
    //C <-> A 

    return this->_node;
}

template <class Element> void Position<Element>::setPrevious(NodeList<Element>* node){
    if (node == nullptr || this->_node == nullptr){
        throw runtime_error("No hi ha cap node apuntat");
    }
    // A <- B
    this->_node->setPrevious(node);
    //  A <-> B
    node->setNext(this->_node);    
}

template <class Element> void Position<Element>::setNext(NodeList<Element>* node){
    if (node == nullptr || this->_node == nullptr){
        throw runtime_error("No hi ha cap node apuntat");
    }
    // A -> B 
    this->_node->setNext(node);
    //  A <-> B 
    node->setPrevious(this->_node);

}

template <class Element> Position<Element> Position<Element>::operator++() const{
    return this->next();
}

template <class Element> Position<Element> Position<Element>::operator--() const{
    return this->previous();
}

template <class Element> bool Position<Element>::operator==(const Position<Element> & other) const{
    return this->_node == other._node;
}

template <class Element> bool Position<Element>::operator!=(const Position<Element> & other) const{
    return this->_node != other._node;
}

template <class Element> const Element& Position<Element>::operator*() const{
    return this->element();
}
#endif // POSITION_H
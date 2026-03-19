// Autor: Junjie Zhou

#ifndef POSITION_H
#define POSITION_H
#include <NodeList.h>
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
    if (this->_node == nullptr || this->_node->accessNext() == nullptr){
        throw new out_of_range("No existeix següent posició");
    }
    return this->_node->accesNext();
}

template <class Element> Position<Element> Position<Element>::previous() const{
    if (this->_node == nullptr || this->_node->accessPrevious() == nullptr){
        throw new out_of_range("No existeix anterior posició");
    }
    return this->_node->accessPrevious();
}

template <class Element> const Element& Position<Element>::element() const{
    if (this->_node == nullptr){
        throw new runtime_error("No hi ha element en aquesta posició");
    }
    return this->_node->accesElement();
}

template <class Element> NodeList<Element>* Position<Element>::deletePosition(){
    if (this->_node == nullptr){
        throw new runtime_error("No hi ha element per eliminar");
    }
    // Creem un auxiliar per apuntar el node que s'eliminarà, per després retornar-ho
    NodeList<Element>* eliminat = this->_node;
    // Creem dues NodeList que apunten el següent i el anterior node
    NodeList<Element>* seg = this->_node->accessNext();
    NodeList<Element>* ant = this->_node->accessPrevious();

    // Ara fem que el anterior i el següent s'apuntin saltant el _node
    // Si hi ha següent (no es null)
    if (seg != nullptr){
        seg->setPrevious(ant);
    }
    // Si hi ha anterior (no es null)
    if (pre != nullptr){
        pre->setNext(seg);
    }
    // Ara _node aurà d'apuntar el següent (però si no hi ha el anterior)
    // Així hem eliminat el node que apunta _node de la llista
    if (seg != nullptr){
        this->_node = seg;
    } else{
        this->_node = ant;
    }
    return eliminat;
}

template <class Element> void Position<Element>::setPrevious(NodeList<Element>* node){
    if(this->_node != nullptr){
        this->_node->setPrevious(node);
    }
}

template <class Element> void Position<Element>::setNext(NodeList<Element>* node){
        if(this->_node != nullptr){
        this->_node->setNext(node);
    }
}

template <class Element> Position<Element> Position<Element>::operator++() const{
    return this->next();
}

template <class Element> Position<Element> Position<Element>::operator--() const{
    return this->previous();
}

template <class Element> bool Position<Element>::operator==(const Position<Element> & other) const{
    return this->_node == other->_node;
}

template <class Element> bool Position<Element>::operator!=(const Position<Element> & other) const{
    return this->_node != other->_node;
}

template <class Element> const Element& Position<Element>::operator*() const{
    return this->element();
}
#endif // POSITION_H
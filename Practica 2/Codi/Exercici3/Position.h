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
template <class Element> Position<Element>::Position(NodeList<Element>* node){}

template <class Element> Position<Element>::Position(const Position& origen){}

template <class Element> Position<Element>::~Position(){}

template <class Element> Position<Element> Position<Element>::next() const{}

template <class Element> Position<Element> Position<Element>::previous() const{}

template <class Element> const Element& Position<Element>::element() const{}

template <class Element> NodeList<Element>* Position<Element>::deletePosition(){}

template <class Element> void Position<Element>::setPrevious(NodeList<Element>* node){}

template <class Element> void Position<Element>::setNext(NodeList<Element>* node){}

template <class Element> Position<Element> Position<Element>::operator++() const{}

template <class Element> Position<Element> Position<Element>::operator--() const{}

template <class Element> bool Position<Element>::operator==(const Position<Element> & other) const{}

template <class Element> bool Position<Element>::operator!=(const Position<Element> & other) const{}

template <class Element> const Element& Position<Element>::operator*() const{}
#endif // POSITION_H
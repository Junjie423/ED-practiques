// Autor: Junjie Zhou

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "NodeList.h"
#include "Position.h"
#include <iostream>
#include <initializer_list>
using namespace std;

template <class Element> class LinkedList{

public:
    LinkedList();
    LinkedList(initializer_list<Element> elements);
    LinkedList(const LinkedList& origen);
    virtual ~LinkedList();
    int size() const;
    bool isEmpty() const;
    Position<Element> beginning() const; // return first position
    Position<Element> end() const; // return last position
    void insertAfter(Position<Element>& position, const Element& element);
    void insertBefore(Position<Element>& position, const Element& element);
    void insertBeginning(const Element& element);
    void insertEnd(const Element& element);
    void deletePosition(Position<Element>& position);
    void print() const;
private:   
    NodeList<Element>* _head;
    NodeList<Element>* _tail;
    int _size;
};

// Constructors
template <class Element> LinkedList<Element>::LinkedList(){
    this->_head = new NodeList<Element>(); // Fantasma
    this->_tail = new NodeList<Element>(); // Fantasma
    //A<->B
    this->_head->setNext(this->_tail);
    this->_tail->setPrevious(this->_head);
    this->_size = 0;
    
}

template <class Element> LinkedList<Element>::LinkedList(initializer_list<Element> elements){
    this->_head = new NodeList<Element>();
    this->_tail = new NodeList<Element>();
    //A<->B
    this->_head->setNext(this->_tail);
    this->_tail->setPrevious(this->_head);
    this->_size = 0;

    for(typename initializer_list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr){
        this->insertEnd(*itr);
    }
}

template <class Element> LinkedList<Element>::LinkedList(const LinkedList& origen){
    this->_head = new NodeList<Element>();
    this->_tail = new NodeList<Element>();
    //A<->B
    this->_head->setNext(this->_tail);
    this->_tail->setPrevious(this->_head);
    this->_size = 0;

    for(Position<Element> itr = origen.beginning(); itr != origen.end(); itr = ++itr){
        this->insertEnd(*itr);
    }
}

template <class Element> LinkedList<Element>::~LinkedList(){
    while(!(this->isEmpty())){
        Position<Element> aux = this->beginning();
        this->deletePosition(aux); 
    }
    delete _head;
    delete _tail;
}

// Mètodos
template <class Element> int LinkedList<Element>::size() const{
    return this->_size;
}

template <class Element> bool LinkedList<Element>::isEmpty() const{
    return this->_size == 0;
}

template <class Element> Position<Element> LinkedList<Element>::beginning() const{
    Position<Element> inici (this->_head);
    return ++inici; // El següent del fantasm
}

template <class Element> Position<Element> LinkedList<Element>::end() const{
    Position<Element> fin (this->_tail);
    return fin;
}

template <class Element> void LinkedList<Element>::insertAfter(Position<Element>& position, const Element& element){
    // A <-> C     B
    // A <-> B <-> C
    NodeList<Element>* nou = new NodeList<Element>(element);
    position.next().setPrevious(nou);// B <-> C
    // Si next es nullptr vol dir que posicio es fantasma, i no es pot inserir després de fantasma
    position.setNext(nou); // A <-> B
    this->_size ++;
}

template <class Element> void LinkedList<Element>::insertBefore(Position<Element>& position, const Element& element){
    // A <-> C     B
    // A <-> B <-> C
    NodeList<Element>* nou = new NodeList<Element>(element);
    position.previous().setNext(nou);// A <-> B
    // Si previous es nullptr vol dir que posicio es fantasma, i no es pot inserir abans de fantasma
    position.setPrevious(nou); // B <-> C
    this->_size ++;
}

template <class Element> void LinkedList<Element>::insertBeginning(const Element& element){
    // F <-> B     A
    // F <-> A <-> B
    Position<Element> inici = this->beginning();
    this->insertBefore(inici, element);        
}

template <class Element> void LinkedList<Element>::insertEnd(const Element& element){
    Position<Element> fin = this->end();
    this->insertBefore(fin, element);
}

template <class Element> void LinkedList<Element>::deletePosition(Position<Element>& position){
    //if (position == end() || position == (--beginning())){
    //    throw runtime_error("No es pot eliminar el fantasma");
    //}
    delete position.deletePosition();
    this->_size --;
}
template <class Element> void LinkedList<Element>::print() const{
    if(this->isEmpty()){
        cout << "La llista està buida" << endl;
    } else{
        for (Position<Element> itr = this->beginning(); itr != this->end(); itr = ++itr){
            cout << *itr << endl;
        }
    }
    cout << endl;
    /*
    Una manera més bonica per fer print de la llista, diferent del exemple de sortida 
    que ens dona en el casProva2 de l'ex3.

    if (isEmpty()){
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    auto it = beginning();
    for(; it != --end(); it = ++it) cout << *it << ", ";
    cout << *it << "]"<< endl;

    */
}

#endif // LINKED_LIST_H
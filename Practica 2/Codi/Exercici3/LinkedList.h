// Autor: Junjie Zhou

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <NodeList.h>
#include <Position.h>
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
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
    
}

template <class Element> LinkedList<Element>::LinkedList(initializer_list<Element> elements){
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
    for(typename initializer_list<Element>::const_iterator itr = elements.beginning(); itr != elements.end(); ++itr){
        this->insertEnd(*itr);
    }
}

template <class Element> LinkedList<Element>::LinkedList(const LinkedList& origen){
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
    for(typename Position<Element> itr = origen.beginning(); itr != origen.end(); ++itr){
        this->insertEnd(*itr);
    }
}

template <class Element> LinkedList<Element>::~LinkedList(){
    while(this->!isEmpty()){
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
    return this->_size() == 1;
}

template <class Element> Position<Element> LinkedList<Element>::beginning() const{
    Position<Element> inici = this->_head;
    return inici;
}

template <class Element> Position<Element> LinkedList<Element>::end() const{
    Position<Element> fin = this->_tail;
    return fin;
}

template <class Element> void LinkedList<Element>::insertAfter(Position<Element>& position, const Element& element){

}

template <class Element> void LinkedList<Element>::insertBefore(Position<Element>& position, const Element& element){

}

template <class Element> void LinkedList<Element>::insertBeginning(const Element& element){

}

template <class Element> void LinkedList<Element>::insertEnd(const Element& element){

}

template <class Element> void LinkedList<Element>::deletePosition(Position<Element>& position){

}

template <class Element> void LinkedList<Element>::print() const{

}

#endif // LINKED_LIST_H
// Autor: Junjie Zhou

#ifndef NODELIST_H
#define NODELIST_H


template <class Element> class NodeList{

public:
    NodeList(); // inicialitza NodeList per defecte
    NodeList(const Element elem); // inicialitza amb l'element que rep com a paràmetre
    NodeList(const NodeList<Element> &original); // constructor còpia
    ~NodeList(); // destructor 
    const Element& accessElement() const; // retorna l’element que hi ha guardat al node
    NodeList<Element>* accessNext() const; // retorna l'adreça del següent node o nullptr en cas que no hi hagi següent
    void setNext(NodeList<Element>* node); // modifica l'adreça de _next per l’adreça rebuda com a paràmetre
    NodeList<Element>* accessPrevious() const; // retorna l'adreça del node anterior o nullptr en cas que no hi hagi terior
    void setPrevious(NodeList<Element>* node); // modifica l'adreça de _previous per l'adreça rebuda com a paràmetre

private:
    Element _element;
    NodeList<Element>* _previous;
    NodeList<Element>* _next;
};
// Constructor
template <class Element> NodeList<Element>::NodeList(){
    this->_previous = nullptr;
    this->_next = nullptr;
}

template <class Element> NodeList<Element>::NodeList(const Element elem){
    this->_element = elem;
    this->_previous = nullptr;
    this->_next = nullptr;
}

template <class Element> NodeList<Element>::NodeList(const NodeList<Element> &original){
    this->_element = original.accessElement();
    this->_previous = nullptr;
    this->_next = nullptr;
}

template <class Element> NodeList<Element>::~NodeList(){} // No cal fer res

// Mètodes
template <class Element> const Element& NodeList<Element>::accessElement() const{
    return this->_element;
}

template <class Element> NodeList<Element>* NodeList<Element>::accessNext() const{
    return this->_next;
}

template <class Element> void NodeList<Element>::setNext(NodeList<Element>* node){
    this->_next = node;
}

template <class Element> NodeList<Element>* NodeList<Element>::accessPrevious() const{
    return this->_previous;
}

template <class Element> void NodeList<Element>::setPrevious(NodeList<Element>* node){
    this->_previous = node;
}

#endif // NODE_LIST_H

// Autor: Junjie Zhou

#ifndef NODE_:LIST_H
#define NODE_LIST_H
using namespace std;

template <class Element> class NodeList{

public:
    NodeList(); // inicialitza NodeList per defecte
    NodeList(const Element elem); // inicialitza amb l'element que rep com a paràmetre
    NodeList(const NodeList<Element> &original); // constructor còpia
    ~NodeList(); // destructor 
    Element& accessElement() const; // retorna l’element que hi ha guardat al node
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

}

template <class Element> NodeList<Element>::NodeList(const Element elem){
    
}

template <class Element> NodeList<Element>::NodeList(const NodeList<Element> &original){
   
}

template <class Element> NodeList<Element>::~NodeList(){}

// Mètodes
template <class Element> Element& NodeList<Element>::accessElement() const{}

template <class Element> NodeList<Element>* NodeList<Element>::accessNext() const{}

template <class Element> NodeList<Element>* NodeList<Element>::accessPrevious() const{}

template <class Element> void NodeList<Element>::setNext(NodeList<Element>* node){}

template <class Element> void NodeList<Element>::setPrevious(NodeList<Element>* node){}

#endif // NODE_LIST_H

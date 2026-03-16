// Autor: Junjie Zhou

#ifndef NODE_:LIST_H
#define NODE_LIST_H
using namespace std;

template <class Element> class NodeList{

public:
    NodeList(); // inicialitza NodeList per defecte
    NodeList(const Element); // inicialitza amb l'element que rep com a paràmetre
    NodeList(const NodeList &original); // constructor còpia
    ~NodeList(); // destructor 
    Element& accesElement() const;

private:
    Element _element;
    int _previous;
    int _next;
};

#endif // NODE_LIST_H
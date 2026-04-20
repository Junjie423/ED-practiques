#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTree.h"
#include "Position.h"
#include <vector>
#include <iostream>
using namespace std;

template <class Key, class Value>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree<Key, Value>& orig);
    virtual ~BinaryTree();
    bool isEmpty() const;
    Position<Key, Value>* getRoot() const;
    int size() const;
    int height() const;
    virtual Position<Key, Value>* insert(const Key& key, const Value& value);
    bool contains(const Key& key) const;
    Position<Key, Value>* search(const Key& key) const;
    const vector<Value>& getValues(const Key& key) const;
    void printPreOrder(const Position<Key, Value> *node = nullptr) const;
    void printPostOrder(const Position<Key, Value> *node = nullptr) const;
    bool identicalTree(const BinaryTree<Key, Value>& other) const;
    
protected:
    Position<Key, Value>* root;
private:
    int _size;
    /* Mètodes auxiliars definiu aquí els que necessiteu */    
}; 

// Constructors
template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(){
    this->root = nullptr;
    this->_size = 0;
}

template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(const BinaryTree<Key, Value>& orig){
    this->root = new Postion<Key, Value> (orig->getRoot());
    this->_size = orig->size();
}

// Destructor
template <class Key, class Value> BinaryTree<Key, Value>::~BinaryTree(){
    // Cal omplir
}

// Consultors
template <class Key, class Value> bool BinaryTree<Key, Value>::isEmpty() const{
    return this->_size == 0;
}

template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::getRoot() const{
    return this->root;
}

template <class Key, class Value> int BinaryTree<Key, Value>::size() const{
    return this->_size;
}

/* Mapa mental
              02
        /             \        
      00              08  
   /      \        /      \
  --      --      05      45
 /  \    /  \    /  \    /  \ 
--  --  --  --  03  --  40  76 
*/
template <class Key, class Value> bool BinaryTree<Key, Value>::contains(const Key& key) const{
    if(this->root == nullptr){
        throw out_of_range("No hi ha cap element a l'arbre");
    }
    Position<Key, Value>* actual = this->root;
    bool trobat = false;
    while(!trobat && !actual != nullptr){
        if (actual->getKey() > key){
            actual = actual->left();
        }
        else if (actual->getKey() < key){
            actual = actual->right();
        }
        else{
            trobat = true;
        }
    }
    return trobat;
}

template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::search(const Key& key) const{

}

template <class Key, class Value> const vector<Value>& BinaryTree<Key, Value>:: getValues(const Key& key) const{

}

// Modificador
template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::insert(const Key& key, const Value& value){
    Position<Key, Value>*itr = this->root;
    bool dret = true;
    while(itr != nullptr){
        if (itr->getKey() > key){
            itr = itr->left();
            dret = false;
        }
        if (itr->getKey() < key){
            itr = itr->right();
            dret = true;
        }
    }
    Position<Key, Value> nou = new Position<Key, Value>(key);
    nou->addValue(value);
    nou->setParent(itr);
    nou->setLeft(nullptr);
    nou->setRight(nullptr);
    if(dret){
        itr->setRight(nou);
    } else{
        itr->setLeft(nou);
    }
    return itr;
}

// Operadors
template <class Key, class Value> void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value> *node = nullptr) const{

}

template <class Key, class Value> void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value> *node = nullptr) const{

}

template <class Key, class Value> bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const{
    
}
    
#endif // BINARYTREE_H
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTree.h"
#include "Position.h"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template <class Key, class Value>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree<Key, Value>& orig);
    virtual ~BinaryTree();
    bool isEmpty() const; // O(1)
    Position<Key, Value>* getRoot() const; // O(1)
    int size() const; // O(1)
    int height() const;  //
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
    void rec_BinaryTree(const Position<Key, Value>* orig, Position<Key, Value>* actual);
    int rec_height(const Position<Key, Value>* act, int& num);
    Position<Key, Value>* rec_search(Position<Key, Value>* act, Key& key);
    void rec_preOrdre(Position<Key, Value>* act) const;
    void rec_postOrdre(Position<Key, Value>* act) const;
    bool rec_identicalTree(Position<Key, Value>* node1, Position<Key, Value>* node2) const;

    // Mètodes auxiliars
    
}; 

// Constructors
template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(){
    this->root = nullptr;
    this->_size = 0;
}

template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(const BinaryTree<Key, Value>& orig){
    this->_size = 0;
    this->root = new Position<Key, Value> (orig.getRoot()->getKey());
    this->_size++;
    rec_BinaryTree(orig.getRoot(), this->root);
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

/*template <class Key, class Value> int BinaryTree<Key, Value>::height() const{
    
}
*/

/*
      02
    /      \        
   00      08  
        /      \
       05      45
       /       /  \ 
      03      40  76  
*/
template <class Key, class Value> bool BinaryTree<Key, Value>::contains(const Key& key) const{
    if(this->root == nullptr){   // També es pot fer if (this->isEmpty())
        throw out_of_range("No hi ha cap element a l'arbre");
    }
    Position<Key, Value>* actual = this->root;
    bool trobat = false;
    while(!trobat && actual != nullptr){
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
    if(this->isEmpty()){
        throw out_of_range("L'arbre està buit");
    }
    return rec_search(this->root, key);
}

template <class Key, class Value> const vector<Value>& BinaryTree<Key, Value>:: getValues(const Key& key) const{
    Position<Key, Value>* trobat = search(key);
    if(trobat == nullptr){
        throw out_of_range("No s'ha trobat la clau");
    }
    return trobat->getValues();
}

// Modificador
template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::insert(const Key& key, const Value& value){
    Position<Key, Value>* itr = this->root;
    Position<Key, Value>* itrPare = nullptr;
    bool trobat = false;
    bool dret = false;
    while(itr != nullptr && !trobat){
        if (itr->getKey() > key){
            itrPare = itr;
            itr = itr->left();
            dret = false;
        } else if (itr->getKey() < key){
            itrPare = itr;
            itr = itr->right();
            dret = true;
        } else{
            trobat = true;
        }
    }
    if(trobat){
        itr->addValue(value);
    } else{
        this->_size++;
        Position<Key, Value>*nou = new Position<Key,Value>(key);
        nou->addValue(value);
        if(this->root == nullptr){
            this->root = nou;
            return this->root;
        }
        nou->setParent(itrPare);
        if(dret){
            itrPare->setRight(nou);
        } else{
            itrPare->setLeft(nou);
        }
    }
    return itr;
}

// Operadors
template <class Key, class Value> void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value> *node) const{
    if (this->root == nullptr){
        throw out_of_range("L'arbre està buit");
    }
    rec_preOrdre(this->root);
}

template <class Key, class Value> void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value> *node) const{
    if (this->root == nullptr){
        throw out_of_range("L'arbre està buit");
    }
    rec_postOrdre(this->root);

}

template <class Key, class Value> bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const{
    return rec_identicalTree(this->root, other.getRoot());
}   

// Mètodes auxiliars
template <class Key, class Value> void BinaryTree<Key, Value>::rec_BinaryTree(const Position<Key, Value>* orig, Position<Key, Value>* actual){
    for (Value v : orig->getValues()){
            actual->addValue(v);
    }

    Position<Key, Value>* left = orig->left();
    Position<Key, Value>* right = orig->right();

    if (right != nullptr){
        Position<Key, Value>* dret = new Position<Key, Value>(right->getKey());
        actual->setRight(dret);
        dret->setParent(actual);
        this->_size++;
        rec_BinaryTree(right,dret);
    }

    if (left != nullptr){
        Position<Key, Value>* esq = new Position<Key, Value>(left->getKey());
        actual->setLeft(esq);
        esq->setParent(actual);
        this->_size++;
        rec_BinaryTree(left,esq);
    }
}


template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::rec_search(Position<Key, Value>* act, Key& key){
    while (act != nullptr){
        if (act->getKey() > key){
            rec_search(act->left(), key);
        } else if (act->getKey() < key){
            rec_search(act->right(), key);
        } else{
            return act;
        }
    }
    return act;
}

template <class Key, class Value> void BinaryTree<Key, Value>::rec_preOrdre(Position<Key, Value>* act) const{
    if(act == nullptr){
        return;
    }
    cout << act->getKey() << " ";
    rec_preOrdre(act->left());
    rec_preOrdre(act->right());
}

template <class Key, class Value> void BinaryTree<Key, Value>::rec_postOrdre(Position<Key, Value>* act) const{
    if(act == nullptr){
        return;
    }
    rec_postOrdre(act->left());
    rec_postOrdre(act->right());
    cout << act->getKey() << " ";
}
template <class Key, class Value> bool BinaryTree<Key, Value>::rec_identicalTree(Position<Key, Value>* node1, Position<Key, Value>* node2) const{
    if (node1 == nullptr && node2 == nullptr){
        return true;
    }
    if (node1 == nullptr || node2 == nullptr){
        return false;
    }
    if (node1->getKey() != node2->getKey() || node1->getValues() != node2->getValues()){
        return false;
    }
    return rec_identicalTree(node1->left(), node2->left()) && rec_identicalTree(node1->right(), node2->right());
}

#endif // BINARYTREE_H
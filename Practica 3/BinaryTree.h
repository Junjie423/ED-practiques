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
    Position<Key, Value>* rec_search(Position<Key, Value>* act, Key& key);
    void rec_preOrdre(Position<Key, Value>* act) const;
    void rec_postOrdre(Position<Key, Value>* act) const;
}; 

// Constructors
template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(){
    this->root = nullptr;
    this->_size = 0;
}

template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(const BinaryTree<Key, Value>& orig){
    this->root = new Position<Key, Value> (orig.getRoot());
    this->_size = orig.size();
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

/*
      02
    /      \        
   00      08  
        /      \
       05      45
       /       /  \ 
      03      40  76  



go(Node n){
    n.print();   → Preordre
    go(Left);    ← recursivitat
    n.print();   → Inordre
    go(Right);   ← recursivitat
    n.print();   → Postordre
    }
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
    Position<Key, Value>*itr = this->root;
    Position<Key, Value>*itrPare = nullptr;
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
        nou->setPare(itrPare);
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
    rec_preOrdre(this->root);

}

template <class Key, class Value> bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const{
    return false;
}

// Mètodes auxiliars
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
    cout << act->getKey() << endl;
    rec_preOrdre(act->left());
    rec_preOrdre(act->right());
}

template <class Key, class Value> void BinaryTree<Key, Value>::rec_postOrdre(Position<Key, Value>* act) const{
    if(act == nullptr){
        return;
    }
    rec_preOrdre(act->left());
    rec_preOrdre(act->right());
    cout << act->getKey() << endl;
}
#endif // BINARYTREE_H
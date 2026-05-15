#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "BinaryTree.h"
#include "Position.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <class Key, class Value>
class BalancedTree : public BinaryTree<Key, Value> {
public:
    // Constructor
    BalancedTree();
    BalancedTree(const BalancedTree<Key, Value>& orig);
    // Destructor
    virtual ~BalancedTree();

    // Mètodes
    Position<Key, Value>* insert(const Key& key, const Value& value);
private:
    /* Les rotacions, definiu-les aquí sota */
    void rotacio();
    void act_height(Position<Key,Value>* node);
    void dret_simple(Position<Key, Value>* node);
    void esq_simple(Position<Key, Value>* node);
    void dret_esq(Position<Key, Value>* node);
    void esq_dret(Position<Key, Value>* node);
};


// Constructors
template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree():
    BinaryTree<Key, Value>()
{}

template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree(const BalancedTree<Key, Value>& orig){
    BinaryTree<Key, Value>(orig);
}

// Destructor
template <class Key, class Value> BalancedTree<Key, Value>::~BalancedTree(){} // No cal modificar

// Mètodes
template <class Key, class Value> Position<Key, Value>* BalancedTree<Key, Value>::insert(const Key& key, const Value& value){
    BinaryTree<Key, Value>::insert(key, value);
}
//h.dret - h.esquerra 
    /*  Esquerra
        a                   
         \                  b     
          b     --->      /  \
         / \             a    c
            c             \
    */
    /*  Dreta
            c      
           /                b     
          b     --->      /  \
         / \             a    c
        a                    /
    */
    /*  Dreta-Esquerra
        a              a 
         \              \                   b     
          c     --->    b       --->      /  \
         /                \               a    c
        b                 c                                       
                          
    */
    /*  Esquerra-Dreta
         c               c  
       /                /                  b     
      a        --->    b       --->      /  \
       \              /                 a    c
        b            a                 
    */

template <class Key, class Value> void BalancedTree<Key, Value>::rotacio(){
    
}

template <class Key, class Value> void BalancedTree<Key, Value>::act_height(Position<Key, Value>* node){
    // Cas de que node sigui null no fem res:
    if (node == nullptr){
        return;
    }
    // Creem dos variables per guardar l'altura dels fills (si existeixen). En cas de no tenir algun fill assignar 0
    int h_left, h_right;
    if (node->left() == nullptr){
        h_left = 0;
    } else{
        h_left = node->left()->getHeight();
    }
    if (node->right() == nullptr){
        h_right = 0;
    } else{
        h_right = node->right()->getHeight();
    }
    // Actualitzem l'altura del node introduït com a parametre
    node->setHeight(max(h_left, h_right)+1);
}

template <class Key, class Value> void BalancedTree<Key, Value>::dret_simple(Position<Key, Value>* node){
// Cas de que l'arrel està desequilibrada

}

template <class Key, class Value> void BalancedTree<Key, Value>::esq_simple(Position<Key, Value>* node){

}
template <class Key, class Value> void BalancedTree<Key, Value>::dret_esq(Position<Key, Value>* node){

}

template <class Key, class Value> void BalancedTree<Key, Value>::esq_dret(Position<Key, Value>* node){

}

#endif // BALANCEDTREE_H
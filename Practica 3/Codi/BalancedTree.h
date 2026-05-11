#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "BinaryTree.h"
#include "Position.h"
#include <vector>
#include <iostream>
#include <stdexcept>

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
    void dreta_simple();
    void esq_simple();
};


// Constructors
template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree(){

}

template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree(const BalancedTree<Key, Value>& orig){

}

// Destructor
template <class Key, class Value> BalancedTree<Key, Value>::~BalancedTree(){

}

// Mètodes
template <class Key, class Value> Position<Key, Value>* BalancedTree<Key, Value>::insert(const Key& key, const Value& value){

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

template <class Key, class Value> void BalancedTree<Key, Value>::dreta_simple(){

}

template <class Key, class Value> void BalancedTree<Key, Value>::esq_simple(){

}

#endif // BALANCEDTREE_H
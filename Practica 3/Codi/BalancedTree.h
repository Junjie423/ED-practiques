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
    void rotacio(Position<Key,Value>* node,Position<Key,Value>* net, int factor);
    int act_height_balance(Position<Key,Value>* node); // Retorna balance-factor
    void dret_simple(Position<Key, Value>* node);
    void esq_simple(Position<Key, Value>* node);
};


// Constructors
template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree():
    BinaryTree<Key, Value>()
{}

template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree(const BalancedTree<Key, Value>& orig):
    BinaryTree<Key, Value>(orig)
{}

// Destructor
template <class Key, class Value> BalancedTree<Key, Value>::~BalancedTree(){} // No cal modificar

// Mètodes
template <class Key, class Value> Position<Key, Value>* BalancedTree<Key, Value>::insert(const Key& key, const Value& value){
    // Creem un punter que apunta el nou node insertat
    Position<Key, Value>*node_nou = BinaryTree<Key, Value>::insert(key, value);


    if (node_nou == this->getRoot() || node_nou->parent() == this->getRoot()) return node_nou;
    
    // Iterem cap a dalt per actualitzar les altures dels antecedents i comprovem que el balaced factor no sigui 2 o -2
    Position<Key, Value>*iterator = node_nou->parent()->parent();
    Position<Key, Value>*iterator_fill= node_nou->parent();
    Position<Key, Value>*iterator_net = node_nou;
    
    int bf = 0;
    int none; // Només serveix per actualitzar l'altura del fill, no s'utilitzarà el seu balanced factor (el pare del node nou mai estarà desequilibrat)
    // Mentre l'alfa (iterator) no sigui nullptr
    while(iterator == nullptr){
        // Actualitzem l'altura del fill i de l'alfa i calculem el balanced factor de l'alfa
        none = act_height_balance(iterator_fill);
        bf = act_height_balance(iterator);
        // Cridem a la funcio rotacio amb el alfa, el node net i el balanced factor de l'alfa
        rotacio(iterator, iterator_net, bf);

        // Pujem
        iterator_net = iterator_fill;
        iterator_fill = iterator;
        iterator = iterator->parent();
    }

    return node_nou;
 }
//h.dret - h.esquerra 
    /*  Esquerra (factor = -2)
        a                   
         \                  b     
          b     --->      /  \
         / \             a    c
            c             \
    */
    /*  Dreta (factor = 2)
            c      
           /                b     
          b     --->      /  \
         / \             a    c
        a                    /
    */
    /*  Dreta-Esquerra (factor = -2)
        a              a 
         \              \                   b     
          c     --->    b       --->      /  \
         /                \               a    c
        b                 c                                       
                          
    */
    /*  Esquerra-Dreta (factor = 2)
         c               c  
       /                /                  b     
      a        --->    b       --->      /  \
       \              /                 a    c
        b            a                 
    */

template <class Key, class Value> void BalancedTree<Key, Value>::rotacio(Position<Key,Value>* node,Position<Key,Value>* net, int factor){
    if (node == nullptr ) return;

    // Si el factor es 2 vol dir que el fill esquerre té més altura (cal fer rotació simple dret o doble esq-dret)
    if (factor == 2){
        // Si el net està esquerre esquerre fem rotació simple dret (passant el alfa)
        if (node->left()->left() == net){
            cout << "Cal fer una rotació simple dreta" << endl;
            dret_simple(node);
        } else{
            // Cas que el net esta esquerra dreta (cal fer doble esq-dret)
            // Rotem esq al node left de l'alfa (amb el net) i després fem una rotació simple dret amb l'alfa (en aquest moment el seu node left serà el net)
            cout << "Cal fer una rotació doble esquerra-dreta" << endl;
            esq_simple(node->left());
            dret_simple(node);
        }
    }
    else if (factor == -2){
        // Cas de que el net està dreta dreta (cal fer esq simple amb el alfa)
        if (node->right()->right() == net){
            cout << "Cal fer una rotació simple esquerra" << endl;
            esq_simple(node);
        }else{
            // Cas de que el net està dreta esquerra (cal fer doble dret-esq)
            // Rotem primer simple dret al node right de l'alfa i després fem un simple esq al node alfa
            cout << "Cal fer una rotació doble dreta-esquerra" << endl;
            dret_simple(node->right());
            esq_simple(node);
        }
    }else{
        return;
    }      
}

template <class Key, class Value> int BalancedTree<Key, Value>::act_height_balance(Position<Key, Value>* node){
    // Cas de que node sigui null no fem res:
    if (node == nullptr){
        return 0;
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

    return h_left - h_right;
}

template <class Key, class Value> void BalancedTree<Key, Value>::dret_simple(Position<Key, Value>* node){
    // Cal convertir el node en el fill dret del node->left() i passar el fill dret del node->left() en el fill esq del node
    cout << "Abans de la rotació simple dreta sobre: " << node->getKey() << endl;
    this->print();
    Position<Key, Value>*pare = node->parent();
    Position<Key, Value>*fill_dret = node->left()->right();
    node->setParent(node->left());
    node->left()->setRight(node);
    node->setLeft(fill_dret);
    node->parent()->setParent(pare);
    cout << "Després de la rotació simple dreta sobre: " << node->getKey() << endl;
    this->print();
}

template <class Key, class Value> void BalancedTree<Key, Value>::esq_simple(Position<Key, Value>* node){
    // Cal convertir el node en el fill esq del node->right() i passar el fill esq del node->right() en el fill dret del node
    cout << "Abans de la rotació simple esquerra sobre: " << node->getKey() << endl;
    this->print();
    Position<Key, Value>*pare = node->parent();
    Position<Key, Value>*fill_esq = node->right()->left();
    node->setParent(node->right());
    node->right()->setLeft(node);
    node->setRight(fill_esq);
    node->parent()->setParent(pare);
    cout << "Abans de la rotació simple esquerra sobre: " << node->getKey() << endl;
    this->print();
}

#endif // BALANCEDTREE_H
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
    BalancedTree(); // O(1)
    BalancedTree(const BalancedTree<Key, Value>& orig); // O(n) (crida el constructor còpia de BinaryTree)
    // Destructor
    virtual ~BalancedTree(); // O(1) (BinaryTree ja ho destrueix)

    // Mètodes
    Position<Key, Value>* insert(const Key& key, const Value& value); // O(log n) millor cas, O(n) pitjor cas (arbre lineal)
private:
    /* Les rotacions, definiu-les aquí sota */
    void rotacio(Position<Key,Value>* node,Position<Key,Value>* net, int factor); // O(1)
    int act_height_balance(Position<Key,Value>* node); // Retorna balance-factor. O(1)
    void dret_simple(Position<Key, Value>* node); // O(1)
    void esq_simple(Position<Key, Value>* node); // O(1)
};


// Constructors
template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree():
    BinaryTree<Key, Value>() // Crida el constructor de BinaryTree
{}

template <class Key, class Value> BalancedTree<Key, Value>::BalancedTree(const BalancedTree<Key, Value>& orig):
    BinaryTree<Key, Value>(orig) // Crida el constructor còpia de BinaryTree
{}

// Destructor
template <class Key, class Value> BalancedTree<Key, Value>::~BalancedTree(){} // No cal modificar

// Mètodes
template <class Key, class Value> Position<Key, Value>* BalancedTree<Key, Value>::insert(const Key& key, const Value& value){
    // Creem un punter que apunta el nou node insertat
    Position<Key, Value>* node_nou = BinaryTree<Key, Value>::insert(key, value);

    // Si es l'arrel o el seu pare és l'arrel no cal fer canvis
    if (node_nou == this->root){
        return node_nou;
    }
    if (node_nou == nullptr){
        cout << "why?";
    }
    if (node_nou->parent() == nullptr){
        return node_nou;
    }
    
    // Iterem cap a dalt per actualitzar les altures dels antecedents i comprovem que el balaced factor no sigui 2 o -2
    Position<Key, Value>* iterator = node_nou->parent()->parent();
    Position<Key, Value>* iterator_fill= node_nou->parent();
    Position<Key, Value>* iterator_net = node_nou;
    
    int bf = 0;
    // Mentre l'alfa (iterator) no sigui nullptr
    while(iterator_net != nullptr){
        // Actualitzem l'altura del fill i de l'alfa i calculem el balanced factor de l'alfa
        act_height_balance(iterator_fill);
        bf = act_height_balance(iterator);
        // Cridem a la funcio rotacio amb el alfa, el node net i el balanced factor de l'alfa
        rotacio(iterator, iterator_net, bf);

        // Pujem
        iterator_net = iterator_fill;
        iterator_fill = iterator;
        if (iterator != nullptr){
        iterator = iterator->parent();    
        }
    }
    // Retornem el node nou insertat
    return node_nou;
 }

template <class Key, class Value> void BalancedTree<Key, Value>::rotacio(Position<Key,Value>* node,Position<Key,Value>* net, int factor){
    // Si node és nullptr no fem res
    if (node == nullptr ) return;

    // Si el factor es 2 vol dir que el fill esquerre té més altura (cal fer rotació simple dret o doble esq-dret)
    if (factor == 2){
        // Si el net està esquerre esquerre fem rotació simple dret (passant el alfa)
        if (node->left()->left() == net){
            //cout << "Cal fer una rotació simple dreta" << endl;
            dret_simple(node);
        } else{
            // Cas que el net esta esquerra dreta (cal fer doble esq-dret)
            // Rotem esq al node left de l'alfa (amb el net) i després fem una rotació simple dret amb l'alfa (en aquest moment el seu node left serà el net)
            //cout << "Cal fer una rotació doble esquerra-dreta" << endl;
            esq_simple(node->left());
            dret_simple(node);
        }
    }
    else if (factor == -2){
        // Cas de que el net està dreta dreta (cal fer esq simple amb el alfa)
        if (node->right()->right() == net){
            //cout << "Cal fer una rotació simple esquerra" << endl;
            esq_simple(node);
        }else{
            // Cas de que el net està dreta esquerra (cal fer doble dret-esq)
            // Rotem primer simple dret al node right de l'alfa i després fem un simple esq al node alfa
            //cout << "Cal fer una rotació doble dreta-esquerra" << endl;
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
    Position<Key, Value>* pare = node->parent();
    Position<Key, Value>* net_dret = node->left()->right();
    Position<Key, Value>* fill_esq = node->left();
    
    // fill_esq  <-> node
    node->setParent(node->left());
    fill_esq->setRight(node);

    // node <-> net_dret
    node->setLeft(net_dret);
    if (net_dret != nullptr){
        net_dret->setParent(node);
    }
    
    // pare<-fill_esq 
    fill_esq->setParent(pare);
    
    // pare->fill_esq 
    if (pare == nullptr){ // Cas que node és arrel
        this->root = fill_esq;
    }
    else if (pare->right() == node){ // Es fill dret
        pare->setRight(fill_esq);
    } else{
        pare->setLeft(fill_esq);
    }
    // Actualitzem les altures del node i del fill esq (que ara és el pare del node)
    act_height_balance(node);
    act_height_balance(fill_esq);
}

template <class Key, class Value> void BalancedTree<Key, Value>::esq_simple(Position<Key, Value>* node){
    // Cal convertir el node en el fill esq del node->right()) i passar el fill esq del node->right() en el fill dret del node

    Position<Key, Value>*pare = node->parent();
    Position<Key, Value>*net_esq = node->right()->left();
    Position<Key, Value>*fill_dret = node->right();
    
    // fill_dret  <-> node
    node->setParent(node->right());
    fill_dret->setLeft(node);

    // node <-> net_dret
    node->setRight(net_esq);
    if(net_esq != nullptr){
        net_esq->setParent(node);
    }
    
    // pare<-fill_dret
    fill_dret->setParent(pare);
    
    // pare->fill_esq 
    if (pare == nullptr){ // Cas que node és arrel
        this->root = fill_dret;
    }
    else if (pare->right() == node){ // Es fill dret
        pare->setRight(fill_dret);
    } else{
        pare->setLeft(fill_dret);
    }
    // Actualitzem les altures del node i del fill dret (que ara és el pare del node)
    act_height_balance(node);
    act_height_balance(fill_dret);
}

#endif // BALANCEDTREE_H
#include "BinaryTree.h"
#include "Position.h"
#include <vector>
using namespace std;

template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(){
    this->root = nullptr;
    this->_size = 0;
}

template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(const BinaryTree<Key, Value>& orig){
    this->root = new Postion<Key, Value> (orig->getRoot());
    this->_size = orig->size();
}

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

}

// Operadors
template <class Key, class Value> void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value> *node = nullptr) const{

}

template <class Key, class Value> void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value> *node = nullptr) const{

}

template <class Key, class Value> bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const{
    
}
    
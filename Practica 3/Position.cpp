#include "Position.h"
#include <vector> 
using namespace std;

template <class Key, class Value> Position<Key, Value>::Position(const Key clau){
    this->key = clau;
    this->pare = nullptr;
    this->esq = nullptr;
    this->dret = nullptr;
}

template <class Key, class Value> Position<Key, Value>::Position(const Position<Key, Value>& orig){
    this->values = orig.getValues();
    this->key = orig.getKey();
    this->pare = nullptr;
    this->esq = nullptr;
    this->dret = nullptr;
}

template <class Key, class Value> Position<Key, Value>::~Position(){
    if(this->esq != nullptr){
        delete this->esq;
    }
    if(this->dret != nullptr){
        delete this->dret;
    }
}

// Modificadors
template <class Key, class Value> void Position<Key, Value>::setParent(Position<Key, Value>* pos){
    this-> pare = pos;
}

template <class Key, class Value> void Position<Key, Value>::setLeft(Position<Key, Value>* pos){
    this-> esq = pos;
}

template <class Key, class Value> void Position<Key, Value>::setRight(Position<Key, Value>* pos){
    this->der = pos;
}

// Consultors
template <class Key, class Value> const Key& Position<Key, Value>::getKey() const{
    return this->key;
}

template <class Key, class Value> const vector<Value>& Position<Key, Value>::getValues() const{
    return this->values;
}

template <class Key, class Value> Position<Key, Value> Position<Key, Value>::parent() const{
    return this->pare;
}

template <class Key, class Value> Position<Key, Value> Position<Key, Value>::left() const{
    return this->esq;
}

template <class Key, class Value> Position<Key, Value> Position<Key, Value>::right() const{
    return this->dret;
}

// Operacions
template <class Key, class Value> bool Position<Key, Value>::isRoot() const{
    return this->pare == nullptr;
}

template <class Key, class Value> bool Position<Key, Value>::isLeaf() const{
    return this->esq == nullptr && this->der == nullptr;
}

template <class Key, class Value> int Position<Key, Value>::depth() const{
    if (this->isRoot()){
        return 0;
    }
    return this->pare->depth()+1;
}

template <class Key, class Value> int Position<Key, Value>::height() const{
    if(this->isLeaf()){
        return 1;
    }
    int num = 0;
    int num2 = 0;
       if (this->esq != nullptr){
        num = this->esq->height()+1;
    }
    if (this->dret != nullptr){
        num2 = this->dreta->height()+1;
    }
    if (num > num2){
        return num;
    } else{
        return num2;
    }
}

template <class Key, class Value> void Position<Key, Value>::addValue(const Value& value){
    (this->values).push_back(value);
}

template <class Key, class Value> bool Position<Key, Value>::operator==(const Position<Key, Value>& other) const{
    return other.getKey() == this->key;
}



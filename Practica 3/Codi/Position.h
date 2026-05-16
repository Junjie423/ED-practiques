#ifndef POSITION_H
#define POSITION_H

#include "Position.h"
#include <vector> 
#include <iostream>
#include <stdexcept>

using namespace std;

template <class Key, class Value>
class Position {
public:
    Position(const Key key); // O(1)
    Position(const Position<Key, Value>& orig); // O(1)
    virtual ~Position(); // O(1)
    
    /* Modificadors */
    void setParent(Position<Key, Value>* pos); // O(1)
    void setLeft(Position<Key, Value>* pos); // O(1)
    void setRight(Position<Key, Value>* pos); // O(1)
    void setHeight(int h); // O(1)
    /* Consultors */
    const Key& getKey() const; // O(1)
    const int getHeight() const; // O(1)
    const vector<Value>& getValues() const; // O(1)
    Position<Key, Value>* parent() const; // O(1)
    Position<Key, Value>* left() const; // O(1)
    Position<Key, Value>* right() const; // O(1)

    /* Operacions */
    bool isRoot() const; // O(1)
    bool isLeaf() const; // O(1)
    int depth() const; // O(n) on n es la quantitat de antecedents
    int height() const; // O(n) (recorre tot l'arbre de baix a dalt fins al node)
    void addValue(const Value& value); // O(1)
    bool operator==(const Position<Key, Value>& other) const; // O(1)
    
private:
    int h;
    Key key;
    vector<Value> values;
    Position<Key, Value>* pare;
    Position<Key, Value>* esq;
    Position<Key, Value>* dret;
};

// Constructors
template <class Key, class Value> Position<Key, Value>::Position(const Key clau){
    // Assignem key a la clau introduida i tots els punters nullptr
    this->key = clau;
    this->pare = nullptr;
    this->esq = nullptr;
    this->dret = nullptr;
    this-> h = 1;
}

template <class Key, class Value> Position<Key, Value>::Position(const Position<Key, Value>& orig){
    // Assignem els valors i la clau de l'original i els punters nullptr
    this->values = orig.getValues();
    this->key = orig.getKey();
    this->pare = nullptr;
    this->esq = nullptr;
    this->dret = nullptr;
    this->h = orig.getHeight();
}

// Destructor
template <class Key, class Value> Position<Key, Value>::~Position(){
    // Eliminem els punters fills
    if(this->esq != nullptr){
        delete this->esq;
    }
    if(this->dret != nullptr){
        delete this->dret;
    }
}

// Modificadors
template <class Key, class Value> void Position<Key, Value>::setParent(Position<Key, Value>* pos){
    this->pare = pos;
}

template <class Key, class Value> void Position<Key, Value>::setLeft(Position<Key, Value>* pos){
    this->esq = pos;
}

template <class Key, class Value> void Position<Key, Value>::setRight(Position<Key, Value>* pos){
    this->dret = pos;
}

template <class Key, class Value> void Position<Key, Value>::setHeight(int h){
    this->h = h;
}

// Consultors
template <class Key, class Value> const Key& Position<Key, Value>::getKey() const{
    return this->key;
}

template <class Key, class Value> const int Position<Key, Value>::getHeight() const{
    return this->h;
}

template <class Key, class Value> const vector<Value>& Position<Key, Value>::getValues() const{
    return this->values;
}

template <class Key, class Value> Position<Key, Value>* Position<Key, Value>::parent() const{
    return this->pare;
}

template <class Key, class Value> Position<Key, Value>* Position<Key, Value>::left() const{
    return this->esq;
}

template <class Key, class Value> Position<Key, Value>* Position<Key, Value>::right() const{
    return this->dret;
}

// Operacions
template <class Key, class Value> bool Position<Key, Value>::isRoot() const{
    // Només l'arrel no té node pare
    return this->pare == nullptr;
}

template <class Key, class Value> bool Position<Key, Value>::isLeaf() const{
    // Les fulles no tenen fill dret ni fill esquerre
    return this->esq == nullptr && this->dret == nullptr;
}

template <class Key, class Value> int Position<Key, Value>::depth() const{
    // Si es arrel retorna 0
    if (this->isRoot()){
        return 0;
    }
    // Si no es arrel, fa una recursivitat retornant el nombre del pare + 1 (arriba fins l'arrel i va tornant afegint 1 cada salt que s'ha fet)
    return (this->pare->depth())+1;
}

template <class Key, class Value> int Position<Key, Value>::height() const{
    // En cas de ser fulla retorna 1
    if(this->isLeaf()){
        return 1;
    }
    // En cas de no ser fulla, fa una crida recursiva retornant el height del fill dret i fill esquerre tots + 1
    // I agafant el més gran dels fills, crida fins a arribar les fulles i va tornant.
    int num = 0;
    int num2 = 0;
       if (this->esq != nullptr){
        num = this->esq->height()+1;
    }
    if (this->dret != nullptr){
        num2 = this->dret->height()+1;
    }
    if (num > num2){
        return num;
    } else{
        return num2;
    }
}

template <class Key, class Value> void Position<Key, Value>::addValue(const Value& value){
    // Afegeix el valor al darrere del vector values
    this->values.push_back(value);
}

template <class Key, class Value> bool Position<Key, Value>::operator==(const Position<Key, Value>& other) const{
    // L'operador == per els nodes compara si la clau és la mateixa
    return other.getKey() == this->key;
}

#endif //POSITION_H
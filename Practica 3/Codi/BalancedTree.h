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
    BalancedTree();
    BalancedTree(const BalancedTree<Key, Value>& orig);
    virtual ~BalancedTree();
    Position<Key, Value>* insert(const Key& key, const Value& value);
private:
    /* Les rotacions, definiu-les aquí sota */
};
#endif // BALANCEDTREE_H
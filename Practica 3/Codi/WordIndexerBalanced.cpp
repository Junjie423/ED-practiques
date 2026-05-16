#include "WordIndexerBalanced.h"
#include "BalancedTree.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

WordIndexerBalanced::WordIndexerBalanced(string path){
    // Creem l'arbre com a BalancedTree
    this->tree = new BalancedTree<string, Tuple<int>>(); 
    this->addText(path);  
}

WordIndexerBalanced::WordIndexerBalanced(const WordIndexerBalanced& orig){
    // Copiem l'arbre orig fent un downcasting (perquè l'atribut tree està guardat com un BinaryTree en el TAD WordIndexer)
    BalancedTree<string, Tuple<int>>* copy = dynamic_cast<BalancedTree<string, Tuple<int>>*>(orig.tree);
    if((copy == nullptr) || (copy->isEmpty())){
        this->tree = new BinaryTree<string, Tuple<int>>();
    } else{
        this->tree = new BinaryTree<string, Tuple<int>>(*orig.tree);
    }
}

WordIndexerBalanced::~WordIndexerBalanced(){} // No cal fer res, el WordIndexer ja ho destrueix
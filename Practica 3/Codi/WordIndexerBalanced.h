#ifndef WORDINDEXERBALANCED_H
#define WORDINDEXERBALANCED_H

#include "WordIndexer.h"
#include "BalancedTree.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class WordIndexerBalanced : public WordIndexer {
    public:
        WordIndexerBalanced(string path); // O(n) -> n nombre de paraules del fitxer (crida addText)
        WordIndexerBalanced(const WordIndexerBalanced& orig); // O(n) -> n nombre de nodes de l'arbre (crida el constructor còpia de BinaryTree)
        virtual ~WordIndexerBalanced(); // O(1) (WordIndexer ja ho destrueix)
};
#endif // WORDINDEXERBALANCED_H
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
        WordIndexerBalanced(string path);
        WordIndexerBalanced(const WordIndexerBalanced& orig);
        virtual ~WordIndexerBalanced();
};
#endif // WORDINDEXERBALANCED_H
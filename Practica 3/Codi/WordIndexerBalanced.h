#ifndef WORDINDEXERBALANCED_H
#define WORDINDEXERBALANCED_H

#include "WordIndexer.h"
#include "Tuple.h"
#include "BinaryTree.h"
#include "Position.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

class WordIndexerBalanced : public WordIndexer {
public:
WordIndexerBalanced(string path);
WordIndexerBalanced(const WordIndexerBalanced& orig);
virtual ~WordIndexerBalanced();
};
#endif // WORDINDEXERBALANCED_H
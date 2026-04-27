#ifndef WORDINDEXER_H
#define WORDINDEXER_H

#include <stdexcept>
#include "BinaryTree.h"
#include "Tuple.h"

using namespace std;

class WordIndexer {
public:
    WordIndexer();
    WordIndexer(std::string path);
    WordIndexer(const WordIndexer& orig);
    virtual ~WordIndexer();
 
    int size() const;
    int height() const;
    bool contains(const std::string &word) const;
    void printOccurrences(const std::string &word) const;
    void printDictionary(Position<string, Tuple<int> > *node = nullptr) const;
protected:
    // BSTree 
    BinaryTree<string, Tuple<int> > *tree;
    void addText(std::string path);
private:
    void insertWord(const std::string &word, const int &line, const int &position);
    /* Metodes auxiliars, definiu-los aquí sota */

};
#endif // WORDINDEXER_H
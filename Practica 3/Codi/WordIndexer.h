#ifndef WORDINDEXER_H
#define WORDINDEXER_H

#include "BinaryTree.h"
#include "Position.h"
#include "Tuple.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class WordIndexer {
public:
    // Constructors
    WordIndexer(); 
    WordIndexer(string path);
    WordIndexer(const WordIndexer& orig);
    virtual ~WordIndexer();
 
    int size() const;
    int height() const;
    bool contains(const string &word) const;
    void printOccurrences(const string &word) const;
    void printDictionary(Position<string, Tuple<int> > *node = nullptr) const;
    void print40() const;
protected:
    // BSTree 
    BinaryTree<string, Tuple<int>> *tree;
    void addText(string path);
private:
    void insertWord(const string &word, const int &line, const int &position);
    /* Metodes auxiliars, definiu-los aquí sota */
    void rec_print40(Position<string, Tuple<int>>* node, int &cont, bool&) const;
};
#endif // WORDINDEXER_H
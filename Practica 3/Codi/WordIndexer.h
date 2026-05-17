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
    WordIndexer(); // O(1)
    WordIndexer(string path); // O(n) -> n nombre de paraules del fitxer (crida addText)
    WordIndexer(const WordIndexer& orig); // O(n) -> n nombre de nodes de l'arbre (crida el constructor còpia de BinaryTree)
    // Destructor
    virtual ~WordIndexer(); // O(1) (BinaryTree ja destrueix)
 
    // Mètodes
    int size() const; // O(1)
    int height() const; // O(n) (crida height() de BinaryTree)
    bool contains(const string &word) const; // O(log n) millor cas, O(n) pitjor cas (crida contains() de BinaryTree)
    void printOccurrences(const string &word) const; // O(log n) millor cas, O(n) pitjor cas (crida getValues() de BinaryTree)
    void printDictionary(Position<string, Tuple<int> > *node = nullptr) const; // O(n) (recursiva, recorre tot l'arbre)
    void print40() const; // O(n) (crida a la funció recursiva)
protected:
    // BSTree 
    BinaryTree<string, Tuple<int>> *tree;
    void addText(string path); // O(n) -> n nombre de paraules del fitxer (crida també n vegades a insertWord)
private:
    void insertWord(const string &word, const int &line, const int &position); // O(log n) millor cas, O(n) pitjor cas (crida insert() de BinaryTree)
    /* Metodes auxiliars, definiu-los aquí sota */
    void rec_print40(Position<string, Tuple<int>>* node, int &cont, bool&) const; // O(n) (recursiva, recorre tot l'arbre)
};
#endif // WORDINDEXER_H
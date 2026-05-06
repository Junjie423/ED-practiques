#ifndef WORDINDEXER_H
#define WORDINDEXER_H

#include "BinaryTree.h"
#include "Tuple.h"
#include <stdexcept>

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
protected:
    // BSTree 
    BinaryTree<string, Tuple<int> > *tree;
    void addText(string path);
private:
    void insertWord(const string &word, const int &line, const int &position);
    /* Metodes auxiliars, definiu-los aquí sota */

};

WordIndexer::WordIndexer(){

}

WordIndexer::WordIndexer(string path){

}

WordIndexer::WordIndexer(const WordIndexer& orig){

}

WordIndexer::~WordIndexer(){

}

int WordIndexer::size() const{

}

int WordIndexer::height() const{

}

bool WordIndexer::contains(const string &word) const{

}

void WordIndexer::printOccurrences(const string &word) const{

}

void WordIndexer::printDictionary(Position<string, Tuple<int> > *node) const{

}

void WordIndexer::addText(string path){

}

void WordIndexer::insertWord(const string &word, const int &line, const int &position){
    
}

#endif // WORDINDEXER_H
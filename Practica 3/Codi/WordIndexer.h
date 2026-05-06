#ifndef WORDINDEXER_H
#define WORDINDEXER_H

#include "BinaryTree.h"
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
protected:
    // BSTree 
    BinaryTree<string, Tuple<int>> *tree;
    void addText(string path);
private:
    void insertWord(const string &word, const int &line, const int &position);
    /* Metodes auxiliars, definiu-los aquí sota */

};

WordIndexer::WordIndexer(){
    this->tree = new BinaryTree<string, Tuple<int>>();
}

WordIndexer::WordIndexer(string path){
    this->tree = new BinaryTree<string, Tuple<int>>(); 
    this->addText(path);  
}

WordIndexer::WordIndexer(const WordIndexer& orig){
    BinaryTree<string, Tuple<int>>* copy = orig.tree;
    if((copy == nullptr) || (copy->isEmpty())){
        this->tree = new BinaryTree<string, Tuple<int>>();
    } else{
        this->tree = new BinaryTree<string, Tuple<int>>(*orig.tree);
    }
}

WordIndexer::~WordIndexer(){
    if (this->tree != nullptr){
    delete this->tree;
    }
}

int WordIndexer::size() const{
    return this->tree->size();
}

int WordIndexer::height() const{
    return this->tree->height();
}

bool WordIndexer::contains(const string &word) const{
    return this->tree->contains(word);
}

void WordIndexer::printOccurrences(const string &word) const{
    vector<Tuple<int>> tuples = this->tree->getValues(word);
    cout << word << " [";
    for (int i = 0; i < tuples.size(); i++){
        cout << "(" << tuples[i].getFila() << ", " << tuples[i].getColumna() << ") ";
    }
    cout << "]" << endl;
}

void WordIndexer::printDictionary(Position<string, Tuple<int> > *node) const{

}

void WordIndexer::addText(string path){
    ifstream file(path);
    if(!file.is_open()){
        throw runtime_error("No s'ha pogut obrir el fitxer");
    }
    string linia;
    int fila = 0;
    int col = 0;
    while(getline(file, linia)){
        fila++;
        stringstream ss(linia);
        string paraula;
        
        while(ss >> paraula){
            col++;
            this->insertWord(paraula, fila, col);
        }
    }
}

void WordIndexer::insertWord(const string &word, const int &line, const int &position){
            Tuple<int>* tupla = new Tuple<int>();
            tupla->setFila(line);
            tupla->setColumna(position);
            this->tree->insert(word, *tupla);
}

#endif // WORDINDEXER_H
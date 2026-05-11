#include "WordIndexer.h"
#include "BinaryTree.h"
#include "Position.h"
#include "Tuple.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

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
    if(node == nullptr){
        node = this->tree->getRoot();
    }
    if(node->left() != nullptr){
        printDictionary(node->left());
    }
    vector<Tuple<int>> tuples = node->getValues();
    cout << node->getKey() << " [";
    for (int i = 0; i < tuples.size(); i++){
        cout << "(" << tuples[i].getFila() << ", " << tuples[i].getColumna() << ") ";
    }
    cout << "]" << endl;
    if(node->right() != nullptr){
        printDictionary(node->right());
    }
    
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
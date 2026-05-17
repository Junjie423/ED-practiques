#include "WordIndexer.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

WordIndexer::WordIndexer(){
    // Inicialitzem l'arbre com un nou BinaryTree buit
    this->tree = new BinaryTree<string, Tuple<int>>(); 
}

WordIndexer::WordIndexer(string path){
    // Inicialitzem l'arbre amb un nou BinaryTree buit i cridem a addText per omplir-lo
    this->tree = new BinaryTree<string, Tuple<int>>(); 
    this->addText(path);  
}

WordIndexer::WordIndexer(const WordIndexer& orig){
    // Copiem l'arbre, si està buida o és nullptr inicialitzem un buit
    BinaryTree<string, Tuple<int>>* copy = orig.tree;
    if((copy == nullptr) || (copy->isEmpty())){
        this->tree = new BinaryTree<string, Tuple<int>>();
    } else{
        this->tree = new BinaryTree<string, Tuple<int>>(*orig.tree);
    }
}

WordIndexer::~WordIndexer(){
    // Eliminem l'arbre si no és nullptr
    if (this->tree != nullptr){
    delete this->tree;
    }
}

int WordIndexer::size() const{
    // Cridem el size() de BinaryTree
    return this->tree->size();
}

int WordIndexer::height() const{
    // Cridem el height() de BinaryTree
    return this->tree->height();
}

bool WordIndexer::contains(const string &word) const{
    // Cridem el contains() de BinaryTree
    return this->tree->contains(word);
}

void WordIndexer::printOccurrences(const string &word) const{
    // Cridem el getValues() de BinaryTree per obtenir el vector de tuples i els imprimim
    vector<Tuple<int>> tuples = this->tree->getValues(word);
    cout << word << " [";
    for (int i = 0; i < tuples.size(); i++){
        cout << "(" << tuples[i].getFila() << ", " << tuples[i].getColumna() << ")";
    }
    cout << "]" << endl;
}

void WordIndexer::printDictionary(Position<string, Tuple<int> > *node) const{
    // Quan no s'introdueix cap node com paràmetre és nullptr per defecte i per tan començem per l'arrel.
    if(node == nullptr){
        node = this->tree->getRoot();
    }
    // Fem una crida recursiva en inordre (esq-pare-dret)
    if(node->left() != nullptr){
        printDictionary(node->left());
    }
    vector<Tuple<int>> tuples = node->getValues();
    cout << node->getKey() << " [";
    for (int i = 0; i < tuples.size(); i++){
        cout << "(" << tuples[i].getFila() << ", " << tuples[i].getColumna() << ")";
    }
    cout << "]" << endl;
    if(node->right() != nullptr){
        printDictionary(node->right());
    }
    
}

void WordIndexer::addText(string path){
    // Obrim el fitxer i comprovem que s'ha obert correctament
    ifstream file(path);
    if(!file.is_open()){
        throw runtime_error("No s'ha pogut obrir el fitxer");
    }
    // Creem un avariable per guardar cada linia del fitxer
    string linia;
    // Iniciem la fila i la columna
    int fila = 0;
    int col = 0;
    while(getline(file, linia)){
        // Cada vegada que llegim una linia, incrementem fila i començem la columna a 1 (cada fila reinicia la columna)
        fila++;
        col = 1;
        // Utilitzem un stringstream per separar les paraules de la linia
        stringstream ss(linia);
        string paraula;
        while(ss >> paraula){
            // Per a cada paraula de la linia cridem insertWord i incrementem la columna
            this->insertWord(paraula, fila, col);
            col++;
        }
    }
}

void WordIndexer::insertWord(const string &word, const int &line, const int &position){
    // Creem una tupla, assignem la fila i la columna i cridem insert() de BinaryTree guardar un node amb la paraula i la tupla
    Tuple<int>* tupla = new Tuple<int>();
    tupla->setFila(line);
    tupla->setColumna(position);
    this->tree->insert(word, *tupla);
}

void WordIndexer::print40() const{
    // Si està buit, excepció
    if(this->tree->isEmpty()){
        throw out_of_range("L'arbre per printar està buit");
    }
    // Cridem a una funció recursiva que imprimeix els nodes en inordre de 40 a 40 preguntant si vol continuar
    int cont = 0;
    bool keep = true;
    rec_print40(this->tree->getRoot(), cont, keep);
}

void WordIndexer::rec_print40(Position<string, Tuple<int>>* node, int &cont, bool& keep) const{
    // Si no volem que continuï surtim de la funció
    if(!keep) return;
    // Si hem arribat a un node nullptr, sortim de la funció
    if(node == nullptr) return;
    // Cridem per l'esquerre
    rec_print40(node->left(),cont,keep);

    // Si el contador ha arribat a 40 i encara continua, preguntem si vol continuar
    if  (keep && cont == 40){
        string op = "start";
        while (op != "s" && op != "n"){
            cout << "Vols continuar? (s/n): ";
            cin >> op;
        }
        if (op == "s"){
            // Si vol continuar reiniciem el contador a 0
            cont = 0;
        } else{
            // Si no vol continuar, assignem keep com a false i sortim
            keep = false;
            return;
        }
    }
    // Només quan keep és true i no arriba a 40 s'imprimeix la paraula amb les tuples i s'augmenta el contador
    if(keep){
        vector<Tuple<int>> tuples = node->getValues();
        cout <<node->getKey() << " [";
        for (int i = 0; i < tuples.size(); i++){
            cout << "(" << tuples[i].getFila() << ", " << tuples[i].getColumna() << ")";
        }
        cout << "]" << endl;
        cont++;
    }

    // Cridem per la dreta
    rec_print40(node->right(),cont,keep);
    
}
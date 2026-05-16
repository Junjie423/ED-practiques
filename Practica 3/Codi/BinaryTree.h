#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Position.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

//Para el print
#include <string>
#include <queue>
#include <cmath>
#include <sstream>

using namespace std;

template <class Key, class Value>
class BinaryTree {
public:
    BinaryTree(); // O(1)
    BinaryTree(const BinaryTree<Key, Value>& orig); // O(n)
    virtual ~BinaryTree();
    bool isEmpty() const; // O(1)
    Position<Key, Value>* getRoot() const; // O(1)
    int size() const; // O(1)
    int height() const;  // O(n)
    virtual Position<Key, Value>* insert(const Key& key, const Value& value); // O(log n) millor cas, O(n) pitjor cas
    bool contains(const Key& key) const; // O(log n) millor cas, O(n) pitjor cas
    Position<Key, Value>* search(const Key& key) const; // O(log n) millor cas, O(n) pitjor cas
    const vector<Value>& getValues(const Key& key) const; // O(log n) millor cas, O(n) pitjor cas
    void printPreOrder(const Position<Key, Value> *node = nullptr) const; // O(n)
    void printPostOrder(const Position<Key, Value> *node = nullptr) const; // O(n)
    bool identicalTree(const BinaryTree<Key, Value>& other) const; // O(n)
    vector<Key> getLeaves() const; // O(n)

    void print() const;
    
protected:
    Position<Key, Value>* root;
private:
    int _size;
    /* Mètodes auxiliars definiu aquí els que necessiteu */
    void rec_BinaryTree(const Position<Key, Value>* orig, Position<Key, Value>* actual); // O(n)
    int rec_height(const Position<Key, Value>* act) const; // O(n) on n es la quantitat de nodes de l'arbre (recorre tot l'arbre)
    Position<Key, Value>* rec_search(Position<Key, Value>* act,const Key& key) const; // O(log n) millor cas, O(n) pitjor cas
    void rec_preOrdre(Position<Key, Value>* act) const; // O(n)
    void rec_postOrdre(Position<Key, Value>* act) const; // O(n)
    bool rec_identicalTree(Position<Key, Value>* node1, Position<Key, Value>* node2) const; // O(n)
    void rec_getLeaves(Position<Key, Value>* node, vector<Key>& vect) const; // O(n)
    
}; 

// Constructors
template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(){
    this->root = nullptr;
    this->_size = 0;
}

template <class Key, class Value> BinaryTree<Key, Value>::BinaryTree(const BinaryTree<Key, Value>& orig){
    // Inicialitzem l'arbre assignant l'arrel el node amb la clau de l'arrel de l'arbre original i augmentem el size
    this->_size = 0;
    this->root = new Position<Key, Value> (orig.getRoot()->getKey());
    this->_size++;
    // Cridem una funció recursiva que anira creant els nodes de l'arbre original i afegint al nostre arbre a partir de l'arrel
    rec_BinaryTree(orig.getRoot(), this->root);
}

// Destructor
template <class Key, class Value> BinaryTree<Key, Value>::~BinaryTree(){
    if(this->root != nullptr){
    delete this->root;
    }
}

// Consultors
template <class Key, class Value> bool BinaryTree<Key, Value>::isEmpty() const{
    return this->_size == 0;
}

template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::getRoot() const{
    return this->root;
}

template <class Key, class Value> int BinaryTree<Key, Value>::size() const{
    return this->_size;
}

template <class Key, class Value> int BinaryTree<Key, Value>::height() const{
    // Si l'arbre està buit llançem excepció
    if (this->isEmpty()){
        throw out_of_range("L'arbre està buit");
    }
    // Cridem a la funció recursiva que ens calcula l'altura de l'arbre
    return rec_height(this->root);
}
/*
      02
    /      \        
   00      08  
        /      \
       05      45
       /       /  \ 
      03      40  76  
*/
template <class Key, class Value> bool BinaryTree<Key, Value>::contains(const Key& key) const{
    // Cas de arbre buit
    if(this->root == nullptr){   // També es pot fer if (this->isEmpty())
        throw out_of_range("No hi ha cap element a l'arbre");
    }
    // Creem un iterador que comença a l'arrel
    Position<Key, Value>* actual = this->root;
    // Creem un bolean per aturar la cerca en cas de trobar-la
    bool trobat = false;
    // Mentre no estigui trobat i l'iterador no arriba fins a una fulla
    while(!trobat && actual != nullptr){
        // Si la clau del node que apunta l'iterador és més gran que la clau que cerquem l'iterador va al fill esquerre
        if (actual->getKey() > key){
            actual = actual->left();
        }
        // Si és més petit, llavors va al fill dret
        else if (actual->getKey() < key){
            actual = actual->right();
        }
        // Si és la mateixa clau assigna trobat com true i surt del bucle
        else{
            trobat = true;
        }
    }
    // Retorna si s'ha trobat o no (si l'arbre el conté o no)
    return trobat;
}

template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::search(const Key& key) const{
    // Cas arbre buit
    if(this->isEmpty()){
        throw out_of_range("L'arbre està buit");
    }
    // Crida a una funció recursiva que busca el node amb la clau passant l'arrel i la clau
    return rec_search(this->root, key);
}

template <class Key, class Value> const vector<Value>& BinaryTree<Key, Value>:: getValues(const Key& key) const{
    // En cas d'arbre buit
    if (this->isEmpty()){
        throw out_of_range("L'arbre està buit");
    }
    // Creem un node que apunta a la posició de la key utilitzant el mètode search()
    Position<Key, Value>* trobat = search(key);
    // En cas de que no trobar en l'arbre
    if(trobat == nullptr){
        throw out_of_range("No s'ha trobat la clau");
    }
    // Si ho troba, retornem el vector amb els valors d'aquest node
    return trobat->getValues();
}

// Modificador
template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::insert(const Key& key, const Value& value){
    // Creem un iterador que comença a l'arrel i un altre per guardar el pare
    Position<Key, Value>* itr = this->root;
    Position<Key, Value>* itrPare = nullptr;
    // Creem un bolean per aturar la cerca en cas de trobar la clau i un altre per saber si el fill serà dret o esquerre
    bool trobat = false;
    bool dret = false;
    // Mentre no s'hagi trobat la clau i l'iterador no arribi a una fulla anem comparant la clau del node que apunta l'iterador amb la key
    while(itr != nullptr && !trobat){
        // Si la clau del node es més gran que el key, guardem el node de l'iterador com a pare i fem que avanci l'iterador
        // cap a l'esquerra i assignem dret com false
        if (itr->getKey() > key){
            itrPare = itr;
            itr = itr->left();
            dret = false;
        } else if (itr->getKey() < key){
            // Si la clau del node és més petita que el key, guardem el node de l'iterador com a pare i fem que avanci l'iterador
            // cap a la dreta i assignem dret com true
            itrPare = itr;
            itr = itr->right();
            dret = true;
        } else{
            // en cas de trobar la clau, assignem trobat com true i sortim del bucle
            trobat = true;
        }
    }
    // En cas de trobar el node amb la clau itr apunta a aquest node, per tant podem afegir el valor directament
    if(trobat){
        itr->addValue(value);
    } else{
        // Si no s'ha trobat creem un node fill dret o esquerre dependent del boolean dret
        this->_size++;
        // creem el node amb la key i guardem el valor al seu vector de valors
        Position<Key, Value>*nou = new Position<Key,Value>(key);
        nou->addValue(value);
        // Si és el cas d'arbre buit, el nou node serà l'arrel
        if(this->root == nullptr){
            this->root = nou;
            return this->root;
        }
        // Si no és arbre buit, enllacem el nou node amb el seu pare (que haviem guardat en el bucle) 
        // i el pare amb el nou node depenent de si és fill dret o esquerre
        nou->setParent(itrPare);
        if(dret){
            itrPare->setRight(nou);
        } else{
            itrPare->setLeft(nou);
        }
    }
    // retornem el node afegit (posicio)
    return itr;
}

// Operadors
template <class Key, class Value> void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value> *node) const{
    // Cas arbre buit
    if (this->root == nullptr){
        throw out_of_range("L'arbre està buit");
    }
    // Crida a una funció recursiva que imprimeix els nodes en preordre passant l'arrel
    rec_preOrdre(this->root);
}

template <class Key, class Value> void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value> *node) const{
    // Cas arbre buit
    if (this->root == nullptr){
        throw out_of_range("L'arbre està buit");
    }
    // Crida a una funció recursiva que imprimeix els nodes en postordre passant l'arrel
    rec_postOrdre(this->root);

}

template <class Key, class Value> bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const{
    // Retorna el resultat d'una crida recursiva que compara els nodes de dos arbres, passant les arrels d'ambdós arbres
    return rec_identicalTree(this->root, other.getRoot());
}

template <class Key, class Value> vector<Key> BinaryTree<Key, Value>::getLeaves() const{
    // Creem un vector on guardarem les claus de les fulles
    vector<Key> vect;
    // Cridem a una funció recursiva que omple aquest vector passant l'arrel i el vector (com referència)
    rec_getLeaves(this->root, vect);
    // Retornem el vector amb les claus de les fulles
    return vect;
}

// Mètodes auxiliars
template <class Key, class Value> void BinaryTree<Key, Value>::rec_BinaryTree(const Position<Key, Value>* orig, Position<Key, Value>* actual){
    // Per a cada node de l'original cal afegir els valors un a un al nostre node
    for (Value v : orig->getValues()){
            actual->addValue(v);
    }

    // Creem dos nodes que apunten als fills del node de l'arbre origianl
    Position<Key, Value>* left = orig->left();
    Position<Key, Value>* right = orig->right();

    // Si existeix fill dreta creem un node amb la clau d'aquest fill i l'enllacem amb el nostre node
    // Després augmentem el tamany de l'arbre i tornem a cridar la funció recursiva amb el fill dret original i el nostre
    // Per tal de copiar els valors i continuar amb els fills d'aquests si en tenen
    if (right != nullptr){
        Position<Key, Value>* dret = new Position<Key, Value>(right->getKey());
        actual->setRight(dret);
        dret->setParent(actual);
        this->_size++;
        rec_BinaryTree(right,dret);
    }
    // Fem el mateix per els fills esquerres
    if (left != nullptr){
        Position<Key, Value>* esq = new Position<Key, Value>(left->getKey());
        actual->setLeft(esq);
        esq->setParent(actual);
        this->_size++;
        rec_BinaryTree(left,esq);
    }
    // Quan s'acabi totes les crides, ja tindrem un arbre idèntic a l'arbre passat com a paràmetre en el constructor còpia
}

template <class Key, class Value> int BinaryTree<Key, Value>::rec_height(const Position<Key, Value>* act) const{
    // Si no te cap fill (fulla) retorna 1
    if (act == nullptr)
        return 0;
    // En cas de no ser-ho fa una crida recursiva fins les fulles i va tornant agafant el height més gran entre els dos fills
    // sumant 1
    return (max(rec_height(act->left()), rec_height(act->right())) + 1);
}

template <class Key, class Value> Position<Key, Value>* BinaryTree<Key, Value>::rec_search(Position<Key, Value>* act,const Key& key) const{
    // Mentre el node actual no sigui nullptr, mirem que coincideixin la clau del node amb la key
    while (act != nullptr){
        // En cas de que la clau del node sigui més gran que la key, mirem el fill esquerre
        if (act->getKey() > key){
            rec_search(act->left(), key);
        } else if (act->getKey() < key){
            // En cas de ser més petit, mirem el fill dret
            rec_search(act->right(), key);
        } else{
            // Si és la mateixa clau, retornem el node
            return act;
        }
    }
    // En cas d'arribar al final (fill d'una fulla = nullptr) retorna nullptr (no s'ha trobat)
    return act;
}

template <class Key, class Value> void BinaryTree<Key, Value>::rec_preOrdre(Position<Key, Value>* act) const{
    // Si el node es nullptr retornem i no fem res
    if(act == nullptr){
        return;
    }
    // (preordre = node, fill esquerre, fill dret)
    // Si no és nullptr imprimim la clau i tornem a cridar la funció per el fill dret i després el fill esquerre 
    cout << act->getKey() << " ";
    rec_preOrdre(act->left());
    rec_preOrdre(act->right());
}

template <class Key, class Value> void BinaryTree<Key, Value>::rec_postOrdre(Position<Key, Value>* act) const{
    // Si el node es nullptr retornem i no fem res
    if(act == nullptr){
        return;
    }
    // (postordre = fill esquerre, fill dret, node)
    // Si no és nullptr cridem la funció per el fill dret i després el fill esquerre i finalment imprimim la clau
    rec_postOrdre(act->left());
    rec_postOrdre(act->right());
    cout << act->getKey() << " ";
}

template <class Key, class Value> bool BinaryTree<Key, Value>::rec_identicalTree(Position<Key, Value>* node1, Position<Key, Value>* node2) const{
    // Si els dos nodes són nullptr, vol dir que hem arribat al final dels dos arbres i no s'ha trobat cap diferència, per tant retornem true
    if (node1 == nullptr && node2 == nullptr){
        return true;
    }
    // Si un dels dos nodes és nullptr i l'altre no, vol dir que els arbres no són idèntics, per tant retornem false
    if (node1 == nullptr || node2 == nullptr){
        return false;
    }
    // Si les claus dels nodes no són iguals o els vectors de valors no són iguals, vol dir que els arbres no són idèntics
    if (node1->getKey() != node2->getKey() || node1->getValues() != node2->getValues()){
        return false;
    }
    // Si aquests nodes passen el test, cal comprovar que els dos fills també
    return rec_identicalTree(node1->left(), node2->left()) && rec_identicalTree(node1->right(), node2->right());
}

template <class Key, class Value> void BinaryTree<Key, Value>::rec_getLeaves(Position<Key, Value>* node, vector<Key>& vect) const{
    if(node == nullptr) return;
    
    // Si el node és fulla afegim la seva clau al vector paràmetre
    if (node->isLeaf()){
        vect.push_back(node->getKey());
    } else{
        // En cas de no ser fulla, cridem recursivament per el fill esquerre i després pel fill dret, passant el mateix vector per anar omplint
        rec_getLeaves(node->left(), vect);
        rec_getLeaves(node->right(), vect);
    }
}

template <class Key, class Value>
void BinaryTree<Key, Value>::print() const {
    if (isEmpty()) { 
        cout << " --- Arbre buit ---" << endl;
        return;
    }
    
    // Llindar
    int h = this->height();
    if (h > 6) { 
        cout << " --- Arbre massa gran ---" << endl;
        return;
    }

    cout << "  --- Nodes : " + to_string(size()) + " ---" << endl;

    // ==========================================
    // Funciones Lambda (Auxiliares integradas)
    // ==========================================
    
    // Convierte un tipo genérico a string usando un flujo de salida
    auto convert_str = [](const Key& k) -> string {
        ostringstream oss;
        oss << k;
        return oss.str();
    };

    // Centra un string dentro de un ancho específico rellenando con espacios
    auto center = [](const string& str, int width) -> string {
        int len = str.length();
        if (width <= len) return str;
        int pad_left = (width - len) / 2;
        int pad_right = width - len - pad_left;
        return string(pad_left, ' ') + str + string(pad_right, ' ');
    };

    // ==========================================

    // Amplada maxima para centrar de manera que abajo quede xx--xx--xx--....
    // xx-- son cuatro caracteres, y sabemos que habran 2^h elementos (h = alçada)
    int base = 4; // Espai per a cada element a la base de l'arbre
    int amplada = pow(2, h - 1) * base;

    // Recorregut d'amplada amb cua com vist a teoria
    queue<Position<Key, Value>*> cua;

    // Comencem amb el root
    cua.push(root);

    // Variables auxiliars
    Position<Key, Value>* top;
    int nivell = 0;
    int fets = 0;
    
    // 4 espai_minim es un element, en 2 ja no hauria de fer print
    while (amplada >= base) {
        // Agafem el front
        top = cua.front();
        
        // Si es null imprimeix l'espai
        if (top == nullptr) {
            cout << center("  ", amplada);
        }
        // Sino agafem la key del node i la imprimeix
        else {
            cout << center(convert_str(top->getKey()), amplada);
        }
        
        // Treiem l'imprès
        cua.pop();
        fets++;

        // Si es null fiquem mes nuls per completar a un arbre perfecte
        if (top == nullptr) {
            cua.push(nullptr);
            cua.push(nullptr);
        }
        // Sino els corresponents
        else {
            cua.push(top->left());
            cua.push(top->right());
        }

        /*
          Los numeros de la forma si k = 2^(n+1) -1 son  k = 01111111
          enotnces k+1 = 1000000
          entonces k & (k+1) = 0 combinando los bits

          Si k es de esta forma entonces habremos hecho los nodos de un arbol perfecto
          como la queue tiene los null para rellenar entonces k se esa forma dice que
          hay que hacer un salto de linea
        */
        if ((fets & (fets + 1)) == 0) {
            // Salt
            amplada /= 2;
            cout << endl;

            // Atura a l'ultim nivell
            if (amplada < base) continue;
            
            // Palitos que conecten els nodes
            int num_Nodes = pow(2, nivell);

            // Per a cada node del nivell imprimin els palets a sota de cada node
            // Clon de la cua
            queue<Position<Key, Value>*> copia = cua;
            
            // Per cada node del nivell actual
            for (int i = 0; i < num_Nodes; i++) {
                // Agafem els fills
                Position<Key, Value>* izq = copia.front(); copia.pop();
                Position<Key, Value>* der = copia.front(); copia.pop();
                
                // Fem les branques si hi ha fill
                string brancaIzq = (izq != nullptr) ? " /" : "  ";
                string brancaDer = (der != nullptr) ? "\\ " : "  ";
                
                cout << center(brancaIzq, amplada) << center(brancaDer, amplada);
            }
            cout << endl;
            nivell++;
        }
    }
}

#endif // BINARYTREE_H
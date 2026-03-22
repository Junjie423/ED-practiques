// Autor: Junjie Zhou

/*
Preguntes sobre la pràctica:
1. Tenint en compte la teva implementació del TAD LinkedList, indica per a cadascuna de les
operacions del TAD Llista quin és el seu cost computacional teòric. Justifica la resposta.
    Constructors i destructor:
    LinkedList(): Té complexitat O(1), perquè només crea dos NodeList (complexitat O(1)) i els 
    encadena un a l'altre i assigna 0 a l'atribut _size.

    LinkedList(initializer_list<Element> elements): Té complexitat O(n) on n és la longitud de
    initializer_list, ja que recorreix tota la llista per afegir nodes amb l'element un per un a la llista.

    LinkedList(const LinkedList& origen): Té complexitat O(n) on n és el size de la LinkedList que
    serveix com a parametre, perquè recorre tota la LinkedList amb un iterador de tipus Position
    per afegir nodes amb l'element a la llista (un per un).

    ~LinkedList(): També té complexitat O(n) perquè elimina un per un fins que la LinkedList estigui buida.

    Mètodes:
    size(): Té complexitat O(1), perquè només retorna el atribut _size.

    isEmpty(): Té complexitat O(1), només retorna si _size és igual a 0.

    beginning(): Té complexitat O(1), perquè accedeix directament al _next de NodeList (accesNext() de Nodelist té
    O(1) i next() de Position també té O(1)).

    end(): Té complexitat O(1) perquè accedeix directament a l'atribut _tail.

    insertAfter(Position<Element>& position, const Element& element): Té complexitat O(1), perquè només crea un nou 
    node amb l'element i actualitza els enllaços (setNext() i setPrevious() tenen complexitat O(1)).

    insertBefore(Position<Element>& position, const Element& element): Té també complexitat O(1), pel mateix motiu
    que insertAfter().

    insertBeginning(const Element& element): Té complexitat O(1), perquè crida a insertBefore() amb la posició del 
    beginning.

    insertEnd(const Element& element): També és O(1), perquè crida a insertBefore() amb la posició de end.

    deletePosition(Position<Element>& position): Té complexitat O(1), perquè crida només el mètode deletePosition de
    la classe Position, aquest métode és també de O(1), perquè només actualitza enllaços.

    print(): Aquest últim mètode té complexitat O(n), perquè ha de recorrer tota la LinkedList per imprimir per 
    pantalla, tots els elements, en ordre.


2. Creieu que la classe NodeList hauria estat millor implementar-la amb encadenaments simples?
Justifica la teva resposta.
    Crec que no hauria estat millor implementar la classe NodeList amb encadenaments simples perquè 
    si fossin cadenes simples, només podrem avançar per la llista i no podrem anar cap enrere. Aixó
    provocarà que els mètodes per inserir abans i inserir després, tindran una complexitat computacional 
    molt més elevada, ja que hauràn de recorrer en el pitjor cas tota la  llista per arribar a la posició 
    on cal inserir el nou node amb l'element. A més, per eliminar algún node, també tindrà complexitat O(n). 
    Finalment, els nodes _head i _tail, els dos fantasmes, sense doble encadenació, perden la funcionalitat 
    de simplificar el cost en afegir nodes al principi i al final. D'altra banda, en aquest cas, que no estem
    tractant una cua o una pila, no té sentit utilitzar encadenaments simples.

*/
#include "LinkedList.h"
#include "NodeList.h"
#include "Position.h"
#include <iostream>
using namespace std;

void casProva1(){
    LinkedList<int> list1;
    list1.insertBeginning(5);
    list1.insertBeginning(3);
    list1.insertEnd(7);
    list1.insertEnd(8);
    list1.print();
    try{
        Position<int> pos = list1.beginning();
        pos = list1.beginning(); list1.insertAfter(pos, 4); list1.print();
        pos = list1.beginning(); list1.insertBefore(pos, 2); list1.print();
        pos = list1.end(); list1.insertBefore(pos, 9); list1.print();
        pos = list1.beginning(); list1.insertAfter(pos, 5); list1.print();
        pos = list1.end(); list1.insertAfter(pos, 8); list1.print();
    }catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    int posicio, element;
    cout << "A quina posicio vols inserir" << endl;
    cin >> posicio;
    cout << "Quin element vols inserir" << endl;
    cin >> element;
    try {
        auto itr = list1.beginning();
        for (int i = 0; i < posicio; ++i){
            itr = ++itr;
        }
        list1.insertBefore(itr, element);
        list1.insertAfter(itr, element + 10);
    }catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    list1.print();
    cout << " Segona part de la prova 1 de la llista " << endl;
    LinkedList<int> list2 = {1, 2, 3, 4, 5};
    list2.print();
    Position<int> pos2 = list2.beginning();
    list2.deletePosition(pos2);
    list2.print();
    pos2 = list2.beginning();
    pos2 = ++pos2;
    list2.deletePosition(pos2);
    list2.print();
}

// Mètode que fa la primera pregunta
char inserirPrincipi(){
    string sn;
    do{
        cout << "Inserir al principi? (s/n) ";
        cin >> sn;
        if(sn != "s" && sn != "n"){
            cout << "Ha de ser 's' o 'n' en minúscules" << endl;
        }
    }while (sn != "s" && sn != "n");
    return sn[0];
}

// Mètode que fa la segona pregunta
char inserirFinal(){
    string sn;
    do{
        cout << "Inserir al final? (s/n) ";
        cin >> sn;
        if(sn != "s" && sn != "n"){
            cout << "Ha de ser 's' o 'n' en minúscules" << endl;
        }
    }while (sn != "s" && sn != "n");
    return sn[0];
}   

// Mètode que fa la tercera pregunta
char inserirPosicio(){
    string sn;
    do{
        cout << "Inserir abans de la posició? (s/n) ";
        cin >> sn;
        if(sn != "s" && sn != "n"){
            cout << "Ha de ser 's' o 'n' en minúscules" << endl;
        }
        cin.ignore(100,'\n');
    }while (sn != "s" && sn != "n");
    return sn[0];
}

void casProva2(){
    // Per si el casProva 1 dona error i l'entrada es manté
    if(cin.fail()){
        cin.clear();
        cin.ignore(100,'\n');
    }
    // Iniciem una llista
    LinkedList<string> llista = LinkedList<string>();
    // Demanem el nombre de paraules
    int num = -1;
    do {
        cout << "Introdueix quantes paraules vols inserir: ";
        cin >> num;
        if (cin.fail()){
            cin.clear();
            cin.ignore(100,'\n');
            num = -1;
        } 
    } while(num < 0);
    
    // Preguntem la paraula i afegim-ho a la posició que vol l'usuari
    while (num != 0){
        string paraula;
        cout << "Introdueix una paraula: ";
        cin >> paraula;
        char p1 = inserirPrincipi();
        // Si ho vol al principi
        if (p1 == 's'){
            llista.insertBeginning(paraula);
        } else{
            // Si ho vol al final
            char p2 = inserirFinal();
            if (p2 == 's'){
                llista.insertEnd(paraula);
            } else{
                // Si ho vol a una posició concreta
                int pos = -1;
                do {
                    cout << "A quina posició vols inserir? ";
                    cin >> pos;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(100,'\n');
                        pos = -1;
                    } 
                } while(pos < 0); 
                Position<string> actual = llista.beginning();
                while ( pos > 0 && actual!=llista.end()){
                    actual = actual.next();
                    pos--;
                }
                if(actual == llista.end()){
                    cout << "S'ha afegit per defecte al final de la llista" << endl;
                    llista.insertEnd(paraula);
                    num--;
                    continue;
                }
                // Si posa una posició que encara no hi ha elements, llavors per defecte s'afegeix al final
                char p3 = inserirPosicio();
                // Si ho vol abans de la posició
                if (p3 == 's'){
                    llista.insertBefore(actual, paraula);
                } else{
                    // Si ho vol després
                    llista.insertAfter(actual, paraula);
                }
            }
        }
        // Passem la següent paraula
        num--;
    }
    // imprimim la llista final
    llista.print();
}

int main(){
    casProva1();
    casProva2();
    return 0;
}
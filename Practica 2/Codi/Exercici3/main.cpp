// Autor: Junjie Zhou

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
    }while (sn != "s'"&& sn != "n");
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
                } while(num < 0); 
                Position<string> actual = llista.beginning();
                while ( pos > 0 && actual!=llista.end()){
                    actual = actual.next();
                    pos--;
                }
                if(actual == llista.end()){
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
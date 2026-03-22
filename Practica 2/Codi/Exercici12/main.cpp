// Autor: Junjie Zhou

#include <iostream>
#include "PilaEstatica.h"
#include <vector>
using namespace std;

// Mètode del cas de prova Ex1
void casProvaEx1(){

    // 1 Crear una PilaEstatica de mida 3
    PilaEstatica <int> pila(3);
    cout << "Estructura creada" << endl;

    // 2 "Inserir element 10"
    try {
        pila.anadirElemento(10);
        cout << "Element 10 agregat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 3 Inserir element 11
    try {
        pila.anadirElemento(11);
        cout << "Element 11 agregat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 4 Imprimir front
    try {
        cout << "Front: " << pila.elementoEncima() << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // "Inserir element 12"
    try {
        pila.anadirElemento(12);
        cout << "Element 12 agregat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 6 Inserir element 13
    try {
        pila.anadirElemento(13);
        cout << "Element 13 agregat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 7 Imprimir PilaEstatica
    pila.print();
    cout << "\n";

    // 8 Imprimir front
    try{
        cout << "Front: " << pila.elementoEncima() << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 9 Suprimir element
    try{
        pila.suprimirElemento();
        cout << "Element 12 eliminat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 10 Inserir element 14
    try{
        pila.anadirElemento(14);
        cout << "Element 14 agregat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 11 Imprimir PilaEstatica
    pila.print();
    cout << endl;

    // 12 Imprimir front
    cout << "Front: " << pila.elementoEncima() << endl;

    // 13 Suprimir element
    try{
        pila.suprimirElemento();
        cout << "Element 14 eliminat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }
    // 14 Suprimir element
    try{
        pila.suprimirElemento();
        cout << "Element 11 eliminat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 15 Suprimir element
    try{
        pila.suprimirElemento();
        cout << "Element 10 eliminat" << endl;
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }

    // 16 Suprimir element
    try {
        pila.suprimirElemento();
    } catch (exception &e) {
        cout << "EXEPTION: " << e.what() << endl;
    }
}

// Mètode del cas de prova amb menú
void casProvaMenu(){
    string arr_options[] = {"1. Inserir element a la pila", "2. Suprimir element de la pila", 
                            "3. Consultar el top de la pila", "4. Imprimir tot el contingut de la PilaEstatica", 
                            "5. Imprimir la posició del top de la pila", "6. Sortir" };
    vector<string> options (arr_options, arr_options+6);
    // Creem una variable per guardar l'opció
    int option = -1;
    // Iniciem la pila
    PilaEstatica<int> pila;
    cout << "Hola, benvingut a la pila" << endl;
    while(option != 6){
        option = -1;
        // Utilitzant while podem fer que mostri el menu
         while(option < 0 || option > 6){
            cout << "Que vols fer?" << endl;
            for (auto itr = options.begin(); itr != options.end(); ++itr) {
                cout << *itr << endl;
            }
            //Guardem l'opció de l'usuari
            cin >> option;
            // Comprovem que l'usuari hagi introduït un numero, si no, llançem excepció i assignem -1 a option
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                option = -1;
            }
        }// Fem que demani sempre que l'opcio no sigui els que hi hagin
        
        // Creem un switch amb l'opció de l'usuari
        switch(option){
        // Cas Inserir element a la pila
        case 1:
            try{
                int num;
                cout << "Element que vols inserir: ";
                cin >> num;
                cout << endl;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw invalid_argument("Ha de ser un enter");
                }
                pila.anadirElemento(num);
                cout << "Element " << pila.elementoEncima() << " agregat" << endl;
            } catch(exception &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas suprimir element de la pila
        case 2:
            try{
                // Creem una variable per guardar l'element que s'eliminarà
                int elim = pila.elementoEncima();
                pila.suprimirElemento();
                cout << "Element " << elim << " eliminat" << endl;
            } catch(exception &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas consultar top
        case 3:
            try{
                cout << "Front: " << pila.elementoEncima() << endl;
            } catch(exception &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas imprimir pila
        case 4:
            try{
                pila.print();
                cout << endl;
            } catch(exception &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
         // Cas imprimir posició top
        case 5:
            try{
                if (pila.estaVacia()){
                    throw out_of_range("L'estructura està buida");
                }
                cout << "Posicio del top: " << pila.tamano() - 1 << endl;
            } catch(exception &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas sortir
        case 6: 
            cout << "Sortint de la pila" << endl;
            break;
        }
    }
}

// Implementem i adaptem el pseudocodi per moure elements
void logistica(int n, PilaEstatica<int> &pA, PilaEstatica<int> &pB, PilaEstatica<int> &pP){
    // Si n == 1, llavors moure un paquet de pA a pB i mostrar l'estat intermig
    if (n == 1){
        int elemMogut = pA.elementoEncima();
        pA.suprimirElemento();
        pB.anadirElemento(elemMogut);
        // Imprimir l'estat intermig
        cout << "L'estat intermig és el següent:" << endl;
        cout << "A: Pila = ";
        pA.print();
        cout << " tamaño = " << pA.tamano() << endl;
        cout << "P: Pila = ";
        pP.print();
        cout << " tamaño = " << pP.tamano() << endl;
        cout << "B: Pila = ";
        pB.print();
        cout << " tamaño = " << pB.tamano() << endl;
    } else{
        logistica(n-1, pA, pP, pB);
        logistica(1, pA, pB, pP);
        logistica(n-1, pP, pB, pA);
    }
}

// Mètode del cas de prova Ex2
void casProvaEx2(){
    // Demanem a l'usuari el nombre de paquets i iniciem la pila A amb el quart constructor
    int pack;
    cout << "Hola, sóc el braç robòtic." << endl;
    cout << "Introdueix el nombre de paquets: ";
    cin >> pack;
    cout << endl;
    vector <int> A;
    for (int i = pack; i >= 1; --i){
        A.push_back(i);
    }
    PilaEstatica<int> pilaA(A);
    // Iniciem les altres dues piles
    PilaEstatica<int> pilaB(pack);
    PilaEstatica<int> pilaP(pack);

    // Mostrem l'estat incial
    cout << "L’estat inicial és el següent:" << endl;
    cout << "A: ";
    pilaA.print();
    cout << endl;
    cout << "P: ";
    pilaP.print();
    cout << endl;
    cout << "B: ";
    pilaB.print();
    cout << endl;

    // Cridem la funció logistica per fer els canvis
    cout << endl;
    logistica(pack, pilaA, pilaB, pilaP);
    cout << endl;

    // Mostrem l'estat final
    cout << "L’estat final és el següent:" << endl;
    cout << "A: ";
    pilaA.print();
    cout << endl;
    cout << "P: ";
    pilaP.print();
    cout << endl;
    cout << "B: ";
    pilaB.print();
    cout << endl;

}

int main() {
    casProvaEx1();
    casProvaMenu();
    casProvaEx2();
    return 0;
}                                                                                                                                                                                                                                                                                                                  
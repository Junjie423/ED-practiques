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
        cout << "Que vols fer?" << endl;
        // Utilitzant el do...while... podem fer que mostri almenys una vegada el menu
        do{
            for (int i = 0; i < options.size(); i++) {
                cout << options[i] << endl;
            }
            //Guardem l'opció de l'usuari
            cin >> option;
            // Comprovem que l'usuari hagi introduït un numero, si no, llançem excepció i assignem -1 a option
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                option = -1;
            }
        // Fem que demani sempre que l'opcio no sigui els que hi hagin
        } while(option < 0 || option > 6);
        
        // Creem un switch amb l'opció de l'usuari
        switch(option){
        // Cas Inserir element a la pila
        case 1:
            try{
                int num;
                cout << "Element que vols inserir: ";
                cin >> num;
                if(cin.fail()){
                    throw new invalid_argument("Ha de ser un enter");
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
            } catch(exception &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
         // Cas imprimir posició top
        case 5:
            try{
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

int main() {
    casProvaEx1();
    casProvaMenu();
    
    return 0;
}
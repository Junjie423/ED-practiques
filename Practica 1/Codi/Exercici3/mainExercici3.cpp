// Autor: Junjie Zhou

#include <vector>
#include <iostream>
#include "Estudiant.h"
#include <exception>
#include <fstream>
using namespace std;

// Definim el mètode que ens mostrara per pantalla el menu
// Parametres: vector amb el menu
// Retorna un int, l'opcio introduït per l'usuari
int show_menu(vector<string> options){
    // Creem una variable per guardar l'opció de l'usuari
    int option;
    // Utilitzant el do...while... podem fer que mostri almenys una vegada
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
    } while(option < 1 || option > 4);

    return option;
}
// Definim el mètode que demana l'usuari l'informació de l'estudiant
// Posem un & abans del parametre que rep, així rebrà una referència del parametre, i si es modifica en el mètode
// quan torni al main() la modificació es guarda
// Parametres: l'enllaç del nombre d'Estudiant
void demanar(int &numEstudiants){
    // Creem variables per guardar la informació i demanem a l'usuari que els ompli
    string nom;
    int any;
    int assignatures;
    cout << "Nom? ";
    cin >> nom;
    cout << "Anys naixement? ";
    cin >> any;
    // Si lany de naixement es incorrecte, llença una excepció
    if (any < 0 || any > 2026){
        throw invalid_argument("Error: Any incorrecte!");
    }
    cout << "Assignatures? ";
    cin >> assignatures;
    // Creem l'objecte estudiant 1 amb la informació rebuda
    Estudiant e1(nom, any, assignatures);
    // Cridem el mètode print() de l'objecte, perquè mostri per pantalla la informació de l'estudiant
    e1.print();
    // Cridem el mètode getEdat de l'objecte perquè ens retorni l'edat
    cout << "Edat del nou estudiant: " << e1.getEdat() << endl << endl;
    // Augmentem el numero d'estudiants
    numEstudiants += 1;
}
// Definim el mètode que llegeis el fitxer
// Parametres: l'enllaç del nombre d'estudiants
void llegirFitxer(int &num_estudiants) {
    string nom;
    int any, assignatura;
    ifstream meu_fitxer("fitxer.txt");
    cout << "Ruta arxiu" << endl;
    cout << "fitxer.txt" << endl;
    if (!meu_fitxer.is_open()){
        throw runtime_error("No s'ha pogut obrir l'arxiu");
    }
    while (!meu_fitxer.eof()) {
        meu_fitxer >> nom;
        meu_fitxer >> any;
        meu_fitxer >> assignatura;
        if (any < 0 || any > 2026){
            throw invalid_argument("Any d'algun alumne, incorrecte!");
        }
        Estudiant e1(nom, any, assignatura);
        e1.print();
        num_estudiants += 1;
    }
    meu_fitxer.close();
}
int main(){
    // Creem una variable per guardar l'opcio de l'usuari
    int option;
    // Creem una variable per guardar el nombre d'estudiant i l'iniciem com 1.
    int estudiants;
    estudiants = 1;
    // Creem un array amb el menu i un vector per emmagatzemar-ho
    string arr_options[] = {"1. Sortir", "2. Afegir estudiant", "3. Llegir fitxer", "4. Resum estudiants"};
    vector<string> options (arr_options, arr_options+4);

    // Creem el bucle principal que repeteix fins que l'opció sigui 1.
    do{
        cout << "Hola, que vols fer?" << endl;
        option = show_menu(options);
        // Creem un switch amb l'opció de l'usuari
        switch(option){
        // Cas sortir
        case 1: 
            cout << "Fins a la propera" << endl;
            break;
        // Cas informar estudiant
        case 2:
            cout << "Estudiant: " << estudiants << endl;
            // Fem un try-catch al mètode demanar() per capturar una possible excepció
            try{
                demanar(estudiants);
            } catch(invalid_argument& e){
                cout << e.what() << endl;
            }
            break;
        // Cas llegir fitxer
        case 3:
            // Fem un try-catch al metode llegirFitxer() per capturar les excepcions
            try{
               llegirFitxer(estudiants); 
            } catch(runtime_error& e){
                cout << "Error: " << e.what() << endl;
            } catch(invalid_argument& e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas Resum estudiants
        case 4:
            // Cal restar 1 al nombre d'estudiants, perquè l'hem iniciat amb 1
            cout << "Estudiants creats: " << (estudiants - 1) << endl << endl;
            break;
        }
    }while(option !=1);
    return 0;
}
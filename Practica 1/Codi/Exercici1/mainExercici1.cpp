// Autor: Junjie Zhou

#include <vector>
#include <iostream>
using namespace std;

// Definim el mètode que ens mostrara per pantalla el menu
// Parametres: nom, vector amb el menu
// Retorna un int, l'opcio introduït per l'usuari
int show_menu(string name, vector<string> options){
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
    } while(option < 1 || option > 3);

    return option;
}
// Definim un mètode que dona la benvinguda
// Parametres: nom
void hello_world(string name){
    cout << "Benvingut/da a l'assignatura d'estructura de dades " << name << endl;
}
int main(){
    // Creem variables per guardar l'opció i el nom de l'alumne
    int option;
    string name;
    // Creem l'array amb el menu i el vector que emmagatzema el menu
    string arr_options[] = {"1. Sortir", "2. Benvinguda", "3. Redefinir nom"};
    vector<string> options (arr_options, arr_options+3);

    cout << "Hola, com et dius? ";
    cin >> name;

    // Creem el bucle principal que itera fins que option sigui 1
    do{
        cout << "Hola " << name << ", que vols fer?" << endl;
        // Guardem en la variable option, l'opció introduït per l'usuari
        option = show_menu(name, options);
        // Si l'opció és 2, crida a hello_world()
        if(option==2){
            hello_world(name);
        // Si l'opció és 3, torna a demanar el nom i ho actualitza
        } else if(option==3){
            cout << "Hola, com et dius? ";
            cin >> name;
        }
    } while(option != 1);
    // Quan l'usuari introdueix 1
    cout << "Fins a la propera " << name << endl;
    return 0;
}
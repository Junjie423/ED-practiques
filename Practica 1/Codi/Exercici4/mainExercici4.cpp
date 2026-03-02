// Autor: Junjie Zhou

#include <vector>
#include <iostream>
#include "Llibre.h"
#include "Usuari.h"
#include <exception>
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
    } while(option < 0 || option > 6);

    return option;
}

// Definim el mètode que afegeix usuaris al vector usuaris
// Parametres: vector on emmagatzemar usuaris de la biblio
void afegirUsuari(vector<Usuari>& usuaris){
    string nom, adreca, poblacio, telefon, dni;
    int edat;
    // Demanem les dades per pantalla
    cout << "Introdueix les dades de l'usuari:" << endl;
    cout << "Nom: ";
    cin >> nom;
    cout << "Adreça: ";
    cin >> adreca;
    cout << "Poblacio: ";
    cin >> poblacio;
    cout << "telefon: ";
    cin >> telefon;
    cout << "DNI: ";
    cin >> dni;
    cout << "Edat: ";
    cin >> edat;

    // Comprovem que l'usuari no existeixi en el vector usuaris
    for (vector<Usuari>::const_iterator it = usuaris.begin(); it != usuaris.end(); it++){
        // Si el DNI existeix, llavors llancem una excepció i retornem al main
        if (it->getDNI() == dni){
            throw invalid_argument("Usuari existent, no s'ha pogut afegir");
        }
    }
    // Si no existeix, llavors creem l'usuari nou i l'afegim al vector
    Usuari nouUsuari = Usuari(nom, adreca, poblacio, telefon, dni, edat);
    usuaris.push_back(nouUsuari);
    cout << "Usuari afegit correctament" << endl;

    // Preguntem a l'usuari si vol afegir un llibre a aquest usuari
    // Utilitzant un char per guardar s (si) o n (no)
    char resposta;
    cout << "Vols afegir un llibre a aquest usuari? (s/n)" << endl;
    cin >> resposta;
    if (resposta == 's'){
        string titol, autor, isbn;
        int anyPublicacio;
        cout << "Introdueix les dades del llibre:" << endl;
        cout << "Titol: ";
        cin >> titol;
        cout << "Autor: ";
        cin >> autor;
        cout << "ISBN: ";
        cin >> isbn;
        cout << "Any de publicacio: ";
        cin >> anyPublicacio;

        // Podem fer .back() ja que el nou usuari serà l'ultim element del vector
        // Utilitzant el mètode afegeixLlibre de la classe Usuari, afegim el llibre a aquest usuari del vector
        usuaris.back().afegeixLlibre(titol, autor, isbn, anyPublicacio);
        cout << "Llibre afegit correctament" << endl;
    }
}

// Definim el mètode que elimina un usuari del vector usuaris
// Parametres: vector on emmagatzemar usuaris de la biblio
void eliminarUsuari(vector<Usuari>& usuaris){
    string dni;
    cout << "Introdueix el DNI de l'usuari que vols eliminar: " << endl;
    cin >> dni;
    // Utilitzem un iterador que recorrerà el vector
    for (vector<Usuari>::const_iterator it = usuaris.begin(); it != usuaris.end(); ++it){
        // Si trobem el DNI, eliminem l'usuari del vector
        if(it->getDNI() == dni){
            usuaris.erase(it);
            cout << "Usuari eliminat correctament" << endl;
            // Retornem al main quan acabi d'eliminar l'usuari
            return;
        }
    }
    // En cas de no trobar l'usuari, llença una excepció
    throw invalid_argument("No s'ha pogut trobar l'usuari amb DNI: " + dni);
}

// Definim el mètode que afegeix un llibre a un usuari
// Parametres: vector on emmagatzemar usuaris de la biblio
void afegirLlibre(vector<Usuari>& usuaris){
    string dni, titol, autor, isbn;
    int anyPublicacio;
    // Demanem el DNI de l'usuari
    cout << "Introdueix el DNI de l'usuari al que vols afegir un llibre: " << endl;
    cin >> dni;
    // Demanem les dades del llibre
    cout << "Introdueix les dades del llibre:" << endl;
    cout << "Titol: ";
    cin >> titol;
    cout << "Autor: ";
    cin >> autor;
    cout << "ISBN: ";
    cin >> isbn;
    cout << "Any de publicacio: ";
    cin >> anyPublicacio;
    // Creem un iterador normal per assegurar que existeixi l'usuari i poder afegir el llibre
    for (vector<Usuari>::iterator it = usuaris.begin(); it != usuaris.end(); ++it){
        if(it->getDNI() == dni){
            // Si existeix, afegim el llibre a aquest usuari
            it->afegeixLlibre(titol, autor, isbn, anyPublicacio);
            cout << "Llibre afegit correctament" << endl;
            // Retornem al main quan acabi d'afegir el llibre
            return;
        }
    }
    // En cas de no trobar l'usuari, llença una excepció
    throw invalid_argument("No s'ha pogut trobar l'usuari amb DNI: " + dni);
}

// Definim el mètode que elimina un llibre d'un usuari
// Parametres: vector on emmagatzemar usuaris de la biblio
void eliminarLlibre(vector<Usuari>& usuaris){
    string dni, titol;
    // Demanem el DNI de l'usuari
    cout << "Introdueix el DNI de l'usuari: ";
    cin >> dni;
    // Demanem el titol del llibre a eliminar
    cout << "Introdueix el titol del llibre que vols eliminar: ";
    cin >> titol;
    // Creem un iterador per assegurar que existeixi l'usuari
    for (vector<Usuari>::iterator it = usuaris.begin(); it != usuaris.end(); ++it){
        if(it->getDNI() == dni){
            // Si existeix, utilitzant el mètode eliminaLlibre de la classe Usuari eliminem el llibre
            it->eliminaLlibre(titol);
            cout << "Llibre eliminat correctament" << endl;
            // Aquest mètode busca primer si existeix el llibre, si no existeix, mostra un missatge per pantalla
        // Retornem al main quan acabi d'eliminar el llibre
        return;
        }
    }
    // Si no existeix el llibre, llençem una excepció
    throw invalid_argument("No s'ha pogut trobar el llibre amb titol: " + titol);
}

// Definim el mètode que imprimeix els usuaris de la biblioteca municipal
// Parametres: vector on emmagatzemar usuaris de la biblio
void imprimirUsuaris(const vector<Usuari>& usuaris){
    // Utilitzant un iterador que recorre el vector, fem que faci print a cada usuari
    for(vector<Usuari>::const_iterator it = usuaris.begin(); it != usuaris.end(); ++it){
        it->print();
    }
}

// Definim el mètode que imprimeix els llibres d'un usuari
// Parametres: vector on emmagatzemar usuaris de la biblio
void imprimirLlibresUsuari(const vector<Usuari>& usuaris){
    string dni;
    // Demanem el DNI de l'usuari
    cout << "Introdueix el DNI de l'usuari del que vols consultar els llibres: ";
    cin >> dni;
    // Creem un iterador per assegurar que existeixi l'usuari
    for (vector<Usuari>::const_iterator it = usuaris.begin(); it != usuaris.end(); ++it){
        // Si existeix l'usuari
        if(it->getDNI() == dni){
            it->mostraLlibres();
            // Retornem al main quan acabi d'imprimir els llibres
            return;
        }
    }
    // Si no existeix l'usuari, llençem una excepció
    throw invalid_argument("No s'ha pogut trobar l'usuari amb DNI: " + dni);
}

int main(){
    // Creem una variable per guardar l'opcio de l'usuari
    int option;
    // Creem el vector usuaris biblio
    vector<Usuari> usuaris_biblio;
    // Creem un array amb el menu i un vector per emmagatzemar-ho
    string arr_options[] = {"0. Sortir", "1. Afegir Usuari", "2. Eliminar Usuari", "3. Afegir LLibre a un usuari", 
                            "4. Eliminar LLibre d'un usuari", "5. Imprimir usuaris de la biblioteca municipal",
                            "6. Imprimir els libres d’un usuari"};
    vector<string> options (arr_options, arr_options+7);

    // Creem el bucle principal que repeteix fins que l'opció sigui 0.
    do{
        cout << "Hola, que vols fer?" << endl;
        option = show_menu(options);
        // Creem un switch amb l'opció de l'usuari
        switch(option){
        // Cas sortir
        case 0: 
            cout << "Tancant biblioteca municipal, fins a la propera" << endl;
            break;
        // Cas afegir usuari
        case 1:
            try{
               afegirUsuari(usuaris_biblio);
            } catch(invalid_argument &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas eliminar usuari
        case 2:
            try{
                eliminarUsuari(usuaris_biblio);
            } catch(invalid_argument &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas afegir llibre a un usuari
        case 3:
            try{
                afegirLlibre(usuaris_biblio);
            } catch(invalid_argument &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas eliminar llibre d'un usuari
        case 4:
            try{
                eliminarLlibre(usuaris_biblio);
            } catch(invalid_argument &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas imprimir usuaris de la biblioteca municipal
        case 5:
            try{
                imprimirUsuaris(usuaris_biblio);
            } catch(invalid_argument &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        // Cas imprimir els libres d’un usuari
        case 6:
            try{
                imprimirLlibresUsuari(usuaris_biblio);
            } catch(invalid_argument &e){
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
    }while(option !=0);
    return 0;
}
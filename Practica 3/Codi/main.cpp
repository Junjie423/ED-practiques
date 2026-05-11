#include "Position.h"
#include "BinaryTree.h"
#include "Tuple.h"
#include "WordIndexer.h"
#include <iostream>
#include <chrono>
#include <stdexcept>
using namespace std;

void mainExercici1(){
    BinaryTree<int, int> tree1;
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40}; 
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};

    for (int i = 0; i < 8 ; i++) { 
        cout << "Inserta a l'arbre la key " << testKeys[i] << " amb valor " << testValues[i] << endl;
        tree1.insert(testKeys[i], testValues[i]);
    }
    
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;
   
    cout << "Postorder = [";
    tree1.printPostOrder();
    cout << "]" << endl;

    BinaryTree<int, int> tree2(tree1);
    cout << " identics " << tree1.identicalTree(tree2) << endl; 
    
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;

    tree2.insert(4, 4); 
    cout << " identics " << tree2.identicalTree(tree1) << endl; 
    
    cout << "Preorder = [";
    tree2.printPreOrder();
    cout << "]" << endl;

    vector<int> result = tree2.getLeaves();
    cout << "fulles arbres = " ;

    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
} 

void opcio1(){
    string entrada = "res";
    while (entrada != "P" && entrada!= "G" && entrada != "p" && entrada != "g"){
        cout << "Quin fitxer vols (P/G)?" ;
        cin >> entrada;
        
        WordIndexer wordIn;
        if(entrada == "P" || entrada == "p"){
            chrono::steady_clock::time_point begin = chrono::steady_clock::now();
            wordIn = *new WordIndexer("shortText.txt");
            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end -begin).count() << " s." << endl;
        } else if (entrada == "G" || entrada == "g"){
            chrono::steady_clock::time_point begin = chrono::steady_clock::now();
            wordIn = *new WordIndexer("longText.txt");
            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end -begin).count() << " s." << endl;
        } else{
            cout << "Ha de ser P o G" << endl;
        }
    }
}

void opcio2(){

}

void opcio3(){
    
}

void opcio4(){
    
}

void opcio5(){
    
}

void mainExercici2(){
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    // Aquí el vostre codi del que en voleu mesurar el temps d'execució
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::seconds>(end -begin).count() << " s." << endl;

    string arr_options[] = {"1. Llegir fitxer", "2. Mostrar l'arbre", 
                            "3. Llegir fitxer dictionary.txt", "4. Generar índex de paraules", 
                            "5. Profunditat de l'arbre", "6. Sortir" };
    vector<string> options (arr_options, arr_options+6);
    // Creem una variable per guardar l'opció
    int option = -1;

    // creem el bucle principal
    cout << "Benvingut al WordIndexer" << endl;
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
        // Cas llegir un fitxer
        case 1:
            try{
                opcio1();
            }catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas mostrar l'arbre creixent
        case 2:
            try{
                opcio2();
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas llegir fitxer dictionary.txt
        case 3:
            try{
                opcio3();
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas generar índex de paraules
        case 4:
            try{
                opcio4();
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
         // Cas calcular profunditat de l'arbre
        case 5:
            try{
                opcio5();
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas sortir
        case 6: 
            cout << "Sortint del WordIndexer..." << endl;
            break;
        }
    }
}

int main(){
    //mainExercici1();
    mainExercici2();
    return 0;
}
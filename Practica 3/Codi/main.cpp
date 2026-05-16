#include "Position.h"
#include "BinaryTree.h"
#include "Tuple.h"
#include "WordIndexer.h"
#include "WordIndexer.cpp"
#include "BalancedTree.h"
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

void opcio1(WordIndexer*& wordIn){
    if(wordIn != nullptr) { 
        delete wordIn;
        wordIn = nullptr;
    }
    string entrada = "start";
    while (entrada != "P" && entrada!= "G" && entrada != "p" && entrada != "g"){
        cout << "Quin fitxer vols (P/G)? " ;
        cin >> entrada;
        if(entrada == "P" || entrada == "p"){
            chrono::steady_clock::time_point begin = chrono::steady_clock::now();
            wordIn = new WordIndexer("shortText.txt");
            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            cout << "Arbre creat correctament" << endl;
            cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
        } else if (entrada == "G" || entrada == "g"){
            chrono::steady_clock::time_point begin = chrono::steady_clock::now();
            wordIn = new WordIndexer("longText.txt");
            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            cout << "Arbre creat correctament" << endl;
            cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
        } else{
            cout << "Ha de ser P o G" << endl;
        }
    }
}

void opcio2(WordIndexer*& wordIn){
    if (wordIn->size() == 0){
        throw out_of_range("L'arbre està buit");
    }
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    wordIn->print40(); 
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;

}

void opcio3(WordIndexer*& wordIn){
    if (wordIn->size() == 0){
        throw out_of_range("L'arbre està buit");
    }
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    ifstream file("dictionary.txt");
    if(!file.is_open()){
        throw runtime_error("No s'ha pogut obrir el fitxer");
    }
    string linia;
    while(getline(file, linia)){
        
        stringstream ss(linia);
        string paraula;
        while (ss >> paraula)
            wordIn->contains(paraula);
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
}

void opcio4(WordIndexer*& wordIn){
    if (wordIn->size() == 0){
        throw out_of_range("L'arbre està buit");
    }
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    wordIn->printDictionary(); 
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
}

void opcio5(WordIndexer*& wordIn){
    if (wordIn->size() == 0){
        throw out_of_range("L'arbre està buit");
    }
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    cout << "La profunditat de l'arbre guardat: " << wordIn->height() << endl;
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
}

void mainExercici2(){
    string arr_options[] = {"1. Llegir fitxer", "2. Mostrar l'arbre", 
                            "3. Cercar a dictionary.txt", "4. Generar índex de paraules", 
                            "5. Profunditat de l'arbre", "6. Sortir" };
    vector<string> options (arr_options, arr_options+6);
    // Creem una variable per guardar l'opció
    int option = -1;

    WordIndexer* wordIn = nullptr;
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
                opcio1(wordIn);
            }catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas mostrar l'arbre creixent
        case 2:
            try{
                opcio2(wordIn);
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas llegir fitxer dictionary.txt
        case 3:
            try{
                opcio3(wordIn);
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas generar índex de paraules
        case 4:
            try{
                opcio4(wordIn);
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
         // Cas calcular profunditat de l'arbre
        case 5:
            try{
                opcio5(wordIn);
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

void mainExercici3(){
    BalancedTree<int, int> tree1;
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

    BalancedTree<int, int> tree2(tree1);
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
    tree2.print();
} 

int main(){
    //mainExercici1();
    //mainExercici2());
    //mainExercici3();
    
    cout << "   ---  Arbre buit ---" << endl;
    cout << "---  Type '-1' per tancar --- " << endl;
    BalancedTree<int,int> arbre;
    int nou = 0;
    while (nou != -1){
        cout << "Nou element: ";
        cin >> nou;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Només Integers! (-1 per tancar)"<< endl;
        }
        else if (nou != -1)
            arbre.insert(nou,0);
        arbre.print();
    }
    return 0;
    
}
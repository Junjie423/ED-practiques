#include "Position.h"
#include "BinaryTree.h"
#include "Tuple.h"
#include "WordIndexer.h"
#include "BalancedTree.h"
#include "WordIndexerBalanced.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <stdexcept>
using namespace std;
/*
            Exercici 5: Taula temps de generació de l'estructura i cerca
            +--------------+-----------+-----------+------------+----------+----------+--------------+
            |              | Inserció  | Inserció  |  Inserció  |  Cerca   |  Cerca   |    Cerca     |
            |              |  Fitxer   |  Fitxer   |  Fitxer    |  Fitxer  |  Fitxer  |    Fitxer    |
            |              |   SHORT   |   LONG    | UNBALANCED |  SHORT   |   LONG   |  UNBALANCED  |
            +--------------+-----------+-----------+------------+----------+----------+--------------+
            | BinaryTree   |   599 μs  | 27208 μs  | 3470716 μs | 296760 μs| 436581 μs| 126665822 μs |     
            +--------------+-----------+-----------+------------+----------+----------+--------------+
            | BalancedTree |  1279 μs  | 32757 μs  | 20667 μs   | 225178 μs| 374422 μs| 353041 μs    |
            +--------------+-----------+-----------+------------+----------+----------+--------------+

            Comparant el temps que triga en crear l'arbre i cercar el dictionary.txt en l'arbre amb els tres fitxers diferents
            podem veure que per a fitxers petits, el BinaryTree és més ràpid en la inserció, perquè no ha de fer cap operació per 
            rotar l'arbre i actualitzar les altures, però en fitxer més grans o en el cas de unbalanced, el BalancedTree és molt més
            ràpid a l'hora d'insertar, ja que manté l'arbre equilibrat, mentre que el BinaryTree es pot convertir en un arbre linela
            (en el cas de unbalanced) i per tant la inserció es torna lenta. 
            En el cas de la cerca, el BalancedTree és més eficient i ràpid que el BinaryTree, ja que manté l'arbre equilibrat i per tant
            la profunditat de l'arbre és menor, i també perquè el mètode contains() de BalancedTree manté la complexitat O(log n) en el 
            pitjor cas, mentre que el BinaryTree pot arribar a tenir complexitat O(n) en el pitjor cas (arbre lineal), com en el cas de 
            unbalanced, on el BinaryTree s'ha construit com una mena de llista enllaçada i per tant la cerca triga molt de temps (2 min),
            en canvi en Balancedtree només triga 0,35 s.

*/


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
                // Si el fitxer no era nullptr, ho eliminem i l'assignem nullptr
                if(wordIn != nullptr) { 
                    delete wordIn;
                    wordIn = nullptr;
                }
                // Creem un bucle per demanar a l'usuari quin fitxer vol llegir i creem el WordIndexer amb el fitxer escollit i calculem el temps que triga en crearse
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
            }catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas mostrar l'arbre creixent
        case 2:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funció de printar de 40 en 40 i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                wordIn->print40(); 
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas llegir fitxer dictionary.txt
        case 3:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funcio que comprova si les paraules del dictionary estan a l'arbre i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                ifstream file("dictionary.txt");
                if(!file.is_open()){
                    throw runtime_error("No s'ha pogut obrir el fitxer");
                }
                string paraula;
                while(file >> paraula){
                    wordIn->contains(paraula);
                }
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas generar índex de paraules
        case 4:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funció que imprimeix tot l'arbre amb les paraules i les tuples i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                wordIn->printDictionary(); 
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
         // Cas calcular profunditat de l'arbre
        case 5:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funció que calcula la profunditat de l'arbre i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                cout << "La profunditat de l'arbre guardat: " << wordIn->height() << endl;
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
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
} 

void mainExercici4(){
    string arr_options[] = {"1. Llegir fitxer", "2. Mostrar l'arbre", 
                            "3. Cercar a dictionary.txt", "4. Generar índex de paraules", 
                            "5. Profunditat de l'arbre", "6. Sortir" };
    vector<string> options (arr_options, arr_options+6);
    // Creem una variable per guardar l'opció
    int option = -1;

    WordIndexerBalanced* wordIn = nullptr;
    // creem el bucle principal
    cout << "Benvingut al WordIndexerBalanced" << endl;
    while (option != 6){
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
                // Si el fitxer no era nullptr, ho eliminem i l'assignem nullptr
                if(wordIn != nullptr) { 
                    delete wordIn;
                    wordIn = nullptr;
                }
                // Creem un bucle per demanar a l'usuari quin fitxer vol llegir i creem el WordIndexer amb el fitxer escollit i calculem el temps que triga en crearse
                string entrada = "start";
                while (entrada != "P" && entrada!= "G" && entrada != "p" && entrada != "g"){
                    cout << "Quin fitxer vols (P/G)? " ;
                    cin >> entrada;
                    if(entrada == "P" || entrada == "p"){
                        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                        wordIn = new WordIndexerBalanced("shortText.txt");
                        chrono::steady_clock::time_point end = chrono::steady_clock::now();
                        cout << "Arbre creat correctament" << endl;
                        cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
                    } else if (entrada == "G" || entrada == "g"){
                        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                        wordIn = new WordIndexerBalanced("longText.txt");
                        chrono::steady_clock::time_point end = chrono::steady_clock::now();
                        cout << "Arbre creat correctament" << endl;
                        cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
                    } else{
                        cout << "Ha de ser P o G" << endl;
                    }
                }
            }catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas mostrar l'arbre creixent
        case 2:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funció de printar de 40 en 40 i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                wordIn->print40(); 
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas llegir fitxer dictionary.txt
        case 3:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funcio que comprova si les paraules del dictionary estan a l'arbre i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                ifstream file("dictionary.txt");
                if(!file.is_open()){
                    throw runtime_error("No s'ha pogut obrir el fitxer");
                }
                string paraula;
                while(file >> paraula){
                    wordIn->contains(paraula);
                }
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas generar índex de paraules
        case 4:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                 if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funció que imprimeix tot l'arbre amb les paraules i les tuples i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                wordIn->printDictionary(); 
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
         // Cas calcular profunditat de l'arbre
        case 5:
            try{
                // Si l'arbre està buit, llançem excepció o si és nullptr també
                 if (wordIn == nullptr || wordIn->size() == 0){
                    throw out_of_range("L'arbre està buit");
                }
                // Cridem la funció que calcula la profunditat de l'arbre i mesurem el temps que triga
                chrono::steady_clock::time_point begin = chrono::steady_clock::now();
                cout << "La profunditat de l'arbre guardat: " << wordIn->height() << endl;
                chrono::steady_clock::time_point end = chrono::steady_clock::now();
                cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs." << endl;
            } catch (exception &e){
                cerr << "Error: " << e.what() << endl;
            }
            break;
        // Cas sortir
        case 6: 
            cout << "Sortint del WordIndexerBalanced..." << endl;
            break;
        }
    }
}

void cal_TempsCerca(WordIndexer* wordId){
    // Calculem el temps que triga en cercar les paraules del dictionary.txt al wordIndexer introduït com a parametre
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    ifstream dades ("dictionary.txt");
    if (!dades.is_open())                    
        throw runtime_error("No s'ha pogut obrir dictionary.txt");
    
    string paraula;         
    while (dades >> paraula)                        
        wordId-> contains(paraula);                    
    dades.close();
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end -begin).count() << " µs" << endl;
}

void mainExercici5(){
    /* Calculem el temps que triga en crear un WordIndexer i un WordIndexerBalanced amb els fitxers 
        shortText.txt, longText.txt i unbalancedText.txt i el temps que triga en cercar les paraules del dictionary.txt
        a cada un dels WordIndexers creats
    */

    cout << "--- Per el BinaryTree --- " << endl;
    WordIndexer* wordIn;
    cout << "    Cas Short: " << endl;
    cout << " -> Inserció: ";
    chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();
    wordIn = new WordIndexer("shortText.txt");
    chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end1 -begin1).count() << " µs" << endl;
    cout << " -> Cerca: " ;
    cal_TempsCerca(wordIn);

    delete wordIn; 
    wordIn = nullptr;

    cout << endl << "    Cas Long: " << endl;
    cout << " -> Inserció: ";
    chrono::steady_clock::time_point begin2 = chrono::steady_clock::now();
    wordIn = new WordIndexer("longText.txt");
    chrono::steady_clock::time_point end2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end2 -begin2).count() << " µs" << endl;
    cout << " -> Cerca: " ;
    cal_TempsCerca(wordIn);

    delete wordIn;
    wordIn = nullptr;

    cout << endl << "    Cas Unbalanced: " << endl;
    cout << " -> Inserció: ";
    chrono::steady_clock::time_point begin3 = chrono::steady_clock::now();
    wordIn = new WordIndexer("unbalancedText.txt");
    chrono::steady_clock::time_point end3 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end3 -begin3).count() << " µs" << endl;
    cout << " -> Cerca: " ;
    cal_TempsCerca(wordIn);

    delete wordIn;

    cout << endl << endl << " --- Per el BalancedTree --- " << endl;
    WordIndexerBalanced* balancedWordIn;
    cout << "    Cas Short: " << endl;
    cout << " -> Inserció: ";
    chrono::steady_clock::time_point begin4 = chrono::steady_clock::now();
    balancedWordIn = new WordIndexerBalanced("shortText.txt");
    chrono::steady_clock::time_point end4 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end4 -begin4).count() << " µs" << endl;
    cout << " -> Cerca: " ;
    cal_TempsCerca(balancedWordIn);

    delete balancedWordIn; 
    balancedWordIn = nullptr;

    cout << endl << "    Cas Long: " << endl;
    cout << " -> Inserció: ";
    chrono::steady_clock::time_point begin5 = chrono::steady_clock::now();
    balancedWordIn = new WordIndexerBalanced("longText.txt");
    chrono::steady_clock::time_point end5 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end5 -begin5).count() << " µs" << endl;
    cout << " -> Cerca: " ;
    cal_TempsCerca(balancedWordIn);

    delete balancedWordIn;
    balancedWordIn = nullptr;

    cout << endl << "    Cas Unbalanced: " << endl;
    cout << " -> Inserció: ";
    chrono::steady_clock::time_point begin6 = chrono::steady_clock::now();
    balancedWordIn = new WordIndexerBalanced("unbalancedText.txt");
    chrono::steady_clock::time_point end6 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end6 -begin6).count() << " µs" << endl;
    cout << " -> Cerca: " ;
    cal_TempsCerca(balancedWordIn);

    delete balancedWordIn;
}

int main(){
    mainExercici1();
    mainExercici2();
    mainExercici3();
    mainExercici4();
    mainExercici5();
    return 0;
}
#include "Position.h"
#include "BinaryTree.h"
#include <iostream>
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
} 

int main(){
    mainExercici1();
    return 0;
}
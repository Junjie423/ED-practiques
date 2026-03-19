// Autor: Junjie Zhou

#include<LinkedList.h>
#include<NodeList.h>
#include<Position.h>
#include<iostream>
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

void casProva2(){
    
}

int main(){
    casProva1();
    casProva2();
    return 0;
}
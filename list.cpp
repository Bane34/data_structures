#include <iostream>
#include <stdlib.h>
#include "list.h"
using namespace std;

struct NodeList{
    int data;
    NodeList *next;
};

void addList(NodeList *&list, int n) {
    NodeList *new_node = new NodeList();
    new_node -> data = n;

    NodeList *aux1 = lista;
    NodeList *aux2;

    while((aux1 != NULL) && (aux1 -> data < n)){
        aux2 = aux1;
        aux1 = aux1 -> next;
    }

    if (list == aux1)
        lista = new_node;
    else
        aux2 -> next = new_node;
    
    new_node -> next = aux1;

    cout << '\n' << n << " added to the list" << endl;
}

void showList(NodeList *list){
    Node *actual = new Node();
    actual = list;

    while(actual != NULL){
        cout << actual -> data << "->";
        actual = actual -> next;
    }
}

void searcList(NodeList *, int n){
    bool band = false;

    NodeList *actual = new NodeList();
    actual = lista;

    while((actual != NULL) && (actual -> data <= n)){
        if (actual -> dato == n){
            band = true;
        }
        actual = actual -> next;
    }

    if (band == true)
        cout << n << " found in the list!" << endl;
    else
        cout << n << " not found in the list :(" << endl;
}

void removeList(NodeList *&list, int n){
    if(list != NULL){
        NodeList *aux_remove;
        NodeList *previous = NULL;

        aux_remove = list;

        while((aux_remove != NULL) && (aux_remove -> data != n)){
            previous = aux_remove;
            aux_remove = aux_remove -> next;
        }

        if(aux_remove == NULL)
            cout << "There wasnt any number found" << endl;
        else if (previous == NULL){
            list = list -> next;
            delete aux_remove;
        }
        else{
            previous -> next = aux_remove -> next;
            delete aux_remove;
        }
    }
}

void menu(void){
    system("cls");
    cout << "---List methods, what do u want to do?---" << endl;
    cout << "[1] Add an element to the list" << endl;
    cout << "[2] Delete an element from the list" << endl;
    cout << "[3] Show list" << endl;
    cout << "[4] Search an element in the list" << endl;
    cout << "[5] Exit" << endl;
}

void mainList(void){
    cout << "Creating list data structure" << endl;
    Node *list = NULL;
    cout << "Data structure list created" << endl;

    int res, number;

}
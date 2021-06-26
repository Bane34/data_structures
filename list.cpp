#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "list.h"
using namespace std;

struct NodeList{
    int data;
    NodeList *next;
};

void addList(NodeList *&list, int n) {
    NodeList *new_node = new NodeList();
    new_node -> data = n;

    NodeList *aux1 = list;
    NodeList *aux2;

    while((aux1 != NULL) && (aux1 -> data < n)){
        aux2 = aux1;
        aux1 = aux1 -> next;
    }

    if (list == aux1)
        list = new_node;
    else
        aux2 -> next = new_node;
    
    new_node -> next = aux1;

    cout << '\n' << n << " added to the list" << endl;
}

void showList(NodeList *list){
    NodeList *actual = new NodeList();
    actual = list;

    do{
        if(actual -> next == NULL){
            cout << actual -> data;
            break;
        }
        
        cout << actual -> data << "->";
        actual = actual -> next;
    } while(actual != NULL);
}

void searchList(NodeList *list, int n){
    bool band = false;

    NodeList *actual = new NodeList();
    actual = list;

    while((actual != NULL) && (actual -> data <= n)){
        if (actual -> data == n){
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
            cout << n << " removed" << endl;
        }
        else{
            previous -> next = aux_remove -> next;
            delete aux_remove;
            cout << n << " removed" << endl;
        }
    }
}

void deleteList(NodeList *&list, int &n){
    NodeList *aux = list;
    n = aux -> data;
    list = aux -> next;
    delete aux;
}

void getMaxMin(NodeList *list){
    int max = 0, min = 2^63;

    while(list != NULL){
        if(list -> data > max)
            max = list -> data;

        if(list -> data < min)
            min = list -> data;
        
        list = list -> next;
    }

    // As I know in c++ you cant return to values at the same time >:/ so I have to do this shit
    cout << "Maximun element: " << max << endl;
    cout << "Minimun element: " << min << endl;
}

int getSum(NodeList *list){
    int sum = 0;

    while (list != NULL){
        sum = sum + list -> data;
        list = list -> next;
    }

    return sum;
}

void menuList(void){
    system("cls");
    cout << "\n---List methods, what do u want to do?---" << endl;
    cout << "[1] Add an element to the list" << endl;
    cout << "[2] Delete an element from the list" << endl;
    cout << "[3] Show list" << endl;
    cout << "[4] Search an element in the list" << endl;
    cout << "[5] Delete the list" << endl;
    cout << "[6] Search maximun and minimun value in the list" << endl;
    cout << "[7] Get sum of all the list" << endl;
    cout << "[99] Exit" << endl;
}

void mainList(void){
    cout << "Creating list data structure" << endl;
    NodeList *list = NULL;
    cout << "Data structure list created" << endl;

    int res, number;

    while (true) {
        menuList();
        cout << "Option: ";
        cin >> res;

        switch (res) {
            case 1:
                cout << "What number do u want to insert to the list: ";
                cin >> number;
                addList(list, number);
                getch();
                break;
            case 2:
                cout << "What number do u want to remove from the list: ";
                cin >> number;
                removeList(list, number);
                getch();
                break;
            case 3:
                showList(list);
                getch();
                break;
            case 4:
                cout << "What number do u want to find: ";
                cin >> number;
                searchList(list, number);
                getch();
                break;
            case 5:
                while (list != NULL) {
                    if(list->next != NULL)
                        cout << list->data << "->";
                    else
                        cout << list->data << endl;
                    
                    deleteList(list, number);
                }
                getch();
                return;
                break;
            case 6:
                getMaxMin(list);
                getch();
                break;
            case 7:
                cout << getSum(list) << endl;
                getch();
                break;
            case 99:
                exit(0);
            default:
                cout << "Select a valid option" << endl;
                getch();
                continue;
        }
    }
}
#include <iostream>
#include "core.h"
using namespace std;

void menu(void){
    cout << "Select a data structure to operate in" << endl;
    cout << "[1] Stack" << endl;
    cout << "[2] Queue" << endl;
    cout << "[99] Exit" << endl;
}

int main(){
    int res;

    while (true){
        menu();
        cout << ">>";
        cin >> res;
        switch(res){
            case 1:
                mainStack();
                break;
            case 2:
                mainQueue();
                break;
            case 99:
                exit(0);
            default:
                cout << "Select a valid option" << endl;
                continue;
        }
    }

    return 0;
}
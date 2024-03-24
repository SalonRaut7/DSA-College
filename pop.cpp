// POP operation on stack refers to removing of item from the stack.
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int MAXSIZE,data;
    int TOP=-1;
    char choice;
    cout<<"ENter the max size of the stack"<<endl;
    cin>>MAXSIZE;
    int stack[MAXSIZE];
    here:
    cout<<"Do you want to remove an element from the stack (Y/N)?"<<endl;
    cin>>choice;
    switch(choice){
        case 'Y':
        case 'y':
            if(TOP==-1){
                cout<<"Stack is empty.";
            }
            else{
                data=stack[TOP];
                TOP=TOP-1;
                goto here;
            }
        case 'N':
        case 'n':
        cout << "Elements in the stack:" << endl;
        for (int i = TOP; i >= 0; i--) {
            cout << stack[i] << endl;
        }
        exit(0);
          default:
                cout << "Invalid choice. Please enter Y or N." << endl;
    }
    return 0;
}
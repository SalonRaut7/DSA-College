// Push operation on stack refers to insertion of an item on the stack
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int MAXSIZE,data;
    int TOP=-1;
    char choice,choice1;
    cout<<"ENter the max size of the stack"<<endl;
    cin>>MAXSIZE;
    int stack[MAXSIZE];
    here:
    cout<<"Do you want to enter an element in the stack (Y/N)?"<<endl;
    cin>>choice;
    switch(choice){
        case 'Y':
        case 'y':
        if(TOP==MAXSIZE-1){
            cout<<"Stack is full.";
        }
        else{
            TOP=TOP+1;
            cin>>data;
            stack[TOP]=data;
            goto here;
        }
        case 'N':
        case 'n':
        cout << "Elements in the stack:" << endl;
        for (int i = TOP; i >= 0; i--) {
            cout << stack[i] << endl;
        }
        break;
        default:
                cout << "Invalid choice. Please enter Y or N." << endl;
    }
    there:
    cout<<"Do you want to remove an element from the stack (Y/N)?"<<endl;
    cin>>choice1;
    switch(choice1){
        case 'Y':
        case 'y':
            if(TOP==-1){
                cout<<"Stack is empty.";
            }
            else{
                data=stack[TOP];
                TOP=TOP-1;
                cout<<"The element removed is: "<<data<<endl;
                goto there;
            }
        case 'N':
        case 'n':
        cout << "Elements in the stack:" << endl;
        for (int i = TOP; i >= 0; i--) {
            cout << stack[i] << endl;
        }
        break;
          default:
                cout << "Invalid choice. Please enter Y or N." << endl;
    }
    return 0;
}

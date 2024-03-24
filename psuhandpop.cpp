#include <iostream>
#include <cstdlib>
using namespace std;

int TOP = -1;
int MAXSIZE;

void push(int stack[]) {
    if (TOP < MAXSIZE - 1) {
        int data;
        cout << "Enter data to push: ";
        cin >> data;
        TOP = TOP + 1;
        stack[TOP] = data;
    }
    else {
        cout << "Stack is full." << endl;
    }
}

void pop(int stack[]) {
    if (TOP >= 0) {
        int data;
        data = stack[TOP];
        TOP = TOP - 1;
        cout << "The element removed is: " << data << endl;
    }
    else {
        cout << "Stack is empty." << endl;
    }
}

void display(int stack[]) {
    if (TOP >= 0) {
        cout << "Elements in the stack:" << endl;
        for (int i = TOP; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
    else {
        cout << "Stack is empty." << endl;
    }
}

int main() {
    int choice;
    cout << "Enter the max size of the stack: ";
    cin >> MAXSIZE;
    int stack[MAXSIZE];

    while (1) {
        cout << "Enter 1 to push, 2 to pop, 3 to display, 4 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}

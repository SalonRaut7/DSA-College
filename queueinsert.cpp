#include<iostream>
using namespace std;

int rear = -1;
int front = -1;
int maxsize;

void enqueue(int queue[]) {
    if (rear == maxsize - 1) {
        cout << "Queue is full" << endl;
    } else {
        int data;
        cout << "Enter data: ";
        cin >> data;
        rear++;
        if (front == -1) {
            front = 0;
        }
        queue[rear] = data;
    }
}

void dequeue(int queue[]) {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        int data = queue[front];
        cout << "The deleted element is: " << data << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void display(int queue[]) {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Elements in the queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter maxsize of queue: ";
    cin >> maxsize;
    int queue[maxsize];
    int choice;
    while (true) {
        cout << "Enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit: ";
        cin >> choice;
        switch (choice) {
            case 1:
                enqueue(queue);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
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

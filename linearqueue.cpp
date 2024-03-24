// performing enqueue(insertion) operation in linear queue
/*
Algorithm:
1. Initialize rear=-1 and front = -1.
2. if rear==max-1 then print queue is full and exit
3. read data
4. rear++;
5. queue[rear]=data;
6. goto step 2
7. Exit

*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int rear=-1, front=-1;
int maxsize;
int data,choice;
void enqueue(int queue[]){
    if(rear==maxsize-1){
        cout<<"The queue is full"<<endl;
    }
    else{
        rear++;
        cout<<"enter data to be entered in queue: "<<endl;
        cin>>data;
        queue[rear]=data;
        if (front == -1) {
            front = 0; // Update front when inserting the first element
        }
      
    }
}
void dequeue(int queue[]){
 if (front == -1 || front > rear) {
        cout << "The queue is empty" << endl;
    }
    else {
        data = queue[front];
        cout << "The removed element is: " << data << endl;
        front++;
        if (front > rear) {
            // Reset front and rear when all elements are dequeued
            front = -1;
            rear = -1;
        }
    }

}
void display(int queue[]){
  if (front == -1 || front > rear) {
        cout << "The queue is empty" << endl;
    }
    else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
int main(){
    cout<<"Enter maxsize of queue :" <<endl;
    cin>>maxsize;
    int queue[maxsize];
    while(1){
        cout << "Enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit: ";
        cin >> choice;
        switch(choice){
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
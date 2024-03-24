
#include<iostream>
#include<stdlib.h>
using namespace std;
int rear=-1, front=-1;
int maxsize;
int data,choice;
void enqueue(int queue[]){
    if((rear==maxsize-1 && front==0) || (front==((rear+1)%maxsize))){
        cout<<"The queue is full"<<endl;
    }
    else{
        rear=(rear+1)%maxsize;
        cout<<"enter data to be entered in queue: "<<endl;
        cin>>data;
        queue[rear]=data;
        if (front == -1) {
            front = 0; // Update front when inserting the first element
        }
      
    }
}
void dequeue(int queue[]){
 if (front == -1) {
        cout << "The queue is empty" << endl;
    }
    else if(front==rear){
        cout<< "THe dequeued element is : "<<queue[front]<<endl;
        front=-1;
        rear=-1;
    }
    else {
        data = queue[front];
        cout << "The removed element is: " << data << endl;
        front=(front+1)%maxsize;
    }

}
void display(int queue[]){
    int i;
    i = front;
    if (front == -1) {
        cout << "The queue is empty" << endl;
    }
    else {
        cout << "Queue elements: ";
        while (i != rear) {
            cout << queue[i] << endl;
            i = (i + 1) % maxsize;
        }
        cout << queue[i] << endl; // Display the last element
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
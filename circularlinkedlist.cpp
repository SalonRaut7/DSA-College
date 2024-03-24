#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node * next;
};
void linkedlisttraversal(struct Node *head){
    struct Node *ptr=head;
        cout<<"Elements: ";
    do{
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
    while(ptr!=head);
}
int main(){
     struct Node * head;
     struct Node * second;
     struct Node * third;
     struct Node * fourth;
     //Allocate memory for nodes in the linked list in Heap
     head=(struct Node*)malloc(sizeof(struct Node));
     second=(struct Node*)malloc(sizeof(struct Node));
     third=(struct Node*)malloc(sizeof(struct Node));
     fourth=(struct Node*)malloc(sizeof(struct Node));
     //Link first and second node
     head->data=4;
     head->next=second;
      //Link second and third node
     second->data=3;
     second->next=third;
    //link third and fourth
     third->data=6;
     third->next=fourth;
    //terminate fourth node
    fourth->data=1;
    fourth->next=head;
     linkedlisttraversal(head);

     return 0;
}
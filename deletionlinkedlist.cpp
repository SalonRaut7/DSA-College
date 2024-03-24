#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node * next;
};
void linkedlistTraversal(struct Node *ptr){
    while(ptr!=NULL){
    printf("Element= %d\n", ptr->data);
    ptr=ptr->next;
    }
}
struct Node* deletefrombeginning(struct Node* head){
    struct Node *ptr=head;
    head=head->next;
    cout<<"The deleted data is: "<<ptr->data;
    free(ptr);
    return head;
}
struct Node* deleteatindex(struct Node *head, int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0; i< index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;

}
struct Node* deleteatlast(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next != NULL){
         p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;

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
      //Link third and fourth node
     third->data=8;
     third->next=fourth;

     //Terminate the list at fourth node
     fourth->data=1;
     fourth->next=NULL;
     cout<<"Linked list before deletion: "<<endl;
     linkedlistTraversal(head);
     head=deletefrombeginning(head);
    // int index=2;
    // head=deleteatindex(head,index);
    // head=deleteatlast(head);
     cout<<"Linked list after deletion: "<<endl;
     linkedlistTraversal(head);

     return 0;
}
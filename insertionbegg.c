#include<stdio.h>
#include<stdlib.h>
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
struct Node* insertatbeginning(struct Node * head, int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node* insertatindex(struct Node * head, int data,int index){
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node * p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node* insertatend(struct Node * head, int data){
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
     struct Node * p=head;
    while(p->next!=NULL){
        p=p->next;

    }
    p->next= ptr;
    ptr->next=NULL;
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
     head->data=7;
     head->next=second;
      //Link second and third node
     second->data=11;
     second->next=third;
      //Link third and fourth node
     third->data=41;
     third->next=fourth;
     //Terminate the list at the fourth node
     fourth->data=66;
     fourth->next=NULL;
     linkedlistTraversal(head);
    //  head= insertatbeginning(head,56);
    //  head= insertatindex(head,77,1);
     head= insertatend(head,88);
     linkedlistTraversal(head);

     return 0;
}
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// struct Node *createLinkedList(int n)
// {
//     struct Node *head = NULL, *temp = NULL;
//     int data, i;

//     // Create the first node
//     cout << "Enter the data for node 1: ";
//     cin >> data;
//     head = createNode(data);
//     temp = head;

//     // Create remaining nodes
//     for (i = 2; i <= n; i++)
//     {
//         cout << "Enter the data for node " << i << " :";
//         cin >> data;
//         temp->next = createNode(data);
//         temp = temp->next;
//     }

//     return head;
// }
struct Node *insertatbeginning(struct Node *head, int d)
{   
    struct Node *pnew = (struct Node *)malloc(sizeof(struct Node));
    if(head==NULL){
        pnew=head;
    }
    pnew->data = d;
    pnew->next = head;
    head = pnew;
    return head;
}
void display(struct Node *ptr)
{   
    if(ptr==NULL){
        cout<<"The list is empty"<<endl;
    }
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
/*
struct Node* insertatend(struct Node * head, int d){
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=d;
     struct Node * p=head;
    while(p->next!=NULL){
        p=p->next;

    }
    p->next= ptr;
    ptr->next=NULL;
}
*/
struct Node *insertatend(struct Node *head, int d)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = d;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    return head;
}
struct Node *insertatindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node *deletefrombeginning(struct Node *head)
{
    if(head==NULL){
        cout<<"The list is empty."<<endl;
    }
    struct Node *ptr = head;
    head = head->next;
    cout << "The deleted data is: " << ptr->data;
    free(ptr);
    return head;
}
struct Node *deleteatend(struct Node *head)
{
    if(head==NULL){
        cout<<"The list is empty."<<endl;
    }
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    cout << "THe deleted data is: " << q->data << endl;
    p->next = NULL;
    free(q);
    return head;
}
struct Node *deleteatindex(struct Node *head, int index)
{
    if(head==NULL){
        cout<<"The list is empty."<<endl;
    }
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    cout << "THe deleted data is: " << q->data << endl;
    p->next = q->next;
    free(q);
    return head;
}
struct Node *insertBeforePosition(struct Node *head, int data, int position)
{
    if (position <= 0)
    {
        head = insertatbeginning(head, data);
    }
    else
    {
        struct Node *ptr = createNode(data);
        struct Node *p = head;
        int i = 0;
        while (i != position - 2)
        {
            if (p == NULL)
            {
                cout << "Invalid position." << endl;
                return head;
            }
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return head;
}

struct Node *insertAfterPosition(struct Node *head, int data, int position)
{   
    struct Node *ptr = createNode(data);
    struct Node *p = head;
    int i = 0;
    while (i != position - 1)
    {
        if (p == NULL)
        {
            cout << "Invalid position." << endl;
            return head;
        }
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main()
{
    struct Node *head;
    char ch;
    int n, choice, info, index, position;
    // here:
    // cout << "Enter number of nodes: ";
    // cin >> n;
    // if(n==0){
    //     cout<<"Do you want to re-enter? (Y/N) ";
    //     cin>>ch;
    //     switch(ch){
    //     case 'Y':
    //         goto here;
    //         break;
    //     case 'N':
    //         exit(0);
    //         break;
    //     }

    // }
    int information;
    cout<<"ENter data to be inserted in the first node: "<<endl;
    cin>>information;
    // head = createLinkedList(n);
    head = createNode(information);
    cout << endl;
    while (1)
    {
        cout << "Enter 1 to insert from the beginning" << endl;
        cout << "Enter 2 to insert at the end" << endl;
        cout << "Enter 3 to insert before a specified position" << endl;
        cout << "Enter 4 to insert after a specified position" << endl;
        // cout << "Enter 3 to insert at the specified index" << endl;
        cout << "Enter 5 to display the elements of the list" << endl;
        cout << "Enter 6 to delete from the beginning" << endl;
        cout << "Enter 7 to delete from the end" << endl;
        cout << "Enter 8 to delete from the specified index" << endl;
        cout << "Enter 9 to exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter data to be added in beginning: ";
            cin >> info;
            head = insertatbeginning(head, info);
            break;
        case 2:
            cout << "Enter data to be added in end: ";
            cin >> info;
            head = insertatend(head, info);

            break;
        case 3:
            cout << "Enter the position to insert before: ";
            cin >> position;
            cout << "Enter data to be added before position " << position << ": ";
            cin >> info;
            head = insertBeforePosition(head, info, position);
            break;
        case 4:
            cout << "Enter the position to insert after: ";
            cin >> position;
            cout << "Enter data to be added after position " << position << ": ";
            cin >> info;
            head = insertAfterPosition(head, info, position);
            break;
            

        case 5:
            display(head);
            break;
            head = deletefrombeginning(head);
            break;

        case 6:
            head = deletefrombeginning(head);
            break;
            
        case 7:
            head = deleteatend(head);
            break;
           
        case 8:
            cout << "In which index/position you want to delete: " << endl;
            cin >> index;
            head = deleteatindex(head, index);
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    return 0;
}

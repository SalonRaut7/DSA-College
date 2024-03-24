//BEST CODE....

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

struct Node *insertatbeginning(struct Node *head, int d)
{
    struct Node *pnew = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        pnew->data = d;
        pnew->next = NULL;
        head = pnew;
    }
    else
    {
        pnew->data = d;
        pnew->next = head;
        head = pnew;
    }
    return head;
}

void display(struct Node *ptr)
{
    if (ptr == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

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

struct Node *deletefrombeginning(struct Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return NULL;
    }
    else{
    struct Node *ptr = head;
    head = head->next;
    cout << "The deleted data is: " << ptr->data << endl;
    free(ptr);}
    return head;
}

// struct Node *deleteatend(struct Node *head)
// {
//     if (head == NULL)
//     {
//         cout << "The list is empty." << endl;
//         return NULL;
//     }

//     if (head->next == NULL)
//     {
//         cout << "The deleted data is: " << head->data << endl;
//         free(head);
//         return NULL;
//     }

//     struct Node *p = head;
//     struct Node *q = head->next;
//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     cout << "The deleted data is: " << q->data << endl;
//     p->next = NULL;
//     free(q);
//     return head;
// }
struct Node* deleteend(struct Node* head){
    if(head==NULL){
        cout<<"The list is empty"<<endl;
        return NULL;
    }
     if (head->next == NULL)
    {
        cout << "The deleted data is: " << head->data << endl;
        free(head);
        return NULL;
    }
    else{
        struct Node* pthis=head;
        while(pthis->next!=NULL){
            pthis=pthis->next;
        }
        cout<<"The deleted data is: "<<pthis->data;
        free(pthis);
    }
    return head;
}

struct Node *deleteatindex(struct Node *head, int index)
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return NULL;
    }

    if (index == 0)
    {
        return deletefrombeginning(head);
    }

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    cout << "The deleted data is: " << q->data << endl;
    p->next = q->next;
    free(q);
    return head;
}

struct Node *insertBeforePosition(struct Node *head, int data, int position)
{
    if (head == NULL || position <= 0)
    {
        return insertatbeginning(head, data);
    }

    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *insertAfterPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    for (int i = 0; i < position; i++)
    {
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main()
{
    struct Node *head = NULL;
    int data, choice, position;

    cout << "1. Insert at the beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. Delete from the beginning" << endl;
    cout << "4. Delete from the end" << endl;
    cout << "5. Delete at a specific index" << endl;
    cout << "6. Insert before a specific position" << endl;
    cout << "7. Insert after a specific position" << endl;
    cout << "8. Display the list" << endl;
    cout << "0. Exit" << endl;

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 0:
                exit(0);
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                head = insertatbeginning(head, data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                head = insertatend(head, data);
                break;
            case 3:
                head = deletefrombeginning(head);
                break;
            case 4:
                head = deleteend(head);
                break;
            case 5:
                cout << "Enter index to delete: ";
                cin >> position;
                head = deleteatindex(head, position);
                break;
            case 6:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert before: ";
                cin >> position;
                head = insertBeforePosition(head, data, position);
                break;
            case 7:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert after: ";
                cin >> position;
                head = insertAfterPosition(head, data, position);
                break;
            case 8:
                display(head);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

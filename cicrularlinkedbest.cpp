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
    struct Node *pnew = createNode(d);
    if (head == NULL)
    {
        pnew->next = pnew; // Make the new node point to itself
        head = pnew;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head) // Traverse till the end of the circular list
            temp = temp->next;
        temp->next = pnew; // Make the last node point to the new node
        pnew->next = head; // Make the new node point to the head node
        head = pnew; // Update the head node
    }
    return head;
}

struct Node *insertatend(struct Node *head, int d)
{
    struct Node *pnew = createNode(d);
    if (head == NULL)
    {
        pnew->next = pnew; // Make the new node point to itself
        head = pnew;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head) // Traverse till the end of the circular list
            temp = temp->next;
        temp->next = pnew; // Make the last node point to the new node
        pnew->next = head; // Make the new node point to the head node
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

    struct Node *ptr = head;
    if (head->next == head) // If there is only one node in the list
    {
        cout << "The deleted data is: " << ptr->data << endl;
        free(ptr);
        return NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head) // Traverse till the end of the circular list
            temp = temp->next;
        temp->next = head->next; // Update the last node's next pointer to skip the head node
        head = head->next; // Update the head node
        cout << "The deleted data is: " << ptr->data << endl;
        free(ptr);
        return head;
    }
}

struct Node *deleteatend(struct Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return NULL;
    }

    struct Node *ptr = head;
    if (head->next == head) // If there is only one node in the list
    {
        cout << "The deleted data is: " << ptr->data << endl;
        free(ptr);
        return NULL;
    }
    else
    {
        struct Node *prev = NULL;
        while (ptr->next != head) // Traverse till the end of the circular list
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = head; // Make the second last node point to the head node
        cout << "The deleted data is: " << ptr->data << endl;
        free(ptr);
        return head;
    }
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

    struct Node *ptr = head;
    struct Node *prev = NULL;
    int count = 0;
    while (ptr->next != head && count < index)
    {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (count < index) // If the index is out of bounds
    {
        cout << "Invalid index." << endl;
        return head;
    }

    prev->next = ptr->next;
    cout << "The deleted data is: " << ptr->data << endl;
    free(ptr);
    return head;
}

struct Node *insertBeforePosition(struct Node *head, int data, int position)
{
    if (head == NULL || position <= 0)
    {
        return insertatbeginning(head, data);
    }

    struct Node *newNode = createNode(data);
    struct Node *ptr = head;
    struct Node *prev = NULL;
    int count = 0;
    while (ptr->next != head && count < position)
    {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (count < position) // If the position is out of bounds
    {
        cout << "Invalid position." << endl;
        return head;
    }

    newNode->next = ptr;
    prev->next = newNode;
    if (position == 0) // If inserting at the beginning
        head = newNode;
    return head;
}

struct Node *insertAfterPosition(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr = head;
    int count = 0;
    while (ptr->next != head && count < position)
    {
        ptr = ptr->next;
        count++;
    }

    if (count < position) // If the position is out of bounds
    {
        cout << "Invalid position." << endl;
        return head;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }

    struct Node *ptr = head;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
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
            head = deleteatend(head);
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

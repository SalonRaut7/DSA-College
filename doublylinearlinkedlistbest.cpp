#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    cout << "The deleted data is: " << temp->data << endl;
    free(temp);
    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return NULL;
    }
    if (head->next == NULL) {
        cout << "The deleted data is: " << head->data << endl;
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    cout << "The deleted data is: " << temp->data << endl;
    free(temp);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return NULL;
    }
    if (index == 0) {
        return deleteFromBeginning(head);
    }
    struct Node* temp = head;
    for (int i = 0; i < index; i++) {
        if (temp == NULL) {
            cout << "Invalid index." << endl;
            return head;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid index." << endl;
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    cout << "The deleted data is: " << temp->data << endl;
    free(temp);
    return head;
}

struct Node* insertBeforePosition(struct Node* head, int data, int position) {
    if (head == NULL || position <= 0) {
        return insertAtBeginning(head, data);
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position." << endl;
        return head;
    }
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    return head;
}

struct Node* insertAfterPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid position." << endl;
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        cout << "Element: " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
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

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                head = insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                head = insertAtEnd(head, data);
                break;
            case 3:
                head = deleteFromBeginning(head);
                break;
            case 4:
                head = deleteFromEnd(head);
                break;
            case 5:
                cout << "Enter index to delete: ";
                cin >> position;
                head = deleteAtIndex(head, position);
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

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
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return NULL;
    }
    struct Node* temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
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
    struct Node* temp = head->prev;
    if (head->next == head) {
        head = NULL;
    } else {
        head->prev = temp->prev;
        temp->prev->next = head;
    }
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
        temp = temp->next;
        if (temp == head) {
            cout << "Invalid index." << endl;
            return head;
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
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
    for (int i = 0; i < position; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Invalid position." << endl;
            return head;
        }
    }
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
    if (position == 0) {
        head = newNode;
    }
    return head;
}

struct Node* insertAfterPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Invalid position." << endl;
            return head;
        }
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    struct Node* temp = head;
    do {
        cout << "Element: " << temp->data << endl;
        temp = temp->next;
    } while (temp != head);
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

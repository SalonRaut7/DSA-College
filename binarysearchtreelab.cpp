#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *pnew, *pthis, *ppthis, *root = NULL;

void create()
{
    char ch;
    int info;
    do
    {
        cout << "Enter data to be inserted in the tree: ";
        cin >> info;
        pnew = (struct node *)malloc(sizeof(struct node));
        pnew->lchild = NULL;
        pnew->rchild = NULL;
        pnew->data = info;

        if (root == NULL)
        {
            root = pnew;
        }
        else
        {
            pthis = root;
            while (pthis != NULL)
            {
                ppthis = pthis;
                if (pnew->data < pthis->data)
                {
                    pthis = pthis->lchild;
                    if (pthis == NULL)
                    {
                        ppthis->lchild = pnew;
                    }
                }
                else if (pnew->data > pthis->data)
                {
                    pthis = pthis->rchild;
                    if (pthis == NULL)
                    {
                        ppthis->rchild = pnew;
                    }
                }
                else
                {
                    cout << "Duplicate node" << endl;
                    free(pnew); // Free the memory of the duplicate node
                    return;     // Exit the function without continuing the loop
                }
            }
        }
        cout << "Do you want to enter another data to the tree? (Y/N)" << endl;
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->data << " ";
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int main()
{
    int choice;
    cout << "1. Create binary tree" << endl;
    cout << "2. Inorder traversal" << endl;
    cout << "3. Preorder traversal" << endl;
    cout << "4. Postorder traversal" << endl;
    cout << "5. Exit" << endl;
    while (1)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break; // Add a break statement
        }
    }

    return 0;
}

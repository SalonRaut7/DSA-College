/*
Binary Search Tree is the type of Binary Tree
Properties of Binary Search Tree:
1. All nodes of the left subtree are lesser.
2. All nodes of the right subtree are greater.
3. Left and Right subtrees are also BST.
4. There are no duplicate nodes.
5. The Inorder Traversal of the BST gives an ascending sorted array.
*/

#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createnode(int data){
    struct node *n;  //creating a node pointer
    n=(struct node*)malloc(sizeof(struct node)); //Allocating the memory in heap
    n->data=data; //Setting the data
    n->left=NULL; //Setting the left and right children to NULL
    n->right=NULL;
    return n;  //Returning the created node
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left); 
        cout<<root->data;
        inorder(root->right);
    }
}
int isBST(struct node* root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}
int main(){
    //Constructing the root node-Using Function
    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2 =createnode(6);
    struct node *p3 =createnode(1);
    struct node *p4 =createnode(4);
    /*
    The Tree should look like this:
         5
        / \ 
       3   6
      / \
     1   4
    */
    //Linking the node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(p);
    cout<<endl;
    cout<<isBST(p);
    return 0;
}
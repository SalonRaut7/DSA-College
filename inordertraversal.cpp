/*
TRAVERSALS in Binary Tree:
1. Preorder Traversal: 
    root->left children->right children
2. Postorder Traversal:
    left children->right children-> root
3. Inorder Traversal: 
    left children->root->right children
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
int main(){
    //Constructing the root node-Using Function
    struct node *p=createnode(4);
    struct node *p1=createnode(1);
    struct node *p2 =createnode(6);
    struct node *p3 =createnode(5);
    struct node *p4 =createnode(2);
    /*
    The Tree should look like this:
         4
        / \ 
       1   6
      / \
     5   2
    */
    //Linking the node with left and right children
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(p);
    return 0;
}
// LIBRARIES INCLUDED
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Function Declaration
typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} Node;

Node * createNode (int newdata){
    Node * ptr = (Node *)malloc(sizeof(Node));
    ptr->data = newdata;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// Recursive Traversal
// Pre-Order Traversal
void PreOrderTraversalR (Node * root){
    Node * p = root;
    if (p != NULL){
        printf(" %d --> ",p->data);
        PreOrderTraversalR(p->left);
        PreOrderTraversalR(p->right);

    }
}

void PostOrderTraversalR (Node * root){
    Node * p = root;
    if (p != NULL){
        PostOrderTraversalR(p->left);
        PostOrderTraversalR(p->right);
        printf(" %d --> ",p->data);

    }
}

void InOrderTraversalR (Node * root){
    Node * p = root;
    if (p != NULL){
        InOrderTraversalR(p->left);
        printf(" %d --> ",p->data);
        InOrderTraversalR(p->right);

    }
}
//

Node * deleteNode (Node * root, int key){
    if (root == NULL){
        return root;
    }
    if (root->data == key){
        free(root);
        return NULL;
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}
//
// Checking Binary Search Tree
int isBinarySearchTree (Node * root){
    static Node * p = NULL;
    if (root != NULL){
        if (!isBinarySearchTree(root->left)){
            return 0;
        }
        else {
            if (p != NULL && root->data <= p->data){
                return 0;
            }
            else {
                p = root;
                return isBinarySearchTree(root->right);
            }
        }
    }
    else {
        return 1;
    }
}
// If BST Then Only ->
// Recursive Searching
Node * searchBST (Node * root, int key){
    if (root == NULL){
        return root;
    }
    if (key == root->data){
        return root;
    }
    else if (key > root->data){
        return searchBST(root->right, key);
    }
    else {
        return searchBST(root->left, key);
    }
}
// Iterative Searching
Node * SearchBSTI (Node * root, int key){
    while (root != NULL){
        if (root->data == key){
            return root;
        }
        else if (root->data < key){
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
        return NULL;
}

void insertBST (Node * root, int given){
    Node * prev = NULL;
    while (root != NULL){
        prev = root;
        if (root->data == given){
            printf("\nDuplicate Can't Be Inserted\n");
            return;
        }
        else if (given > root->data){
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    Node * ptr = createNode(given);
    if (given < prev->data){
        prev->left = ptr;
    }
    else {
        prev->right  = ptr;
    }
}

// MAIN FUNCTION

int main() {
    
    Node * root = createNode(13);    
    Node * childL = createNode(9);    
    Node * childR = createNode(15);    
    Node * childLL = createNode(8);    
    Node * childLR = createNode(10);    
    Node * childRL = createNode(14);    
    Node * childRR = createNode(16);    

    // // // //
       
    //      13
    //     /  \ 
    //    9    15
    //   / \   / \ 
    //  8   10 14 16
 
   // In Order Traversal - left - root - right -> 8 2 1 4 10 6 11

    // Linking
    root->left = childL;
    root->right = childR;

    childL->left = childLL;
    childL->right = childLR;

    childR->left = childRL;
    childR->right = childRR;


    // Pre Order Traversal  (root -> left -> right)
    printf("\nPreorder Recursive\n");
    PreOrderTraversalR(root);

    printf("\n");

    // Post Order Traversal (left -> right -> root)
    printf("\nPostorder Recursive\n");
    PostOrderTraversalR(root);

    printf("\n");

    // In Order Traversal (left -> root -> right)
    printf("\nInorder Recursive\n");
    InOrderTraversalR(root);

    if (isBinarySearchTree(root)){
        printf("\nIt's A Binary Search Tree\n");
    }
    else {
        printf("\nIt's Not A Binary Search Tree\n");
    }
    // Recursive Search
    printf("\nRecursive Search\n");
    if (searchBST(root,9)){
        printf("\n9 Found\n");
    }
    else {
        printf("\n9 Not Found\n");
    }

    if (searchBST(root,20)){
        printf("\n20 Found\n"); 
    }
    else {
        printf("\n20 Not Found\n");
    }
    // Iterative Search
    printf("\nIterative Search\n");
    if (SearchBSTI(root,9)){
        printf("\n9 Found\n");
    }
    else {
        printf("\n9 Not Found\n");
    }

    if (SearchBSTI(root,20)){
        printf("\n20 Found\n");
    }
    else {
        printf("\n20 Not Found\n");
    }
    // deleting a node
    printf("\nThe Data You Want To Delete\n");
    int delete;
    scanf("%d",&delete);    
    
    printf("\nAfter Deleting Node \n");
    if (root->data == delete){
        printf("\nYou Can't Delete The Root Node Itself\n");
    }
    else {
        root = deleteNode(root,delete);
    }
    printf("\n");

    // In Order Traversal (left -> root -> right) for BST is Ascending Order
    InOrderTraversalR(root);

    printf("\n");
    
    insertBST(root,17);
    InOrderTraversalR(root);
    printf("\n%d\n",root->right->right->right->data);

    return(0);
}

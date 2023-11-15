// // AVL TREES INCLUDING ALL FUNCTION
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
    int height;
    struct node * left;
    struct node * right;
} avlnode;

avlnode * createNode (int newdata){
    avlnode * ptr = (avlnode *)malloc(sizeof(avlnode));
    ptr->data = newdata;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;
    return ptr;
}

int check_height (avlnode * n){
    if (n == NULL){
        return 0;
    }
    return n->height;
}

int max (int n1 , int n2){
    int y = (n1 > n2) ? n1 : n2;
    return y;
}

int check_balanceFactor (avlnode * n){
    if (n == NULL){
        return 0;
    }
    return (check_height(n->right) - check_height(n->left));
}

//      root                                         p
//     /    \        - right rotation ->          /     \ 
//    p      f       <- left rotation -          cg     root
//   / \                                                /   \  
//  cg ch                                              ch    f

// LL - left left
// Because of right-right insertion balance factor not in {-1,0,1}
avlnode * LL_rot (avlnode * p){
    avlnode * root = p->right;  // according to rotation diagram
    avlnode * ch = root->left;
    // changing
    root->left = p;
    p->right = ch;
    // height
    p->height = max(check_height(p->right),check_height(p->left)) + 1; 
    root->height = max(check_height(root->right),check_height(root->left)) + 1;
    // return latest root
    return root;
}

// RR - right right
// Because of left-left insertion balance factor not in {-1,0,1}
avlnode * RR_rot (avlnode * root){
    avlnode * p = root->left;  // according to rotation diagram
    avlnode * ch = p->right;
    // changing
    p->right = root;
    root->left = ch;
    // height
    p->height = max(check_height(p->right),check_height(p->left)) + 1;
    root->height = max(check_height(root->right),check_height(root->left)) + 1;
    // return root always so after rotation p becomes new root
    return p;
}

// Insert function in AVL just like BST Recursive 
avlnode * insertTreeREC (avlnode * root, int newdata){
    if (root == NULL){
        return createNode(newdata);
    }
    if (newdata > root->data){
        root->right = insertTreeREC(root->right, newdata);
    }
    else {
        root->left = insertTreeREC(root->left, newdata);
    }
    return root;
    // height
    root->height = max(check_height(root->right),check_height(root->left)) + 1;
    int balancefactor = check_balanceFactor(root);
    // LL
    if (balancefactor > 1 && newdata < root->left->data){
        return RR_rot(root);
    }
    // LR
    if (balancefactor > 1 && newdata > root->left->data){
        root->left = LL_rot(root->left);
        return RR_rot(root);
    }
    // RL
    if (balancefactor < -1 && newdata < root->right->data){
        root->right = RR_rot(root->right);
        return LL_rot(root);
    }
    // RR
    if (balancefactor < -1 && newdata > root->right->data){
        return LL_rot(root);
    }
    // LL,RR,LR,RL 1st symbol gives which side of tree
    // 2nd symbol gives less than or greater than
    // R (< -1) -- '> (greater)' && L (> 1) -- '< (lesser)'
    // Change the symbol to rotate -- case say RL so LR rotation

    // return actual root after all changes if done
    return root;
}

void preorderTr (avlnode * root){
    avlnode * p = root;
    if (p != NULL){
        printf("%d - ",p->data);
        preorderTr(p->left);
        preorderTr(p->right);
    }
}

// searching and other all functions are just like BST only insert , createnode , LL rotation and RR rotation
// were different cause AVL is nothing but a BST with some modifications

// MAIN FUNCTION

int main() {
    avlnode * root = createNode(10);
    root = insertTreeREC(root,11);
    root = insertTreeREC(root,14);
    root = insertTreeREC(root,15);
    root = insertTreeREC(root,16);
    root = insertTreeREC(root,13);

    preorderTr(root);
    return(0);
}

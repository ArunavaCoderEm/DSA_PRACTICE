// // Linked List

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

// Create a node

struct node {
    int data;
    struct node * next;
};

// Travell and print the linked list

void traverse(struct node *ptr){
    while (ptr != NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

// Insertion process

struct node * insertBeg(struct node *head, int newdata){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = newdata;
    return ptr;
}

struct node * insertEnd(struct node * head, int newdata){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = newdata;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node * insertAfterNode(struct node * head, struct node * givennode, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    ptr->next = givennode->next;
    givennode->next = ptr;
    return head;
}

// //

// Delete node

struct node * deleteFirst (struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node * deleteLast (struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while (q->next != NULL){
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node * deleteafternode (struct node * head, int givennode){
    struct node * p = head;
    struct node * q = head->next;
    while (q->next != NULL && q->data != givennode){
        q = q->next;
        p = p->next;
    }
    if (q->data == givennode){
        p->next = q->next;
        free(q);
    }
    else if (q->data != givennode){
        printf("\nData not found\n");
    }
    return head;
}
// // 

// Search 
int searchLL (struct node * head, int searchdata) {
    int flag = 0;
    struct node * key = head;
    while (key->data != searchdata && key->next != NULL){
        key = key->next;
    }
    if (key->data == searchdata){
        flag = 1;
    }
    return flag;
}
// //

int main() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *sec = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = sec;

    sec->data = 5;
    sec->next = third;

    third->data = 9;
    third->next = NULL;

    printf("Linked List Creation\n");

    traverse(head);

    printf("\n After beginning insertion\n");

    head = insertBeg(head,8);

    traverse(head);
    
    printf("\n After beginning insertion again\n");

    head = insertBeg(head,10);

    traverse(head);
   
    printf("\n After end insertion \n");

    head = insertEnd(head,11);

    traverse(head);
    
    printf("\n After end insertion again\n");

    head = insertEnd(head,13);

    traverse(head);
    
    printf("\n After node insertion \n");

    head = insertAfterNode(head,third,99);

    traverse(head);
    
    printf("\n After node insertion again\n");

    head = insertAfterNode(head,sec,45);

    traverse(head);
    
    printf("\n After first node (head) deletion\n");

    head = deleteFirst(head);

    traverse(head);
    
    printf("\n After last node deletion\n");

    head = deleteLast(head);

    traverse(head);
    
    printf("\n After node deletion\n");

    head = deleteafternode(head,99);

    traverse(head);
    
    printf("\n After node deletion again\n");

    head = deleteafternode(head,101);

    traverse(head);

    printf("\n Searching ...");

    if (searchLL(head,9) == 1){
        printf("\nFound\n");
    }
    else {
        printf("\nNot Found");
    }
    

    return(0);
}


// // Doubly Linked List
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

struct node {
    int data;
    struct node * next;
    struct node * prev;
};

void traverse (struct node * head){
    struct node * p = head;
    printf("NULL");
    while (p != NULL){
        printf(" <- %d -> ",p->data);
        p = p->next;
    }
    printf("NULL");
}

struct node * insertBeg (struct node * head, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    ptr->prev = NULL;
    ptr->next = head;
    return ptr;
}

struct node * insertEnd (struct node * head, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node * p = head;
    while (p->next != NULL){
        p = p->next;
    }    
    ptr->prev = p;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node * insertAfterNode (struct node * head, int givennode, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;    
    struct node * p = head;
    while (p->data != givennode){
        p = p->next;
    }
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
    return head; 
}

struct node * deleteBeg(struct node * head){
    struct node * temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct node * deleteEnd (struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while (q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

int searchDLL (struct node * head, int key){
    struct node * p = head;
    while (p->data != key && p->next != NULL){
        p = p->next;
    }
    if (p->data == key){
        return 1;
    }
    return 0;
}

struct node * deleteNode (struct node * head, int givennode){
    if (searchDLL(head,givennode)){
        struct node * p = head;
        struct node * q = head->next;
        while(q->data != givennode && q->next != NULL){
            p = p->next;
            q = q->next;
        }
        if (q->data == givennode){
            q->next->prev = p;
            p->next = q->next;
            free(q);
        }
    }
    else {
        printf("\nData %d Not Found\n",givennode);
    }
    return head;
}

int main() {
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));

    head->prev = NULL;
    head->data = 45;
    head->next = second;

    second->prev = head;
    second->data = 54;
    second->next = third;

    third->prev = second;
    third->data = 64;
    third->next = NULL;

    printf("\nDoubly Linked List\n");

    traverse(head);

    printf("\n\n");

    printf("After Beginning Insertion\n");

    head = insertBeg(head,34);

    traverse(head);
    
    printf("\nAfter Beginning Insertion Again\n");

    head = insertBeg(head,24);

    traverse(head);
    
    printf("\nAfter End Insertion \n");

    head = insertEnd(head,74);

    traverse(head);
    
    printf("\nAfter End Insertion Again\n");

    head = insertEnd(head,84);

    traverse(head);

    printf("\nAfter Node Insertion\n");

    head = insertAfterNode(head,64,65);

    traverse(head);
    
    printf("\nAfter Node Insertion Again\n");

    head = insertAfterNode(head,65,66);

    traverse(head);
    
    printf("\nAfter Deletion Beginning\n");

    head = deleteBeg(head);

    traverse(head);
    
    printf("\nAfter Deletion Beginning Again\n");

    head = deleteBeg(head);

    traverse(head);
    
    printf("\nAfter Deletion End\n");

    head = deleteEnd(head);

    traverse(head);
    
    printf("\nAfter Deletion End Again\n");

    head = deleteEnd(head);

    traverse(head);

    printf("\nAfter Node Deletion\n");

    head = deleteNode(head,54);

    traverse(head);

    printf("\nAfter Node Deletion Again\n");

    head = deleteNode(head,65);

    traverse(head);

    printf("\nSearching ... \n");

    if (searchDLL(head,66)){
        printf("\nYes Data 66 Found\n");
    }
    else {
        printf("\nData 66 not Found\n");
    }
    
    printf("\nSearching ... \n");

    if (searchDLL(head,69)){
        printf("\nYes Data 69 Found\n");
    }
    else {
        printf("\nData 69 not Found\n");
    }
    
    return(0);
}


// // // Circular Singly Linked List

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

struct node {
    int data;
    struct node * next;
};

void traverseCSLL(struct node * head){
    struct node * p = head;
    printf("%d -> ",p->data);
    p = p->next;
    while (p != head){
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("HEAD");
}

struct node * insertBeg (struct node * head, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node * p = head->next;
    while (p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return ptr;
}

struct node * insertEnd (struct node * head, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct node * insertAfterNode (struct node * head, int givennode, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node * p = head;
    while (p->data != givennode){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node * deleteBeg (struct node * head){
    struct node * p = head;
    struct node * temp;
    while (p->next != head){
        p = p->next;
    }
    temp = head;
    p->next = head->next;
    head = head->next;
    free (temp);
    return head;
}

struct node * deleteEnd (struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while (q->next != head){
        q = q->next;
        p = p->next;
    }
    p->next = head;
    free(q);
    return head;
}

int searchSCLL (struct node * head, int key);

struct node * deleteNode (struct node * head, int givennode){
    struct node * p = head;
    struct node * q = head->next;
    if (searchSCLL(head,givennode)){
        while (q->data != givennode){
            q = q->next;
            p = p->next;
        }
        p->next = q->next;
        free(q);
    }
    else {
        printf("\nData %d Not Found To Be Deleted\n",givennode);
    }
    return head;
}

int searchSCLL (struct node * head, int key){
    struct node * p = head;
    while (p->data != key && p->next != head){
        p = p->next;
    }
    if (p->data == key){
        return 1;
    }
    return 0;
}

int main() {
    struct node * head = (struct node *)malloc((sizeof(struct node)));
    struct node * second = (struct node *)malloc((sizeof(struct node)));
    struct node * third = (struct node *)malloc((sizeof(struct node)));
    struct node * fourth = (struct node *)malloc((sizeof(struct node)));

    head->data = 34;
    head->next = second;

    second->data = 44;
    second->next = third;

    third->data = 54;
    third->next = fourth;

    fourth->data = 64;
    fourth->next = head;

    printf("\n The Circular singly linked list is - \n");

    traverseCSLL(head);

    printf("\n After Inserting To Beginning - \n");

    head = insertBeg(head,14);

    traverseCSLL(head);

    printf("\n After Inserting To Beginning Again - \n");

    head = insertBeg(head,15);

    traverseCSLL(head);

    printf("\n After Inserting To End - \n");

    head = insertEnd(head,84);

    traverseCSLL(head);

    printf("\n After Inserting To End Again - \n");

    head = insertEnd(head,94);

    traverseCSLL(head);

    printf("\n After Inserting After A Node - \n");

    head = insertAfterNode(head,64,65);

    traverseCSLL(head);

    printf("\n After Inserting After A Node Again - \n");

    head = insertAfterNode(head,65,66);

    traverseCSLL(head);

    printf("\n After Deleting Beginning Node - \n");

    head = deleteBeg(head);

    traverseCSLL(head);

    printf("\n After Deleting Beginning Node Again - \n");

    head = deleteBeg(head);

    traverseCSLL(head);

    printf("\n After Deleting End Node - \n");

    head = deleteEnd(head);

    traverseCSLL(head);

    printf("\n After Deleting End Node Again - \n");

    head = deleteEnd(head);

    traverseCSLL(head);

    printf("\n After Deleting Node - \n");

    head = deleteNode(head,65);

    traverseCSLL(head);

    printf("\n After Deleting Node Again - \n");

    head = deleteNode(head,69);

    traverseCSLL(head);

    printf("\nSearching ...\n");

    if (searchSCLL(head,64)){
        printf("\nData 64 Found\n");
    }
    else {
        printf("\nData 64 NOt Found\n");
    }

    if (searchSCLL(head, 69)){
        printf("\nData 69 Found\n"); 
    }

    else {
        printf("\nData 69 NOt Found\n");
    }

    return(0);
}

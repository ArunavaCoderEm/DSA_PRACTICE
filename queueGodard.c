// // // QUEUE USING LINKED SINGLY LINKED LIST

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

void traversalQQ (struct node * head){
    struct node * p = head;
    printf("\nFRONT\n");
    while (p != NULL){
        printf("\n%d\n",p->data);
        p = p->next;
    }
    printf("\nREAR\n");
}

int Qempty (struct node * head){
    if (head == NULL){
        return 1;
    }
    return 0;
}

struct node * enQ (struct node * head, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node * p = head;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node * deQ (struct node * head){
    if (Qempty(head)){
        printf("\nQueue UnderFlown\n");
    }
    else {
        struct node * p = head;
        head = head->next;
        printf("\nDeleted Element Is %d\n",p->data);
        free(p);
    }
    return head;
}

void front(struct node * head) {
    printf("\nFront Data Of Queue Is %d\n",head->data);
}

void rear(struct node * head) {
    struct node * p = head;
    while (p->next != NULL){
        p = p->next;
    }
    printf("\nRear Data Of Queue Is %d\n",p->data);
}

int main() {
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));
    
    head->data = 34;
    head->next = second;

    second->data = 44;
    second->next = third;

    third->data = 54;
    third->next = fourth;

    fourth->data = 64;
    fourth->next = NULL;

    printf("\nQUEUE IS - \n");

    traversalQQ(head);

    printf("\nAfter QUEUE Insertion\n");

    head = enQ(head,99);
    head = enQ(head,109);
    head = enQ(head,229);
    head = enQ(head,209);
    head = enQ(head,29);

    traversalQQ(head);

    printf("\nAfter Queue Deletion\n");

    head = deQ(head);
    head = deQ(head);
    head = deQ(head);

    traversalQQ(head);

    front(head);

    rear(head);

    return(0);
}
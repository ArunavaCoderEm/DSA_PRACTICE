// Stack Using array

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

struct stack {
    int size;
    int top;
    int *arr;
};

int isFull (struct stack * ptr){
    if (ptr->top == ptr->size-1){
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty (struct stack * ptr){
    if (ptr->top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

void push (struct stack * sp, int val){
    if (isFull(sp)){
        printf("\nStack Overflow\n");
    }
    else {
        sp->top++;
        sp->arr[sp->top] = val;
    }
}

int pop (struct stack * sp){
    if (isEmpty(sp)){
        printf("\nStack Underflow\n");
        return -1;
    }
    else {
        int value = sp->arr[sp->top];
        sp->top--;
        return value;
    }
}

void peek (struct stack * sp){
    printf("\nTop element : %d\n",sp->arr[sp->top]);
}

void traverseStack(struct stack * stk){
    int i;
    for (i = stk->top; i >= 0; --i){
        printf("%d\n",stk->arr[i]);
    }
}

int main() {
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (int*)malloc(sizeof(int)*sp->size);
    push(sp,57);
    push(sp,58);
    push(sp,59);
    push(sp,60);
    push(sp,61);
    push(sp,62);
    push(sp,63);
    printf("\n Stack Is - \n");
    traverseStack(sp);
    peek(sp);
    printf("\n\nPopped element is %d\n",pop(sp));
    traverseStack(sp);
    peek(sp);
    return(0);
}


// // // Stack Using Singly Linked List

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

struct node * push (struct node * head, int newdata){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = newdata;
    struct node * p = head;
    while (p->next != NULL){
        p = p-> next;
    }
    p->next = ptr;
    ptr->next = NULL;
}

struct node * pull (struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while (q->next != NULL){
        p = p->next;
        q = q->next;
    }
    int res = q->data;
    p->next = NULL;
    printf("\n Popped Element From Top Is %d\n",res);
    free(q);
}

struct node * peek (struct node * head){
    struct node * u = head;
    while (u->next != NULL){
        u = u->next;
    }
    printf("\nThe Top Element Of Stack Is %d\n",u->data);
}

void traverseStack (struct node * head) {
    struct node * t = head;
    printf("\nBOTTOM\n\n");
    while (t != NULL){
        printf("%d\n",t->data);
        t = t->next;
    }
    printf("\nTOP\n");
}

int main() {
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head->data = 29;
    head->next = NULL;
    push(head,34);
    push(head,44);
    push(head,54);
    push(head,64);
    push(head,74);
    push(head,84);
    push(head,94);
    printf("\nStack Is - \n");
    traverseStack(head);
    peek(head);
    pull(head);
    printf("\nStack Is - \n");   
    traverseStack(head);
    peek(head);
    pull(head);
    printf("\nStack Is - \n");   
    traverseStack(head);
    peek(head);    
    return(0);
}
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

int peek (struct stack * sp){
    return sp->arr[sp->top];
}

int weight(char s){
    if(s == '*' || s == '/') return 4;
    else if (s == '+' || s == '-') return 3;
    return 2;
}

int sign(char s){
    if(s == '/' || s == '*' || s == '+' || s == '-'){
        return 1;
    }
    return 0;
}

char* infToPost(char* inf){
    struct stack * st = (struct stack *) malloc(sizeof(struct stack));
    st->size = 100; st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));
    char * post = (char *)malloc((strlen(inf)+1) * sizeof(char));
    int in = 0, po = 0;
    while (inf[in] != '\0'){
        if(! sign(inf[in])){
            post[po++] = inf[in++];
        }
        else{
            if(weight(inf[in]) > weight(peek(st))){
                push(st, inf[in++]);
            }
            else{
                post[po++] = pop(st);
            }
        }
    }
    while (! isEmpty(st)){
        post[po++] = pop(st);
    }
    post[po] = '\0';
    return post;
}



// MAIN FUNCTION

int main() {
    char * inf = "a-b+t/6";
    printf("Post fix %s",infToPost(inf));
    return(0);
}

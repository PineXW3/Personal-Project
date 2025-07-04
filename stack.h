//
// Created by Xiangtao Wu on 2025/6/28.
//

#ifndef STACK_H
#define STACK_H


typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct Stack {
    struct node *top;
} Stack;

//Create and Destroy Stack
Stack * createStack();
void destroyStack(Stack *stack);

//Common Stack Operations
void push(Stack *stack, int data );
int pop(Stack *stack);
int peek(Stack *stack);
int size(Stack *stack);
int isEmpty(Stack *stack);

#endif //STACK_H



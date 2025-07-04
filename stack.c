//
// Created by Xiangtao Wu on 2025/6/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Stack creation failed\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

void destroyStack(Stack *stack) {
    if (stack == NULL) return;
    node *temp = stack->top;
    while (temp != NULL) {
        stack->top = temp->next;
        free(temp);
        temp = stack->top;
    }
    free(stack);
}

void push(Stack *stack, int data) {
    if (stack == NULL) return;
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack) {
    if ( stack == NULL || stack->top == NULL ) {
        printf("Stack is empty or stack doesn't exist\n");
        return -1;
    }
    node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

int peek(Stack *stack) {
    if (stack != NULL && stack->top != NULL)
        return stack->top->data;

    printf("Stack is empty or stack doesn't exist\n");
    return -1;
}

int size(Stack *stack) {
    if (stack == NULL) return -1;
    node *temp = stack->top;
    int count = 0;
    while ( temp != NULL ) {
        temp = temp->next;
        count++;
    }

    return count;
}

int isEmpty(Stack *stack) {
    if (stack == NULL) return -1;
    return stack->top == NULL;
}




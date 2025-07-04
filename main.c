//
//Created by Xiangtao Wu on 2025/6/28
//

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"
#define FILE_NAME "Postfix Expression Problems.txt"
#define TRUE 1
#define FALSE 0
#define ZERO '0'

//Function declaration
int calculator (int operand1, int operand2, char operator);
int isOperator (char ch);

int main(void) {
    //Create a FILE pointer to read the problems
    FILE *input = fopen(FILE_NAME, "r");
    //Safety Check
    if (input == NULL) {
        perror("Error opening file");
        return -1;
    }
    //Create Stack for storage
    Stack *stack = createStack();

    //Required Variables for file reading
    char ch;
    int sameOperand = FALSE;

    //While is not the end of the file
    while ( (ch = fgetc(input)) != EOF ) {

        if ( isdigit(ch) ) {
            //If the character is a digit
            //Convert the character into an integer
            int num = ch - ZERO;
            if (sameOperand) {
                //If the previous character was a digit
                //Get the previous number and move it by one digit
                //Add the current digit to the previous number and put it back to stack
                int value = pop(stack);
                value *= 10;
                push(stack, value);
            }
            else {
                //If the previous digit is not digit
                //Simply put the num into stack
                //And set sameOperand to TRUE to indicate the previous character is a digit for the next loop
                push(stack, num);
                sameOperand = TRUE;
            }
        }
        else if ( isOperator(ch) ) {
            //If the character is an operator
            //We then access the previous two operands we stored in the stack
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            if (operand1 == -1 || operand2 == -1) {
                //Safety check
                printf("Invalid Postfix Expression");
                break;
            }
            //Use calculator to calculate the result of the two numbers
            //Then push it to the stack
            int num = calculator(operand1, operand2, ch);
            push(stack, num);
        }
        else {
            //If the character is space or newLine
            sameOperand = FALSE;
        }

        if (ch == '\n') {
            //Print the answer of the problems at the end of each line
            printf("%d\n", pop(stack));
        }
    }

    //Destroy the stack and close the file
    destroyStack(stack);
    fclose(input);
    return 0;
}

//Helper functions
int calculator (int operand1, int operand2, char operator) {
    switch (operator) {
        case '^':
            return (int) pow(operand2, operand1);
        case '*':
            return operand2 * operand1;
        case '/':
            return operand2 / operand1;
        case '+':
            return operand2 + operand1;
        case '-':
            return operand2 - operand1;
        default:
            printf("Invalid operator!\n");
            return -1;
    }
}

int isOperator (char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
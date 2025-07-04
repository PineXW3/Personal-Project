# Personal-Project: Infix & Postfix
This Project is meant for Infix and Postfix Problems to be exchangeable to each other, and able to solve the expressions.

Example:
It suppose to be able to change the infix expression 3 + 4 to postfix expression 3 4 +, and be able to solve both expressions with same answer 7.

## Current Status: incomplete
Due to time issues, I only completed one of the ability the Project supposed to done.
This Project currently only has one ability: solve the postfix expressions.

It also can't handle negative operands in the expressions
Example:
You can't include something like -3 4 + in the problems

## Planned Update
1. Solve the negative operands issue
2. Include the ability to exchange the postfix expression to infix expression

## Project Structure
Personal-Project/
CMakeLists.txt # CMake configuration file
main.c # Entry point
stack.c # Stack implementation
stack.h # Stack header file
Postfix Expression Problems.txt # Example inputs/problems
README.md # Project Documentation

## How to Run
I was using the CLion to build the project, and I found out that you have to include the input file in the Working Directory for the file to be able read.
So make sure to do that if you are using CLion.

Also if you want to create your own postfix problems, make sure to hit enter, everytime you created a problem.
It is because this project only print the answer when it reads the '\n'.

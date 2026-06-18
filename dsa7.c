/*7.. Factory Workflow Result Calculator

You are part of a software development team building an automation system for a modern manufacturing plant. In the plant, production steps are recorded in a special operation sequence format where the operands (materials or quantities) are listed first, followed by the operation to be performed on them. This format allows machines to process the workflow without worrying about parentheses or operator precedence.

This sequence format follows a postfix-style structure, where each operation is applied to the most recent values recorded in the workflow.

Your task is to develop a program that evaluates such an operation sequence and computes the final result produced by the manufacturing process.

The program should process the sequence using a stack-based approach, where numbers are pushed onto the stack and operations combine the most recent values.



Problem Description

Implement a function that takes a string representing a postfix-style operation sequence and calculates the final result.



Input Format

A single line containing the operation sequence as a string.
The sequence consists of non-negative integers and the operators + , - , * , / separated by spaces.


Output Format

Print a single integer representing the evaluated result of the operation sequence.



Sample Input

5 1 2 + 4 * + 3 -



Sample Output

14



Explanation

The postfix expression 5 1 2 + 4 * + 3 - is evaluated as follows:
Start with an empty stack.
Push 5 onto the stack: Stack = [5]
Push 1 onto the stack: Stack = [5, 1]
Push 2 onto the stack: Stack = [5, 1, 2]
Encounter +: Pop 2 and 1, calculate 1 + 2 = 3, push back 3: Stack = [5, 3]
Push 4 onto the stack: Stack = [5, 3, 4]
Encounter *: Pop 4 and 3, calculate 3 * 4 = 12, push back 12: Stack = [5, 12]
Encounter +: Pop 12 and 5, calculate 5 + 12 = 17, push back 17: Stack = [17]
Push 3 onto the stack: Stack = [17, 3]
Encounter -: Pop 3 and 17, calculate 17 - 3 = 14, push back 14: Stack = [14]
The final result is 14.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[100];
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while(token != NULL)
    {
        if(isdigit(token[0]))
        {
            push(atoi(token));
        }
        else
        {
            int b = pop();
            int a = pop();

            switch(token[0])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}

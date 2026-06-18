/*6.   Client Logo
DS | REC | 18 Jun
Course Progress
0%
•••
•••
Completed
Production Formula Converter

You are part of a software development team working for a manufacturing automation system. In this system, production formulas are written using operators and operands to describe how different materials and processes are combined. However, before the system can evaluate these formulas efficiently, it must first convert them from infix notation into postfix notation.

In infix notation, operators appear between operands, which is the standard way humans write expressions. In postfix notation, the operator comes after its operands. This format is easier for machines to process because it removes the need for repeatedly checking parentheses and operator precedence during evaluation.

Your task is to implement a function that converts a given infix production formula into its equivalent postfix form.



Problem Description

Implement a function that takes a string representing an infix expression and converts it into its equivalent postfix expression.



Input Format

A single line containing the infix expression as a string.The expression consists of operands, operators + , - , * , /, and parentheses ( ), separated by spaces.



Output Format

Print a string representing the equivalent postfix expression.


Example 1

Sample Input 1

A + B * C - D



Sample Output 1

A B C * + D -



Explanation

The infix expression A + B * C - D is converted to postfix as follows:
Infix: A + (B * C) - D
Postfix: A B C * + D -
In this case, B * C is calculated first, followed by A + (result), and finally subtracting D.



Example 2

Sample Input 2

( A + B ) * C



Sample Output 2

A B + C *



Explanation

The infix expression ( A + B ) * C is converted to postfix as follows:
Infix: (A + B) * C
Postfix: A B + C *
Here, A + B is calculated first, followed by multiplying the result with C.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100];
    fgets(infix, sizeof(infix), stdin);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
            printf("%c ", ch);

        else if (ch == '(')
            push(ch);

        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                printf("%c ", pop());
            pop();
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                printf("%c ", pop());

            push(ch);
        }
    }

    while (top != -1)
        printf("%c ", pop());

    return 0;
}

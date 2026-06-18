/*9.Network Command Validator

You are part of a development team building a network command analyzer for a server monitoring system. In this system, commands sent to the server often include grouped parameters enclosed in brackets. These brackets help structure complex commands and ensure operations are executed in the correct order.

However, during command generation, the system may accidentally include extra or unnecessary brackets that do not affect the actual command execution. These redundant brackets increase the complexity of the command string and make it harder to process efficiently.To optimize command processing, the analyzer must detect whether a command string contains redundant brackets.

Your task is to implement a program that checks each command expression and determines whether it contains unnecessary brackets.



Input Format

The first line contains an integer N, representing the number of command expressions.
The next N lines each contain a command expression represented as a string.


Output Format

For each expression:

Print "Yes" if the expression contains redundant brackets.
Print "No" if the expression does not contain redundant brackets.


Sample Input 1

3

(a + b)

((a + b))

(a + (b + c))



Sample Output 1

No

Yes

No



Explanation

For the expression (a + b), there are no redundant brackets, so the output is "No".
For the expression ((a + b)), the outer brackets are unnecessary, hence the output is "Yes".
For the expression (a + (b + c)), all brackets are needed for the correct evaluation, so the output is "No".*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    while(n--)
    {
        char s[200];
        fgets(s, sizeof(s), stdin);

        int stack[200];
        int top = -1;
        int redundant = 0;

        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] != ')')
            {
                stack[++top] = s[i];
            }
            else
            {
                int hasOp = 0;

                while(top != -1 && stack[top] != '(')
                {
                    if(stack[top] == '+' || stack[top] == '-' ||
                       stack[top] == '*' || stack[top] == '/')
                        hasOp = 1;

                    top--;
                }

                top--; // remove '('

                if(hasOp == 0)
                    redundant = 1;
            }
        }

        if(redundant)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

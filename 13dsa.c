/*13)Reverse Shipment Order in a Delivery Hub

You are part of a development team building a shipment management system for a large delivery hub. Packages arrive at the hub and are stored in a queue based on the order in which they were received.However, due to an unexpected operational issue, the dispatch process must be reversed so that the most recently received package is dispatched first. To handle this situation, the system must reverse the order of package IDs currently stored in the queue.Your task is to write a program that reverses the order of package IDs so that the last package received becomes the first one to be dispatched.For example, if the queue contains package IDs [10, 20, 30, 40, 50], after reversing it should become [50, 40, 30, 20, 10].

Input Format

The first line contains an integer N, representing the number of packages in the queue.
The second line contains N space-separated integers, representing the package IDs.


Constraints

1<= N <= 10^5

Output Format

Print the package IDs in reversed order, separated by spaces.

Sample Input 1

5

1 2 3 4 5

Sample Output 1

5 4 3 2 1

Explanation

Initially, the package queue is:

[1, 2, 3, 4, 5]

After reversing the order, the queue becomes:

[5, 4, 3, 2, 1]

This means the package with ID 5 will now be dispatched first, followed by 4, 3, 2, and 1.*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // print in reverse order
    for(int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    return 0;
}

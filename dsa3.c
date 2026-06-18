/*3 VIP Entry ID Insertion at Beginning

You are building an event management system where VIP entry IDs are maintained in a linked list. Whenever a high-priority guest arrives, their ID must be added at the beginning of the list so they receive immediate attention.

Write a program to insert new VIP entry IDs at the beginning of the linked list. After all insertions are completed, print the entire linked list to verify the final order.



Input Format

The first line contains an integer N, representing the number of VIP entry IDs to be added.
The second line contains N space-separated integers representing the VIP entry IDs.


Output Format

After completing all insertions, print the current linked list with elements separated by a space.



Sample Input 1

5

201 202 203 204 205



Sample Output 1

205 204 203 202 201



Explanation

Initially the linked list is empty. The first VIP entry ID 201 is inserted at the beginning, and the list becomes 201. 
The second VIP entry ID 202 is inserted at the beginning, and the list becomes 202 201. The third VIP entry ID 203 is inserted at the beginning, 
and the list becomes 203 202 201. The fourth VIP entry ID 204 is inserted at the beginning, and the list becomes 204 203 202 201. The fifth VIP entry ID 205 is inserted at the beginning, and the list becomes 205 204 203 202 201.easy c 

*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);

    return 0;
}

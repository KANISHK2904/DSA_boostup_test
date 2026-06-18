/*2.Removing Duplicate Student Registration Numbers

A university maintains a list of student registration numbers for a workshop. Due to manual entry errors, some registration numbers may appear more than once in the list. The list is stored using a linked list and the order represents the sequence in which students registered. To maintain accurate records, the system must remove duplicate registration numbers while keeping the first occurrence of each number in the same order as originally entered Your task is to remove duplicate registration numbers from the linked list.



Input Format

The first line contains an integer N, representing the number of registration numbers initially added to the linked list.
The second line contains N space-separated integers representing the registration numbers.


Output Format

Print the linked list after removing duplicate registration numbers, with elements separated by a space.



Sample Input 1

7

101 102 103 101 104 105 102



Sample Output 1

101 102 103 104 105



Explanation

The initial linked list contains the registration numbers:

101 → 102 → 103 → 101 → 104 → 105 → 102

The numbers 101 and 102 appear more than once.

Only their first occurrences are kept, and the duplicates are removed.

The updated linked list becomes:

101 → 102 → 103 → 104 → 105

Thus, the output is:

101 102 103 104 105.*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
    {
        int duplicate = 0;

        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                duplicate = 1;
                break;
            }
        }

        if(duplicate == 0)
            printf("%d ", a[i]);
    }

    return 0;
}

/*17) First Student in the Last Row

In a classroom, students are seated in a tree-like arrangement represented using a binary tree. Each student has a roll number.The students sitting in the lowest level form the last row of the classroom arrangement. The teacher wants to find the leftmost student in that last row.Your task is to identify the roll number of the first student from the left in the deepest level of the binary tree.

Given the values of a binary tree in level-order traversal, find the leftmost node value in the last row of the tree.

Input Format

The first line contains an integer representing the number of values in the binary tree.
The second line contains space-separated integers representing the input values in level-order traversal.

Output Format

Print a single integer representing the leftmost value in the last row of the binary tree.

Sample Input 1

7
1 2 3 4 5 6 7
Sample Output 1

4
Explanation

The binary tree looks like:

     1

    / \

    2  3

   / \ / \

  4 5 6 7

The last row contains: 4, 5, 6, 7

The leftmost value in the last row is 4.*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int i = 0;
    int count = 1;

    // find last level start index
    while(i + count < n)
    {
        i = i + count;
        count = count * 2;
    }

    printf("%d", a[i]);

    return 0;
}

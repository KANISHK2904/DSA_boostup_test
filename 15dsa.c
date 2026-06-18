/*15)  Mirror Arrangement of a Tree

In a classroom, students are seated in a structured arrangement represented using a binary tree. Each student has a roll number.Due to a classroom activity, the teacher asks the students to swap their positions symmetrically:Every left-side student swaps with the corresponding right-side student at each level.This creates a mirror arrangement of the original seating.

Your task is to perform this transformation and display the new arrangement.
Given a binary tree in level-order traversal, invert the tree by swapping the left and right children of every node, and print the resulting tree in level-order traversal.

Input Format

The first line contains an integer representing the number of nodes.
The second line contains space-separated integers representing the binary tree in level-order traversal.

Output Format

Print the values of the nodes of the inverted binary tree in level-order traversal.

Sample Input 1

7

1 2 3 4 5 6 7

Sample Output 1

1 3 2 7 6 5 4

Explanation

Original tree:

    1

   / \

   2  3

  / \ / \

  4 5 6 7

After swapping left and right at every node:

     1

    / \

   3  2

  / \ / \

  7 6 5 4

Level-order traversal of the mirrored tree is:
1 3 2 7 6 5 4*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // swap children in level-order (0-based indexing)
    for(int i = 0; i < n; i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && right < n)
        {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }

    // print level order
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

/*16) Hierarchy Levels in a Tree Structure

In a company, employees are organized in a hierarchical structure represented as a binary tree. The top-level manager is at the root, and each employee can have up to two subordinates.The number of levels in this structure represents how deep the hierarchy goes from the top manager to the lowest-level employee.Your task is to determine the maximum number of levels in this hierarchy.

Given a binary tree in level-order format (including "null" values), find the maximum depth (number of levels) of the tree.

Input Format

The first line contains an integer representing the number of elements.
The second line contains space-separated values representing the binary tree in level-order, where null indicates no node.
Output Format

Print a single integer representing the maximum depth of the binary tree.



Sample Input 1

7

3 9 20 null null 15 7

Sample Output 1

3

Explanation

3 is the root (top manager).

9 and 20 are subordinates of 3.

9 has no further subordinates.

20 has two subordinates: 15 and 7.

The structure:

   3

   / \

  9  20

     / \

    15 7

The longest path from root to leaf has 3 levels, so the answer is 3.*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char a[100][10];

    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);

    int start = 0;
    int level = 0;

    while(start < n)
    {
        int size = n - start;
        int nodes = 0;

        // count current level nodes (skip null)
        for(int i = 0; i < size; i++)
        {
            if(strcmp(a[start + i], "null") != 0)
                nodes++;
        }

        // move one level (approx safe level grouping)
        start += size;
        level++;
    }

    printf("%d", level);

    return 0;
}

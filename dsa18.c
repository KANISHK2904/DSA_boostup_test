/*18). DS | REC | 18 Jun
Course Progress
0%
•••
Completed
Check Root-to-Leaf Path Sum in a BST

A company stores transaction amounts in a Binary Search Tree (BST) for easy record management.Each node in the tree represents a transaction amount. The company wants to check whether there is any path from the root node to a leaf node such that the sum of all values in that path is exactly equal to a given target amount.Your task is to build the BST using the given transaction amounts and determine whether such a path exists.Given the values of nodes, construct a Binary Search Tree (BST) by inserting the values one by one. Then check whether there exists a root-to-leaf path whose sum is equal to the given targetSum.

Input Format

The first line contains an integer n, representing the number of nodes to be inserted into the BST.
The second line contains n space-separated integers representing the node values.
The third line contains an integer targetSum, representing the required path sum.

Constraints

The tree follows the Binary Search Tree (BST) property.
All node values are positive integers.

Output Format

Print "True" if there exists a root-to-leaf path whose sum is equal to targetSum.
Otherwise, print "False".


Sample Input 1

5

5 3 8 2 4

10

Sample Output 1

true

Explanation

The BST is formed by inserting the values:

5 3 8 2 4

So the tree becomes

   5

   / \

  3  8

  / \

 2  4

Now check the root-to-leaf paths:

5 → 3 → 2 = 10

5 → 3 → 4 = 12

5 → 8 = 13

Since the path 5 → 3 → 2 gives the sum 10, the output is:true*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int val)
{
    if(root == NULL)
        return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int hasPathSum(struct Node* root, int sum)
{
    if(root == NULL)
        return 0;

    sum = sum - root->data;

    if(root->left == NULL && root->right == NULL)
    {
        if(sum == 0)
            return 1;
        else
            return 0;
    }

    return hasPathSum(root->left, sum) ||
           hasPathSum(root->right, sum);
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int targetSum;
    scanf("%d", &targetSum);

    if(hasPathSum(root, targetSum))
        printf("true");
    else
        printf("false");

    return 0;
}

/*19 ) Find Minimum Value in a BST

A warehouse stores product prices in a Binary Search Tree (BST) to organize them efficiently.The manager wants to quickly find the lowest-priced product available in the warehouse.Your task is to build the BST using the given product prices and determine the minimum price present in the tree.Given n product prices, construct a Binary Search Tree (BST) by inserting the values in the given order. Then find and print the minimum value in the BST.

Input Format

The first line contains an integer n, representing the number of products.
The second line contains n space-separated integers representing the product prices.

Output Format

Print a single integer representing the minimum price in the BST.

Sample Input 1

5

150 200 50 300 100

Sample Output 1

50

Explanation

Step 1: Insert the values into the BST:

150, 200, 50, 300, 100

Step 2: In a BST, the minimum value is always found by moving to the leftmost node.

Step 3: The leftmost node in the tree is 50.

Hence, the output is

50*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int x)
{
    if(root == NULL)
        return newNode(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

int findMin(struct Node* root)
{
    while(root->left != NULL)
        root = root->left;

    return root->data;
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

    printf("%d", findMin(root));

    return 0;
}

/*1.  Client Logo
DS | REC | 18 Jun
Course Progress
0%
•••
Completed
Finding Common Customer IDs from Two Service Records

A company maintains customer records from two different service platforms. Each platform stores customer IDs in a linked list, sorted in non-decreasing order. To identify customers who are using both services, the company needs to find the common customer IDs present in both lists.Your task is to compare the two sorted linked lists and identify the intersection, which represents the customer IDs that appear in both service records.



Input Format

The first line contains an integer N1, representing the number of customer IDs in the first linked list.
The second line contains N1 space-separated integers representing the customer IDs in the first list.
The third line contains an integer N2, representing the number of customer IDs in the second linked list.
The fourth line contains N2 space-separated integers representing the customer IDs in the second list.


Output Format

Print the customer IDs that appear in both lists, separated by a space.
If there are no common IDs, print "No Intersection".


Example 1

Sample Input 1

5

101 102 103 104 105

4

102 104 106 108



Sample Output 1

102 104



Explanation

The first service record contains customer IDs:

101 → 102 → 103 → 104 → 105

The second service record contains customer IDs:

102 → 104 → 106 → 108

The common IDs present in both records are 102 and 104.

Therefore, the output is:

102 104



Example 2

Sample Input 2

5

10 20 30 40 50

4

5 15 25 35



Sample Output 2

No Intersection



Explanation

The first service record contains IDs:

10 → 20 → 30 → 40 → 50 easy with c

The second service record contains IDs:

5 → 15 → 25 → 35

Since there are no common IDs between the two lists, the result is No Intersection.easy*/
  
  
  #include <stdio.h>

int main()
{
    int n1, n2, found = 0;

    scanf("%d", &n1);
    int a[n1];

    for(int i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    scanf("%d", &n2);
    int b[n2];

    for(int i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(a[i] == b[j])
            {
                printf("%d ", a[i]);
                found = 1;
                break;
            }
        }
    }

    if(found == 0)
        printf("No Intersection");

    return 0;
}

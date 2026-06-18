/*12)Maximum Sales in Every K-Day Period

You are part of a development team building a sales analytics system for a retail company. The company records the number of products sold each day and wants to analyze sales trends over fixed periods. To help the sales team identify peak performance periods, the system must calculate the maximum sales value in every contiguous block of K days. As new daily sales data arrives, the company wants to continuously know the highest sales figure within the most recent K-day window. This helps in tracking demand spikes and comparing short-term performance.



Input Format

The first line contains an integer N, representing the number of daily sales records.
The second line contains N space-separated integers, representing the sales values for each day.
The third line contains an integer K, representing the size of the sliding window.


Constraints

1<= N <=10^5
1<= K <= N


Output Format

Print the maximum sales value for each contiguous subarray of size K.



Sample Input

6

1 2 3 1 4 5

3



Sample Output

3 3 4 5



Explanation

The maximum sales in the first 3-day period (1, 2, 3) is 3.

The maximum sales in the next 3-day period (2, 3, 1) is also 3.

The maximum sales in (3, 1, 4) is 4.

The maximum sales in (1, 4, 5) is 5.*/

#include <stdio.h>

int dq[100000];
int front = 0, rear = -1;

void push_back(int x)
{
    dq[++rear] = x;
}

void pop_back()
{
    rear--;
}

void pop_front()
{
    front++;
}

int front_val()
{
    return dq[front];
}

int empty()
{
    return front > rear;
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int k;
    scanf("%d", &k);

    front = 0;
    rear = -1;

    for(int i = 0; i < n; i++)
    {
        // remove elements smaller than current
        while(!empty() && a[dq[rear]] < a[i])
            pop_back();

        push_back(i);

        // remove out of window
        if(dq[front] <= i - k)
            pop_front();

        // print result
        if(i >= k - 1)
            printf("%d ", a[dq[front]]);
    }

    return 0;
}

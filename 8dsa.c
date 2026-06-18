/*8.  Client Logo
DS | REC | 18 Jun
Course Progress
0%
•••
•••
Completed
Stock Price Waiting Analyzer

You are part of a financial analytics team developing a stock monitoring application for investors. The application records the daily stock prices of a company and helps investors understand how long they must wait to see a higher stock price in the future. This insight allows investors to plan their buying or selling strategies more effectively.

Your task is to implement a function that takes an array of integers representing the daily stock prices and returns another array indicating how many days an investor must wait after each day to see a higher stock price.



Problem Description

Given an array prices where prices[i] represents the stock price on the i-th day, produce an array answer such that:

answer[i] represents the number of days until a higher stock price occurs.
If there is no future day with a higher price, then answer[i] = 0.


Input Format

The first line contains an integer N, representing the number of days.
The second line contains N space-separated integers, representing the stock prices for each day.


Output Format

Print N integers representing the number of days to wait for a higher stock price for each day.



Sample Input

8

73 74 75 71 69 72 76 73



Sample Output

1 1 4 2 1 1 0 0



Explanation

Day 0: The stock price is 73. A higher price (74) appears after 1 day, so the output is 1.

Day 1: The stock price is 74. A higher price (75) appears after 1 day, so the output is 1.

Day 2: The stock price is 75. The next higher price (76) occurs after 4 days, so the output is 4.

Day 3: The stock price is 71. A higher price (72) occurs after 2 days, so the output is 2.

Day 4: The stock price is 69. A higher price (72) occurs after 1 day, so the output is 1.

Day 5: The stock price is 72. A higher price (76) occurs after 1 day, so the output is 1.

Day 6: The stock price is 76. There is no future day with a higher price, so the output is 0.

Day 7: The stock price is 73. There is no future day with a higher price, so the output is 0.*/


#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n], ans[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
    {
        ans[i] = 0;

        for(int j = i + 1; j < n; j++)
        {
            if(a[j] > a[i])
            {
                ans[i] = j - i;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}

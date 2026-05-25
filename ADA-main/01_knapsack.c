#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W, i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    // Input profits and weights
    for(i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &profit[i], &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // DP table
    int dp[n + 1][W + 1];

    // Bottom-up table filling
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            // Base condition
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            // Item can be included
            else if(weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]]
                );
            }

            // Item cannot be included
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print DP table
    printf("\nDP Table:\n");

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            printf("%4d", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}

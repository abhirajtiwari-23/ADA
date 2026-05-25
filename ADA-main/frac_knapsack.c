#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

void sortItems(struct Item item[], int n)
{
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &item[i].weight, &item[i].profit);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("\nEnter capacity of knapsack: ");
    scanf("%f", &capacity);

    // Sort items based on profit/weight ratio
    sortItems(item, n);

    printf("\nSelected Items:\n");

    for(i = 0; i < n; i++)
    {
        if(item[i].weight <= capacity)
        {
            printf("Item %d taken completely\n", i + 1);

            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else
        {
            float fraction = capacity / item[i].weight;

            printf("Item %d taken %.4f fraction\n",
                   i + 1, fraction);

            totalProfit += item[i].profit * fraction;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}

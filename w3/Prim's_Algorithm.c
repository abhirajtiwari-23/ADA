#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, i, j;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    // Input cost adjacency matrix
    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (no edge)
            if(cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    int visited[MAX] = {0};
    int min_cost = 0;
    int edges = 0;

    // Start from vertex 0
    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u != -1 && v != -1) {
            printf("%d -> %d  cost = %d\n", u, v, min);
            min_cost += min;
            visited[v] = 1;
            edges++;
        }
    }

    printf("\nMinimum Cost = %d\n", min_cost);

    return 0;
}

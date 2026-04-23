#include <stdio.h>

#define INF 999

int main() {
    int n, i, j, k;
    int cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 (except diagonal) with INF
            if(i != j && cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    // Floyd's Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    // Output result
    printf("Shortest path matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(cost[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}























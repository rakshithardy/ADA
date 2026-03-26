#include <stdio.h>

#define MAX 20
#define INF 9999

int parent[MAX];

// Find root
int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

// Union
void unionSet(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize parent (IMPORTANT FIX)
    for(int i = 0; i < n; i++)
        parent[i] = i;

    printf("Enter cost adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int edges = 0, mincost = 0;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        int min = INF, a = -1, b = -1;

        // Find minimum edge
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if(u != v) {
            printf("%d - %d : %d\n", a, b, min);
            mincost += min;
            unionSet(u, v);
            edges++;
        }

        // Remove edge
        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}


#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, graph[MAX][MAX];
    int visited[MAX] = {0};
    int min, u = 0, v = 0;
    int total_cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    for (int k = 0; k < n - 1; k++) {
        min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", u, v, min);
        total_cost += min;
        visited[v] = 1;
    }

    printf("\nTotal cost of MST = %d\n", total_cost);

    return 0;
}

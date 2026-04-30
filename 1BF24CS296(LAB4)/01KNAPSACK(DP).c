#include<stdio.h>
int n, M;
int w[10], p[10];
int main() {
    printf("enter number of objects: ");
    scanf("%d", &n);
    printf("enter capacity of knapsack: ");
    scanf("%d", &M);
    printf("enter weight and profit for each object:\n");
    for(int i = 0; i < n; i++) {
        printf("object %d: ", i + 1);
        scanf("%d%d", &w[i], &p[i]);
    }
    int v[n+1][M+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= M; j++) {
            if(i == 0 || j == 0) {
                v[i][j] = 0;
            }
            else if(w[i-1] > j) {
                v[i][j] = v[i-1][j];
            } else {
                int in = v[i-1][j - w[i-1]] + p[i-1];
                int ex = v[i-1][j];
                v[i][j] = (in>ex)?in:ex;
            }
        }
    }
    printf("\nmax profit = %d\n", v[n][M]);
    int x[n];
    for(int i = 0; i < n; i++) {
        x[i] = 0;
    }
    int i = n, j = M;
    while(i > 0 && j > 0) {
        if(v[i][j] != v[i-1][j]) {
            x[i-1] = 1;
            j = j - w[i-1];
        }
        i--;
    }
    printf("\nsolution vector:");
    for(int k = 0; k < n; k++) {
        printf("%d ", x[k]);
    }
    printf("\nselected objects:");
    for(int k = 0; k < n; k++) {
        if(x[k] == 1) {
            printf("%d ", k+1);
        }
    }
    printf("\n");
    return 0;
}

#include <stdio.h>
int M, n, w[10], p[10], idx[10];
float r[10], x[10], final_x[10];
int main() {
    printf("Enter number of objects: ");
    scanf("%d", &n);
    printf("Enter weights of objects:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    printf("Enter profits of objects:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);
     for(int i = 0; i < n; i++) {
        r[i] = (float)p[i] / w[i];
        x[i] = 0.0;
        idx[i] = i;
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(r[i] < r[j]) {
                // swap ratios
                float temp = r[i];
                r[i] = r[j];
                r[j] = temp;
                // swap weights
                int t = w[i];
                w[i] = w[j];
                w[j] = t;
                // swap profits
                t = p[i];
                p[i] = p[j];
                p[j] = t;
                // swap indices
                t = idx[i];
                idx[i] = idx[j];
                idx[j] = t;
            }
        }
    }

    float totalProfit = 0.0;
    int remaining = M;
    for(int i = 0; i < n; i++) {
        if(w[i] <= remaining) {
            x[i] = 1.0;
            totalProfit += p[i];
            remaining -= w[i];
        } else {
            x[i] = (float)remaining / w[i];
            totalProfit += x[i] * p[i];
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        final_x[idx[i]] = x[i];
    }

    printf("Solution vector (original order):\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i, final_x[i]);
    }
    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;
}

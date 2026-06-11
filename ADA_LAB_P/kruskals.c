#include<stdio.h>
#define max 20
#define inf 999
    int parent[max];

int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}
void unionset(int i,int j){
    parent[j]=i;
}
int main(){
    int n,cost[max][max];
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
                cost[i][j] = inf;
        }
    }
    int edges=0,mincost=0;
    printf("edges in mst:\n");
    while(edges<n-1){
        int min=inf,a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        int u=find(a);
        int v=find(b);
        if(u!=v){
            printf("%d-->%d =%d\n",a,b,min);
            mincost+=min;
            unionset(u,v);
            edges++;
        }
        cost[a][b]=cost[b][a]=inf;
    }
    printf("minimum cost=%d\n",mincost);
    return 0;


}

#include<stdio.h>
#include<limits.h>
int main(){
    int i,j,k,n;
    printf("enter no of vertices:");
    scanf("%d",&n);
    int graph[n][n],visited[n]={};
    int u=0,v=0,min,total_cost=0;
    printf("enter adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0)
                graph[i][j]=INT_MAX;
        }
    }
    int start;
    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    visited[start] = 1;
    printf("edges in mst:\n");
    for(k=0;k<n-1;k++){
        min=INT_MAX;
        for(i=0;i<n;i++){
            if(visited[i]==1){
                for(j=0;j<n;j++){
                    if(graph[i][j]<min&&visited[j]!=1){
                        min=graph[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        printf("%d->%d=%d \n",u,v,min);
        total_cost+=min;
        visited[v]=1;
    }
    printf("total cost of mst:%d\n",total_cost);
    return 0;
}

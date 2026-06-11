#include<stdio.h>
int n,i,j,k;
#define max 999
int main(){
    printf("enter no of vertices:");
    scanf("%d",&n);
    int cost[n][n];
    printf("enter cost adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(i!=j&&cost[i][j]==0){
                cost[i][j]=max;
            }
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(cost[i][k]+cost[k][j]<cost[i][j])
                    cost[i][j]=cost[i][k]+cost[k][j];
            }
        }
    }
    printf("shortest path matrix:\n  ");
    for(i=0;i<n;i++)
      printf(" %d",i+1);
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d |",i+1);
        for(j=0;j<n;j++){
            if(cost[i][j]==max){
                printf("- ");
            }else{
                printf("%d ",cost[i][j]);
            }
        }
        printf("\n");
    }
}

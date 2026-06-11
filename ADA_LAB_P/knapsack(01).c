#include<stdio.h>
int n,m;
int w[10],p[10];
int main(){
    printf("enter no of objects:");
    scanf("%d",&n);
    printf("enter capacity of knapsack:");
    scanf("%d",&m);
    printf("enter weights and profits:\n");
    for(int i=0;i<n;i++){
        printf("object %d:",i+1);
        scanf("%d%d",&w[i],&p[i]);
    }
    int v[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                v[i][j]=0;
            }else if(w[i-1]>j){
                v[i][j]=v[i-1][j];
            }else{
                int in=v[i-1][j-w[i-1]]+p[i-1];
                int ex=v[i-1][j];
                v[i][j]=(in>ex)?in:ex;
            }
        }
    }
    printf("max profit:%d\n",v[n][m]);
    int x[n];
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    int i=n,j=m;
    while(i>0&&j>0){
        if(v[i][j]!=v[i-1][j]){
            x[i-1]=1;
            j-=w[i-1];
        }
        i--;
    }
    printf("solution vector:[ ");
    for (int i=0;i<n;i++){
        printf("%d ",x[i]);
    }
    printf("]\n");
    printf("selected objects:");
    for (int i=0;i<n;i++){
       if(x[i]==1){
           printf("%d ",i+1);
       }
    }
    printf("\n");
    printf("dp table:\n");
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}

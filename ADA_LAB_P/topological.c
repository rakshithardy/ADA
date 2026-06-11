#include<stdio.h>
int n,i,j;
int main(){
  printf("enter no of vertices:");
  scanf("%d",&n);
  int adj[n][n],in[n],out[n];
  for(i=0;i<n;i++){
     in[i]=0;
     out[i]=0;
  }
  printf("enter adjacency matrix:\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&adj[i][j]);
        if(adj[i][j]!=0){
            in[j]+=adj[i][j];
            out[i]+=adj[i][j];
        }
    }
  }
  int visited[n]={};
  int count=0;
  printf("topological order:\n");
  while(count<n){
    int found=0;
    for(i=0;i<n;i++){
        if(in[i]==0&&visited[i]==0){
            printf("%d ",i+1);
            count++;
            visited[i]=1;
            found=1;
            for(j=0;j<n;j++){
                if(adj[i][j]!=0){
                    in[j]--;
                }
            }
        }
    }
    if(!found){
        printf("cycle found..topological order not possible.\n");
    }
  }
  return 0;
}


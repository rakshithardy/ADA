#include<stdio.h>
int n,adj[10][10],in[10],out[10];
int main(){
    printf("enter number of vertices:");
    scanf("%d",&n);
    printf("enter adjacency matrix:");
    for(int i=0;i<n;i++){
        in[i]=0;
        out[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
            if(adj[i][j]!=0){
                out[i] += adj[i][j];
                in[j] += adj[i][j];
            }
        }
    }
    int vis[10] = {0};
    int count = 0;
    printf("\nTopological Order:\n");
    while(count < n) {
        int found=0;
        for(int i = 0; i < n; i++) {
            if(in[i] == 0 && vis[i] == 0) {
                printf("%d ", i + 1);
                vis[i] = 1;
                count++;
                found=1;
                // Remove outgoing edges
                for(int j = 0; j < n; j++) {
                    if(adj[i][j] != 0) {
                        in[j]--;
                    }
                }
            }
        }
        if(!found){
            printf("cycle exists..topological order is not possible\n");
        }
    }
    return 0;
}

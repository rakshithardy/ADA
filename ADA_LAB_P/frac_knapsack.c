
#include<stdio.h>
int n,m,i,j,temp;
int main(){
    printf("enter no of objects:");
    scanf("%d",&n);
    int w[n],p[n],idx[n];
    float r[n],x[n],final_x[n];
    printf("enter weights and profits for\n");
    for(i=0;i<n;i++){
        printf("object %d:",i+1);
        scanf("%d%d",&w[i],&p[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        idx[i]=i;
        r[i]=(float)p[i]/w[i];
        x[i]=0.0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(r[j]<r[j+1]){
                temp=w[j];w[j]=w[j+1];w[j+1]=temp;
                temp=p[j];p[j]=p[j+1];p[j+1]=temp;
                temp=r[j];r[j]=r[j+1];r[j+1]=temp;
                temp=idx[j];idx[j]=idx[j+1];idx[j+1]=temp;

            }
        }
    }
    float total_profit=0;
    int remaining=m;
    for(i=0;i<n;i++){
        if(w[i]<=remaining){
            total_profit+=p[i];
            remaining-=w[i];
            x[i]=1;
        }else{
            x[i]=(float)remaining/w[i];
            total_profit+=x[i]*p[i];
            break;
        }
    }
    for(i=0;i<n;i++){
        final_x[idx[i]]=x[i];
    }
        printf("Solution vector (original order):\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %.2f\n", i, final_x[i]);
    }
    printf("Maximum profit = %.2f\n", total_profit);
    return 0;

}

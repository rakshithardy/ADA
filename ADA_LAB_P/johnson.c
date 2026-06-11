#include<stdio.h>
int i,j;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void print(int a[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n],a[n],dir[n];
    int count=1;
    printf("enter array elemnts:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        a[i]=arr[i];
        dir[i]=-1;   // -1 = left
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        a[i]=arr[i];
        dir[i]=-1;   // -1 = left
    }
    printf("%d : ", count);
    print(a,n);
    while(1){
        int mobile=0,pos=-1;
        // find largest mobile element
        for(int i=0;i<n;i++){
            if(dir[i]==-1 && i!=0 && a[i]>a[i-1] && a[i]>mobile){
                mobile=a[i];
                pos=i;
            }
            if(dir[i]==1 && i!=n-1 && a[i]>a[i+1] && a[i]>mobile){
                mobile=a[i];
                pos=i;
            }
        }
        if(pos==-1)
            break;
        int next=pos+dir[pos];
        swap(&a[pos],&a[next]);
        swap(&dir[pos],&dir[next]);
        pos=next;
        // change directions
        for(int i=0;i<n;i++){
            if(a[i]>mobile)
                dir[i]=-dir[i];
        }
        // Increase permutation count
        count++;
        // Print next permutation
        printf("%d : ", count);
        print(a,n);
    }
     // Print total permutations
    printf("\nTotal permutations = %d", count);
    return 0;
}

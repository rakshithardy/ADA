#include<stdio.h>
int n;
void merge(int a[],int low,int mid,int high){
    int i,j,k,c[n];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high){
        if(a[i]<a[j]){
            c[k++]=a[i++];
        }else{
            c[k++]=a[j++];
        }
    }
    while(i<=mid){
        c[k++]=a[i++];
    }
    while(j<=high){
        c[k++]=a[j++];
    }
    for(i=low;i<=high;i++){
        a[i]=c[i];
    }
}
void mergesort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main(){
    printf("enter no of elements:");
    scanf("%d",&n);
    int a[n];
    printf("enter array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int low=0,high=n-1;
    mergesort(a,low,high);
    printf("sorted array:");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

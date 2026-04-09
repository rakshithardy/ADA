#include<stdio.h>
int a[10],low,high;

void merge(int a[],int low,int mid,int high){
    int i,j,k,c[10];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high){
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=high){
        c[k++]=a[i];
        i++;
    }
    while(j<=high){
        c[k++]=a[j];
        j++;
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
    int n;
    printf("enter number of array elements:\n");
    scanf("%d",&n);
    low=0;
    high=n-1;
    printf("enter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,low,high);
    printf("sorted array elements:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
    }

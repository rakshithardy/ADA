#include<stdio.h>
int partition(int a[],int low,int high){
   int i,j,pivot,temp;
   pivot=a[low];
   i=low+1;
   j=high;
   while(i<=j){
       while(i<=high&&a[i]<=pivot){
        i++;
       }
       while(j>low&&a[j]>=pivot){
        j--;
       }
       if(i<j){
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
       }
   }
   temp=a[low];
   a[low]=a[j];
   a[j]=temp;
   return j;
}
void quicksort(int a[],int low,int high){
int p;
if(low<high){
    p=partition(a,low,high);
    quicksort(a,low,p-1);
    quicksort(a,p+1,high);
}}
int main(){
int n;
printf("enter n:");
scanf("%d",&n);
int a[n];
int low=0,high=n-1;
printf("enter array elements:");
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
quicksort(a,low,high);
printf("sorted array:\n");
for(int i=0;i<n;i++){
    printf("%d ",a[i]);
}
return 0;
}


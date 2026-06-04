#include<stdio.h>
#include<stdlib.h>
int board[20];
int count = 0;
int place(int row,int column)
{
        int j;
    int flag=1;
    for(j=1;j<=row-1;j++)
    {
        if((board[j]==column) ||
           (abs(board[j]-column)==abs(j-row)))
        {
            flag=0;
        }
    }
    return flag;
}
void queens(int row,int n)
{
    int j;
    for(j=1;j<=n;j++)
    {
        if(place(row,j)==1)
        {
            board[row]=j;
            if(row==n)
            {
                print(n);
            }
            else
            {
                queens(row+1,n);
            }
        }
    }
}
void print(int n)
{
    int i,j;
    count++;
    printf("\nSolution %d\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(board[i]==j)
                printf("Q\t");
            else
                printf("-\t");
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter value of n : ");
    scanf("%d",&n);
    queens(1,n);
    if(count==0)
    {
        printf("No Solution\n");
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int ts=0;
void merge(char arr[],int lb,int mid,int ub);

void mergesort(char arr[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
void merge(char arr[],int lb,int mid,int ub)
{
    int lb1,ub1,i,c=0;
    lb1=lb;
    ub1=mid+1;
    i=lb;
    int b[100];
    while(lb1<=mid && ub1<=ub)
    {
        if(arr[lb1]<arr[ub1])
        {
             b[i]=arr[lb1];
            lb1++;i++;
        }
        else
        {
            b[i]=arr[ub1];
            ub1++;i++;
        } 
        c++;  
    }
    while(lb1<=mid)
        {
            b[i]=arr[lb1];
            lb1++;
            i++;
            c++;
        }
    while(ub1<=ub)
        {
            b[i]=arr[ub1];
            ub1++;
            i++;
            c++;
        }
    for(int i=lb;i<=ub;i++)
        arr[i]=b[i];
        ts+=c;
        printf("\nlb=%d,ub=%d,mid=%d,count=%d",lb,ub,mid,c);
}
int main()
{
    char arr[100],n=0;
    printf("enter the string");
    scanf("%s",arr);
    for(int i=0;arr[i]!='\0';i++)
        n++;
    int  lb=0;int ub=n-1;
    mergesort(arr,lb,ub);
    printf("\n The sorted list is \n");
    printf("%s",arr);
    printf("\ntotal no. of steps = %d",ts);
}

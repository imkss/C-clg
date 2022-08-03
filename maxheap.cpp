#include<stdio.h>
#include<stdlib.h>
void printarray(int a[] ,int n)
{
for(int i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
void swap(int *a ,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void maxheapify(int a[], int i, int m)
{
int largest=i;
int l=2*i+1;
int r=2*i+2;
if(l<m && a[l]>a[largest])
{
largest=l;
}
if(r<m && a[r]>a[largest])
{
largest=r;
}
if(largest!=i)
{
swap(&a[largest],&a[i]);

maxheapify(a,largest,m);
}
}
void buildmaxheap(int a[],int m)
{
for(int i=(m/2)-1;i>=0;i--)
{
maxheapify(a,i,m);
}
}
int main()
{
int arr[100],n;
printf("enter size to create array : \n");
scanf("%d",&n);
printf(" enter elements in array :\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("\n before heapify");
printarray(arr,n);
printf("\n after heapify ");

buildmaxheap(arr,n);
printarray(arr,n);
}

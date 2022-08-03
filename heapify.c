
/*#include<stdio.h>
void sort(int a[],int b[],int fre[],int n){
  for(int i=0;i<n;i++){
    b[fre[a[i]]-1] = a[i];
    fre[a[i]]--;
  }
}
int main(){
  int n;
  printf("enter size\n");
  scanf("%d",&n);
  int a[n],fre[11]={0};
  int b[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    fre[a[i]]++;
    b[i]=0;
  }
  for(int i=1;i<11;i++) fre[i] += fre[i-1];
  sort(a,b,fre,n);
  for(int i=0;i<n;i++){
    printf("%d",b[i]);
  }
}

#include<stdio.h>
int size=0;
void swap(int *a,int *b){
  int temp = *a;
  *a=*b;
  *b = temp;
}

void heapify(int a[],int size,int i){
  if(size == 0) printf("only one element\n");
  else{
    int lr =i;
    int l = i*2+1;
    int r = i*2+2;
    if(l<size&& a[l]>a[lr]) lr = l;
    if(r<size&& a[r]>a[lr]) lr = r;
    if(i!=lr){
      swap(&a[i],&a[lr]);
      heapify(a,size,lr);
    }
  }
}

void insert(int a[],int n){
  if(size==0){
    a[0] = n;
      size+=1;
  }else{
    a[size] = n;
    size+=1;
    for(int i=size/2-1;i>=0;i--) heapify(a,size,i);
  }
}

void delete(int a[],int d){
  int i;
  for(i=0;i<size;i++) if(d == a[i]) break;
  swap(&a[i],&a[size-1]);
  size-=1;
  for(int i=size/2-1;i>=0;i--) heapify(a,size,i);
}

void print(int a[],int s){
  for(int i=0;i<s;i++) printf("%d ",a[i]);
}
int main(){
  int a[10];
  int ele;
  printf("eneter elements ;\n");
  for(int i=0;i<4;i++){
    scanf("%d",&ele);
    insert(a,ele);
  }
  print(a,size);
  printf("\n");
  delete(a,3);
  print(a,size);
}
*/

#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {

        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest])
            largest = l;
        if (r < size && array[r] > array[largest])
            largest = r;

        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}

void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}

void deleteRoot(int array[], int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == array[i])
            break;
    }

    swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[10];
    int ele;
    printf("Enter 5 element\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Enter %dth element\n", i);
        scanf("%d", &ele);
        insert(array, ele);
    }

    printf("Max-Heap array: ");
    printArray(array, size);

    deleteRoot(array, 4);

    printf("After deleting an element: ");

    printArray(array, size);
}
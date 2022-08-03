#include <stdio.h>
int ss=0;
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size,int k) {
  for (int step = 0; step < size - 1; step++) {
      if(k==step){
    printf("Array unsorted till %d pass\n",k);
    printArray(array,size);
    }
     int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
        ss++;
    }
    swap(&array[min_idx], &array[step]);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int size;
  int data[50],k;
printf("Enter the size of array: ");
scanf("%d",&size);
printf("Elements in the array are : ");
for(int i=0;i<size;i++)
{
scanf("%d",&data[i]);
}
printf("Enter the value of k: ");
scanf("%d",&k);
  selectionSort(data, size,k);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
printf("No of step count: %d",ss);
printf("\n");
return 0;
}
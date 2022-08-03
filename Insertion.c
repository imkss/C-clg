#include <stdio.h>
int si=0;
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size,int k) {
  for (int step = 1; step < size; step++) {
    if(k==step){
    printf("Array unsorted till %d pass\n",k);
    printArray(array,size);
    }
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    si++;
    }
    array[j + 1] = key;
  }
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
  insertionSort(data, size,k);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
printf("No of step count: %d",si);
printf("\n");
return 0;
}
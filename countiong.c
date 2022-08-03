// #include <stdio.h>
// void countingSort(int a[],int freq[],int b[],int n){
//     for(int i=0;i<n;i++){
//         b[freq[a[i]]-1]=a[i];
//         freq[a[i]]--;
//     }
// }
// int main(){
//     int n;
//     printf("Enter the size of array: ");
//     scanf("%d",&n);
//     int a[n],freq[11]={0};
//     int b[n];
//     printf("Enter the elements:\n");
//     for(int i=0;i<n;i++){
//         printf("A[%d]: ",i);
//         scanf("%d",&a[i]);
//         freq[a[i]]++;
//         b[i]=0;
//     }
//     for(int i=1;i<11;i++){
//         freq[i]+=freq[i-1];
//     }
//     printf("The Unsorted Array:\n");
//     for(int i=0;i<n;i++){
//         printf("%d ",a[i]);
//     }
//     printf("\n");
//     countingSort(a,freq,b,n);
//     printf("The Sorted Array:\n");
//     for(int i=0;i<n;i++){
//         printf("%d ",b[i]);
//     }
//     printf("\n");

//     return 0;
// }

// Counting sort in C programming

#include <stdio.h>

void countingSort(int array[], int size) {
  int output[10];

  // Find the largest element of the array
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // The size of count must be at least (max+1) but
  // we cannot declare it as int count(max+1) in C as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int count[10];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);
  countingSort(array, n);
  printArray(array, n);
}
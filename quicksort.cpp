#include<stdio.h>
#include<stdlib.h>
void swap (int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low,int high) {
    int pivot = arr[low];
    int j = low + 1;
    for(int i = low + 1; i <= high; i++) {
        if(arr[i] < pivot) {
            if(i != j) { 
                swap(&arr[j], &arr[i]);
            }
            j++;
        }
    }
    arr[low] = arr[j - 1];
    arr[j - 1] = pivot;
    return j - 1;
}
int c = 0;
void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int p_index = partition(arr, low, high);
        quicksort(arr, low, p_index-1);
        quicksort(arr, p_index+1, high);
    }
    c++;
}

int main() {
    printf("Enter Size of Array : ");
    int n; scanf("%d", &n);
    printf("Enter Array Elements : ");
	int *arr = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
	quicksort(arr, 0, n - 1);
	printf("Sorted array : ");
	for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nCounter : %d",c);
	return 0;
}

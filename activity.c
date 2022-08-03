// Online C compiler to run C program online
#include <stdio.h>
void swap();
void sort(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
            }
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void printmax(int s[], int f[], int n, int ans[])
{
    int i = 0, j;
    int a = 1;
    ans[0] = 0;
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            ans[a++] = j;
            i = j;
        }
    }
    printarray(ans, a);
}
int main()
{
    int s[100], f[100], ans[100], n;
    printf("\n  Enter n \n");
    scanf("%d", &n);
    printf("\nEnter array s\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    printf("\nEnter array f\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
    }
    sort(f, s, n);
    printmax(s, f, n, ans);
}
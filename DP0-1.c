#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void sort(int arr1[], int arr2[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr1[i] > arr1[j])
            {
                swap(&arr1[i], &arr1[i]);
                swap(&arr2[i], &arr2[j]);
            }
        }
    }
}
void Knapsack(int w[], int p[], int n, int m)
{
    int rows = n + 1;
    int col = m + 1;
    int table[rows][col];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < col; j++)
        {
            table[i][j] = 0;
        }

    sort(w, p, n);
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (j >= w[i - 1])
            {
                table[i][j] = max((table[i - 1][j - w[i - 1]]) + p[i - 1], table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    rows -= 1;
    col -= 1;
    printf("Max Profit is %d -:", table[n][m]);

    printf("\n");
}
int main()
{
    int n, m, i;
    printf("Enter the numbe of items:");
    scanf("%d", &n);
    int w[n];
    int p[n];
    printf("Enter the bag capacity:");
    scanf("%d", &m);
    for (i = 0; i < n; i++)
    {

        printf("Enter the  %dth weigth\n", i + 1);

        scanf("%d", &w[i]);
        printf("Enter the %dthPrice\n ", i + 1);
        scanf("%d", &p[i]);
    }
    Knapsack(w, p, n, m);
}
#include <stdio.h>

void bubble()

{
    int count, temp, i, j, number[30];

    printf("How many numbers are u going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d numbers: ", count);

    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);
    for (i = count - 2; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (number[j] > number[j + 1])
            {
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }

    printf("Sorted elements: ");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);
}

void selection_sort()
{
    int i, j, count, temp, number[25];

    printf("How many numbers u are going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    // Loop to get the elements stored in array
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);

    // Logic of selection sort algorithm
    for (i = 0; i < count; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (number[i] > number[j])
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }

    printf("Sorted elements: ");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);
}

void insertation()
{
    int i, j, count, temp, number[25];

    printf("How many numbers u are going to enter?: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    // This loop would store the input numbers in array
    for (i = 0; i < count; i++)
        scanf("%d", &number[i]);

    // Implementation of insertion sort algorithm
    for (i = 1; i < count; i++)
    {
        temp = number[i];
        j = i - 1;
        while ((temp < number[j]) && (j >= 0))
        {
            number[j + 1] = number[j];
            j = j - 1;
        }
        number[j + 1] = temp;
    }

    printf("Order of Sorted elements: ");
    for (i = 0; i < count; i++)
        printf(" %d", number[i]);
}

int main()
{
    int h;
    do
    {
        printf("1.for bubble sorting\n2.for selection sorting\n3.for insertation\n4.exit\n");
        printf("enter your choice :");
        scanf("%d", &h);
        switch (h)
        {
        case 1:
            bubble();
            break;
        case 2:
            selection_sort();
            break;
        case 3:
            insertation();
            break;
        case 4:
            break;
        default:
            printf("\n ener a valid choice");
            break;
        }
    } while (h >= 4);

    return 0;
  }
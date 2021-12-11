#include <stdio.h>
#include <stdbool.h>

int arr[100], n, i, j, temp, ch;

void bubblesort();
void output();
void selectionsort();
void bubblesort2();

int main()
{

    printf("\nMain Menu");
    printf("\n1.Bubble Sort");
    printf("\n2.Selection Sort");
    printf("\n3.Bubble Sort 2");
    printf("\n4.Exit");
    do
    {

        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            input();
            bubblesort();
            output();
            break;
        case 2:
            input();
            selectionsort();
            output();
            break;
        case 3:
            input();
            bubblesort2();
            output();
            break;
        default:
            printf("Exit");
        }
    } while (ch != 4);
    return 0;
}

void input()
{
    printf("Enter the no. of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Elements: ");
        scanf("%d", &arr[i]);
    }
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d\n", arr[i]);
    }
}
void bubblesort()
{

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t;
                t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void selectionsort()
{

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubblesort2()
{
    bool swap = true;
    int j = 0;
    int tmp;
    while (swap)
    {
        swap = false;
        j++;
        for (i = 0; i < n - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swap = true;
            }
        }
    }
}
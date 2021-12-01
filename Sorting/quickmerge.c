#include <stdio.h>
#include <stdlib.h>
void arrdisplay(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void arrayinput(int a[], int *n)
{
    int i;
    printf("Enter the size of an array:");
    scanf("%d", &*n);
    printf("Enter the elements of an array:");
    for (i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void quicksort(int a[], int l, int h, int n)
{
    int partitionindex;
    if (l < h)
    {
        printf("iteration::");
        arrdisplay(a, n);
        printf("\n");
        partitionindex = partition(a, l, h);
        quicksort(a, l, partitionindex - 1, n);
        quicksort(a, partitionindex + 1, h, n);
    }
}
int partition(int a[], int l, int h)
{
    int i = l + 1, temp;
    int j = h;
    int pivot = a[l];
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}
void mergesort(int a[], int l, int h, int n)
{
    if (l < h)
    {
        printf("iteration::");
        arrdisplay(a, n);
        printf("\n");
        int m = (l + h) / 2;
        mergesort(a, l, m, n);
        mergesort(a, m + 1, h, n);
        merge(a, l, m, h);
    }
}

void merge(int a[], int l, int m, int h)
{
    int i = l, j = m + 1, k = l, b[h + 1];

    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= m)
    {
        b[k++] = a[i++];
    }
    while (j <= h)
    {
        b[k++] = a[j++];
    }
    for (i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int a[100], i, j, chc, n;
    char choice;
    do
    {
        printf("\n\n-----MENU-----\n");
        printf("1. Quick Sort\n2. Merge Sort");
        printf("\nEnter your choice: ");
        scanf("%d", &chc);

        switch (chc)
        {
        case 1:
            arrayinput(a, &n);
            quicksort(a, 0, n - 1, n);
            printf("After sorting:");
            arrdisplay(a, n);
            break;
        case 2:
            arrayinput(a, &n);
            mergesort(a, 0, n - 1, n);
            printf("After sorting:");
            arrdisplay(a, n);
            break;
        }
        printf("\nDo you want to continue?(Press y/n) y/n\n");
        scanf(" %c", &choice);
    } while (choice == 'y');
}
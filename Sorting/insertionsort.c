#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100], i = 1, n, j, temp, k, l, key;

    printf("Enter the total numbers of elements:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    //Insertion sort
    for (i = 1; i < n; i++)
    {
        key = a[i];
        // j=i-1;
        /* while(j>=0 && a[j]>key){
        a[j+1]=a[j];
        j--;
    }*/
        for (j = i - 1; j >= 0 && a[j] > key; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
    printf("Ascending order:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
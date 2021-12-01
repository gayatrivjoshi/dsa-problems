#include <stdio.h>
#define SIZE 10

int h[SIZE];

void insert()
{
    int k, index, i, flag = 0, hk;
    printf("\nEnter a value to be inserted : ");
    scanf("%d", &k);

    hk = k % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        index = (hk + i * i) % SIZE;

        if (h[index] == NULL)
        {
            h[index] = k;
            break;
        }
    }

    if (i == SIZE)
    {
        printf("\nElement cannot be inserted.");
    }
}

void search()
{
    int k, index, i, flag = 0, hk;
    printf("\nEnter the element to be Searched : ");
    scanf("%d", &k);

    hk = k % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        index = (hk + i * i) % SIZE;
        if (h[index] == k)
        {
            printf("Element at index %d", index);
            break;
        }
    }
    if (i == SIZE)
    {
        printf("\nNot Found.\n");
    }
}
void display()
{
    int i;

    printf("\nElements in the Hash Table are :\n");
    printf("\nIndex     Value ");
    for (i = 0; i < SIZE; i++)
    {
        printf("\n %d         %d", i, h[i]);
    }
}

int main()
{
    int choice, flag = 0;
    while (flag != 1)
    {
        printf("\n-----Menu-----\n 1.Insert \n 2.Display \n 3.Search \n 4.Exit \n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            flag = 1;
            break;
        }
    }
    return 0;
}

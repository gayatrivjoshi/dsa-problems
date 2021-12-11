// Double Hashing in C
#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

int arr[SIZE];

int insert(int num)
{

    int key, index, i, f1key, f2key;
    key = num;
    f1key = key % SIZE;
    f2key = 8 - (key % 8);
    if (arr[f1key] == NULL)
    {
        arr[f1key] = key;
        return;
    }
    for (i = 0; i < SIZE; i++)
    {
        index = (f1key + (i * f2key)) % SIZE;
        if (arr[index] == NULL)
        {
            arr[index] = key;
            return;
        }
    }
    if (i == SIZE)
        printf("\nTable is Full\n");
}

int search(int val)
{
    int index, f1key, f2key, i;
    f1key = val % SIZE;
    f2key = 8 - (val % 8);
    if (arr[f1key] == val)
    {
        printf("The Value is Found at INDEX : %d\n", f1key);
        return;
    }
    for (i = 0; i < SIZE; i++)
    {
        index = (f1key + (i * f2key)) % SIZE;
        if (arr[index] == val)
        {
            printf("The Value is Found at INDEX : %d\n", index);
            return;
        }
    }
    if (i == SIZE)
        printf("\nElement NOT Found\n");
}

int display()
{
    printf("Index   Element\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%3d\t   %d\n", i, arr[i]);
    }
}

int main()
{
    int opt, in, sn, a = 0;
    printf("Welcome to Double Hashing\n");
    do
    {
        printf("\nEnter Your Choice \n1) -> Insert \n2) -> Search \n3) -> Display \n4) -> Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the Element : ");
            scanf("%d", &in);
            insert(in);
            break;
        case 2:
            printf("\nEnter the Element you want to search : ");
            scanf("%d", &sn);
            search(sn);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nThank You");
            a = 1;
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    } while (a == 0);
    /*
    insert(4);
    insert(6);
    insert(36);
    insert(2);
    insert(14);
    insert(56);
    insert(24);
    insert(9);
    insert(26);
    insert(69);
    insert(42);
    insert(23);
    display();*/
}
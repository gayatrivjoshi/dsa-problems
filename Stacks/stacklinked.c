#include <stdio.h>
#include <stdlib.h>

typedef struct stacknode
{
    int data;
    struct stacknode *next;
} sn;

sn *push(sn *temp, int x)
{
    sn *new1 = (sn *)malloc(sizeof(sn));
    new1->data = x;
    new1->next = NULL;

    new1->next = temp;
    temp = new1;
    return temp;
}

void display(sn *temp)
{
    if (temp == NULL)
    {
        printf("Stack Underflow/ Empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

sn *pop(sn *temp)
{
    if (temp == NULL)
    {
        printf("Stack Underflow/ Empty\n");
        return NULL;
    }
    temp = temp->next;
    return temp;
}

int main()
{
    sn *top = NULL;
    while (1)
    {
        printf("Menu | press 1 for push | press 2 for pop | press 3 for display | press 4 for exit\n");
        int n;
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the value that you want to push\n");
            int val;
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            break;
        }
    }
}
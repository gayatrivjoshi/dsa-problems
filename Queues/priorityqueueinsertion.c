#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int priority;
    int data;
    struct node *next;
} pq;

pq *front = NULL;
pq *rear = NULL;
void insert(int val, int priority)
{
    pq *temp, *qu;
    temp = (pq *)malloc(sizeof(pq));
    temp->data = val;
    temp->priority = priority;

    if (front == NULL || priority < front->priority)
    {
        temp->next = front;
        front = temp;
    }
    else
    {
        qu = front;
        while (qu->next != NULL && qu->next->priority <= priority)
            qu = qu->next;
        temp->next = qu->next;
        qu->next = temp;
    }
}

void del()
{
    pq *temp;

    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        temp = front;
        printf("Deleted value from the queue is %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    pq *help_ptr;
    help_ptr = front;
    if (front == NULL)
        printf("Queue is empty!!!\n");
    else
    {
        printf("Queue is :\n");
        printf("Data       Priority\n");
        while (help_ptr != NULL)
        {
            printf("%2d        %5d\n", help_ptr->data, help_ptr->priority);
            help_ptr = help_ptr->next;
        }
    }
}

int main()
{
    int option, val, priority;
    int i = 0;
    printf("-----Priority Queue-----");
    while (i == 0)
    {

        printf("\nEnter your option : \n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            printf("Enter the priority of the value inserted : ");
            scanf("%d", &priority);
            insert(val, priority);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            i++;
            break;
        default:
            printf("Enter the correct option!\n");
        }
    }

    return 0;
}
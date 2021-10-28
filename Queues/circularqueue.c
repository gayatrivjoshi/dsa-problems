// Write a menu driven program of circular queue using arrays having menu with options enqueue , dequeue , display and exit.
#include <stdio.h>
#define size 5
typedef struct Queue
{
    int queue[size];
    int front;
    int rear;
} q;

void enqueue(q *q1)
{
    int new1;
    printf("\nEnter element\n");
    scanf("%d", &new1);
    if (q1->front == -1 && q1->rear == -1)
    {
        q1->queue[++q1->rear] = new1;
        q1->front = 0;
        return;
    }
    if ((q1->front == 0 && q1->rear == size - 1) || q1->front == q1->rear + 1)
        printf("Queue full\n");
    else
    {
        q1->rear = (q1->rear + 1) % size;
        q1->queue[q1->rear] = new1;
    }
    return;
}

void dequeue(q *q1)
{
    if (q1->rear == -1 && q1->front == -1)
    {
        printf("Queue empty");
        return;
    }
    printf("Element deleted = %d", q1->queue[q1->front]);
    q1->front = (q1->front + 1) % size;
    if (q1->front == (q1->rear + 1) % size)
    {
        q1->front = -1;
        q1->rear = -1;
    }
    return;
}

void display(q *q1)
{
    int temp;
    if (q1->front == -1 && q1->rear == -1)
    {
        printf("Queue empty");
        return;
    }
    temp = q1->front;
    while (temp != q1->rear)
    {
        printf("%d\n", q1->queue[temp]);
        temp = (temp + 1) % size;
    }
    printf("%d\n", q1->queue[q1->rear]);
    return;
}

void main()
{
    int choice;
    q q1;
    q1.front = -1;
    q1.rear = -1;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            enqueue(&q1);
            break;
        }
        case 2:
        {
            dequeue(&q1);
            break;
        }
        case 3:
        {
            display(&q1);
            break;
        }
        case 4:
            break;
        default:
            printf("Invalid choiceoice");
        }
    } while (choice != 4);
}
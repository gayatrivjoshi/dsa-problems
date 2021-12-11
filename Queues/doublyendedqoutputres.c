#include <stdio.h>
#include <stdbool.h>

typedef struct qnode
{
    int data;
    struct qnode *next;
} qn;
qn *front = NULL;
qn *rear = NULL;

void enqueuefront(int x)
{
    qn *new1 = (qn *)malloc(sizeof(qn));
    new1->data = x;
    new1->next = NULL;
    if (front == NULL)
    {
        front = new1;
        rear = new1;
        return;
    }
    new1->next = front;
    front = new1;
    return;
}

void enqueuerear(int x)
{
    qn *new1 = (qn *)malloc(sizeof(qn));
    new1->data = x;
    new1->next = NULL;
    if (front == NULL)
    {
        front = new1;
        rear = new1;
        return;
    }
    rear->next = new1;
    rear = new1;
    return;
}

void display()
{
    qn *i;
    if (front == NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("The queue is :\n");
    for (i = front; i != NULL; i = i->next)
    {
        printf("%d\n", i->data);
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    qn *temp;
    temp = front;
    printf("The deleted item is %d\n", front->data);
    front = front->next;
    free(temp);
    return;
}

int main(void)
{
    int in, b;
    bool run = true;
    do
    {
        printf("MAIN MENU\n");
        printf("1.EnqueueFront\n");
        printf("2.EnqueueRear\n");
        printf("3.Display\n");
        printf("4.Dequeue\n");
        printf("5.Exit\n");
        scanf("%d", &in);
        switch (in)
        {
        case 1:
            printf("Enter the number\n");
            scanf("%d", &b);
            enqueuefront(b);
            display();
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d", &b);
            enqueuerear(b);
            display();
            break;
        case 3:
            printf("The Queue is");
            display();
            printf("\n");
            break;
        case 4:
            dequeue();
            display();
            break;
        case 5:
            run = false;
            break;
        default:
            printf("Invalid choice !!!");
        }
    } while (run);
}
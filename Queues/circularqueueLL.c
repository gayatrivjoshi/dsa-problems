#include <stdio.h>
#include <stdlib.h>
typedef struct qnode
{
    int data;
    struct qnode *next;
} qn;
qn *front = NULL;
qn *rear = NULL;
void enqueue(int x)
{
    qn *new = (qn *)malloc(sizeof(qn));
    new->data = x;
    new->next = NULL;
    if (front == NULL)
    {
        front = new;
        rear = new;
        return;
    }
    rear->next = new;
    rear = new;
    return;
}
void display()
{
    qn *i;
    if (front == NULL)
    {
        printf("\n Queue empty");
        return;
    }
    printf("Queue: ");
    for (i = front; i != NULL; i = i->next)
    {
        printf(" %d", i->data);
    }
}
void dequeue()
{
    if (front == NULL)
    {
        printf("\n Queue empty");
        return;
    }
    qn *temp;
    temp = front;
    printf("\nDeleted element:%d", front->data);
    front = front->next;
    free(temp);
    return;
}
int main()
{
    printf("Queue Using Linked List\n");
    int x;
    int i = 0;
    while (i == 0)
    {
        int o;
        printf("\n\nEnter Choice:");
        printf("\n1. Enqueue \n2. Display \n3. Dequeue \n4. Exit \n");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            printf("Enter the number you want to insert:");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            display();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            i++;
            break;
        default:
            printf("\n Invalid Choice!\n");
        }
    }
}
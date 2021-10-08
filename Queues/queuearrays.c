// Write a menu driven program of queues using arrays having menu with options enqueue , dequeue , display and exit. 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 3
 
typedef struct Queue
{
    int arr[SIZE];
    int f;
    int r;
}queue;

void display(queue *q)
{
    if(isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("The queue is : \n");
    for(int i=q->f;i<=q->r;i++)
    {
        printf("%d\n", q->arr[i]);
    }
    
}
 
int isEmpty(queue *q){
    if(q->r== -1){
        return 1;
    }
    return 0;
}

int isFull(queue *q){
    if(q->r==SIZE-1){
        return 1;
    }
    return 0;
}
 
void enqueue(queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
        return;
    }
    if(q->f==-1)    // if Queue is empty
    {
        q->f++;
        q->r++;
        q->arr[q->f] = val;
        return;
    }
    q->r++;
    q->arr[q->r] = val;
}
 
void dequeue(queue *q){
    if(isEmpty(q)){
        printf("This Queue is empty\n");
        return;
    }
    printf("The deleted element from the array is: %d\n", q->arr[q->f]);
    if(q->f == q->r)   // if Queue is full
    {
        q->f = -1;
        q->r = -1;
        return;
    }
    q->f++;
}
 
int main(){
    queue q;
    q.f = q.r = -1;
    bool run = true;
    do
    {
        int in;
        int enq,deq;
        printf("----MENU----\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d",&in);
        switch(in)
        {
        case 1:
            printf("Enter number to enqueue: \n");
            scanf("%d",&enq);
            enqueue(&q,enq);
            display(&q);
            break;
        case 2:
            dequeue(&q);
            display(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            run = false;
            break;
        default:
            printf("Invalid Choice");
        }
    }while(run);
    return 0;
}

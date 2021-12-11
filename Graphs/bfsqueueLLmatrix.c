#include <stdio.h>
#include <stdlib.h>
#define size 10
int a[size][size];
int seen[size];
int vertex = 0;
typedef struct qnode
{
    int data;
    struct qnode *next;
} qn;
qn *front = NULL;
qn *rear = NULL;
void enqueue(int x)
{
    qn *temp = (qn *)malloc(sizeof(qn));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
    return;
}
int dequeue()
{
    qn *temp;
    if (rear == NULL)
    {
        printf("\n Queue Empty");
        return -1;
    }
    if (front == rear)
    {
        temp = front;
        front = NULL;
        rear = NULL;

        return temp->data;
    }
    temp = front;
    front = front->next;

    return temp->data;
}
int isEmpty(void)
{
    if (rear == NULL)
    {
        return -1;
    }
    return 0;
}
void bfs(int s)
{
    enqueue(s);
    while (isEmpty() != -1)
    {
        int dq = dequeue();
        if (seen[dq] == 0)
        {
            seen[dq] = 1;
            printf("%2d", dq);
        }

        int i = dq;
        for (int j = 0; j < vertex; j++)
        {
            if (seen[j] == 0)
            {
                enqueue(j);
            }
        }
    }
}
int main(void)
{
    int v = 0;
    int e = 0;
    printf("Enter the no of vertices\n");
    scanf("%d", &v);
    printf("Enter the no of edges\n");
    scanf("%d", &e);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            a[i][j] = 0;
        }
    }
    for (int j = 0; j < v; j++)
    {
        seen[j] = 0;
    }
    vertex = v;
    for (int i = e - 1; i >= 0; i--)
    {
        printf("Enter vertices of edges\n");
        int r;
        int c;
        scanf("%d%d", &r, &c);
        a[r][c] = 1;
        a[c][r] = 1;
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
    int s = 0;
    printf("Enter the source node:");
    scanf("%d", &s);
    bfs(s);
}
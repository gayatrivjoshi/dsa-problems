#include <stdio.h>
#include <stdlib.h>
int vis[10];
int queue[10];
int front = -1;
int rear = -1;

typedef struct BSFarr
{
    int vertex;
    struct BSFarr *next;
} bt;
bt *node;

void create(struct node *adj[], int v)
{

    bt *new, *last, *cp;
    int e, ele, nei, x, i;

    for (i = 0; i < v; i++)
    {
        last = NULL;
        printf("\nEnter the no of neighbours of %d ", i);
        scanf("%d", &nei);
        for (int j = 1; j <= nei; j++)
        {
            printf("Enter the %dst neighbour of %d ", j, i);
            scanf("%d", &x);
            new = (bt *)malloc(sizeof(bt));
            new->vertex = x;
            new->next = NULL;
            if (adj[i] == NULL)
            {
                adj[i] = new;
            }
            else
            {
                last->next = new;
            }
            last = new;
        }
    }
    return;
}
void bsf(int v, struct BSFarr *adj[])
{
    bt *hp;
    int p, x, s;
    printf("\nEnter the source node\n");
    scanf("%d", &s);
    enqueue(s);
    p = deque();
    printf("The Breath first search starting from node %d \n", p);
    hp = adj[p];
    vis[p] = 1;
    for (int i = 0; i < v; i++)
    {
        while (hp != NULL)
        {
            if (vis[hp->vertex] == 0)
            {
                enqueue(hp->vertex);
                vis[hp->vertex] = 1;
            }
            hp = hp->next;
        }
        if (front <= rear)
        {
            p = deque();
            hp = adj[p];
            printf("\t%d", p);
        }
    }
}
void enqueue(int new)
{
    if (front == -1)
    {
        front++;
        rear++;
    }
    rear++;
    queue[rear] = new;
    return;
}
int deque()
{
    int t;
    t = queue[front];
    front++;
    return t;
}
void display(struct BSfarr *adj[], int v)
{
    bt *hp;
    for (int i = 0; i < v; i++)
    {
        printf("\n");
        hp = adj[i];
        printf("%d\t", i);
        while (hp != NULL)
        {
            printf("\t%d", hp->vertex);
            hp = hp->next;
        }
    }
}

void main()
{
    bt *adj[10];
    int v, n;
    printf("\nEnter no of vertices\n");
    scanf("%d", &v);
    for (int i = 0; i <= v; i++)
    {
        adj[i] = NULL;
    }
    do
    {
        printf("\nEnter choice\n 1.Create a graph \n 2.Display \n 3.Breadth First Search \n 4.Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            create(adj, v);
            break;
        case 2:
            display(adj, v);
            break;
        case 3:
            bsf(v, adj);
            break;
        case 4:
            n = 5;
            break;
        default:
            printf("\nWrong Input\n");
        }
    } while (n > 0 && n <= 4);
}
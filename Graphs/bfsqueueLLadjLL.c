//BFS Queue Using Linked List (Adjacency List)

#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct bfs_queue
{
    int vertex;
    struct bfs_queue *next;
} bfs;

bfs *arr[size];
bfs *front = NULL;
bfs *rear = NULL;
int vis[size];

bfs *createGraph(bfs *root, int val);
int display(bfs *root);

int enqueue(int val)
{
    bfs *ptr = (bfs *)malloc(sizeof(bfs));
    ptr->vertex = val;
    ptr->next = NULL;
    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
        return;
    }
    rear->next = ptr;
    rear = ptr;
    return;
}

int dequeue()
{
    if (front == NULL)
    {
        return;
    }
    struct bfs *ptr;
    int t = front->vertex;
    ptr = front;
    front = front->next;
    free(ptr);
    return t;
}

bfs *createGraph(bfs *root, int val)
{
    bfs *ptr = (bfs *)malloc(sizeof(bfs));
    ptr->vertex = val;
    ptr->next = root;
    root = ptr;
    return root;
}

int BFS(int source, int v)
{
    int p, i, j;
    enqueue(source);
    vis[source] = 1;
    p = dequeue();
    if (p != 0)
        printf("%4d", p);
    while (p != 0)
    {
        for (i = 1; i <= v; i++)
        {
            if (arr[p] != NULL && vis[arr[p]->vertex] == 0)
            {
                enqueue(arr[p]->vertex);
                vis[arr[p]->vertex] = 1;
                arr[p] = arr[p]->next;
            }
        }
        p = dequeue();
        if (p != 0)
            printf("%4d", p);
    }
    for (j = 1; j <= v; j++)
        if (vis[j] == 0)
        {
            front--;
            BFS(j, v);
        }
}

int display(bfs *root)
{
    bfs *temp = root;
    while (temp != NULL)
    {
        printf(" -> %d", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ver, edge, i, j, k, n;
    printf("Enter the number of vertices : ");
    scanf("%d", &ver);
    printf("Enter the number of edges : ");
    scanf("%d", &edge);
    for (i = 1; i <= ver; i++)
    {
        arr[i] = NULL;
        vis[i] = 0;
    }
    for (i = 1; i <= edge; i++)
    {
        printf("\nEnter pair of vertex : ");
        printf("\nVertex 1 : ");
        scanf("%d", &j);
        printf("Vertex 2 : ");
        scanf("%d", &k);
        arr[j] = createGraph(arr[j], k);
        arr[k] = createGraph(arr[k], j);
    }
    printf("\n");
    for (i = 1; i <= ver; i++)
    {
        printf("%d", i);
        display(arr[i]);
    }
    printf("Enter the source node : ");
    scanf("%d", &n);
    BFS(n, ver);
}
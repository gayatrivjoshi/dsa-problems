#include <stdio.h>
#define size 10
int a[size][size];
int vis[size];
int queue[size];

int front = -1;
int rear = -1;

void enqueue(int new)
{
    queue[++rear] = new;
    return;
}

int dequeue()
{
    int t;
    t = queue[++front];
    queue[front] = 0;
    return t;
}

void bfs(int s, int n)
{
    int p, i, j;
    enqueue(s);
    vis[s] = 1;
    p = dequeue();
    if (p != 0)
        printf("%4d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if (a[p][i] != 0 && vis[i] == 0)
            {
                enqueue(i);
                vis[i] = 1;
            }
        p = dequeue();
        if (p != 0)
            printf("%4d", p);
    }
    for (j = 1; j <= n; j++)
        if (vis[j] == 0)
        {
            front--;
            bfs(j, n);
        }
}

void main()
{
    int v, e, i, j, k, l, n;
    printf("\nEnter no of vertices and edges: ");
    scanf("%d%d", &v, &e);
    for (i = 1; i <= v; i++)
        vis[i] = 0;
    for (i = 1; i <= v; i++)
        for (l = 1; l <= v; l++)
            a[i][l] = 0;
    for (i = 1; i <= e; i++)
    {
        printf("\nEnter pair of vertices\n");
        scanf("%d%d", &j, &k);
        a[j][k] = a[k][j] = 1;
    }
    for (i = 1; i <= v; i++)
    {
        for (l = 1; l <= v; l++)
            printf("%4d", a[i][l]);
        printf("\n");
    }
    printf("\nEnter the source node: ");
    scanf("%d", &n);
    bfs(n, v);
    printf("\n");
}
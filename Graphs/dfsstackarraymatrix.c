#include <stdio.h>
#define size 10
int a[size][size];
int vis[size];
int stack[size];
int top = 0;

void push(int num)
{
    top++;
    stack[top] = num;
}

int pop()
{
    int t;
    t = stack[top];
    top--;
    return t;
}

void dfs(int s, int n)
{
    int p = stack[top], i, j;
    push(s);
    vis[s] = 1;
    p = pop();
    if (p != 0)
        printf("%4d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if (a[p][i] != 0 && vis[i] == 0)
            {
                push(i);
                vis[i] = 1;
            }
        p = pop();
        if (p != 0)
            printf("%4d", p);
    }
    for (j = 1; j <= n; j++)
        if (vis[j] == 0)
        {
            top--;
            dfs(j, n);
        }
}

void main()
{
    int v, e, i, j, k, l, n;
    printf("Enter no of vertices and edges: \n");
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
    dfs(n, v);
    printf("\n");
}
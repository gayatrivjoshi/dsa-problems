// Write a program of depth first search , stack using linked list and using adjaceny matrix in graphs

#include <stdio.h>
#include <stdlib.h>
#define size 10
int a[size][size];
int vis[size];

typedef struct stacknode
{
    int data;
    struct stacknode *next;
} sn;

void push(int new, sn ***top)
{
    sn *new1 = (sn *)malloc(sizeof(sn));
    new1->data = new;
    new1->next = **top;
    **top = new1;
    return;
}

int pop(sn ***top)
{
    if (**top == NULL)
    {
        return 0;
    }
    int t = (**top)->data;
    **top = (**top)->next;
    return t;
}

void dfs(int s, int n, sn **top)
{
    int p, i, j;
    push(s, &top);
    vis[s] = 1;
    p = pop(&top);
    if (p != 0)
        printf("%4d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if (a[p][i] != 0 && vis[i] == 0)
            {
                push(i, &top);
                vis[i] = 1;
            }
        p = pop(&top);
        if (p != 0)
            printf("%4d", p);
    }
    for (j = 1; j <= n; j++)
        if (vis[j] == 0)
        {
            //top--;
            *top = (*top)->next;
            dfs(j, n, &*top);
        }
}

void main()
{
    int v, e, i, j, k, l, n;
    sn *top = NULL;
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
    dfs(n, v, &top);
    printf("\n");
}

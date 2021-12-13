#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *top = NULL;
int n, visited[20];
struct node *G[20];

void push(int x)
{
    stack *new1 = (stack *)malloc(sizeof(stack));
    new1->data = x;
    new1->next = top;
    top = new1;
    return;
}
void pop()
{
    stack *ntbd;

    if (top == NULL)
    {
        printf("Stack is underflow");
        return top;
    }

    ntbd = top;
    top = top->next;
    free(ntbd);
}
void dfs(int i)
{
    struct node *p;
    printf("\n%d", i);

    p = G[i];
    visited[i] = 1;

    while (p != NULL)
    {
        i = p->vertex;
        if (!visited[i])
        {
            dfs(i);
        }
        p = p->next;
    }
}

void readgraph()
{
    int i, vi, vj, no_edges;

    printf("\nEnter number of Vertices : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        G[i] = NULL;
    }

    printf("\nEnter number of edges:");
    scanf("%d", &no_edges);

    for (i = 0; i < no_edges; i++)
    {
        printf("\nEnter and edge(u,v): ");
        scanf("%d%d", &vi, &vj);
        insert(vi, vj);
        insert(vj, vi);
    }
}
insert(int vi, int vj)
{
    struct node *p;
    struct node *q = (struct node *)malloc(sizeof(struct node));

    q->vertex = vj;
    q->next = NULL;

    if (G[vi] == NULL)
    {
        G[vi] = q;
    }
    else
    {
        p = G[vi];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
}

int main()
{
    int i, nodeee;
    readgraph();

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the value of Source Node : ");
    scanf("%d", &nodeee);
    dfs(nodeee);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int verNum;
    struct node *next;
} node;
void addNode(int s, int d, node *adjlist[])
{
    struct node *temp;
    struct node *src = (struct node*)malloc(sizeof(struct node));
    src->verNum = d;
    src->next = NULL;
    if (adjlist[s] == NULL)
    {
        adjlist[s] = src;
        return;
    }
    temp = adjlist[s];
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = src;
    return;
}
void printlist(int nodes, node *adjlist[])
{
    int i;
    for (i = 1; i <= nodes; ++i)
    {
        node *p = adjlist[i];
        printf("\nAdjacency list for vertex %d: ", i);
        while (p)
        {
            printf(" -> %d ", p->verNum);
            p = p->next;
        }
        printf("\n");
    }
}
void main()
{
    int i;
    int srce, desti, nodess, edges;
    printf("Enter no of nodes:");
    scanf("%d", &nodess);
    printf("Enter no of edges:");
    scanf("%d", &edges);
    node *adjlist[nodess];
    for (i = 1; i <= nodess; i++)
    {
        adjlist[i] = NULL;
    }
    for (i = 1; i <= edges; i++)
    {
        printf("Enter The source: ");
        scanf("%d", &srce);
        printf("Enter The destination: ");
        scanf("%d", &desti);
        addNode(srce, desti, adjlist);
        addNode(desti, srce, adjlist);
    }
    printlist(nodess, adjlist);
    return;
}
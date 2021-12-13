//code to add and display in a circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void add(struct node **first, int val)
{
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    struct node *temp = *first;
    if (temp == NULL)
    {
        *first = nn;
        nn->next = nn;
    }
    else
    {
        while (temp != *first)
        {
            temp = temp->next;
        }
        *first = nn;
        nn->next = temp->next;
        temp->next = nn;
    }
}

void display(struct node *first)
{
    struct node *temp = first->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != first->next);
}

int main()
{
    struct node *head = NULL;
    add(&head, 10);
    add(&head, 30);
    add(&head, 20);
    display(head);

    return 0;
}
//double linked list
//addition at the end and display
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
};

void add(struct node **first, int val)
{
    struct node *temp = *first;
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    nn->prev = NULL;
    if (temp == NULL)
    {
        *first = nn;
    }
    else
    {
        //temp variable will be used
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        //adding a new node at the end
        temp->next = nn;
        nn->prev = temp;
    }
}

//prints linked list in the reverse direction
void reverse(struct node *first)
{
    struct node *temp = first;
    //traversed till one before the end
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

void display(struct node *first)
{
    struct node *temp = first;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delete (struct node **first, int val)
{
    struct node *temp = *first;
    while (temp != NULL)
    {
        if (temp->data == val)
            break;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("Not Found !");
    else if (temp == *first)
    {
        *first = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
    else if (temp->next == NULL)
    {
        temp->prev = NULL;
        free(temp);
    }
    else if (temp->prev != NULL && temp->next != NULL)
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
    else
        *first = NULL;
}

int main()
{
    struct node *head = NULL;
    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    display(head);
    printf("\n");
    reverse(head);
    printf("\n");
    delete (&head, 40);
    delete (&head, 30);
    delete (&head, 20);
    delete (&head, 10);
    display(head);
    return 0;
}
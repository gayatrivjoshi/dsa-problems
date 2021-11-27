#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
  int data;
  struct qnode *next;
} qn;
qn *front = NULL;
qn *rear = NULL;
int
main ()
{
  int choice, x;
  while (1)
    {
      printf ("\n1.To Enqueue\n");
      printf ("2.To Dequeue\n");
      printf ("3.Display Elements\n");
      printf ("4.Quit\n");
      printf ("\nEnter your choice : ");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1:
	  printf ("\nEnter the element for enqueue : ");
	  scanf ("%d", &x);
	  enqueue (x);
	  break;
	case 2:
	  printf ("\nDeleted element from QUEUE is %d\n", dequeue ());
	  break;
	case 3:
	  display ();
	  break;
	case 4:
	  exit (1);
	default:
	  printf ("\nWrong choice\n");
	}
    }
}

void
enqueue (int x)
{
  qn *new1 = (qn *) malloc (sizeof (qn));
  new1->data = x;
  new1->next = NULL;
  if (front == NULL)
    {
      front = new1;
      rear = new1;
      return;
    }
  rear->next = new1;
  rear = new1;
  return;
}

void
display ()
{
  qn *i;
  if (front == NULL)
    {
      printf ("\n Queue Is Empty");
      return;
    }
  for (i = front; i != NULL; i = i->next)
    {
      printf ("\n %d", i->data);
    }
}

void
dequeue ()
{
  if (rear == NULL)
    {
      printf ("\n Queue Is Empty");
      return;
    }
  qn *temp;
  temp = front;
  printf ("\n The deleted item from QUEUE is %d", front->data);
  front = front->next;
  free (temp);
  return;
}

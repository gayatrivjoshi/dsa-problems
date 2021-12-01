#include <stdio.h>
#include <stdbool.h>

int size = 5;
int top = -1;
int arr[50];
int n;
bool run = true;

int main()
{
    do
    {
        int in, num;
        printf("Enter option number\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        scanf("%d", &in);
        switch (in)
        {
        case 1:
            printf("Enter number to push\n");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            run = false;
            break;
        default:
            printf("Invalid choice");
        }
    } while (run);
}

void display()
{
    if (top == -1)
    {
        printf("Nothing to display\n");
        return;
    }
    else
    {
        printf("The stack is: \n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", arr[i]);
        }
        return;
    }
}

void push(int n)
{
    if (top == size - 1)
    {
        printf("OverFlow\n");
        return;
    }
    else
    {
        top++;
        arr[top] = n;
        return;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Nothing to show\n");
        return;
    }
    else
    {
        printf("Element on the top is : %d\n", arr[top]);
        return;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("UnderFlow\n");
        return;
    }
    else
    {
        int a = arr[top];
        top--;
        printf("The deleted element was: %d\n", a);
        return;
    }
}
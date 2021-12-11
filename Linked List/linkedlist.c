#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lnode
{
    int roll;
    int pin;
    char name[50];
    char sex;
    int marks[6];
    int tmarks;
    double percentage;
    struct lnode *next;
};
struct lnode *head = NULL;

int in;
bool run = true;

int main()
{
    do
    {
        printf("MAIN MENU\n");
        printf("1.Search");
        printf("2.Delete");
        printf("3.Add");
        printf("4.Update");
        printf("5.Display");
        printf("6.Exit");
        scanf("%d", &in);
        int sum;
        char name[100];
        int delrol, searol, uprol;
        char sex;

        switch (in)
        {
        case 1:
            printf("Enter the roll no. you want to search:");
            scanf("%d", &searol);
            search(searol);
            break;
        case 2:
            printf("Enter the roll no. you want to delete:");
            scanf("%d", &delrol);
            delete (delrol);
            break;
        case 3:
            printf("Enter name: \n");
            scanf("%s", &name);

            int rollNo;
            printf("Enter rollNo: \n");
            scanf("%d", &rollNo);

            int pincode;
            printf("Enter pin: \n");
            scanf("%d", &pincode);

            printf("Enter sex: \n");
            scanf("%s", &sex);

            printf("Enter the marks out of 100:\n");
            int marks[6];
            for (int i = 0; i < 6; i++)
            {
                printf("marks for sub %i : \n", i + 1);
                scanf("%d", &marks[i]);
            }
            insert(name, rollNo, sex, pincode, marks);
            display();
            break;
        case 4:
            printf("Enter the roll no. you want to update:");
            scanf("%d", &uprol);
            update(uprol);
            break;
        case 5:
            display();
            break;
        case 6:
            run = false;
            break;
        default:
            printf("ERROR!!\n");
        }
    } while (run);

    return 0;
}

void display()
{
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    struct lnode *temp;
    temp = head;
    printf("Roll no.     Name     Sex     PinCode     Total marks     Percentage\n");
    while (temp != NULL)
    {
        printf("%d           %s       %c      %d          %d              %lf\n", temp->roll, temp->name, temp->sex, temp->pin, temp->tmarks, temp->percentage);
        temp = temp->next;
    }
}

void insert(char name[], int rollNo, char sex, int pincode, int marks[])
{

    struct lnode *new = malloc(sizeof(struct lnode));
    struct lnode *temp = head;

    strcpy(new->name, name);
    new->roll = rollNo;
    new->sex = sex;
    new->pin = pincode;
    int sum;

    for (int i = 0; i < 6; i++)
    {
        new->marks[i] = marks[i];
        sum = sum + marks[i];
    }

    double per = (sum / 6.0);

    new->percentage = per;
    new->tmarks = sum;
    new->next = NULL;

    if (head == NULL)
    {

        head = new;
        return;
    }
    if (new->roll < head->roll)
    {
        new->next = head;
        head = new;
        return;
    }

    temp = head;
    while (temp->next != NULL && temp->next->roll < rollNo)
    {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    return;
}

void delete (int n)
{
    struct lnode *temp, *ntbd;
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    if (head->roll == n)
    {
        ntbd = head;
        head = head->next;
        free(ntbd);
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->roll == n)
        {
            ntbd = temp->next;
            temp->next = ntbd->next;
            free(ntbd);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void search(int n)
{
    struct lnode *temp;
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    if (head->roll == n)
    {
        printf("Record Found !!!\n");
        printf("Roll no.     Name     Sex     PinCode     Total marks     Percentage\n");
        printf("%d           %s       %c      %d          %d              %lf\n", head->roll, head->name, head->sex, head->pin, head->tmarks, head->percentage);
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->roll == n)
        {
            printf("Record Found !!!\n");
            printf("Roll no.     Name     Sex     PinCode     Total marks     Percentage\n");
            printf("%d           %s       %c      %d          %d              %lf\n", temp->next->roll, temp->next->name, temp->next->sex,
                   temp->next->pin, temp->next->tmarks, temp->next->percentage);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found\n");
    return head;
}

void update(int n)
{
    struct lnode *temp, *ntbd;
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    if (head->roll == n)
    {
        printf("Record Found!!!\n");
        char upName[50];
        int upNum;
        int upPin;
        char upGen;
        printf("Enter the field that you want to update : \n");
        printf("1.Name\n");
        printf("2.Pin\n");
        printf("3.Sex\n");
        printf("4.Marks\n");
        scanf("%d", &upNum);

        switch (upNum)
        {
        case 1:
            printf("Enter updated Name :\n");
            scanf("%s", &upName);
            strcpy(head->name, upName);
            printf("UPDATED !!!\n");
            break;
        case 2:
            printf("Enter updated Pin:\n");
            scanf("%d", &upPin);
            head->pin = upPin;
            printf("UPDATED !!!\n");
            break;
        case 3:
            printf("Enter updated Sex :\n");
            scanf("%s", &upGen);
            head->sex = upGen;
            printf("UPDATED !!!\n");
            break;
        case 4:
            printf("Enter updated Marks :\n");
            int upMarks[6];
            int sum;
            for (int i = 0; i < 6; i++)
            {
                printf("marks for sub %i : \n", i + 1);
                scanf("%d", &upMarks[i]);
                head->marks[i] = upMarks[i];
                sum = sum + upMarks[i];
            }
            double per = (sum / 6.0);
            head->percentage = per;
            head->tmarks = sum;
            printf("UPDATED !!!\n");
            break;
        default:
            printf("Invalid choice");
        }
        printf("Roll no.     Name     Sex     PinCode     Total marks     Percentage\n");
        printf("%d           %s       %c      %d          %d              %lf\n", head->roll, head->name, head->sex, head->pin, head->tmarks, head->percentage);
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->roll == n)
        {
            printf("Record Found!!!\n");
            char upName[50];
            int upNum;
            int upPin;
            char upGen;
            printf("Enter the field that you want to update : \n");
            printf("1.Name\n");
            printf("2.Pin\n");
            printf("3.Sex\n");
            printf("4.Marks\n");
            scanf("%d", &upNum);

            switch (upNum)
            {
            case 1:
                printf("Enter updated Name :\n");
                scanf("%s", &upName);
                strcpy(temp->next->name, upName);
                printf("UPDATED !!!\n");
                break;
            case 2:
                printf("Enter updated Pin:\n");
                scanf("%d", &upPin);
                temp->next->pin = upPin;
                printf("UPDATED !!!\n");
                break;
            case 3:
                printf("Enter updated Sex :\n");
                scanf("%s", &upGen);
                temp->next->sex = upGen;
                printf("UPDATED !!!\n");
                break;
            case 4:
                printf("Enter updated Marks :\n");
                int upMarks[6];
                int sum;
                for (int i = 0; i < 6; i++)
                {
                    printf("marks for sub %i : \n", i + 1);
                    scanf("%d", &upMarks[i]);
                    temp->next->marks[i] = upMarks[i];
                    sum = sum + upMarks[i];
                }
                double per = (sum / 6.0);
                temp->next->percentage = per;
                temp->next->tmarks = sum;
                printf("UPDATED !!!\n");
                break;
            default:
                printf("Invalid choice");
            }

            printf("Roll no.     Name     Sex     PinCode     Total marks     Percentage\n");
            printf("%d           %s       %c      %d          %d              %lf\n", temp->next->roll, temp->next->name, temp->next->sex,
                   temp->next->pin, temp->next->tmarks, temp->next->percentage);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found...");
    return head;
}
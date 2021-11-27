#include <stdio.h>
#include<stdlib.h>
#define SIZE 3
int h[SIZE];
void init()
{
    int i;
    for(i=0;i<SIZE;i++)
        h[i]=0;
}

void insert()
{

 int key,index,i,hkey;
 printf("\n Enter a value to be inserted :\n");
 scanf("%d",&key);
 hkey=key%SIZE;
 for(i=0;i<SIZE;i++)
    {

     index=(hkey+i)%SIZE;

     if(h[index] ==0)
     {
        h[index]=key;
         break;
     }

    }

    if(i == SIZE)

     printf("\nElement cannot be inserted\n");
}
void search()
{

 int key,index,i,hkey;
 printf("\nEnter search element\n");
 scanf("%d",&key);
 hkey=key%SIZE;
 for(i=0;i<SIZE; i++)
 {
    index=(hkey+i)%SIZE;
    if(h[index]==key)
    {
      printf("Value is found at index %d",index);
      break;
    }
  }
  if(i == SIZE)
    printf("\n Value does not exsists\n");
}
void display()
{

  int i;

  printf("\nElements in the hash table are \n");

  for(i=0;i< SIZE; i++)

  printf("\nAt index %d \t value =  %d",i,h[i]);

}
int main()
{
    void init();

    int choice,i;
    while(choice!=4)
    {
        printf("\nPress \n 1. Insert\n 2. Display \n 3. Search \n 4.Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:choice=4;
            break;
            default:
                printf("\nInvalid Choice!!!\n");
        }
    }
}

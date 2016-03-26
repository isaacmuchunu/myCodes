#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *link;
};
struct node *first=NULL, *last=NULL;
void create();
void insert();
void display();
void delete();
void main()
{
 int ch;
 while (1)
 {
  printf("\n......MAIN MENU.....");
  printf("\n1.create\n2.insert\n3.delete\n4.display\n5.Exit\n");
  printf("Enter choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: create();
           break;
   case 2: insert();
	   break;
   case 3: delete();
           break;
   case 4: display();
           break;
   case 5: exit(0);
	   break;
   default: printf("invalid input");
  }
 }
}
void create()
{
 struct node *new;
 new=(struct node *)malloc(sizeof(struct node));
 printf("Enter data into node:");
 scanf("%d",&new->data);
 if(first==NULL)
 {
  first=new;
 }
 else
 {
  last->link=new;
 }
 last=new;
}
void insert()
{
 struct node *prev ,*curr;
 int count=1,pos;
 struct node *new;
 new = (struct node *)malloc(sizeof(struct node));
 printf("Enter the data: ");
 scanf("%d",&new->data);
 new->link=NULL;
 prev=NULL;
 curr=first;
 printf("Enter the position :");
 scanf("%d",&pos);
 while(count!=pos)
 {
  prev=curr;
  curr=curr->link;
  count++;
 }
 if(count==pos)
  {
   prev->link=new;
   new->link=curr;
  }
 else
  {
   printf("INSERTION IMPOSSIBLE");
  }
}
void delete()
{
 struct node *prev ,*curr;
 int count=1,pos;
 prev=NULL;
 curr=first;
 printf("Enterthe position:");
 scanf("%d",&pos);
 while(count!=pos)
 {
  prev=curr;
  curr=curr->link;
  count++;
 }
 if (count==pos)
 {
  printf("......deleted:%d ", curr->data);
  prev->link=curr->link;
 }
 else
 {
  printf("DELETION NOT POSSIBLE");
 }
}
void display()
{
 struct node *temp=first;
 if(first==NULL)
 {
  printf("EMPTY LIST");
 }
 else
 {
 while(temp!=NULL)
  {
   printf("%d->",temp->data);
   temp=temp->link; 
  }
 }
}


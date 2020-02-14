#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;

};

 struct node *start=NULL;
 struct node* createNode()
 {
    struct node *newNOde;
    newNode=(struct node*)malloc(sizeof(struct node));
    return (newNOde);
 }
 int getdata(int data,int loc)
 {
     printf("\nEnter a number:");
     scanf("%d",&data);
     return data;
 }
 int getLoc()
 {
     int loc;
     printf("\nEnter the Location where you want insert:");
     scanf("%d",&loc);
     return loc;
 }
 void traverse(getLoc())
 {
     struct node *trv
     trv=start;
     while(trv!=NULL)
        {
            trv=trv->link;
            if(trv==loc)
                break;
        }
 }
 void insertNode()
 {
     struct node* temp;
     temp=createNode();
     getdata(&temp->info);
     temp->link=NULL;
     if(start==NULL)
       {
          printf("You insert Data at first time!\n");
          start=temp;
       }
     else
     {
         traverse();
         trv->link=temp;

     }
 }


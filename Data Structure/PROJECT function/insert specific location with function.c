#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	int info ;
	struct Node *next;
}node;
void createNode(node**,int);
void insertAtloc(node **,int,int,int *i);
void display(node *);

void main()
{
	int ch, item, pos,loc,i;
	node *start ;
	start = NULL;
	printf("Enter number of node: ");
	scanf("%d",&i);
	createNode(&start,i);
	//createNode(node **start,int i)
	printf("\nThe list is : ");
	display(start);
	lebel:
	printf("\n\nEnter the inserting Item Location : ");
	scanf("%d",&loc);
	printf("\n\nEnter the item to be inserted : ");
    scanf("%d",&item);
    insertAtloc(&start,item,loc,&i);


    //insertAtloc(node **start,int item , int i,int k )


        /*else if(loc<1)
        {
            printf("error: Please enter a valid positive integer!");
            goto lebel;
        }*/
        /*else
        {

            printf("\n\nEnter the item to be inserted : ");
            scanf("%d",&item);
            insertAtloc(&start,item,loc,&i);
        }*/

	printf("\nyour first node was: %d\n",i);
	printf("\nNow the list is : ");
	display(start);
	goto lebel;
	getch();
}
void createNode(node **start,int i)
{

    int item ,k=1;
	while(i)
	{ node *ptr,*last;
	printf("\nEnter the value for node %d : ",k);
	scanf("%d",&item);
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(*start==NULL)
	{
		*start = ptr ;
	}
	else
	{	last = *start;
		while(last->next != NULL)
		{
		    last=last->next;
		}
		last->next = ptr ;
	}
	i--;
	k++;
	}
}
//insertAtloc(&start,item,loc,i);
void insertAtloc(node **start,int item , int L,int *i )
{
	node *ptr,*loc,*last;
	int n= *i;
	lebel:
	if(n==-5)
    {
        printf("\n\nEnter the inserting Item Location : ");
        scanf("%d",&L);
        printf("\n\nEnter the item to be inserted : ");
        scanf("%d",&item);
        n=*i;
    }

	if(n+1<L || L<1)
        {
            printf("\nerror: the node have not exist!\nplease try again!\n");
            n=-5;
            //exit(1);
            goto lebel;
        }


	n=1 ;
	L=L-1;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	loc = *start ;
	if(*start==NULL)
	{
		ptr->next = NULL ;
        *start = ptr ;
	}
	else if(L==0)
    {
        ptr->next=*start;
        *start=ptr;
    }
	//insert mid or last node
	else if(L<=i)
	{   while(n != L)
		{
			loc=loc->next;
			n++;
		}
		ptr->next = loc->next ;
		loc->next = ptr ;
	}
	//insert last node
	else
	{
	    printf("error: Please! insert a valid number.");

		/*last = *start;
		while(last->next != NULL)
		{
		    last=last->next;
		}
		last->next = ptr ;*/
	}
	i++;
	n= *i;
}

void display(node *start)
{
    int i=0;
     while(start !=NULL)
     { printf("\t %d",start->info);
       start = start->next;
       i++;
     }
    printf("\nNow your total node is: %d\n",i);
}



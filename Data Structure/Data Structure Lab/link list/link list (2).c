#include<stdio.h>
#include<stdlib.h>
struct LinkedList
{ int data;
struct LinkedList * next;
};
typedef struct LinkedList node;
// declarations of function prototypes
void AddFront(node **front, node *newnode);
int DeleteElm( node **front, int data);
int GetData();
int GetChoice();
void DisplayList(node *front);

int main()
{
   node* front = NULL;

   node *newnode;
   int data,pos;
  while(1)
  { switch(GetChoice())
   {
    case 1:

    {
     data=GetData();
     newnode=( node*) malloc(sizeof(node));
     newnode->data=data;
     newnode->next=NULL;
     AddFront(&front,newnode); //&front is a pointer to pointer
     DisplayList(front); // front is a pointer to list
     break;
    }


    case 2:
   {
        data=GetData();
    if(DeleteElm(&front,data)==0)
     printf("no element whose value is %d\n ", data);
   else
   {
    printf(" the Linked List after deletion is....\n");
    DisplayList(front); // display the list
   }
   break;
  }

    case 4:

     { DisplayList(front); // display the list
      break;
     }


   case 5: exit(0);
  } // end of switch
 } // end of while
}// end of main
//* AddFront adds node pointed by new node in thebegining


void AddFront (node **front, node *newnode)

{
    // make new node as first node. // next to point to * front
    node * cur;
	cur = front ; // cur is the node for traversal

    while (cur->next!=NULL)
		{
			cur = cur->next ; // go to next node
		}

    cur->next =newnode;//*front ;
     // ref 2. Now you made newnode to be known as * front.
}
/* deletes at pos. first element is 0. fn returns 0 if no element at given pos*/



int DeleteElm( node **front, int data)

{
    node *cur,* prev;
    // traverse to find required node
    cur=*front;
    while(cur&& cur->data!=data)
    {
        prev=cur; // save cur in prev
        cur=cur->next;
    }
    // if the element is found
    if (cur)
        { // if its first element
        if(cur==*front)
        *front=(*front)->next;
        else
            prev->next=cur->next;
        free(cur);
        return 1;
    }
    else
    return 0;
}// end of DeleteElm

int GetChoice ( )
{
    int choice ;
    do
    {
        printf("\n1 Insert at beginning of the Linked List \n");

        printf ("2 Delete an element of given data \n");
        printf ("3 Display the Linked List \n");
        printf ("4 Erase the Linked List \n");
        printf ("5 Quit \n");
        printf ("\n Enter your choice.. : ");

        scanf("%d", &choice);
    }
     while(choice <1 || choice >6); // continue loop
    return (choice);
}//end of GetChoice()

int GetData ( )
{
	 int data;
   	printf("\n Enter data for the node : ");

	scanf( "%d", & data);
	return data;
}//end of GetData( )


void DisplayList (node *front)
{    node * cur;
	cur = front ; // cur is the node for traversal
	if (cur==NULL)
	printf("\n the list is empty \n ");
	else
	{
		printf("\n the list is......\n");
		while (cur!=NULL)
		{
			printf ("%d", cur->data);
			if (cur->next!=NULL) ;// next node exists
			printf(" -> ");
			cur = cur->next ; // go to next node
		}
	}

} // end of DisplayList( )




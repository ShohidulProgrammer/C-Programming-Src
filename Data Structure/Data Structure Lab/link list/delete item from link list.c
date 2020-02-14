
typedef struct Node
{
	int info ;
	struct Node *next;
}node;
void createNode(node**,int);
int deleteSpecificItem(node** start, int);

void main()
{
	int ch, item, pos,loc,i;
	node *start ;
	//start = NULL;
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
    deleteSpecificItem(node** start,item);
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


int deleteSpecificItem(node** start, int item)
{
    if (!start || !(*start)) return -1;

    node* tmp = *start;
    node* prev = NULL;

    while (tmp->next != item && tmp->next != NULL)
    {
        prev = tmp;
        temp = temp->next;
    }

    if (tmp->info == item)
    {
        if (prev)
        {
            prev->next = tmp->next;
        }
        else
        {
            *start = tmp->next;
        }
        free(tmp);
        return item;
    }

    return -1;
}

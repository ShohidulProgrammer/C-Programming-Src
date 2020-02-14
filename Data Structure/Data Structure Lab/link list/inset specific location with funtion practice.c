#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int info ;
	struct Node *next;
}node;
void createNode(node**,int);
void insertAtloc(node **,int,int,int *i);
int deleteSpecificItem(node **,int);
void display(node *);
void main(){
	int ch, item, pos,loc,i;
	char choice;
	node *start ;
	start = NULL;
	printf("Enter number of node: ");
	scanf("%d",&i);
	createNode(&start,i); //or createNode(node **start,int i)
	lebel:
	display(start);
	    printf("\n\nEnter your choice:\n[1] for insert\n[2] for delete\n ");
	    fflush(stdin);
	    fflush(stdout);
	    scanf("%c",&choice);
	    switch(choice){
	        case '1' :  printf("\n\nEnter the inserting Item Location : ");
                        scanf("%d",&loc);
                        printf("\n\nEnter the item to be inserted : ");
                        scanf("%d",&item);
                        insertAtloc(&start,item,loc,&i);
                        break;
            case '2' :  printf("\n\nEnter the item to be deleted : ");
                        scanf("%d",&item);
                        deleteSpecificItem(&start,item);
                        break;
            }
	printf("\nPrevious node was: %d\n",i);
	goto lebel;
	getch();
}
//display node
void display(node *start){
    printf("\nThe list is : ");
    int i=0;
     while(start !=NULL)
     { printf("\t %d",start->info);
       start = start->next;
       i++;
     }
    printf("\nNow total node is: %d\n",i);
}
//node create
void createNode(node **start,int i){
    int item ,k=1;
	while(i){
	    node *ptr,*last;
        printf("\nEnter the value for node %d : ",k);
        scanf("%d",&item);
        ptr=(node*)malloc(sizeof(node));
        ptr->info=item;
        ptr->next=NULL;
        if(*start==NULL){
            *start = ptr ;
        }
        else{
                last = *start;
                while(last->next != NULL){
                    last=last->next;
                }
                last->next = ptr ;
            }
        i--;
        k++;
    }
}
//insert at specific location
//insertAtloc(&start,item,loc,i);
void insertAtloc(node **start,int item , int L,int *i ){
	node *ptr,*loc,*last;
	int n= *i;
	lebel: if(n==-5){
        printf("\n\nEnter the inserting Item Location : "); scanf("%d",&L);
        printf("\n\nEnter the item to be inserted : ");    scanf("%d",&item);
        n=*i;
    }
	if(n+1<L || L<1){
            printf("\nerror: the node have not exist!\nplease try again!\n");
            n=-5; //exit(1);
            goto lebel;
        }
	n=1 ;  L=L-1;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;  ptr->next=NULL;  loc = *start ;
	if(*start==NULL){
		ptr->next = NULL ;  *start = ptr ;
	}
	else if(L==0){
        ptr->next=*start;  *start=ptr;
    }  //insert mid or last node
	else if(L<=i){
	    while(n != L){
			loc=loc->next;
			n++;
		}
		ptr->next = loc->next ;  loc->next = ptr ;
	} //insert last node
    else{
	    printf("error: Please! insert a valid number.");
		/* last = *start;  while(last->next != NULL){ last=last->next; }last->next = ptr ; */
	}
	i++;  n= *i;
}
int deleteSpecificItem(node **start,int item){
    node *cur,* prev;
    // traverse to find required node
    cur = *start;
    while(cur && cur->info!=item){
        prev=cur; // save current in previous
        cur=cur->next;
    }
    // if the element is found
    if (cur){ // if its first element
        if(cur==*start)
        *start=(*start)->next;
        else
            prev->next=cur->next;
        free(cur);
        printf("\nItem successfully deleted\n");
        return 1;
    }
    else{
        printf("\nItem not found\n");
        return 0;
    }
}




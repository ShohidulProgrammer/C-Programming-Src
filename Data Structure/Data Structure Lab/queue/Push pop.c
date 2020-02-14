//Push Pop in C programming
#include<stdio.h>
void push();
int pop();
int stack[2],top=-1,max=2,empty=-1;
main()
{
    int n;
    while(1)
    {
        printf("\nPress [1] for Inter a value.\nPress [2] for Delete top value.\n");
        scanf("%d",&n);
        //check user want to insert(push) or delete(pop) item
    if(n==1)
        push();
    else if(n==2)
        pop();
    else
        printf("You Enter a Invalid Number\n");
    }
}
//function for insert(push) an item
void push(){
    int item;
    //check stack is full
    if(top==max)
           printf("Stack Overflow.");
    //insert an item
    else{
        top++;
        printf("Enter your Value: ");
        scanf("%d",&item);
        stack[top]=item;
        printf("You Enter: %d\n",stack[top]);
    }
}
//function for delete(pop) an item
int pop(){
    //check whether the stack is empty
    if(top==empty)
        printf("Stack is Underflow.\n");
    else{
        printf("You have Deleted the top value of: %d\n",stack[top]);
        //delete the last inserted item
        --top;
    }
}

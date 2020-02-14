//Enqueue & Dequeue in C Programming
#include<stdio.h>
void enqueue();
int dequeue();
int stack[2],top=-1,max=2,empty=-1,s=0,f=0;
main(){
    int n;
    while(1){
        printf("\nPress [1] for Inter a value.\nPress [2] for Delete First value.\n");
        scanf("%d",&n);
        if(n==1){
            enqueue();
        }
        else if(n==2){
            dequeue();
        }
        else
            printf("You Enter a Invalid Number\n");
        }
}
void enqueue(){
    int a;
    if(top==max){
        if(s<f){
            printf("Enter your Value: ");
            scanf("%d",&a);
            stack[s]=a;
            printf("You Enter: %d\n",stack[s]);
            s++;
        }
        else
            printf("Queue Overflow!");
       }
    else{
        top++;
        printf("Enter your Value: ");
        scanf("%d",&a);
        stack[top]=a;
        printf("You Enter: %d\n",stack[top]);
    }
}
int dequeue(){
    if(f>top){
       if(s<=max)
            s++;
       else
            printf("Queue Underflow\n");
    }
    else{
        printf("You have Deleted the value of: %d\n",stack[f]);
        f++;
    }
}

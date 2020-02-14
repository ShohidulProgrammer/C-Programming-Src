//Binary search in C Programming
#include<stdio.h>
main()
{
int i,findVal,n,mid,flag=0;
printf("Enter the total series: ");
scanf("%d",&n);
int sr[n];
printf("Enter the series value in Ascending Order: ");
for(i=0;i<n;i++)
{
    //series value input
    scanf("%d",&sr[i]);
    //ask next value
    if(i<n-1)
    printf("\nEnter the next series value: ");
}
    //display the series value
    printf("\nThe series value are : ");
    for(i=0;i<n;i++){
        printf(" %d",sr[i]);
    }
    //ask which value want to find
    printf("\nFinding value: ");
    scanf("%d",&findVal);
    //Binary search
    int start=0;
    int End=n-1;
    while(start<=End)
    {
        mid=(start+End)/2;
        if(sr[mid]==findVal){
           printf("\n%d is in %d index : ",findVal,mid+1);
           flag=1;
           break;
        }
    /*whether finding value is grater then middle position value*/
        else if(sr[mid]<findVal){
            start=mid+1;
        }
        /*whether finding value is Less then middle position value*/
        else if(sr[mid]>findVal){
            End=mid-1;
        }
    }
    //check value is founded or not
    if(flag==0){
        printf("\nThe value is not Exist\n");
    }
}

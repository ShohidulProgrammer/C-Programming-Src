//Linear Search in C Programming:
#include<stdio.h>
int main()
{
    int i,location=-1,n;
    printf("Enter the number of total series: ");
    scanf("%d",&n);
    int data[n];
    printf("Enter the %d values:  ",n);
    for(i=0;i<n;i++){
        //series value input
        scanf("%d",&data[i]);
        //ask next value
        if(i<n-1)
            printf("\nEnter the next value: ");
        }
        int key;
        printf("\nPress the value you want to Find: ");
        scanf("%d",&key);
        i=0;
        while(i<n){
            if(key==data[i]){
                location=i+1;
                printf("\nThe value=%d is in location=%d \n",key,location);
                break;
            }
            i++;
        }
        if(location==-1){
            printf("\nItem is not in the list");
        }
        return 0;
}



#include<stdio.h>
//Binary Search
void BinarySearch(int searchingArray[],int arrayLength,int findingValue)
{
    int mid,flag=0,start=0,End=arrayLength-1;

    while(start<=End){
        mid=(start+End)/2;
        if(searchingArray[mid]==findingValue){
            printf("\n%d is in %d no. index : ",findingValue,mid+1);
            flag=1;
            break;
        }
        else if(searchingArray[mid]<findingValue){
            start=mid+1;
        }
        else if(searchingArray[mid]>findingValue){
             End=mid-1;
        }
    }

    if(flag==0){
         printf("\nThe value is not Exist\n");
    }
}

main(){
    int i,findingValue,n;
    printf("Enter the total series length: ");
    scanf("%d",&n);
    int searchingArray[n];


    // Hear Need to Sort
    printf("Enter the series value in Ascending Order:   ");
    for(i=0;i<n;i++){
        scanf("%d",&searchingArray[i]);
        if(i<n-1){
            printf("\nEnter the next series value: ");
        }
    }

    printf("\nEnter Your Finding value: ");
    scanf("%d",&findingValue);

    BinarySearch(searchingArray,n,findingValue);
}

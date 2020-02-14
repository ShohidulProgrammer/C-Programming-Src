//Bubble Short in C programing:
#include<stdio.h>
main(){
    int j,i,n,temp;
    printf("Enter the total input size: ");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
        printf("\nEnter the value: ");
        scanf("%d",&ar[i]);
    }
    for(j=0;j<n;j++){
            for(i=0;i<n;i++){
                if(ar[i]>ar[i+1]){
                    temp=ar[i];
                    ar[i]=ar[i+1];
                    ar[i+1]=temp;
                }
            }
    }
    for(i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
}

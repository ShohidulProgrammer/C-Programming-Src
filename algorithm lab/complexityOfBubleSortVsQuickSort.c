#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int a[100000],n=100000;
void swap(int i,int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;

}
void quicksort(int left, int right)
{
    int q;
    if(left<right)
    {
        q= partition(left,right);
        quicksort(left,q-1);
        quicksort(q+1,right);
    }

}

int partition(int left,int right)
{
    int x,i,j;
    x= a[right];
    i = left -1;
    for(j=left;j<=right-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(i,j);
        }
    }
    swap((i+1),right);
    return (i+1);
}




//Bubble Sort in C programing:
void bubbleSort()
{
    int i,j,temp=0;

    for(j=0;j<n;j++){
            for(i=0;i<n;i++){
                if(a[i]>a[i+1]){
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
    }
    /*
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    */
}



int main()
{
    int i;
    clock_t t;


    /*
    //time_t t;
    //Initializes random number generator
     srand((unsigned)time(&t));
    */
    srand(time(NULL));

    //printf("Enter number of index:\n");
    //scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        //printf("\nEnter the value in the index: %d\n",i+1);
        //scanf("%d",&a[i]);
        a[i] = rand();
    }


    //count quick sort using time
    t= clock();
    i=0;
    quicksort(i,n-1);

    /*
    //printout quick sorted value
    printf("\nThe sorted value is:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);

    }
    */

    t = clock() -t;
    double qickSort_time_taken = ((double)t)/CLOCKS_PER_SEC;//In seconds
    printf("\nQuick sort Execution time : %.3f s\n\n",qickSort_time_taken);


    t= clock();
    bubbleSort();
    t = clock() -t;
    double bubleSort_time_taken = ((double)t)/CLOCKS_PER_SEC;//In seconds
    printf("\n\nBubble sort Execution time : %.3f s\n\n",bubleSort_time_taken);

    getch();

}


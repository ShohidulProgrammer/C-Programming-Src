#include<stdio.h>
int a[20];
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
int main()
{
    int n,i;
    printf("Enter number of index:\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter the value in the index: %d\n",i+1);
        scanf("%d",&a[i]);
    }
    i=0;
    quicksort(i,n-1);
    printf("\nThe sorted index is:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);

    }
    printf("\n");

}

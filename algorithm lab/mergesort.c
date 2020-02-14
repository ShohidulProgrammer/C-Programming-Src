#include<stdio.h>
int a[20];

void merge(int left,int center,int right)
{
    int n1,n2,i,j,k;
    n1= (center-left+1);
    n2= right-center;
    int L[n1],r[n2];
    for(i=1;i<=n1;i++)
    {
        L[i] = a[(left+i-1)];
    }
    for(j=1;j<=n2;j++)
    {
        r[j] = a[(center+j)];
    }
    i=1,j=1;
    for(k=left;k<=right;k++)
    {
        if(L[i]<=r[j])
        {
            a[k] = L[i];
            i++;
        }
        else
            {
                a[k] = r[j];
                j++;
            }
    }
}

void merge_sort(int left, int right)
{
    int center;

    if(left<right)
    {
        center= ((left+right)/2);
        merge_sort(left,center);
        merge_sort(center+1,right);
        merge(left,center,right);
    }
}
main()
{
    int n,i;
    printf("Enter number of index:\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter the value in the index: %d\n",i+1);
        scanf("%d",&a[i]);
    }
    i=1;
    merge_sort(i,n-1);
    printf("\nThe sorted index is:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);

    }
    printf("\n");
}

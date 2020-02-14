#include<stdio.h>
long int s1[4],s2[4];
int snakInput(long int snak[])
{
    int i;
    for(i=1;i<=4;i++)
        scanf("%ld",&snak[i]);

    //x or y axis check
    // if x1==x2 then the line is in Y-axis
    if(snak[1]==snak[3])
        return 2;

    // if y1==y2 then the line is in X-axis
    else
        return 1;

}

void swaping(int i)
{
    int temp=0;
    if(s1[i]>s1[i+2])
    {
       temp=s1[i];
       s1[i]=s1[i+2];
       s1[i+2]=temp;
    }
}

int matchPoint(long int sn1[4],long int sn2[4])
{
    if((sn1[1]==sn2[1])||(sn1[3]==sn2[3]))
    {
        if((sn1[2]==sn2[2])||(sn1[4]==sn2[4]))
        {
            return 1;
        }
    }
    else
        return 0;
}
int sameSnack(int i)
{
    swaping(i);
    if(((s1[i]<=s2[i])&&(s1[i+2]>=s2[i]))||((s1[i]<=s2[i+2])&&(s1[i+2]>=s2[i+2])))
    {
       return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{

    int temp=0,s1Axis,s2Axis;
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        s1Axis=snakInput(s1);
        s2Axis=snakInput(s2);

        if(s1Axis==s2Axis)
        {
            temp=sameSnack(s1Axis);
        }
        else
        {
            // they are not in same axis
            // calculate each end point is both are match
            if(s1Axis==2)
            {
               temp=matchPoint(s1,s2);
            }
            else
            {
                temp=matchPoint(s2,s1);
            }
        }
        if(temp)
            printf("yes\n");
        else
            printf("no\n");

    }
    return 0;
}

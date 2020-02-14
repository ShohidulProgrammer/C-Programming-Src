#include<stdio.h>
/*
j=0;
            while((eq[i] >= '0' && eq[i] <= '9') || (eq[i] == '.'))
            {
                num[j]=eq[i];
                i++;
                j++;
            }
            coficiant = atoi(num);
            printf("\nCoficiant: %d",coficiant);
            */
void equation()
{
    int i=0,p=0,j=0;
    char eq[30],num[30];
    scanf("%s",eq);
    // x^4-8x^3-35x^2+450x-1001
    while(eq[i] != '\0')
    {
        if(eq[i]== '+')
        {
            if(eq[i]!= '*')
            {
                num[j]=eq[i];
            }
        }
        else if(eq[i]=='x' && eq[i+1] == '^')
        {
                p=eq[i+2]-48;
                printf("\n P = %d",p);
        }
        printf("\n%d: The eq. is: %c",i,eq[i]);
        i++;
    }
    // convert string to digit



}
float fun(float x)
{

}
int main()
{

    printf("Enter the Function: ");
    equation();
}

#include<stdio.h>

int main()
{
    int ID;
    char gender;
    while(1)
    {


    printf("\n Enter your ID:");

    scanf("%d",&ID);

    if(ID%2==0)
    {
        printf("if you are a boy press[B]\nor if you are a Girl press[G]");
        scanf("%d",&n);
        getch(gender);
        if(n=='b')//||gender=='B'
        {
            printf("your set is x");
        }
        else if(gender=='g'||gender=='G')
            printf("your set is y");
        //else if(gender!='b'||gender!='B'||gender!='g'||gender!='G')
            //printf("invalid character");
        else
            printf("\ninvalid\n");
    }



        else
        {
            printf("if you are a girl press [G] \nor if you are a boy press [B]\n");
            scanf("%c, gender");
            if(gender=='b'||gender=='B')
            {
                printf("your set is x");
            }
        else if(gender=='g'||gender=='G')
            printf("your set is y");
        else if(gender!='b'||gender!='B'||gender!='g'||gender!='G')
            printf("Odd invalid character");
        }

    }
}

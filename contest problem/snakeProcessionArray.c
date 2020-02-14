#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n,temp=0,i = 0;
    char c, *input,*output;
    printf("Enter n:\n");
    scanf("%d",&n);
    input = (char *) malloc(sizeof(char));
    output=input;
    if(input != NULL) {
        getch();
            printf("\nEnter character:\n");
        while(c = getchar()!='\n') {
        //while((c=getchar())<=n){
            realloc(input, (sizeof(char)));
            input[i++] = c;
            if(i<=n)
                break;
        }

        input[i] = '\0';
        i=0;
        while(i<=n){
            if(input[i]=='H'){
               for(i=i+1;i<=n;i++)
               {
                   if(input[i]=='T')
                    {
                        temp=1;
                        break;
                    }
               }
            }
            else if((input[i]=='T'))
            {
                temp=0;
            }

            else
            {
               temp=0;
            }
            i++;
        }
        if(temp==1)
            printf("\nValid\n");
        else
            printf("\nInValid\n");
        printf("\nYou entered the string: %c\n", input[2]);
    }

}



// E=>iEp
// Ep=>+iEp|epsilon
// i+i$
#include<stdio.h>
char l;

// match function start from here..
match(char t)
{
    if(l == t)
    {
        l = getchar();
    }
    else
        printf("Error");
}

// E prime function start from here..
Ep()
{
    if(l == '+')
    {
        match('+');
        match('i');
        Ep();
    }
    else
        return;
}

// E function start from here
E()
{
    if(l == 'i')
    {
        match('i');
        Ep();
    }
}

main()
{
    l= getchar();
    E();
    if(l == '$')
        printf("parsing success");
}



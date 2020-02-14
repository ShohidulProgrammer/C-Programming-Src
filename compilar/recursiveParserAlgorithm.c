void E()
{
    choose a production/Rules E=> E1,E2,E3,....,Ek
    for(i=1 to k)
    {
        if(Ei is non terminal)
            Ei();
        else if (Ei == look ahead symbol)
            increment input pointer;
        else
            error(backtracking);
    }
}

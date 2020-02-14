int DeleteElm( node **start, int item)

{
    node *cur,* prev;
    // traverse to find required node
    cur = *start;
    while(cur && cur->info!=item)
    {
        prev=cur; // save cur in prev
        cur=cur->next;
    }
    // if the element is found
    if (cur)
        { // if its first element
        if(cur==*start)
        *start=(*start)->next;
        else
            prev->next=cur->next;
        free(cur);
        return 1;
    }
    else
    return 0;
}// end of DeleteElm

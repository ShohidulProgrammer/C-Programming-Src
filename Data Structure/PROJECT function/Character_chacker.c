int character_check(char *p)

{
	n = 0;

	for(i=0 ;i < strlen(p);i++)
	{
	    /* Comparing the ASCII values of characters
	    with the values of the characters entered*/
		if( *(p+i) >=65 && *(p+i) <=90 || *(p+i) >= 95 && *(p+i) <=122 || *(p+i) == 32)
		{
				n++;
		}
	}
	/* Check whether the length of the input exceeds
	the limit of the memory provided*/
	if(strlen(p)>18)
	{
		printf("\a\n\t\tERROR: LENGTH EXCEEDED BEYOND 18\n");
		return 0;
	}
	if((*(p+0)==32||*(p+1)==32) && (strlen(p)==1||strlen(p)==2))
	{
		printf("\a\n\tERROR:FIELD CANNOT BE LEFT BLANK");
		return 0;
	}
	if(n != strlen(p))
	{
		printf("\a\n\t\tERROR: CAN ACCEPT ALPHABETS A-Z ONLY");
		return 0;
	}
	else
	{
		return 1;
	}
}

// Function to check the presence of the special characters in the input
int special_character_check(char *p)
{
	n =0;

// strlen() will return the length of the string provided with parenthesis
	for(i=0;i < strlen(p);i++)
	{
		if( *(p+i) >= 48 && *(p+i)<=57 || *(p+i)>=65 && *(p+i)<=90 || *(p+i)>= 97 && *(p+i)<=122 || *(p+i) == 32)
		{
			n++;
		}

	}
// Checking for the limit or size of the array
	if(strlen(p)>15)
	{
		printf("\a\n\t\tERROR: LENGTH EXCEEDED BEYOND 15\n");
		return 0;
	}
	if((*(p+0)==32||*(p+1)==32) && (strlen(p)==1||strlen(p)==2))
	{
		printf("\a\n\tERROR:FIELD CANNOT BE LEFT BLANK");
		return 0;
	}
	else if(n!=strlen(p))
	{
		printf("\a\n\t\tERROR: NO SPECIAL CHARACTERS ALLOWED\n");
		return 0;
	}
	else
	{
		return 1;
	}

}

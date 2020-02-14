void uppercase(char *p)
{
	for(i=0;i<strlen(p);i++)
	{
		*(p+i) = toupper( *(p+i) );
	}
}

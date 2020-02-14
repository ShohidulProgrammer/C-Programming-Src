void id_scan()
{
	do{

	printf("\n\nPROVIDE THE STUDENT ID NUMBER =  ");
	fflush(stdin);
	gets(temp_id);
	fflush(stdin);
	flag = special_character_check(temp_id);

	if(stricmp(temp_id,"")==0)
	{
		printf("\a\n\tERROR: STUDENT_ID FIELD CANNOT BE BLANK");
		flag = 0;
		continue;
	}

	if(start!=NULL)
	{
			while(unique_id_check()!=1)
		{
				printf("\n\nENTER THE STUDENT ID NUMBER   =  ");
			gets(temp_id);
			fflush(stdin);
			flag = special_character_check(temp_id);
		}
	}

	}while(flag!=1);
	uppercase(temp_id);

}

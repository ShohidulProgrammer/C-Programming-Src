void id_wise_display()

/* Function will scan a particular Student_id, check whether the id exist or not. if the student_id exist then that particlaur record
will get displayed otherwise message will be displayed that the record will that particular id does not exist*/

{
	system("cls");
	linked_menu();

	do{
	printf("\n\tENTER THE ID NUMBER = ");
	fflush(stdin);
	gets(temp_id);
	temp = special_character_check(temp_id);

	if(strcmp(temp_id,"")==0)
	{
		printf("\a\n\tERROR: STUDENT_ID FIELD CANNOT BE BLANK");
		temp=0;
	}
	else
		temp=1;

	fflush(stdin);

	}while(temp!=1);

	uppercase(temp_id);
	temp_point = start;
	flag = 0;
	while(temp_point!=NULL)
	{
		if(stricmp(temp_id,temp_point-> student_id)==0)
		{
				flag = 1;
				break;
		}
			temp_point = temp_point -> ptr;
	}
			if(flag == 1)
			{

				printf("\n\nRECORDS IN THE LIST ARE AS FOLLOW - ");
				printf("\n\n   |  STUDENT NAME      |  STUDENT_ID     |  BRANCH        |  SEMESTER  |");
				printf("\n   __________________________________________________________________  ");
				printf("\n\n   ");
				printf("|  %-18s", temp_point -> student_name);
				printf("|  %-14s", temp_point -> student_id);
				printf("|  %-14s",temp_point -> student_branch);
				printf("|    %-3d  |",temp_point->level_number);

			}
			else if(flag==0)
			{
					printf("\a\n\t\tSTUDENT_ID %s DOESNOT EXIST IN THE LIST",temp_id);
			}

}

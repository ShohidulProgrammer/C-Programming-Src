/* Updating a pre existing record in the list
(First the particular record would be deleted
and the new record will be inserted)*/
void linked_update()
{
	system("cls");
	linked_menu();

	printf(" ^^ SELECT THE RECORD TO UPDATE  ^^");

/* Displaying all the records present in the list
to select a particular one*/
	entire_list_display();
	// If no record exist
	//record are not empty
	if(start!=NULL)
	{

	printf("\n   __________________________________________________________________  \n");
	do{
	printf("\n\tENTER THE STUDENT_ID NUMBER = ");
	gets(temp_id);

	flag = special_character_check(temp_id);
	uppercase(temp_id);

	if(strcmp(temp_id,"")==0)
	{
		printf("\a\n\tERROR: ENTER THE STUDENT_ID FROM THE ABOVE RECORDS\n");
		flag = 0;
		continue;
	}

	}while(flag!=1);

	temp_point=start;
	prev = NULL;
	flag = 0;

// Until the temp_point does not reach the end of the list
	while(temp_point!=NULL)
	{
	    /* Until the record to be updated is not find out
	    change the pointers addresses*/
		if(stricmp(temp_id,temp_point-> student_id)!=0)
		{
			prev = temp_point;
			temp_point = temp_point -> ptr;
		}
		else
		{
			flag = 1;
			break;
		}

	}
	if(temp_point==NULL || flag==0)
	{
		printf("\n\t     RECORD WITH STUDENT_ID %s DOESNOT EXIST",temp_id);

	}
	else{

/* If only single record exist then free up that memory,
set the start pointer to NULL and then
insert the updated record at its appropriate location*/
	if(prev==NULL && temp_point->ptr ==NULL)
	{
		freepoint = temp_point;
		start = NULL;
	}
	else if(prev==NULL&&temp_point->ptr!=NULL)
	{
		freepoint=temp_point;
		start=temp_point->ptr;
	}
	else
	{
		prev->ptr=temp_point->ptr;
		freepoint=temp_point;
	}

	strcpy(temp_name,temp_point->student_name);
	strcpy(temp_branch,temp_point->student_branch);
	level = temp_point->level_number;

	free(freepoint);
	system("cls");
	linked_menu();

	printf("\n\n\t ^^ ENTER THE FIELD YOU WANT TO UPDATE ^^\n");

	printf("\n\n  1.  UPDATE STUDENT_ID FOR PARTICULAR RECORD");
	printf("\n\n  2.  UPDATE NAME FOR PARTICULAR RECORD");
	printf("\n\n  3.  UPDATE BRANCH FOR PARTICULAR RECORD");
	printf("\n\n  4.  UPDATE SEMISTER FOR PARTICULAR RECORD");

	printf("\n\n\tENTER THE CHOICE = ");

	choice =number_check();


	switch(choice)
	{
	case 1: id_scan();
			break;
	case 2: do{
			printf("\nENTER THE NEW NAME = ");
			fflush(stdin);
			// scan in the student name
			gets(temp_name);
			// Clearing the buffer
			fflush(stdin);
			/* Checking the name for special characters
			as well as numeric values*/
			flag = character_check(temp_name);
            // Checking whether name entered is empty string or not
			if(stricmp(temp_name,"")==0)
			{
			    // Error Message
				printf("\a\n\tERROR: NAME FIELD CANNOT BE BLANK");
				flag = 0;
			}

			}while(flag!=1);
			break;

	case 3: do{
			printf("\nENTER THE NEW BRANCH = ");
			fflush(stdin);
			gets(temp_branch);
			fflush(stdin);

				/* Checking the string entered for
				special characters and numeric values*/
			flag = character_check(temp_branch);

				if(stricmp(temp_branch,"")==0)
				{
					printf("\a\n\tERROR: BRANCH FIELD CANNOT BE BLANK");
					flag = 0;
				}
			}while(flag!=1);
			break;

	case 4:printf("\nENTER THE NEW SEMESTER = ");
			level = number_check();break;
	}

	newnode = (struct node*)malloc(sizeof(struct node));

	uppercase(temp_name);
	uppercase(temp_branch);

	strcpy(newnode->student_name,temp_name);
	strcpy(newnode->student_id,temp_id);
	strcpy(newnode->student_branch,temp_branch);
	newnode->level_number=level;
	newnode->ptr=NULL;

	sorting();
	printf("\n\n\t\t ^^    RECORD UPDATED SUCCESSFULLY    ^^\n");
	}
	}
	printf("\n\nPRESS ENTER TO CONTINUE......");
	while(getch()!=13){}
	system("cls");

}

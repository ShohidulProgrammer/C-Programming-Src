void linked_delete()
{
	system("cls");

	linked_menu();

// Checking whether the list is empty
	if(start == NULL)
	{
		printf("\a\n\n\t\tNO ELEMENT IN THE RECORD TO BE DELETED");
		printf("\n\nPRESS ENTER TO CONTINUE........");
		while((int)getch()!=13){}

	}
	else
	{
	    // For displaying all the records before deleting a particular one

	entire_list_display();
	fflush(stdin);
	printf("\n   _______________________________________________________________  ");

// Record will be deleted on the basis of the unique id
	printf("\n\n\tENTER THE STUDENT ID = ");
	do{
	fflush(stdin);
	gets(temp_id);
	temp = special_character_check(temp_id);

	if(strcmp(temp_id,"")==0)
	{
		printf("\a\n\tERROR: STUDENT ID FIELD CANNOT BE BLANK");
		temp=0;
	}
	else
		temp=1;

	fflush(stdin);

	}while(temp!=1);

	uppercase(temp_id);
	temp_point=start;
	placefound=0;
	prev = NULL;

/* Transversing through the list for checking
whether student_id entered exist or not*/
	while(temp_point!=NULL && placefound==0)
	{
	    /* Comparing the student_id entered with one
	    that actually is present in the record*/
		if(stricmp(temp_point -> student_id,temp_id)==0)
		{
			placefound=1;
		}
		else
		{
		    // prev represents the previous node that has been checked
			prev = temp_point;
			temp_point = temp_point ->ptr;
		}
	}

/* if the record with that particular id exist
execute the if block*/
	if (placefound==1)
	{
		system("cls");
	    linked_menu();

		printf("\n\n   |  STUDENT NAME      |  STUDENT_ID     |  BRANCH        |  Semester  |");
		printf("\n   _______________________________________________________________\n\n   ");

		// Displaying that particular record that has been find out

		printf("|  %-18s", temp_point -> student_name);
		printf("|  %-14s", temp_point -> student_id);
		printf("|  %-14s",temp_point -> student_branch);
		printf("|    %-3d  |",temp_point->level_number);

		printf("\n\n\t=> PRESS Y TO CONFIRM\t\t=> PRESS N TO SKIP\n");

		printf("\n ENTER YOUR CHOICE = ");
		ch = getche();

			if(ch=='Y'||ch=='y')
			{
				freepoint = temp_point;

// IF there is only one record in the list
				if (prev == NULL && start->ptr==NULL)
				{
				    /* Set the start pointer to NULL
				    i.e no record is present in the list*/
					start = NULL;
				}
				// If the first record need to be deleted
				else if (prev==NULL && start->ptr!=NULL)
				{
                    /* Set the start pointer with
                    the address of the next node in the list*/
					start = start->ptr;
				}
				else
				{
					prev -> ptr = temp_point -> ptr;
				}
				/* Freeing up the memory which was occupied
				by that particular node that is deleted now*/
					free(freepoint);
					printf("\a\n\n\t\t ^^ RECORD DELETED SUCCESSFULLY ^^");
					printf("\n\n\tPRESS ENTER TO CONTINUE.....");
					while(getch()!=13){}
					system("cls");
			}
			/* if user presses n
			then no record will be deleted from the list*/
			else if(ch=='N'||ch=='n')
			{

				printf("\a\n\n\t\t ^^ RECORD IS NOT DELETED ^^");
				printf("\n\n\tPRESS ENTER TO CONTINUE.....");
				while(getch()!=13){}
				system("cls");
				return ;

			}
	}
	/* If the record with that particular id does not exist
in the list then this else block will get executed*/
	else
	{
		printf("\a\n\n\tMESSAGE : THE RECORD WITH STUDENT_ID %s DOESNOT EXIST",temp_id);
		printf("\nPRESS ENTER TO CONTINUE....");
		while(getch()!=13){}
	}

	}
	system("cls");

}

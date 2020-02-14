void entire_list_display()

/*Function will display all the records present in the list,
if no record exist then it will present a message that
the list is empty*/

{
	system("cls");
	linked_menu();
	if(start==NULL)
	{
		printf("\n\t        NO RECORD IN THE LIST ADD SOME RECORD FIRST");
	}
	else
	{
	printf("\n\nRECORDS IN THE LIST ARE AS FOLLOW - ");
	printf("\n\n   |  STUDENT NAME      |  STUDENT_ID     |  COURSE        |  SEMESTER  |");
	printf("\n   __________________________________________________________________  ");
	temp_point = start;

// Transversing through the list and display the records
		while(temp_point!=NULL )
		{
			printf("\n\n   ");
			printf("|  %-18s", temp_point -> student_name);
			printf("|  %-14s", temp_point -> student_id);
			printf("|  %-14s",temp_point -> student_branch);
			printf("|    %-3d  |",temp_point->level_number);

			temp_point = temp_point -> ptr;
		}
	}
}

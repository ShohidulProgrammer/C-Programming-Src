void level_wise_display()

/* Function will display all the records
for a particular semester */

{
	printf("\nENTER THE SEMESTER NUMBER TO DISPLAY RECORDS = ");
	level = number_check();

	temp_point = start;
	system("cls");
	linked_menu();
	temp=0;

	printf("\n\nRECORDS IN THE LIST IS AS FOLLOW - ");
	printf("\n\n   |  STUDENT NAME      |  STUDENT_ID     |  COURSE        |  SEMESTER  |");
	printf("\n   __________________________________________________________________  ");
	while(level >= temp_point-> level_number)
		{
			if(level == temp_point->level_number)
			{
				temp++;
					printf("\n\n   ");
					printf("|  %-18s", temp_point -> student_name);
					printf("|  %-14s", temp_point -> student_id);
					printf("|  %-14s",temp_point -> student_branch);
					printf("|    %-3d  |",temp_point->level_number);
			}

					temp_point = temp_point -> ptr;
					if(temp_point == NULL)
					{
						break;
					}

	}
	if(temp==0)
	{
		system("cls");
		linked_menu();
		printf("\n\n\tNO RECORD IN THE LIST WITH SEMESTER = %d \nADD SOME RECORD FIRST\n\n",level);
	}

}

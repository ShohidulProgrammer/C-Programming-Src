// Function for  Displaying in the records present in the list
void linked_display()
{
/* Setting a temporary pointer temp_point to start
where start represents the first node in the list*/
	temp_point = start;
// Clearing the Screen
	system("cls");
	linked_menu();
// Checking if the list is Empty
		if(temp_point == NULL)
		{
			printf("\n\n\t\tINSERT SOME RECORD FIRST \"LIST IS EMPTY\"");
		}

		else
		{
/* Choice for the user how the user wants to display
 in the records*/
			printf("\n\n      ^^  WHICH WAY YOU WANT TO PRINT THE RECORDS  ^^");
			printf("\n\n 1. PRINT THE RECORDS (SEMISTER WISE)");
			printf("\n\n 2. PRINT THE RECORDS (ID WISE)");
			printf("\n\n 3. PRINT THE RECORDS (ENTIRE LIST)");
			printf("\n\n");

			do{

			printf("\tENTER YOUR CHOICE = ");

			choice = number_check();

			if(choice == 1)
			{
				level_wise_display();
				flag=1;
			}
			else if(choice == 2)
			{
				id_wise_display();
				flag=1;
			}
			else if(choice == 3)

			{
				entire_list_display();
				flag=1;
			}
			else{
				printf("\a\n\t\t  ERROR: ENTER BETWEEN 1 TO 3 ONLY\n\n");
				flag =0;
			}
			}while(flag!=1);

		}

	printf("\n\nPRESS ENTER TO CONTINUE......");
	while(getch()!=13){}
	system("cls");
}

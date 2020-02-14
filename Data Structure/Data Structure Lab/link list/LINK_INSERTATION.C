void linked_insertion()
{
	system("cls");
	linked_menu();

	newnode = (struct node * ) malloc(sizeof(struct node));				// Dynamically allocating memory at runtime which will return a void pointer and typecasting the void pointer to type struct node

// IF memory is not available
	if (newnode == NULL)
	{
		printf("\n\tMEMORY NOT AVAILABLE");
		exit(1);
	}
	else
	{
	printf("\n\t\t__________________________________________\n\n");
	printf("\t\t| PLEASE FILL IN THE APPROPRIATE DETAILS |\n");
	printf("\t\t__________________________________________\n");

	do{


	printf("\n\nPROVIDE THE STUDENT NAME  =  ");
	fflush(stdin);
	gets(temp_name);													// scan in the student name
	fflush(stdin);														// Clearing the buffer

	flag = character_check(temp_name);									// Checking the name for special characters as well as numeric values


	if(stricmp(temp_name,"")==0)										// Checking whether name entered is empty string or not
	{
		printf("\a\n\tERROR: NAME FIELD CANNOT BE BLANK");				// Error Message
		flag = 0;
	}

	}while(flag!=1);

	uppercase(temp_name);												// Converting all the lowercase letters added to uppercase

	strcpy(newnode -> student_name, temp_name);							// Coping the string scanned to member of the strcuture variable newnode

	id_scan();														// Fucntion will scan and check the input for special characters as well

	do {

	printf("\n\nPROVIDE THE BRANCH NAME   =  ");
	fflush(stdin);
	gets(temp_branch);
	fflush(stdin);

	flag = character_check(temp_branch);								// Checking the string entered for special characters and numeric values

	if(stricmp(temp_branch,"")==0)
	{
		printf("\a\n\tERROR: BRANCH FIELD CANNOT BE BLANK");
		flag = 0;
	}

	}while(flag!=1);

	// Changing the lowercase letters to uppercase
	uppercase(temp_branch);

	do{
	    //SEMESTER=level
        printf("\n\nPROVIDE THE SEMESTER NUMBER  =  ");
        level = number_check();

	// Checking whether the level/semester entered is in between 1-12 or not

	if(level>=1 && level<=12)
	{
		flag=1;
	}
	else{
		printf("\a\n\t     ERROR: CAN ACCEPT BETWEEN 1-12 ONLY");
		flag = 0;
	}

	}while(flag!=1);

	// Copying the values of the variables to the members of structure variable newnode

	strcpy(newnode -> student_id, temp_id);
	strcpy(newnode -> student_branch,temp_branch);
	newnode -> level_number = level;
	newnode -> ptr = NULL;

// For insertion of the record at its appropriate location
	sorting();

	printf("\n\n\t\t ^^    RECORD INSERTED SUCCESSFULLY    ^^\n");

	printf("\n  PRESS ENTER TO CONTINUE......");

	/* This while loop will hold the program until
	the user will press the "ENTER" key on keyboard*/
	while(getch()!=13){}	//13 means enter key
	system("cls");
	}
}

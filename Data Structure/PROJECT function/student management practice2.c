// Header Files For various in built in Function

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

// Defining Global Variables

int choice,number_of_retailers,number,temp,n,i,flag,semester,placefound;
char temp_number[10],temp_name[18],temp_course[14],temp_id[15],ch;

// Declaring the Variables Globally (which can be accessed anywhere in the program)

int number_check();

void wait ( int seconds )
{
  clock_t endwait;

  endwait = clock () + seconds * CLOCKS_PER_SEC ;

  while (clock() < endwait) {}
}
void clock_copy();


void sorting_id();

// Modules For Linked List
void linked_menu();							// Function to print the title of Module "STUDENT MANAGEMENT SYSTEM"
void linked_list();
void createlist();							// Funtion to initialize the start pointer that would point towards then first node in list "Initially it is pointing to NULL"
void linked_delete();						// Function to delete a particular record from the list on basis of student_id

void linked_display();
void linked_update();
/* This Function would place
the node at its particular location after sorting
on the basis of level(1st) and name wise(2nd)*/
void sorting();
void linked_insertion();					// For scanning in the values of the appropriate fields
void id_wise_display();					// Displaying the record of a particular student on the basis of id
void entire_list_display();					// Displaying the entire list at a time
void semester_wise_display();					// Displaying all records of a particular level

int unique_id_check();						// For checking the uniqueness of the intake_id entered

void uppercase(char *p);					// Coverting lowercase letters to uppercase
void id_scan();
void set_course();
void set_semester();

// Definition of Strcutures

struct node
{
	char student_name[18], student_id[15], student_course[14];
	int semester_number;
	struct node * next;
}*newnode,*start,*prev,*temp_point,*freepoint;

void main()
{

	system("cls");
	// Function Call for the Initial Screen
	//clock_copy();
    system("cls");


	printf("\n\t\t   ************************************");
	printf("\n\t\t   *    SOHIDUL ISLAM  ID: 152002005  *");
	printf("\n\t\t   ************************************\n\n");

	printf("\n\t\t   S.NO.     PREFERNCES/CHOICES");
	printf("\n\t\t _______________________________________");

	printf("\n\n\t\t     1 \t     STUDENT MANAGEMENT SYSTEM");
	printf("\n\n\t\t     2 \t     SORTED RECODE INFORMATION");
	printf("\n\t\t _______________________________________");

	printf("\n\n ");

	flag=0;

// DoWhile Loop for scanning input "if input wrong scan again"
	do{

	printf("\n\t   PRESS S.NO. TO SELECT YOUR PREFERENCE = ");

// Scannning the Choice user will perform
	choice = number_check();

	if(choice==1||choice==2)
	{
	    /* Flag is just to check the accuracy of inputted data
	     if 1 input is correct*/
		flag = 1;
	}
	else
	{
		printf("\a\n\t\t  ERROR: ENTER EITHER 1 OR 2 ONLY\n");
		flag = 0 ;
	}
	}while(flag!=1);

	switch(choice)
	{
	    // Function calling Linked_list
	case 1: linked_list(); break;

	// Function calling sorting_id
	case 2: sorting_id(); break;
	}
}
/* Function to check
whether the number entered is positive integer or not*/
int number_check()
{
	int number;

/* "temp" will act as flag to store
either 0 and 1 for looping purpose*/
	temp = 1;

	do{
		if(temp == 0)
		{
			printf("\n\n\t   ENTER THE VALUE AGAIN\t = ");
		}
		number=0;

/* Scanning the number through gets function
 defined in <string.h> library*/
		fflush(stdin);
		gets(temp_number);

		if(stricmp(temp_number,"")==0)
		{
			printf("\a\n\t\t  ERROR: FIELD CAN'T BE SKIPPED");
			temp=0;
		}
		else
		{
			n=0;
			for(i=0;i<strlen(temp_number);i++)
			{
			    // 48-57 are the ASCII values of numbers 0-9
				if(temp_number[i]>=48 && temp_number[i]<=57)
				{
					n++;
					switch (temp_number[i])
					{

					case '0': number = number*10 + 0; break;
					case '1': number = number*10 + 1; break;
					case '2': number = number*10 + 2; break;
					case '3': number = number*10 + 3; break;
					case '4': number = number*10 + 4; break;
					case '5': number = number*10 + 5; break;
					case '6': number = number*10 + 6; break;
					case '7': number = number*10 + 7; break;
					case '8': number = number*10 + 8; break;
					case '9': number = number*10 + 9; break;

					}
				}
			}

			if(n!=strlen(temp_number))
			{
				printf("\a\n\t\t  ERROR: ENTER POSITIVE INTEGERS ONLY");
				temp=0;
			}
			else
			{
				temp=1;
			}
		}
	}while(temp!=1);

	return number;
}

void createlist()
{
	start = NULL;
	//temp_start=1;
}
void linked_list()
{
    // For clearing screen defined in <stlib.h> class library
	system("cls");


	    createlist();




	do{
	linked_menu();

	printf("\n\t\t      S.NO.     PREFERNCES/CHOICES");
	printf("\n\t\t __________________________________________");

	printf("\n\n\t\t        1 \tINSERT NEW STUDENT RECORD");
	printf("\n\n\t\t        2 \tPRINT THE EXISTING RECORD");
	printf("\n\n\t\t        3 \tDELETE AN EXISTING RECORD");
	printf("\n\n\t\t        4 \tUPDATE AN EXISTING RECORD");
	printf("\n\n\t\t        5 \tSORTED AN EXISTING RECORD");
	printf("\n\n\t\t        6 \tQUIT TO MAIN MENU");

	printf("\n\t\t __________________________________________\n\n");

	do{
	printf("\n\t   PRESS S.NO. TO SELECT YOUR PREFERENCE = ");

	choice = number_check();

	if(choice>=1 && choice <=6)
	{
		flag = 1;
	}
	else
	{
		printf("\a\n\t\t  ERROR: ENTER CHOICE BETWEEN 1 TO 6 ONLY\n");
		flag = 0 ;
	}
	}while(flag!=1);

	switch(choice)
		{
			case 1: linked_insertion(); break;
			case 2: linked_display(); break;
			case 3: linked_delete(); break;
			case 4: linked_update(); break;
			case 5: sorting_id(); break;
			case 6: main(); break;
		}

	}while(choice!=6);

	getch();
}

void linked_menu()
{

	printf("\n\t\t    **********************************");
	printf("\n\t\t    *    STUDENT_MANGEMENT_SYSTEM    *");
	printf("\n\t\t    **********************************\n");

}

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

	id_scan();
	set_course();
	set_semester();														// Fucntion will scan and check the input for special characters as well

// Copying the values of the variables to the members of structure variable newnode

	strcpy(newnode -> student_id, temp_id);
	strcpy(newnode -> student_course,temp_course);
	newnode -> semester_number = semester;
	newnode -> next = NULL;

// For insertion of the record at its appropriate location
	//sorting();
	entire_list_display();
	fflush(stdin);
	printf("\n   _______________________________________________________________  ");


	printf("\n\n\t\t ^^    RECORD INSERTED SUCCESSFULLY    ^^\n");

	printf("\n  PRESS ENTER TO CONTINUE......");

	/* This while loop will hold the program until
	the user will press the "ENTER" key on keyboard*/
	while(getch()!=13){}	//13 means enter key
	system("cls");
	}
}


set_course()
{
    do {

	printf("\n\nPROVIDE THE BRANCH NAME   =  ");
	fflush(stdin);
	gets(temp_course);
	fflush(stdin);

	flag = character_check(temp_course);								// Checking the string entered for special characters and numeric values

	if(stricmp(temp_course,"")==0)
	{
		printf("\a\n\tERROR: BRANCH FIELD CANNOT BE BLANK");
		flag = 0;
	}

	}while(flag!=1);

	// Changing the lowercase letters to uppercase
	uppercase(temp_course);
}

set_semester()

{
    do{
	    //take SEMESTER number
        printf("\n\nPROVIDE THE SEMESTER NUMBER  =  ");
        semester = number_check();

	// Checking whether the level/semester entered is in between 1-12 or not

	if(semester>=1 && semester<=12)
	{
		flag=1;
	}
	else{
		printf("\a\n\t     ERROR: CAN ACCEPT BETWEEN 1-12 ONLY");
		flag = 0;
	}

	}while(flag!=1);
}




/* Function to check the inputted data
for special characters as well as numeric data*/
    int character_check(char *p)

{
	n = 0;

	for(i=0 ;i < strlen(p);i++)
	{
	    /* Comparing the ASCII values of characters
	    with the values of the characters entered
	    */
	    // 65-90:A-Z, 97-122:a-z,(95: _ ,  96:`), 32: space
		if( *(p+i) >=65 && *(p+i) <=90 || *(p+i) >= 95 && *(p+i) <=122 || *(p+i) == 32)
		{
				n++;
		}
	}
	/* Check whether the length of the input exceeds
	the limit of the memory provided*/
	if(strlen(p)>18)
	{
		printf("\a\n\t\tERROR: LENGTH EXCEEDED BEYOND 18\n");
		return 0;
	}
	//check if input only space
	if((*(p+0)==32||*(p+1)==32) && (strlen(p)==1||strlen(p)==2))
	{
		printf("\a\n\tERROR:FIELD CANNOT BE LEFT BLANK");
		return 0;
	}
	// if all input is correct then n= p, if n!=length of p so user input special character or numeric value
	if(n != strlen(p))
	{
		printf("\a\n\t\tERROR: CAN ACCEPT ALPHABETS A-Z ONLY");
		return 0;
	}
	else
	{
		return 1;
	}
}

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
				semester_wise_display();
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
			temp_point = temp_point ->next;
		}
	}

/* if the record with that particular id exist
execute the if block*/
	if (placefound==1)
	{
		system("cls");
	    linked_menu();

		printf("\n\n   |  STUDENT NAME      |  STUDENT_ID     |  COURSE        |  Semester  |");
		printf("\n   _______________________________________________________________\n\n   ");

		// Displaying that particular record that has been find out

		printf("|  %-18s", temp_point -> student_name);
		printf("|  %-14s", temp_point -> student_id);
		printf("|  %-14s",temp_point -> student_course);
		printf("|    %-3d  |",temp_point->semester_number);

		printf("\n\n\t=> PRESS Y TO CONFIRM\t\t=> PRESS N TO SKIP\n");

		printf("\n ENTER YOUR CHOICE = ");
		ch = getche();

			if(ch=='Y'||ch=='y')
			{
				freepoint = temp_point;

// IF there is only one record in the list
				if (prev == NULL && start->next==NULL)
				{
				    /* Set the start pointer to NULL
				    i.e no record is present in the list*/
					start = NULL;
				}
				// If the first record need to be deleted
				else if (prev==NULL && start->next!=NULL)
				{
                    /* Set the start pointer with
                    the address of the next node in the list*/
					start = start->next;
				}
				else
				{
					prev -> next = temp_point -> next;
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

/* Updating a previous existing record in the list
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

    //if Return value = 0 then it indicates temp_id is equal to empty value
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
			temp_point = temp_point -> next;
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
	if(prev==NULL && temp_point->next ==NULL)
	{
		freepoint = temp_point;
		start = NULL;
	}
	else if(prev==NULL&&temp_point->next!=NULL)
	{
		freepoint=temp_point;
		start=temp_point->next;
	}
	else
	{
		prev->next=temp_point->next;
		freepoint=temp_point;
	}

	strcpy(temp_name,temp_point->student_name);
	strcpy(temp_course,temp_point->student_course);
	semester = temp_point->semester_number;

	free(freepoint);
	system("cls");
	linked_menu();

	printf("\n\n\t ^^ ENTER THE FIELD YOU WANT TO UPDATE ^^\n");

	printf("\n\n  1.  UPDATE STUDENT_ID FOR PARTICULAR RECORD");
	printf("\n\n  2.  UPDATE NAME FOR PARTICULAR RECORD");
	printf("\n\n  3.  UPDATE COURSE FOR PARTICULAR RECORD");
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
			printf("\nENTER THE NEW COURSE = ");
			fflush(stdin);
			gets(temp_course);
			fflush(stdin);

				/* Checking the string entered for
				special characters and numeric values*/
			flag = character_check(temp_course);

				if(stricmp(temp_course,"")==0)
				{
					printf("\a\n\tERROR: BRANCH FIELD CANNOT BE BLANK");
					flag = 0;
				}
			}while(flag!=1);
			break;

	case 4:printf("\nENTER THE NEW SEMESTER = ");
			semester = number_check();break;
	}

	newnode = (struct node*)malloc(sizeof(struct node));

	uppercase(temp_name);
	uppercase(temp_course);

	strcpy(newnode->student_name,temp_name);
	strcpy(newnode->student_id,temp_id);
	strcpy(newnode->student_course,temp_course);
	newnode->semester_number=semester;
	newnode->next=NULL;

	sorting();
	printf("\n\n\t\t ^^    RECORD UPDATED SUCCESSFULLY    ^^\n");
	}
	}
	printf("\n\nPRESS ENTER TO CONTINUE......");
	while(getch()!=13){}
	system("cls");

}

void id_wise_display()

/* Function will scan a particular Student_id, check whether the id exist or not. if the student_id exist then that particular record
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
			temp_point = temp_point -> next;
	}
			if(flag == 1)
			{

				printf("\n\nRECORDS IN THE LIST ARE AS FOLLOW - ");
				printf("\n\n   |  STUDENT NAME      |  STUDENT_ID     |  COURSE        |  SEMESTER  |");
				printf("\n   __________________________________________________________________  ");
				printf("\n\n   ");
				printf("|  %-18s", temp_point -> student_name);
				printf("|  %-14s", temp_point -> student_id);
				printf("|  %-14s",temp_point -> student_course);
				printf("|    %-3d  |",temp_point->semester_number);

			}
			else if(flag==0)
			{
					printf("\a\n\t\tSTUDENT_ID %s DOESNOT EXIST IN THE LIST",temp_id);
			}

}

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
			printf("|  %-14s",temp_point -> student_course);
			printf("|    %-3d  |",temp_point->semester_number);

			temp_point = temp_point -> next;
		}
	}
}
void semester_wise_display()

/* Function will display all the records
for a particular semester */

{
	printf("\nENTER THE SEMESTER NUMBER TO DISPLAY RECORDS = ");
	semester = number_check();

	temp_point = start;
	system("cls");
	linked_menu();
	temp=0;

	printf("\n\nRECORDS IN THE LIST IS AS FOLLOW - ");
	printf("\n\n   |  STUDENT NAME      |  STUDENT_ID     |  COURSE        |  SEMESTER  |");
	printf("\n   __________________________________________________________________  ");
	while(semester >= temp_point-> semester_number)
		{
			if(semester == temp_point->semester_number)
			{
				temp++;
					printf("\n\n   ");
					printf("|  %-18s", temp_point -> student_name);
					printf("|  %-14s", temp_point -> student_id);
					printf("|  %-14s",temp_point -> student_course);
					printf("|    %-3d  |",temp_point->semester_number);
			}

					temp_point = temp_point -> next;
					if(temp_point == NULL)
					{
						break;
					}

	}
	if(temp==0)
	{
		system("cls");
		linked_menu();
		printf("\n\n\tNO RECORD IN THE LIST WITH SEMESTER = %d \nADD SOME RECORD FIRST\n\n",semester);
	}

}


void sorting()
{
/* if list is empty then start will point towards
the record inputted*/
	if(start==NULL)
	{
		start = newnode;
	}
	else if(start -> semester_number > semester)

/*
if the level/semester entered is smaller than the level
of the first record in the list
then start will again point to newnode
but pointer of newnode will point towards
the address that was previously stored in pointer
start
*/
	{
		newnode -> next = start;
		start = newnode;
	}
	else
	{
		placefound = 0 ; temp_point = start;

		while(placefound==0 && temp_point!=NULL )
		{
		    /* if level entered is bigger than the level in the particular record go to next record*/
			if(temp_point -> semester_number < semester)
			{
				prev = temp_point;
				temp_point = temp_point -> next;
			}
// If level is same the n check for the sorting of the names
			else if(temp_point -> semester_number == semester)
			{
			    /* stricmp() will compare the two strings
			    regardless of its case,
			    if existing name in record is smaller on
                the basis of ASCII values again jump to next
                record*/
				if(stricmp(temp_point -> student_name,temp_name)<0)
				{
					prev = temp_point;
					temp_point = temp_point -> next;
				}
				else
				{
//Else the place if is found when this block will get executed
					placefound = 1 ;
				}

			}
			else
			{
					placefound = 1 ;
			}
		}

// If only one records exist in the list

		if(temp_point == start)
        {
            newnode -> next = start;
			start = newnode;
        }

		else
		{
			newnode->next=temp_point;
			prev->next=newnode;
		}
	}

}





/*Function will check the uniqueness of the id entered
i.e whether the student id is already present,
if yes it will display error messages*/
int unique_id_check()
{
		temp_point = start;

		while(temp_point!=NULL )
		{
			if(stricmp(temp_point->student_id,temp_id)==0)
			{
				printf("\n\t   ERROR: ID SHOULD BE UNIQUE");
				return 0;
			}
			else
				temp_point = temp_point -> next;
		}
		return 1;
}
void uppercase(char *p)
{
	for(i=0;i<strlen(p);i++)
	{
		*(p+i) = toupper( *(p+i) );
	}
}
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







void sorting_id()
{
/* if list is empty then start will point towards
the record inputted*/
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

	placefound = 0 ;
    temp_point = start;
    prev=temp_point;
    temp_point=temp_point->next;
		while(placefound==0 && temp_point!=NULL )
		{
		    /* if id entered is bigger than the id in the particular record go to next record*/
			if(temp_point -> student_id < prev->student_id)
			{
				temp=prev;
				prev = temp_point;
				temp_point = temp_point -> next;
			}

			else
			{
					placefound = 1 ;
			}
		}

// If only one records exist in the list

		if(temp_point == start)
        {
            newnode -> next = start;
			start = newnode;
        }

		else
		{
			newnode->next=temp_point;
			prev->next=newnode;
		}


}






void clock_copy()
{
  int n;


  printf("\n________________________________________________________________________________\n");
  printf("\n\t\t\tGREEN UNIVERSITY OF BANGLADESH\n");
  printf("\n\t\t\t\tBy SOHIDUL ISLAM\n");
  printf("\n\t\t\t\t ID: 152002005\n");
  printf("\n\t\t\t\t   PROJECT\n");
  printf("\n\t\t      **********************************");
  printf("\n\t\t     *   \"STUDENT MANAGEMENT SYSTEM\"    *");
  printf("\n\t\t      **********************************\n");
  printf("\n________________________________________________________________________________\n");
  wait(1);
  printf("\n\n      MODULE LECTURER\n");
  printf("\n____ Ashaduzzaman LECTURERAR OF GREEN UNIVERSITY____");
  wait(1);
 printf("\n\n\t\tPRESS ENTER TO CONTINUE....");
  while(getch()!=13){}
}

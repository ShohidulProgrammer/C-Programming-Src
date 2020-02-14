// Defining the size of bins through constant variable delclaration

#define top_of_stack 5

// Header Files For various in built in Function

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

// Defining Global Variables

int choice,number_of_retailers,number,j,temp,n,i,flag,level,placefound,top[5];
char temp_number[10],temp_name[18],temp_branch[14],temp_intake[15],ch;

// Declaring the Variables Globally (which can be accessed anywhere in the program)

int number_check();

void wait ( int seconds )					// http://www.cplusplus.com/reference/clibrary/ctime/time/
{
  clock_t endwait;

  endwait = clock () + seconds * CLOCKS_PER_SEC ;

  while (clock() < endwait) {}
}
void clock_copy();

// Modules For Stacks

void stack_start();
void id_scanning();							// Function to scan all the respective product_id as well as bin_id
void stack_display();						// Function to display the bins
void stack_menu();

// Modules For Linked List
void linked_menu();							// Function to print the title of Module "STUDENT MANAGEMENT SYSTEM"
void linked_list();
void createlist();							// Funtion to initialize the start pointer that would point towards teh firt node in list "Initially it is poinitng to NULL"
void linked_delete();						// Function to delete a particular record from the list on basis of intake_id

void linked_display();
void linked_update();

void sorting();								// This Function would place the node at its particular location after sorting on the basis of level(1st) and name wise(2nd)

void linked_insertion();					// For scanning in the values of the appropriate fields
void intake_wise_display();					// Displaying the record of a particular student on the basis of intake
void entire_list_display();					// Displaying the entire list at a time
void level_wise_display();					// Displaying all records of a particular level

int unique_id_check();						// For checking the uniqueness of the intake_id entered

void uppercase(char *p);					// Coverting lowercase letters to uppercase
void intake_scan();

// Definition of Strcutures

struct node
{
	char student_name[18], student_intake[15], student_branch[14];
	int level_number;
	struct node * ptr;
}*newnode,*start,*prev,*temp_point,*freepoint;

struct retailer{					// Strcuture Definition with member product_id and bin_id
	char product_id[10];
	int bin_id;
}*newretail,stack_temp[5];

struct bin_temp{					// Structure Definition for Storing the data into bins
	char product_name[10];
}bin[5][5];							// Multidimensional array Bin represents that there are 5 array each of max size 5


void main()
{

	system("cls");
	clock_copy();					// Function Call for the Initial Screen
system("cls");


	printf("\n\t\t   ************************************");
	printf("\n\t\t   *   DATABASE AND DATA STRUCTURES   *");
	printf("\n\t\t   ************************************\n\n");

	printf("\n\t\t   S.NO.     PREFERNCES/CHOICES");
	printf("\n\t\t _______________________________________");

	printf("\n\n\t\t     1 \t     STUDENT MANAGEMENT SYSTEM");
	printf("\n\n\t\t     2 \t     AUTOMATED STOOCKROOM");
	printf("\n\t\t _______________________________________");

	printf("\n\n ");

	flag=0;

	do{														// DoWhile Loop for scanning input "if input wrong scan again"

	printf("\n\t   PRESS S.NO. TO SELECT YOUR PREFERENCE = ");

	choice = number_check();								// Scannning the Choice user will perform

	if(choice==1||choice==2)
	{
		flag = 1;											// Flag is just to check the accuracy of inputted data if 1 input is correct
	}
	else
	{
		printf("\a\n\t\t  ERROR: ENTER EITHER 1 OR 2 ONLY\n");
		flag = 0 ;
	}
	}while(flag!=1);

	switch(choice)
	{
	case 1: linked_list(); break;							// Function calling Linked_list
	case 2: stack_start(); break;							// Function calling stack_start
	}
}
int number_check()											// Function to check whether the number entered is positive integer or not
{
	int number;

	temp = 1;												// "temp" will act as flag to store either 0 and 1 for looping purpose

	do{
		if(temp == 0)
		{
			printf("\n\n\t   DO ENTER THE VALUE AGAIN\t = ");
		}
		number=0;

		gets(temp_number);									// Scanning the number through gets function defined in <string.h> library
		fflush(stdin);

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
				if(temp_number[i]>=48 && temp_number[i]<=57)		// 48-57 are the ASCII values of numbers 0-9
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
}
void linked_list()
{
	system("cls");					// For clearing screen defined in <stlib.h> class library

	createlist();

	do{
	linked_menu();

	printf("\n\t\t      S.NO.     PREFERNCES/CHOICES");
	printf("\n\t\t __________________________________________");

	printf("\n\n\t\t        1 \tINSERT NEW STUDENT RECORD");
	printf("\n\n\t\t        2 \tPRINT THE EXISTING RECORD");
	printf("\n\n\t\t        3 \tDELETE AN EXISTING RECORD");
	printf("\n\n\t\t        4 \tUPDATE AN EXISTING RECORD");
	printf("\n\n\t\t        5 \tQUIT TO MAIN MENU");

	printf("\n\t\t __________________________________________\n\n");

	do{
	printf("\n\t   PRESS S.NO. TO SELECT YOUR PREFERENCE = ");

	choice = number_check();

	if(choice>=1 && choice <=5)
	{
		flag = 1;
	}
	else
	{
		printf("\a\n\t\t  ERROR: ENTER CHOICE BETWEEN 1 TO 5 ONLY\n");
		flag = 0 ;
	}
	}while(flag!=1);

	switch(choice)
		{
			case 1: linked_insertion(); break;
			case 2: linked_display(); break;
			case 3: linked_delete(); break;
			case 4: linked_update(); break;
			case 5: main(); break;
		}

	}while(choice!=5);

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

	if (newnode == NULL)		// IF memory is not available
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

	intake_scan();														// Fucntion will scan and check the input for special characters as well

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

	uppercase(temp_branch);												// Changing the lowercase letters to uppercase

	do{
	printf("\n\nPROVIDE THE LEVEL NUMBER  =  ");
	level = number_check();

	// Checking whether the level entered is in between 0-3 or not

	if(level>=0 && level<=3)
	{
		flag=1;
	}
	else{
		printf("\a\n\t     ERROR: CAN ACCEPT BETWEEN 0-3 ONLY");
		flag = 0;
	}

	}while(flag!=1);

	// Copying the values of the variables to the members of structure variable newnode

	strcpy(newnode -> student_intake, temp_intake);
	strcpy(newnode -> student_branch,temp_branch);
	newnode -> level_number = level;
	newnode -> ptr = NULL;

	sorting();					// For insertion of the record at its appropriate location

	printf("\n\n\t\t ^^    RECORD INSERTED SUCCESSFULLY    ^^\n");

	printf("\n  PRESS ENTER TO CONTINUE......");
	while(getch()!=13){}							// This while loop will hold the program until the user will press the "ENTER" key on keyboard
	system("cls");
	}
}

int character_check(char *p)						// Function to check the inputted data for special charcters as well as numeric data
{
	n = 0;

	for(i=0 ;i < strlen(p);i++)
	{
		if( *(p+i) >=65 && *(p+i) <=90 || *(p+i) >= 95 && *(p+i) <=122 || *(p+i) == 32)		// Comparing the ASCII values of charcters with the values of the charcters entered
		{
				n++;
		}
	}
	if(strlen(p)>18)							// Check whether the length of the input exceeds the limit of the memory provided
	{
		printf("\a\n\t\tERROR: LENGTH EXCEEDED BEYOND 18\n");
		return 0;
	}
	if((*(p+0)==32||*(p+1)==32) && (strlen(p)==1||strlen(p)==2))
	{
		printf("\a\n\tERROR:FIELD CANNOT BE LEFT BLANK");
		return 0;
	}
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

int special_character_check(char *p)		 // Function to check the presence of the special characters in the input
{
	n =0;

	for(i=0;i < strlen(p);i++)				// strlen() will return the lenth of the string provided with parenthesis
	{
		if( *(p+i) >= 48 && *(p+i)<=57 || *(p+i)>=65 && *(p+i)<=90 || *(p+i)>= 97 && *(p+i)<=122 || *(p+i) == 32)
		{
			n++;
		}

	}

	if(strlen(p)>15)						// Checking for the limit or size of the array
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

void linked_display()					// For Diplating in the records present in the list
{
	temp_point = start;					// Setting a temporary pointer temp_point to start where start represents the first node in the list

	system("cls");						// Clearing the Screen
	linked_menu();

		if(temp_point == NULL)			// Checking if the list is Empty
		{
			printf("\n\n\t\tINSERT SOME RECORD FIRST \"LIST IS EMPTY\"");
		}

		else
		{
			printf("\n\n      ^^  WHICH WAY YOU WANT TO PRINT THE RECORDS  ^^");		// Choice for the user how the user wants to display in the records
			printf("\n\n 1. PRINT THE RECORDS (LEVEL WISE)");
			printf("\n\n 2. PRINT THE RECORDS (INTAKE WISE)");
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
				intake_wise_display();
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

	if(start == NULL)				// Checking whether the list is empty
	{
		printf("\a\n\n\t\tNO ELEMENT IN THE RECORD TO BE DELETED");
		printf("\n\nPRESS ENTER TO CONTINUE........");
		while((int)getch()!=13){}

	}
	else
	{

	entire_list_display();				// For displaying all the records bbefore deleting a particular one
	fflush(stdin);
	printf("\n   _______________________________________________________________  ");

	printf("\n\n\tENTER THE INTAKE_ID = ");		// Record will be deleted on the basis of the unique intake_id
	do{
	fflush(stdin);
	gets(temp_intake);
	temp = special_character_check(temp_intake);

	if(strcmp(temp_intake,"")==0)
	{
		printf("\a\n\tERROR: INTAKE_ID FIELD CANNOT BE BLANK");
		temp=0;
	}
	else
		temp=1;

	fflush(stdin);

	}while(temp!=1);

	uppercase(temp_intake);
	temp_point=start;
	placefound=0;
	prev = NULL;

	while(temp_point!=NULL && placefound==0)				// Transversing through the list for checking whether intake_id entered exist or not
	{
		if(stricmp(temp_point -> student_intake,temp_intake)==0)	// Comparing the intake_id enetered with one that actuallly is present in the record
		{
			placefound=1;
		}
		else
		{
			prev = temp_point;							// prev represents the previous node that has been checked
			temp_point = temp_point ->ptr;
		}
	}

	if (placefound==1)									// if the record with that particular id exist execute the if block
	{
		system("cls");
	    linked_menu();

		printf("\n\n   |  STUDENT NAME      |  INTAKE_ID     |  BRANCH        |  LEVEL  |");
		printf("\n   _______________________________________________________________\n\n   ");

		// Displaying that particular record that has been find out

		printf("|  %-18s", temp_point -> student_name);
		printf("|  %-14s", temp_point -> student_intake);
		printf("|  %-14s",temp_point -> student_branch);
		printf("|    %-3d  |",temp_point->level_number);

		printf("\n\n\t=> PRESS Y TO CONFIRM\t\t=> PRESS N TO SKIP\n");

		printf("\n ENTER YOUR CHOICE = ");
		ch = getche();

			if(ch=='Y'||ch=='y')
			{
				freepoint = temp_point;

				if (prev == NULL && start->ptr==NULL)		// IF there is only one record in the list
				{
					start = NULL;							// Set the start pointer to NULL i.e no record is present in the list
				}
				else if (prev==NULL && start->ptr!=NULL)	// If the first record need to be deleted
				{
					start = start->ptr;						// Set the start pointer with the address of the next node in the list
				}
				else
				{
					prev -> ptr = temp_point -> ptr;
				}
					free(freepoint);						// Freeying up the meomory which was occupied by that particular node that is deleted now
					printf("\a\n\n\t\t ^^ RECORD DELETED SUCCESSFULLY ^^");
					printf("\n\n\tPRESS ENTER TO CONTINUE.....");
					while(getch()!=13){}
					system("cls");
			}
			else if(ch=='N'||ch=='n')						// if user presses n then no record will be deleted from the list
			{

				printf("\a\n\n\t\t ^^ RECORD IS NOT DELETED ^^");
				printf("\n\n\tPRESS ENTER TO CONTINUE.....");
				while(getch()!=13){}
				system("cls");
				return ;

			}
	}
	else		// If the record with that particular id does not exist in the list then this else block will get executed
	{
		printf("\a\n\n\tMESSAGE : THE RECORD WITH INTAKE_ID %s DOESNOT EXIST",temp_intake);
		printf("\nPRESS ENTER TO CONTINUE....");
		while(getch()!=13){}
	}

	}
	system("cls");

}

void linked_update()				// Updating a pre existing record in the list (First the particular record would be deleted and the new record will be inserted)
{
	system("cls");
	linked_menu();

	printf(" ^^ SELECT THE RECORD TO UPDATE  ^^");

	entire_list_display();			// Diplaying all the records present in the list to select a particular one
	if(start!=NULL)					// If no record exist
	{

	printf("\n   __________________________________________________________________  \n");
	do{
	printf("\n\tENTER THE INTAKE NUMBER = ");
	gets(temp_intake);

	flag = special_character_check(temp_intake);
	uppercase(temp_intake);

	if(strcmp(temp_intake,"")==0)
	{
		printf("\a\n\tERROR: ENTER THE INTAKE_ID FROM THE ABOVE RECORDS\n");
		flag = 0;
		continue;
	}

	}while(flag!=1);

	temp_point=start;
	prev = NULL;
	flag = 0;

	while(temp_point!=NULL)				// Until the temp_point does not reach the end of the list
	{
		if(stricmp(temp_intake,temp_point-> student_intake)!=0)			// Until the record to be updated is not findout change the pointers addresses
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
		printf("\n\t     RECORD WITH INTAKE_ID %s DOESNOT EXIST",temp_intake);

	}
	else{

	if(prev==NULL && temp_point->ptr ==NULL)			// If only single record exist then free up that memory, set the start pointer to NULL and then insert the updated record at its appropriate location
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

	printf("\n\n  1.  UPDATE INTAKE_ID FOR PARTICULAR RECORD");
	printf("\n\n  2.  UPDATE NAME FOR PARTICULAR RECORD");
	printf("\n\n  3.  UPDATE BRANCH FOR PARTICULAR RECORD");
	printf("\n\n  4.  UPDATE LEVEL FOR PARTICULAR RECORD");

	printf("\n\n\tENTER THE CHOICE = ");

	choice =number_check();


	switch(choice)
	{
	case 1: intake_scan();
			break;
	case 2: do{
			printf("\nENTER THE NEW NAME = ");
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
			break;

	case 3: do{
			printf("\nENTER THE NEW BRANCH = ");
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
			break;

	case 4:printf("\nENTER THE NEW LEVEL = ");
			level = number_check();break;
	}

	newnode = (struct node*)malloc(sizeof(struct node));

	uppercase(temp_name);
	uppercase(temp_branch);

	strcpy(newnode->student_name,temp_name);
	strcpy(newnode->student_intake,temp_intake);
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

void intake_wise_display()

/* Function will scan a particular intake_id, check whether the id exist or not. if the intake_id exist then that particlaur record
will get displayed otherwise message will be displayed that the record will that particular id does not exist*/

{
	system("cls");
	linked_menu();

	do{
	printf("\n\tENTER THE INTAKE NUMBER = ");
	fflush(stdin);
	gets(temp_intake);
	temp = special_character_check(temp_intake);

	if(strcmp(temp_intake,"")==0)
	{
		printf("\a\n\tERROR: INTAKE_ID FIELD CANNOT BE BLANK");
		temp=0;
	}
	else
		temp=1;

	fflush(stdin);

	}while(temp!=1);

	uppercase(temp_intake);
	temp_point = start;
	flag = 0;
	while(temp_point!=NULL)
	{
		if(stricmp(temp_intake,temp_point-> student_intake)==0)
		{
				flag = 1;
				break;
		}
			temp_point = temp_point -> ptr;
	}
			if(flag == 1)
			{

				printf("\n\nRECORDS IN THE LIST ARE AS FOLLOW - ");
				printf("\n\n   |  STUDENT NAME      |  INTAKE_ID     |  BRANCH        |  LEVEL  |");
				printf("\n   __________________________________________________________________  ");
				printf("\n\n   ");
				printf("|  %-18s", temp_point -> student_name);
				printf("|  %-14s", temp_point -> student_intake);
				printf("|  %-14s",temp_point -> student_branch);
				printf("|    %-3d  |",temp_point->level_number);

			}
			else if(flag==0)
			{
					printf("\a\n\t\tINTAKE_ID %s DOESNOT EXIST IN THE LIST",temp_intake);
			}

}

void entire_list_display()

//Function will display all the records present in the list, if no record exist then it will present a meassage that the list is empty

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
	printf("\n\n   |  STUDENT NAME      |  INTAKE_ID     |  BRANCH        |  LEVEL  |");
	printf("\n   __________________________________________________________________  ");
	temp_point = start;

		while(temp_point!=NULL )			// Transversing thorugh the list and display the records
		{
			printf("\n\n   ");
			printf("|  %-18s", temp_point -> student_name);
			printf("|  %-14s", temp_point -> student_intake);
			printf("|  %-14s",temp_point -> student_branch);
			printf("|    %-3d  |",temp_point->level_number);

			temp_point = temp_point -> ptr;
		}
	}
}
void level_wise_display()

/* Funtion will display all the records for a particular level */

{
	printf("\nENTER THE LEVEL NUMBER TO DISPLAY RECORDS = ");
	level = number_check();

	temp_point = start;
	system("cls");
	linked_menu();
	temp=0;

	printf("\n\nRECORDS IN THE LIST IS AS FOLLOW - ");
	printf("\n\n   |  STUDENT NAME      |  INTAKE_ID     |  BRANCH        |  LEVEL  |");
	printf("\n   __________________________________________________________________  ");
	while(level >= temp_point-> level_number)
		{
			if(level == temp_point->level_number)
			{
				temp++;
					printf("\n\n   ");
					printf("|  %-18s", temp_point -> student_name);
					printf("|  %-14s", temp_point -> student_intake);
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
		printf("\n\n\tNO RECORD IN THE LIST WITH LEVEL = %d ADD SOME RECORD FIRST\n\n",level);
	}

}
void sorting()
{
	if(start==NULL)			// if list is empty then start will point towards the record inputted
	{
		start = newnode;
	}
	else if(start -> level_number > level)

		/*if the level entered is smaller than the level of the first reocrd in the list then start will again point to newnode but pointer of newnode will point towards
the address that was previously stored in pointer start
*/
	{
		newnode -> ptr = start;
		start = newnode;
	}
	else
	{
		placefound = 0 ; temp_point = start;

		while(placefound==0 && temp_point!=NULL )
		{
			if(temp_point -> level_number < level)			// if level entered is bigger than the level in the particular record go to next record
			{
				prev = temp_point;
				temp_point = temp_point -> ptr;
			}
			else if(temp_point -> level_number == level)	// If level is same the ncheck for the sorting of the names
			{
				if(stricmp(temp_point -> student_name,temp_name)<0)		// stricmp() will compare the two strings regardless of its case, if existing name in record is smaller on the basis of ASCII values again jump to next record
				{
					prev = temp_point;
					temp_point = temp_point -> ptr;
				}
				else
				{
					placefound = 1 ;			// Else the place if is found when this block will get executed

				}

			}
			else
			{
					placefound = 1 ;
			}
		}


		if(temp_point == start)			// If only one records exist in the list
		{
			newnode -> ptr = start;
			start = newnode;
		}
		else
		{
			newnode->ptr=temp_point;
			prev->ptr=newnode;
		}
	}

}
int unique_id_check()			// Function will check the uniqueness of the id enetered i.e whether the intake id is already present, if yes it will display error messages
{
		temp_point = start;

		while(temp_point!=NULL )
		{
			if(stricmp(temp_point->student_intake,temp_intake)==0)
			{
				printf("\n\t   ERROR: ID SHOULD BE UNIQUE");
				return 0;
			}
			else
				temp_point = temp_point -> ptr;
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
void intake_scan()
{
	do{

	printf("\n\nPROVIDE THE INTAKE NUMBER =  ");
	fflush(stdin);
	gets(temp_intake);
	fflush(stdin);
	flag = special_character_check(temp_intake);

	if(stricmp(temp_intake,"")==0)
	{
		printf("\a\n\tERROR: INTAKE_ID FIELD CANNOT BE BLANK");
		flag = 0;
		continue;
	}

	if(start!=NULL)
	{
			while(unique_id_check()!=1)
		{
				printf("\n\nENTER THE INTAKE NUMBER   =  ");
			gets(temp_intake);
			fflush(stdin);
			flag = special_character_check(temp_intake);
		}
	}

	}while(flag!=1);
	uppercase(temp_intake);

}

// Automated stockroom modules starts from here being implemented suing the concept of stacks

void stack_start(){
	stack_menu();
	do{
	printf("\n\t ENTER THE TOTAL NUMBER OF RETAILERS = ");

	// Scan the total number of retailers
	number = number_check();
	if(number>=100)
	{
		printf("\a\n\t ERROR: NUBER OF PRODUCTS ARE LIMITED TO 100\n");
		temp=0;
	}
	else
	{
		temp=1;
	}
	}while(temp!=1);

	id_scanning();
	stack_display();

	getch();
}

void stack_menu()
{
	system("cls");
	printf("\n\t\t    **********************************");
	printf("\n\t\t    *       AUTOMATED_STOCKROOM      *");
	printf("\n\t\t    **********************************\n");
}

void id_scanning()
{
	newretail = (struct retailer *)malloc (number * sizeof(struct retailer));

	if(newretail == NULL)
	{
		printf("\a\n\tMEMORY NOT AVAILABLE");
	}

	else{

	for(level=0;level<number;level++)
	{
		do{
		fflush(stdin);
		printf("\n  PRODUCT [%d] ID = ",level+1);
		gets(temp_name);

		temp= special_character_check(temp_name);


		if (stricmp(temp_name,"")==0)				// Checking whether the string eneterd is NULL string
			{
				printf("\a\n\t  ERROR: PRODUCT MUST HAVE A ID\n");
				temp=0;
			}

		if(level!=0)				// this will get executed when there will be more than one product_id scanned
		{
			j = level;
			while(j>=0)
			{
				if(stricmp(newretail[j].product_id,temp_name)==0)		// Compare the id eneterd with the existing ones
				{
					printf("\a\n\t  ERROR:PRODUCT MUST HAVE A UNIQUE ID\n");
					temp=0;
				}
				j--;
			}

		}

		}while(temp!=1);

		uppercase(temp_name);

		strcpy(newretail[level].product_id,temp_name);

		do{

		fflush(stdin);
		printf("\n  BIN [%d] ID     = ",level+1);
		choice=number_check();				// Scanning the bin_id


		if(choice>=0&&choice<=4)
		{
			temp=1;
		}
		else{
			printf("\tERROR:BIN_ID SHOULD BE BETWEEN 0-4\n");
			temp=0;
		}

		}while(temp!=1);

		newretail[level].bin_id = choice;


		printf("\n_______________________________\n");
	}

	for(i=0;i<5;i++)
	{
		top[i]=-1;			// intializing all array elements  of top to -1 that represents the intially there is not element in any of the bins
	}

	j=0;

	do{

		temp=0;

		while(temp<5 && j!=number)		// Copying the product id and bin id respectively in the stacker firve at a time or until the all the relatilers being removed
		{
			strcpy(stack_temp[temp].product_id,newretail[j].product_id);
			stack_temp[temp].bin_id = newretail[j].bin_id;
			j++;
			temp++;
		}

		for(i = temp-1;i>=0;i--)
		{
			if(top[stack_temp[i].bin_id] == top_of_stack-1)
			{
				strcpy(bin[stack_temp[i].bin_id][4].product_name,stack_temp[i].product_id);
			}
			else
			{
				strcpy(bin[stack_temp[i].bin_id][++top[stack_temp[i].bin_id]].product_name,stack_temp[i].product_id);
			}
		}
	}while(j!=number);


	printf("\n\n  PRESS ENTER TO DISPLAY THE STOCKROOM........  ");
	while((int)getch()!=13);
	}
}

void stack_display()
{
	system("cls");
	printf("\n\t\t\t**********************");
	printf("\n\t\t\t*  STOCKROOM INSIDE  *");
	printf("\n\t\t\t**********************");
	printf("\n");

	printf("\n\t\t ___________________________\n");
	printf("\t\t   BIN_ID\tPRODUCT_ID");

	for(i=0;i<top_of_stack;i++)
	{
		temp=top[i];			// Copying the top of particular element into temp variable for poping purpose

		while(temp != -1)
		{
			printf("\n\t\t|__________________________|");
			printf("\n\t\t%5d",i);
			printf(" \t    %s ",bin[i][temp].product_name);		// Print the product_id stored in array bin
			temp--;

		}

	}
	printf("\n\t\t|__________________________|");


	printf("\n\n\n=> PRESS 1 TO ADD RETAILERS AGAIN IN STOCKROOM\n\n");
	printf("=> PRESS 2 TO GO TO MAIN MENU AGAIN");

	do{
	printf("\n\n\tENTER YOUR CHOICE = ");
	fflush(stdin);

	ch = getch();
	while((int)ch==13||(int)ch==8||(int)ch==32||(int)ch==9)		// if enter, space, backspace or tab will be pressed nothing would get displayed
	{
		ch=getch();
	}
	putch(ch);

	while((int)getch()!=13){}

	if(ch=='1'||ch=='2')
	{
		temp=1;
	}
	else {
		printf("\a\n\n\t\tERROR:ENTER A VALID CHOICE");
		temp=0;
	}
	}while(temp!=1);


	if(ch=='1')
	{
		stack_start();
	}
	else
	{
		main();
	}
}
void clock_copy()
{
  int n;


  printf("\n________________________________________________________________________________\n");
  printf("\n\t\tASIA PACIFIC INSTITUTE OF INFORMATION TECHNOLOGY\n");
  printf("\n\t\t\t\tGROUP NUMBER-4\n");
  printf("\n\t\t\t\t   PRESENTS\n");
  printf("\n\t\t      **********************************");
  printf("\n\t\t      *     \"LINKED LIST AND STACKS\"   *");
  printf("\n\t\t      **********************************\n");
  printf("\n________________________________________________________________________________\n");
  wait(2);
  printf("\n\n      MODULE LECTURER\n");
  printf("\n____ People at Sourcecodester____");
  wait(2);
 printf("\n\n\t\tPRESS ENTER TO CONTINUE....");
  while(getch()!=13){}
}

#include<time.h>
#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <string.h>
#include<graphics.h>
#include <stdlib.h>
#include <iomanip.h>
#include<process.h>
#include<dos.h>

char *menu_items[] ={
	"(1)Add records ",
	"(2)List",
	"(3)Delete",
	"(4)Search",
	"(0)Exit"
};
/////////////////////////////////
// DRAW DOUBLE SIDED RECTANGLE //
/////////////////////////////////
void DDrawRect(int x1, int y1, int x2, int y2)
{
 for(int col=x1;col<x2;col++)
	 {
		   gotoxy(col,y1);
		   cprintf("%c",205);
		   gotoxy(col,y2);
		   cprintf("%c",205);
	 }
	 for(int row=y1;row<y2;row++)
	 {
		   gotoxy(x1,row);
		   cprintf("%c",186);
		   gotoxy(x2,row);
		   cprintf("%c",186);
	 }
	 gotoxy(x1,y1);
	 cprintf("%c",201);
	 gotoxy(x1,y2);
	 cprintf("%c",200);
	 gotoxy(x2,y1);
	 cprintf("%c",187);
	 gotoxy(x2,y2);
	 cprintf("%c",188);
}

 int i=1,j=78;

class S_M_S
{
	private:
	struct address
	{
		char flag;
		char id[10];
		char fname[50];
		char f_name[50];
		char add1[50];
		char d_o_b[50];
		char course[50];
		char branch[50];
		char sex[2];
		char y_o_j[20];
		char phone[10];
	}Mail;

	fstream file;

	public:
		S_M_S();
		void Add();
		void List();
		void Exit();
		void Splash();
		int Search();
		void Menu();
}m;

///////////////////////////
//         MAIN MENU   ////
///////////////////////////

void S_M_S::Menu()
{
	char choice;
	do {

		clrscr();
		DDrawRect(15,4,60,20);
		DDrawRect(16,5,59,7);
		gotoxy(25,6);
		cout << "STUDENT INFORMATION SYSTEM";
		gotoxy(21,8);
		cout <<"Please Choose One of The Following";
		DDrawRect(26,9,49,15);
		gotoxy(27,10);
		cout << "* ADD RECORDS      [1]";
		gotoxy(27,11);
		cout << "* LIST ALL RECORDS [2]";
		gotoxy(27,12);
		cout << "* SEARCH A RECORD  [3]";
		gotoxy(27,13);
		cout << "* HELP             [4]";
		gotoxy(27,14);
		cout << "* EXIT             [0]";
		DDrawRect(1,21,80,23);
		gotoxy(2,22);
		{
			for(i=1;i<=j;i++)
		{
			printf("%c",177);
		}
		}
		 gotoxy(4,22);
		cout << "ADD:1";
		 gotoxy(20,22);
		cout << "LIST:2";
		 gotoxy(36,22);
		cout << "SEARCH:3";
		 gotoxy(52,22);
		cout << "HELP:4";
		 gotoxy(70,22);
		cout << "EXIT:0";
		lblChoice:
		gotoxy(31,17);
		cout << "Your choice? ";
		choice = getchar();
		if (choice == '\n')

			goto lblChoice;
		clrscr();

//////////////////////////////////////////////
//           MAIN MENU CHOICE             ////
//////////////////////////////////////////////
		switch(choice)
		{
			case  '1':
				m.Add();
				break;
			case '2':
				m.List();
				break;


			case '3':
				if (m.Search())
				{
					cout << endl << "Press any key...";
				}
				else
				{
					cout << "Record not found !!!";
				}
				getch();
				break;
			case '4':
				//HELP//
				{
				printf("1.What happened with new records?");
				printf("\n\n\tWhen we add a new record the record will store in a single file  named   STUDENT.pdf.");
				printf("\n\n2.How do I clear all records?");
				printf("\n\n\n\tGO to bin directory of tc and Delete the file STUDENT.pdf.");
				getch();
				}
				     break;
			case ' ' :
				     break;
			case '0':
				m.Exit();
				break;
		}
	}while (choice != 0);
}
/////////////////////////////////////////////
//            SEARCH A RECORD            ////
/////////////////////////////////////////////
int S_M_S::Search()
{	textcolor(YELLOW);
	char id[10];
	cout << "Enter Code:  ";
	cin >> id;
	file.clear();
	file.seekg(0L,ios::beg);
while (file.read((char *)&Mail, sizeof(Mail)))
	{
		// if record found
		if (strcmp(Mail.id,id) == 0)
		{           gotoxy(2,3);
			cout << "NAME:: ";
			cout << Mail.fname << " ";
			gotoxy(40,3);
			cout << "FATHER NAME::  ";
			cout <<Mail.f_name<<"\n";
			gotoxy(2,5);
			cout <<"DATE OF BIRTH:: ";
			cout << Mail.d_o_b<< "";
			gotoxy(40,5);
			cout <<"SEX:: ";
			cout << Mail.sex<<"\n";;
			gotoxy(2,7);
			cout <<"COURSE:: ";
			cout << Mail.course<<"\n";
			gotoxy(25,7);
			cout <<"BRANCH:: ";
			cout << Mail.branch<<"\n";
			gotoxy(40,7);
			cout <<"YEAR OF JOINING:: ";
			cout << Mail.y_o_j<<"\n";
			gotoxy(2,9);
			cout <<"ADDRESS:: ";
			cout << Mail.add1<<"\n";
			gotoxy(2,11);
			cout <<"CONTACT NO.:: ";
			cout << Mail.phone;

			return 1;
		}
	}
	return 0;
}

//////////////////////////////////////////////
// PROG. STARTING (LOADING,WELCOME SCREEN)////
//////////////////////////////////////////////
void S_M_S::Splash()
{
	int x,y;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\tc\bgi");
	x=getmaxx();
	y=getmaxy();
		randomize();
  for (i=0;i<=700;i++)
  {
    putpixel(rand()%640,rand()%480,rand());//fill background with color
  }
	setcolor(10);
		settextjustify(1,1);
		settextstyle(4,0,10);
	outtextxy(x/4+150,y/4,"Please");
		settextstyle(4,0,9);
	outtextxy(x/4+150,y/2,"wait...");
		gotoxy(1,29);
	printf("\n\nPlease wait untill system load necessary files........");
	gotoxy(1,29);
for(i=1;i<=80;i++)
	{
		printf("%c",219);
		delay(100);
	}


	//WELCOME SCREEN//
	{

	int x,y,i;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\tc\bgi");
	x=getmaxx();
	y=getmaxy();
	{
	randomize();
  for (i=0;i<=1000;i++)
  {
    putpixel(rand()%640,rand()%480,rand());//fill background with color
  }
	settextjustify(1,1);
	setcolor(11);
		 settextstyle(10,0,2);
	outtextxy(x/4+150,y/5-75,"WELCOME TO S.M.S.");
	setcolor(10);
		settextstyle(10,0,5);
	outtextxy(x/2+10,y-350,"B H A G W A N T");
		settextstyle(1,0,6);
	outtextxy(x/2+10,y-250,"GROUP OF INSTITUTIONS");
		settextstyle(8,0,4);
	outtextxy(x/2+7,y/2+150,"BHAGWANTPURAM M.NAGAR");
	getch();
	restorecrtmode();
	 }
}
	textcolor(YELLOW);
}
void S_M_S::S_M_S()
{
	file.open("student.pdf",ios::binary|ios::in|ios::out);
	if (!file)
	{
		cout << endl << "Unable to open file";
		Exit();
	}
}

////////////////////////////////////////////
//        ADD RECORD IN FILE            ////
////////////////////////////////////////////
void S_M_S::Add()
 {
	char ch;
	file.seekp(0L,ios::end);
		textcolor(YELLOW);
	do {

		fflush(stdin);
		cout << endl << "Enter Code : " << endl;
		gets(Mail.id);
		fflush(stdin);
		cout << endl << "Enter Name    : " << endl;
		gets(Mail.fname);
		fflush(stdin);
		cout << endl << "Enter Father Name     : " << endl;
		gets(Mail.f_name);
		fflush(stdin);
		cout << endl << "Date of Birth         : " << endl;
		gets(Mail.d_o_b);
		fflush(stdin);
		cout << endl << "SEX : " << endl;
		gets(Mail.sex);
		fflush(stdin);
		cout << endl << "Course : " << endl;
		gets(Mail.course);
		fflush(stdin);
		cout << endl << "Branch : " << endl;
		gets(Mail.branch);
		fflush(stdin);
		cout << endl << "Year of Joining : " << endl;
		gets(Mail.y_o_j);
		fflush(stdin);
		cout << endl << "ADDRESS : " << endl;
		gets(Mail.add1);
		fflush(stdin);
		cout << endl << "Phone   : " << endl;
		cin >> Mail.phone;
		Mail.flag = ' ';
		file.write((char *)&Mail,sizeof(Mail));
		cout << "Add another record ?(Y/N) ";
		cin >> ch;
		fflush(stdin);

	} while (ch == 'y' || ch == 'Y');
}
///////////////////////////////////////////
// lists all records                   ////
///////////////////////////////////////////
void S_M_S::List()
{
	int recno = 0, a;
	int line = 0;
	file.seekg(0L,ios::beg);
    gotoxy(20,1);
	textcolor(YELLOW);
	cout << "List of Students"<<endl;
	cout << "*****************"<<endl;
	while (file.read((char *)&Mail, sizeof(Mail)))
	{
		if (Mail.flag != '*')
		clrscr();
		   cout << "ID      : " << Mail.id << endl;

		   cout	<< "Name    : " << Mail.fname<< endl;
		   cout	<< "Father Name   : " << Mail.f_name<< endl;
		   cout	<< "Date of Birth : " << Mail.d_o_b<< endl;
		   cout	<< "Sex    : " << Mail.sex<< endl;
		   cout	<< "Course : " << Mail.course<< endl;
		   cout	<< "Branch : " << Mail.branch<< endl;
		   cout	<< "Year of Joining : " << Mail.y_o_j<< endl;
		   cout	<< "Address: " << Mail.add1 << endl;
		   cout << " Phone : " << Mail.phone << endl;


		   line++;
		   if (line== 1)
		   {
			  printf("\npress any key to continue...");
			  getch();
			  line = 0;

		   }

		   cout << endl;
	}
	file.clear();	// reet get pointer
	cout << endl << "Press any key...";
	getch();

}
///////////////////////////////////////////
//            EXIT PROG.               ////
//////////////////////////////////////////
 void S_M_S::Exit()
{
	file.close();
	exit(1);
}

void main()
{
	S_M_S m;
	_setcursortype(_NOCURSOR);
	m.Splash();
	_setcursortype(_NORMALCURSOR);
	m.Menu();

}
#include<stdio.h>

struct info
{
 char name[20];
 char dept[20];
 int ID;
 float CGPA;
 int age;
};
struct info stud[5], extra[0];
int main()
{
 int i, press, p, q, r, temp;
 for(i = 0; i < 5; ++i)
 {
  printf("Enter the name: ");
  scanf("%s",stud[i].name);
  printf("Enter the ID of %s: ", stud[i].name);
  scanf("%d",&stud[i].ID);
  printf("Enter the Department Name of %s: ", stud[i].name);
  scanf("%s",&stud[i].dept);
  printf("Enter the CGPA of %s: ", stud[i].name);
  scanf("%f",&stud[i].CGPA);
  printf("Enter the age of %s: ", stud[i].name);
  scanf("%d",&stud[i].age);
  printf("\nnext\n");
 }

 printf("Press:\n 1 for list\n 2 to search by serial no\n 3 to sort by ID\n 4 to sort by CGPA\n");
 printf("\nPlease enter your choice: ");
 scanf("%d",&press);

 if(press == 1)
 {
  printf("Here's the list\n");
  for(i = 0; i < 5; i++)
  {
   printf("\nName: %s", stud[i].name);
   printf("\nDepartment: %s", stud[i].dept);
   printf("\nAge: %d", stud[i].age);
   printf("\nID: %d", stud[i].ID);
   printf("\nCGPA: %0.3f", stud[i].CGPA);
   printf("\n\n");
  }
 }
 else if(press == 2)
 {
  printf("Please enter the serial no: ");
  scanf("%d",&i);
  i--;

  printf("\nName: %s", stud[i].name);
  printf("\nDepartment: %s", stud[i].dept);
  printf("\nAge: %d", stud[i].age);
  printf("\nID: %d", stud[i].ID);
  printf("\nCGPA: %0.3f", stud[i].CGPA);
  printf("\n");
 }

 else if(press == 3)
 {
  printf("List is sorted in ascending order for ID...\n");
  for(p = 0; p < 5; p++)
  {
   for(q = 0; q < 4; q++)
   {
    if(stud[q].ID > stud[q+1].ID)
    {
     extra[q] = stud[q];
     stud[q] = stud[q+1];
     stud[q+1] = extra[q];
    }
   }
  }
  for(i = 0; i < 5; i++)
  {
   printf("\nName: %s", stud[i].name);
   printf("\nDepartment: %s", stud[i].dept);
   printf("\nAge: %d", stud[i].age);
   printf("\nID: %d", stud[i].ID);
   printf("\nCGPA: %0.3f", stud[i].CGPA);
   printf("\n\n");
  }
 }

 else if(press == 4)
 {
  printf("List is sorted in ascending order for CGPA...\n");
  for(p = 0; p < 5; p++)
  {
   for(q = 0; q < 4; q++)
   {
    if(stud[q].CGPA > stud[q+1].CGPA)
    {
     extra[q] = stud[q];
     stud[q] = stud[q+1];
     stud[q+1] = extra[q];
    }
   }
  }
  for(i = 0; i < 5; i++)
  {
   printf("\nName: %s", stud[i].name);
   printf("\nDepartment: %s", stud[i].dept);
   printf("\nAge: %d", stud[i].age);
   printf("\nID: %d", stud[i].ID);
   printf("\nCGPA: %0.3f", stud[i].CGPA);
   printf("\n\n");
  }
 }
 return 0;
}

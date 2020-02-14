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
				temp_point = temp_point -> ptr;
		}
		return 1;
}

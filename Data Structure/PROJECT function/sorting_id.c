void sorting_id()
{
/* if list is empty then start will point towards
the record inputted*/
	if(start==NULL)
	{
		start = newnode;
	}

/*
if the level/semester entered is smaller than the level
of the first record in the list
then start will again point to newnode
but pointer of newnode will point towards
the address that was previously stored in pointer
start
*/
    else if(start -> student_id > temp_id)
	{
		newnode -> ptr = start;
		start = newnode;
	}
	else
	{
		placefound = 0 ; temp_point = start;

		while(placefound==0 && temp_point!=NULL )
		{
		    /* if level entered is bigger than the level in the particular record go to next record*/
			if(temp_point -> student_id < temp_id)
			{
				prev = temp_point;
				temp_point = temp_point -> ptr;
			}
// If level is same the n check for the sorting of the names
			//else if(temp_point -> student_id == temp_id)
			//{
			    /* stricmp() will compare the two strings
			    regardless of its case,
			    if existing name in record is smaller on
                the basis of ASCII values again jump to next
                record*/
				/*if(temp_point -> level_number<level)
				{
					prev = temp_point;
					temp_point = temp_point -> ptr;
				}
				else
				{
//Else the place if is found when this block will get executed
					placefound = 1 ;
				}*/

			//}

			else
			{
					placefound = 1 ;
			}
		}

// If only one records exist in the list

		if(temp_point == start)
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

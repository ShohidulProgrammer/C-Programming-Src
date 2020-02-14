void sorting()
{
/* if list is empty then start will point towards
the record inputted*/
	if(start==NULL)
	{
		start = newnode;
	}
	else if(start -> level_number > level)

/*
if the level/semester entered is smaller than the level
of the first record in the list
then start will again point to newnode
but pointer of newnode will point towards
the address that was previously stored in pointer
start
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
		    /* if level entered is bigger than the level in the particular record go to next record*/
			if(temp_point -> level_number < level)
			{
				prev = temp_point;
				temp_point = temp_point -> ptr;
			}
// If level is same the n check for the sorting of the names
			else if(temp_point -> level_number == level)
			{
			    /* stricmp() will compare the two strings
			    regardless of its case,
			    if existing name in record is smaller on
                the basis of ASCII values again jump to next
                record*/
				if(stricmp(temp_point -> student_name,temp_name)<0)
				{
					prev = temp_point;
					temp_point = temp_point -> ptr;
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

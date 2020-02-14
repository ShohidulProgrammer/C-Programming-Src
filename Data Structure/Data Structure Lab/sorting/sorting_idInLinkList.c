void sorting_id(){
/* if list is empty then start will point towards
the record inputted*/
	if(start==NULL){
		start = newnode;
	}
    else if(start -> student_id > temp_id){
		newnode -> ptr = start;
		start = newnode;
	}
	else{
		placefound = 0 ; temp_point = start;
		while(placefound==0 && temp_point!=NULL ){
		    /* if level entered is bigger than the level in the particular record go to next record*/
			if(temp_point -> student_id < temp_id){
				prev = temp_point;
				temp_point = temp_point -> ptr;
			}
			else{
                placefound = 1 ;
			}
		}
// If only one records exist in the list
		if(temp_point == start){
            newnode -> ptr = start;
			start = newnode;
        }
		else{
			newnode->ptr=temp_point;
			prev->ptr=newnode;
		}
	}
}

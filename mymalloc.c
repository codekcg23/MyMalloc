
/* -----------       *  Assingment 7  *     ---------------

 * If want to see current status of memory call the 'printMyMemory ' funtion in the main.
 * below progam will give print statements about what operations done and their result
 
 */

#include<stdio.h>
#include"mymalloc.h"

block *base = (void *)myMemory;

void *MyMalloc(size_t size){
	
	printf("\n\n            |||||||||||   MEMORY OPERATION   ||||||||||||||\n\n\n");
	block *ptr,*preptr;

	if(base->next == NULL ){  //first start of memory
		
		base->size = SIZE - sizeof(block);
		base->status = 'F';
		base->next = NULL;
		base->prev = NULL;
		printf("\n\n initialize the memory  \n\n");
		
	}
	
	ptr = base;
	
	 //traverse through the memory array to find releavant block	
		
	while( !((ptr->status == 'F') && (ptr->size >= size )) && (ptr->next != NULL)){  
				
			preptr = ptr;
			ptr = ptr->next;
			ptr->prev = preptr;
				
	}
		
	//find the exactly same memory block
		
	if(ptr->size == size){ 
		
		ptr->status = 'A';
		printf("\n Allocated memory block size :   |    %lu    |",ptr->size);
			
	}
		
	//should split the current memory block
		
	else if(ptr->size > (size + sizeof(block))){      
			
		block *temp = (void*)((void *)ptr + size + sizeof(block));     //this is the pointer of newly created free block
		temp->status = 'F';
		temp->next = ptr->next;     //get block address after free
		temp->prev = ptr  ;
		temp->size = ptr->size - size  - sizeof(block);
		ptr->status ='A';
		ptr->size = size;
		ptr->next = temp;
		printf("\n Allocated the memory block size :  |     %lu     | ",ptr->size);
	//	printf("\n Allocated memory block address : %p",ptr + sizeof(block));
	}
		
	//when can't find a suitable block
			
	else{
		
		printf("\n block not found");   
		return NULL;
		
	}			
			
	
	return((void *)((void *)ptr + sizeof(block)));   //pointer to memory block which  is allocated (not the detailBlock)
		
		
}
	
	

void MyFree(void *blockPtr){
	
	printf("\n\n           |||||||||||   MEMORY OPERATION   ||||||||||||||\n");
	block *ptr = blockPtr - sizeof(block);
	
	//checking given pointer is in the range or not
	
	if((void *)base <= blockPtr && blockPtr <= (void *)(myMemory + SIZE) ){
		
		ptr->status = 'F';
		printf("\n\n free memory block size : |   %lu   |\n",ptr->size);
	//	printf("\n free memory block address : %p ",ptr +sizeof(block));
		
		//merging two consecutive free blocks
		ptr = base;
		
		while(ptr && ptr->next){
			                                                            //    ^  
			if(ptr->status == 'F' && ptr->next->status == 'F' ){    // ex-:  A| F  |  F  | F| A
				
				ptr->size = ptr->size + ptr->next->size + sizeof(block);
				ptr->next = ptr->next->next;
			//	printf("\n merge next free blocks");
				
			}                                                                //  ^
			if(ptr->status == 'F'  && ptr->prev->status == 'F'){  //ex -:  A | F | F  |
				
				ptr->next->prev = ptr->prev;
				ptr->prev->next = ptr->next;
			//	printf("\n merge  prev free blocks "); 
			}
			
			
			ptr = ptr->next;
		}
		
	}
	//when given ponter can't find
	else{
		
		printf("\n invalid pointer");
	}
		
}

void printMyMemory(){
	
	block *ptr = base;
	
	printf(" \n\n\n |||||||||||||||        CURRENT MEMORY STATUS       ||||||||||||||||||  \n\n\n");
	printf("\n\n           |  status     |    size of block          \n\n");
	
	while(ptr != NULL){
		
		printf("           |      %c     |          %lu                \n",ptr->status,ptr->size);
		printf("           ----------------------------------------------\n");
		
		ptr =ptr->next;
	}
	
	
	 
}



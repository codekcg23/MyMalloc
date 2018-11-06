#ifndef MYMALLOC
#define MYMALLOC

#include<stdio.h>
# define SIZE 25000

char myMemory[SIZE];

typedef struct detailBlock{
	
	size_t size;                  //size of block
	char status;                  //'F'= free block ,'A' = allocate block
	struct detailBlock *next;
	struct detailBlock *prev;
	
}block;

//block *base = (void *)myMemory;      ----- getting an error multiple define when run the program----------

void *MyMalloc(size_t size);
void MyFree(void *blockPtr);
void printMyMemory();
	
	
#endif
	
	
	


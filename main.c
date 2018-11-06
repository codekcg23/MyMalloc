#include<stdio.h>
#include"mymalloc.h"


int main(){
	
	int *p =(int *)MyMalloc(100*sizeof(int));
	//char *q = (char)MyMalloc(250*sizeof(char));
	
	//MyFree(p);
	
	char *c =(char *)MyMalloc(20*sizeof(char));
	int *q =(int *)MyMalloc(1000*sizeof(int));
	int *r =(int *)MyMalloc(200*sizeof(int));
	char *t =(char *)MyMalloc(10*sizeof(char));
	MyFree(r);
	MyFree(c);
	MyFree(q);
	printMyMemory();
	
	
	return 0;
	
	
}


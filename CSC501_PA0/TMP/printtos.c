// Name : Ankit Manendra
// Unity ID : amanend
// Assignment Number: PA0

#include<stdio.h>

unsigned long *ebp;

void printtos(){

	asm("movl %ebp,ebp");

	kprintf("void printtos() \n");
	kprintf("Before[0x%08x]: 0x%08x \n",(ebp+2),*(ebp+2));
	kprintf("After[0x%08x]: 0x%08x \n",(ebp),*(ebp));
	
	//here we are creating some variable so that we get some data values in stack
	int j;
        int populate[4];
        for (j=0;j<4;j++){
 	       populate[j] = j; 
        }

	int i; 
	for (i=1;i<=4;i++){
		kprintf("\telement[0x%08x]: 0x%08x \n",(ebp-i),*(ebp-i));
	}
	
}

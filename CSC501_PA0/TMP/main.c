/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int prX;
void halt();

prch(c)
char c;
{
	int i;
	sleep(5);	
}

int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	long param = 2864434397;
	kprintf("output to first function is 0x%x \n", zfunction(param));
	kprintf("\n");
	printsegaddress();
	kprintf("\n");
	printtos();
	kprintf("\n");
	printprocstks(-1);
	kprintf("\n");
	syscallsummary_start();
	resume(prX = create(prch,2000,20,"proc X",1,'A'));
	sleep(10); 
	syscallsummary_stop();
	printsyscallsummary();		
	return 0;
}

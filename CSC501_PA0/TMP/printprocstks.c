// Name : Ankit Manendra
// Unity ID : amanend
// Assignment Number: PA0

#include <kernel.h>
#include <stdio.h>
#include<proc.h>

static unsigned long *esp;

void printprocstks(int priority){

	int larPrioProc[NPROC];
	int i;
	
//initialize all entries with zero
	for (i=0;i<NPROC;i++){
		larPrioProc[i]=0;
	}

//setting indexes for all processes with larger priority to 1	
	for (i=0;i<NPROC;i++){
                if(proctab[i].pprio > priority && proctab[i].pstate!=PRFREE){
			larPrioProc[i]=1;
		}
        }

	kprintf("void printprocstks(int priority) \n");	

	for (i=0;i<NPROC;i++){
                if(larPrioProc[i]==1){
                        kprintf("Process [%s] \n",proctab[i].pname);
			kprintf("\tpid: %d\n",i);
			kprintf("\tpriority: %d\n",proctab[i].pprio);
			kprintf("\tbase: 0x%08x\n",proctab[i].pbase);
			kprintf("\tlimit: 0x%08x\n",proctab[i].plimit);
			kprintf("\tlen: %d\n",proctab[i].pstklen);
						
			if(i == currpid){
				asm("movl %esp,esp");
				kprintf("\tpointer: 0x%08x\n",esp);
			}
			else{
				kprintf("\tpointer: 0x%08x\n",proctab[i].pesp);
			}
                }
        }


}

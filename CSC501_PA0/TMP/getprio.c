/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
SYSCALL getprio(int pid)
{
	
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }
	
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][3] = execTime[currpid][3] + totalTime;
                        freq[currpid][3]++;
                }
		return(SYSERR);
	}
	restore(ps);
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][3] = execTime[currpid][3] + totalTime;
                        freq[currpid][3]++;
                }
	return(pptr->pprio);
}

/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{
	
	long start, totalTime;	
	if(tracking==1){
		start=ctr1000;
	}	

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		if(tracking==1){
			totalTime = ctr1000 - start;
			execTime[currpid][1] = execTime[currpid][1] + totalTime;
			freq[currpid][1]++;
		}
		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][1] = execTime[currpid][1] + totalTime;
                        freq[currpid][1]++;
                }
	return(newprio);
}

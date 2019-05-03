/* suspend.c - suspend */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  suspend  --  suspend a process, placing it in hibernation
 *------------------------------------------------------------------------
 */
SYSCALL	suspend(int pid)
{
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }

	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority returned		*/

	disable(ps);
	if (isbadpid(pid) || pid==NULLPROC ||
	 ((pptr= &proctab[pid])->pstate!=PRCURR && pptr->pstate!=PRREADY)) {
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][24] = execTime[currpid][24] + totalTime;
                        freq[currpid][24]++;
                }
		return(SYSERR);
	}
	if (pptr->pstate == PRREADY) {
		pptr->pstate = PRSUSP;
		dequeue(pid);
	}
	else {
		pptr->pstate = PRSUSP;
		resched();
	}
	prio = pptr->pprio;
	restore(ps);
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][24] = execTime[currpid][24] + totalTime;
                        freq[currpid][24]++;
                }
	return(prio);
}

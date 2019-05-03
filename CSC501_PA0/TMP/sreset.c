/* sreset.c - sreset */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  sreset  --  reset the count and queue of a semaphore
 *------------------------------------------------------------------------
 */
SYSCALL sreset(int sem, int count)
{
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }

	
	STATWORD ps;    
	struct	sentry	*sptr;
	int	pid;
	int	slist;

	disable(ps);
	if (isbadsem(sem) || count<0 || semaph[sem].sstate==SFREE) {
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][22] = execTime[currpid][22] + totalTime;
                        freq[currpid][22]++;
                }
		return(SYSERR);
	}
	sptr = &semaph[sem];
	slist = sptr->sqhead;
	while ((pid=getfirst(slist)) != EMPTY)
		ready(pid,RESCHNO);
	sptr->semcnt = count;
	resched();
	restore(ps);
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][22] = execTime[currpid][22] + totalTime;
                        freq[currpid][22]++;
                }
	return(OK);
}

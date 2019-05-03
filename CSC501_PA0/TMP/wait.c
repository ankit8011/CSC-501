/* wait.c - wait */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * wait  --  make current process wait on a semaphore
 *------------------------------------------------------------------------
 */
SYSCALL	wait(int sem)
{
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }	

	STATWORD ps;    
	struct	sentry	*sptr;
	struct	pentry	*pptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][26] = execTime[currpid][26] + totalTime;
                        freq[currpid][26]++;
                }
		return(SYSERR);
	}
	
	if (--(sptr->semcnt) < 0) {
		(pptr = &proctab[currpid])->pstate = PRWAIT;
		pptr->psem = sem;
		enqueue(currpid,sptr->sqtail);
		pptr->pwaitret = OK;
		resched();
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][26] = execTime[currpid][26] + totalTime;
                        freq[currpid][26]++;
                }
		return pptr->pwaitret;
	}
	restore(ps);
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][26] = execTime[currpid][26] + totalTime;
                        freq[currpid][26]++;
                }
	return(OK);
}

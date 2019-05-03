/* unsleep.c - unsleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * unsleep  --  remove  process from the sleep queue prematurely
 *------------------------------------------------------------------------
 */
SYSCALL	unsleep(int pid)
{
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }
	

	STATWORD ps;    
	struct	pentry	*pptr;
	struct	qent	*qptr;
	int	remain;
	int	next;

        disable(ps);
	if (isbadpid(pid) ||
	    ( (pptr = &proctab[pid])->pstate != PRSLEEP &&
	     pptr->pstate != PRTRECV) ) {
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][25] = execTime[currpid][25] + totalTime;
                        freq[currpid][25]++;
                }
		return(SYSERR);
	}
	qptr = &q[pid];
	remain = qptr->qkey;
	if ( (next=qptr->qnext) < NPROC)
		q[next].qkey += remain;
	dequeue(pid);
	if ( (next=q[clockq].qnext) < NPROC)
		sltop = (int *) & q[next].qkey;
	else
		slnempty = FALSE;
        restore(ps);
	
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][25] = execTime[currpid][25] + totalTime;
                        freq[currpid][25]++;
                }
	return(OK);
}

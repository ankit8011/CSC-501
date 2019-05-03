/* setnok.c - setnok */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setnok  -  set next-of-kin (notified at death) for a given process
 *------------------------------------------------------------------------
 */
SYSCALL	setnok(int nok, int pid)
{
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }
	
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid)) {
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][14] = execTime[currpid][14] + totalTime;
                        freq[currpid][14]++;
                }
		return(SYSERR);
	}
	pptr = &proctab[pid];
	pptr->pnxtkin = nok;
	restore(ps);
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][14] = execTime[currpid][14] + totalTime;
                        freq[currpid][14]++;
                }
	return(OK);
}

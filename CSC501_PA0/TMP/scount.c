/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{

long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }

extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE){
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][10] = execTime[currpid][10] + totalTime;
                        freq[currpid][10]++;
                }
		return(SYSERR);
	}
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][10] = execTime[currpid][10] + totalTime;
                        freq[currpid][10]++;
                }
	return(semaph[sem].semcnt);
}

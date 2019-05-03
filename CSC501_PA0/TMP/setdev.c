/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include<lab0.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }

	
	short	*nxtdev;

	if (isbadpid(pid)){
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][13] = execTime[currpid][13] + totalTime;
                        freq[currpid][13]++;
                }
		return(SYSERR);
	}
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][13] = execTime[currpid][13] + totalTime;
                        freq[currpid][13]++;
                }
	return(OK);
}

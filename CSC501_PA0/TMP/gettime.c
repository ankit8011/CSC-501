/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <lab0.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }
	
	
    /* long	now; */

	/* FIXME -- no getutim */

	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][4] = execTime[currpid][4] + totalTime;
                        freq[currpid][4]++;
                }	

    return OK;
}

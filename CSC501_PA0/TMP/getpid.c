/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	long start, totalTime;
	
	if(tracking==1){
		start=ctr1000; //start holds the time at which this function starts
	}	

	if(tracking==1){
		totalTime=ctr1000-start; //totalTime holds the time from start to end of this func
		execTime[currpid][2] = execTime[currpid][2] + totalTime; 
		freq[currpid][2]++;

	}
	
	return(currpid);
}

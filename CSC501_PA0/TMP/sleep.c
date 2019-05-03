/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{

	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }
	

	STATWORD ps;    
	if (n<0 || clkruns==0){
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][18] = execTime[currpid][18] + totalTime;
                        freq[currpid][18]++;
                }
		return(SYSERR);
	}
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][18] = execTime[currpid][18] + totalTime;
                        freq[currpid][18]++;
                }
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);

	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][18] = execTime[currpid][18] + totalTime;
                        freq[currpid][18]++;
                }
	return(OK);
}

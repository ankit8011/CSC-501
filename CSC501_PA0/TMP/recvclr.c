/* recvclr.c - recvclr */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  recvclr  --  clear messages, returning waiting message (if any)
 *------------------------------------------------------------------------
 */
SYSCALL	recvclr()
{

	long start, totalTime;
        if(tracking==1){
                start=ctr1000;
        }
	

	STATWORD ps;    
	WORD	msg;

	disable(ps);
	if (proctab[currpid].phasmsg) {
		proctab[currpid].phasmsg = 0;
		msg = proctab[currpid].pmsg;
	} else
		msg = OK;
	restore(ps);
	if(tracking==1){
                        totalTime = ctr1000 - start;
                        execTime[currpid][7] = execTime[currpid][7] + totalTime;
                        freq[currpid][7]++;
                }
	return(msg);
}

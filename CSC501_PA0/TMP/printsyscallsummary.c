// Name : Ankit Manendra
// Unity ID : amanend
// Assignment Number: PA0

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

#define totalSCALLIMP 27

int freq[NPROC][totalSCALLIMP];		//holds the number of time each system call is invoked
int execTime[NPROC][totalSCALLIMP];	//holds the avg. execution time for each of these system calls

//below array will hold the names of all 27 sys calls
char sysCalls[totalSCALLIMP][11] = {"freemem","chprio","getpid","getprio","gettime","kill","receive","recvclr",
				"recvtim","resume","scount","sdelete","send","setdev","setnok","screate",
				"signal","signaln","sleep","sleep10","sleep100","sleep1000","sreset","stacktrace",
				"suspend","unsleep","wait"}; 


int tracking=0;		//this variable will be used in all other files to know when to start and stop tracking

void syscallsummary_start(){
	//initialize the freq and execTime arrays
	int i,j;
	for (i=0;i<NPROC;i++){
		for(j=0;j<totalSCALLIMP;j++){
			freq[i][j]=0;
			execTime[i][j]=0;
		}
	}
	tracking=1;
}								

void syscallsummary_stop(){
	tracking=0;
}


void printsyscallsummary(){
	kprintf("void printsyscallsummary() \n");
	int i,j;
	int index = -1;
	for(i=0;i<NPROC;i++){
		for(j=0;j<totalSCALLIMP;j++){
			if(freq[i][j]>0){
				int avgExecTime = execTime[i][j]/freq[i][j];
				if(index!=i){
					kprintf("Process [pid:%d]\n",i);
					index=i;
				}
				kprintf("\t Syscall: sys_%s, count:%d, average execution time:%d (ms) \n",sysCalls[j],freq[i][j],avgExecTime);
			}
		}
	}
}

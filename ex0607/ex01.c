#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#define MY_MAC_VAR 0

int main()
{
	int pid, status;

	pid = fork();

	// fork retvalue = 0
	// child process

	if (pid == 0){
		printf(" parent process pid = %d\n", getpid());
		sleep(1);
		exit(0);
	}
	else {
		int child = waitpid(pid, &status, 0);
		printf(" child = %d\n", child);
		printf(" parent proceess pid = %d\n", getpid());
		exit(0);
	}
}

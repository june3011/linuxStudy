#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{

    int pid, status, child;

    printf("처음 프로세스 pid = %d\n", getpid());
    pid = fork();

    if (pid == 0)
    {
        // 자식프로세스
        printf("자식프로세스 pid = %d\n", getpid());
        exit(1);        // 자식프로세스 종료
    }
    // 자식프로세스 종료되어도 부모프로세스 실행
    child = wait(&status);
    printf("부모프로세스 pid = %d, child = %d\n", getpid(), child);

}
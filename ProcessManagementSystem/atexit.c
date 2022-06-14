//  atexit 프로세스 종료시에 doA함수, doB함수 호출하기
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void doA(){
    printf("I'm doA\n");
}

void doB(){
    printf("I'm doB\n");
}

int main()
{

    int pid;

    pid = fork();

    if (pid == 0){
        if (atexit(doA) != 0)
            perror("error doA");
        if (atexit(doB) != 0)
            perror("error doB");
        printf("프로세스 실행중\n");
        printf("프로세스 실행중\n");
        printf("프로세스 실행중\n");
        printf("프로세스 실행중\n");
        printf("프로세스 실행중\n");
        printf("프로세스 실행중\n");
        exit(0);
    }
    // else{
    //     sleep(3);
    //     perror("parent process");
    //     exit(0);
    // }

    return 0;
}
// system 함수 호출해서 ps >> a 명령어 실행하기
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int pid, n;
    pid = fork();
    
    if (pid == 0){
        system("ps>>a");
        // n = system("ps>>a");
        // printf("%d\n", n);
        exit(0);
    }
    return 0;
}
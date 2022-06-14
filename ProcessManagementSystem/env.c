// 환경변수 읽어와서 출력하기
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int pid, n = 5;
    pid = fork();

    if (pid == 0){
        printf("%d초 뒤 env 명령어가 실행됩니다.\n", n);
        sleep(n);
        execl("/bin/env", "env", NULL);
        exit(0);
    }
    return 0;
}
// 다음과 같은 명령어를 실행하는 쉴 인터프린터를 작성하시오
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

    int pid;
    pid = fork();

    char command[100];
    
    if (pid == 0){
        printf("\n무슨 명령어를 실행하시겠습니까? : ");
        scanf("%[^\n]", command);

        execl("/bin/", command, NULL);
    }

    return 0;
}
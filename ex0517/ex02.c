#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char **argv)
{

    if (argv != 2){
        perror("삭제하실 디렉토리명을 입력하세요");
        return -1;
    }

    if (rmdir(argv[1]) == -1){
        perror("삭제 실패");
        return 0;
    }

}
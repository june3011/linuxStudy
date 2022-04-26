#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>

// struct myval
// {
//     int a;
//     int b;
// };

// void myvalset(struct myval *my){
//     my->a = 10;
//     my->b = 20;
// }


int main(int argc, char **argv){

    printf("argc = %d\n", argc);

    printf("argv[0] = %s\n", argv[0]);
    printf("argv[1] = %s\n", argv[1]);

    struct stat buf;

    // struct myval myv;
    // myvalset(&myv);

    lstat(argv[1], &buf);
    printf("stat %o %x\n", buf.st_mode, buf.st_mode);

    if (S_ISREG(buf.st_mode))
        printf("일반 파일 입니다.\n");
    if (S_ISDIR(buf.st_mode))
        printf("디렉토리 파일 입니다.\n");
}
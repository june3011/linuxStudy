#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void main()
{

    int fd;
    fd = open("aaa", O_RDWR);

    struct flock lock;


    if (fd < 0)
    {
        printf("파일 열기 실패\n");
    }

    lock.l_type = F_WRLCK;      // 쓰기 권한 잠금
    lock.l_whence = SEEK_SET;   // 처음부터
    lock.l_start = 0;           // 쓰기 잠금
    lock.l_len = 100;           // 0~100까지

    fcntl(fd, F_SETLKW, &lock);     // 잠금설정
    printf("잠금되어있음\n");

    if (lock.l_type == F_WRLCK)
        sleep(20);  // 20초 동안 멈추기

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);     // 잠금해제
    printf("잠금해제됨\n");


    close(fd);

}
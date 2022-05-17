#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    int fd = remove(argv[1]);

    if (fd == 0)
    {
        printf("파일이 삭제되었습니다.\n");
    }

}
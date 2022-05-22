#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        printf("%s  <---- 이 형식으로 작성해주세요.\n", argv[0]);
        exit(0);
    }
    char deleteFileName[20];
    printf("삭제할 파일명을 입력하세요. ");
    scanf("%s", deleteFileName);
    // if (argc != 2){
    //     printf("Please type again\n");
    //     printf("%s \"fileName\"\n",argv[0]);
    //     exit(0);
    // }

    // int fd = remove(argv[1]);
    int fd = remove(deleteFileName);

    if (fd == 0)
    {
        printf("파일이 성공적으로 삭제되었습니다.\n");
    }
    else
    {
        printf("존재하지 않는 파일입니다.\n");
    }
    close(fd);

    return 0;
}
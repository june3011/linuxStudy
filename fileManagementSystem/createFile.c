#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
// 사용 예시
//      ./createFile
// 파일명을 입력하세요 aa
// 파일 권한을 입력하세요 777
    // int fd;

    // char fileName[20];
    // char fileMode[20];
    
    // printf("파일명을 입력하세요");
    // scanf("%s", fileName);
    // printf("파일 권한을 입력하세요");
    // scanf("%s", &fileMode);

    // int perm = strtol(fileMode, (char **)NULL, 8);

    // printf("%s\n", fileName);
    // printf("%o\n", fileMode);

    // fd = creat(fileName, perm);

    // if (fd != -1){
    //     printf("파일이 생성되었습니다\n");
    // }


// 사용 예시 
//      ./createFile aa 777
    int fd;

    if (argc < 3)
    {
        printf("Please type again\n");
        printf("%s \"fileName\" \"fileMode\"\n", argv[0]);
    }

    int perm = strtol(argv[2], (char **)NULL, 8);   // 파일 권한 8진수로 변환

    // printf("%s\n", argv[1]);
    // printf("%s\n", argv[2]);

    // 0, -1
    fd = open(argv[1], O_WRONLY || O_RDONLY || O_WRONLY);
    if (fd >= 0)
    {
        printf("이미 있는 파일명입니다.\n");
        // 내용을 삭제하고 다시 만들겠습니까?
        return 0;
    }


    fd = creat(argv[1], perm);

    if (fd != -1)
    {
        printf("파일이 생성되었습니다.\n");
    }

    // if ()

}
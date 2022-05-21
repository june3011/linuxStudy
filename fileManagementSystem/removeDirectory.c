#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{

    if (argc > 1)
    {
        printf("%s   <--- 이 형식으로 입력해주세요.\n", argv[0]);
        exit(0);
    }

    char rmDirectoryName[20];

    printf("삭제할 디렉토리 명을 입력하세요. ");
    scanf("%s", rmDirectoryName);

    int nrmdir = rmdir(rmDirectoryName);

    if (nrmdir == 0)    // 삭제 성공
    {
        printf("디렉토리가 성공적으로 삭제되었습니다.\n");
    }
    else
    {
        printf("존재하지 않는 디렉토리 명 입니다.\n");
    }

}